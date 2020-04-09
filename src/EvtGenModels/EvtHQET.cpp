//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtHQET.cc
//
// Description: Routine to implement semileptonic B->D*lnu decays according
//              to the model HQET
//
//   Lange Nov9/01 adding Dlnu and possible (w-1)^2 term
//
//
// Modification history:
//
//    DJL     April 20, 1998        Module created
//
//------------------------------------------------------------------------
//
#include "EvtGenModels/EvtHQET.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtHQETFF.hh"

#include <assert.h>
#include <stdlib.h>
#include <string>
using std::endl;

std::string EvtHQET::getName()
{
    return "HQET";
}

EvtDecayBase* EvtHQET::clone()
{
    return new EvtHQET;
}

void EvtHQET::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    calcamp->CalcAmp( p, _amp2, hqetffmodel.get() );
}

void EvtHQET::initProbMax()
{
    EvtId parnum, mesnum, lnum, nunum;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    lnum = getDaug( 1 );
    nunum = getDaug( 2 );

    double mymaxprob = calcamp->CalcMaxProb( parnum, mesnum, lnum, nunum,
                                             hqetffmodel.get() );

    setProbMax( mymaxprob );
}

void EvtHQET::init()
{
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino
    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    EvtSpinType::spintype d1type = EvtPDL::getSpinType( getDaug( 0 ) );
    if ( d1type == EvtSpinType::SCALAR ) {
        checkNArg( 1, 2 );
        if ( getNArg() == 1 )
            hqetffmodel = std::make_unique<EvtHQETFF>( getArg( 0 ) );
        else
            hqetffmodel = std::make_unique<EvtHQETFF>( getArg( 0 ), getArg( 1 ) );
        calcamp = std::make_unique<EvtSemiLeptonicScalarAmp>();
    } else if ( d1type == EvtSpinType::VECTOR ) {
        checkNArg( 3, 4 );
        if ( getNArg() == 3 )
            hqetffmodel = std::make_unique<EvtHQETFF>( getArg( 0 ), getArg( 1 ),
                                                       getArg( 2 ) );
        else
            hqetffmodel = std::make_unique<EvtHQETFF>( getArg( 0 ), getArg( 1 ),
                                                       getArg( 2 ), getArg( 3 ) );
        calcamp = std::make_unique<EvtSemiLeptonicVectorAmp>();
    } else {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "HQET model handles only scalar and vector meson daughters. Sorry."
            << endl;
        ::abort();
    }
}
