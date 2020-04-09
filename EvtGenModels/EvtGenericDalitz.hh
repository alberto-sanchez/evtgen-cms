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
// Module: EvtGen/EvtGenericDalitz.hh
//
// Description: Model to describe a generic dalitz decay
//
// Modification history:
//
//    DCC     16 December, 2011         Module created
//
//------------------------------------------------------------------------

#ifndef EVTGENERICDALITZ_HH
#define EVTGENERICDALITZ_HH

#include "EvtGenBase/EvtDalitzReso.hh"
#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtFlatte.hh"

#include <string>
#include <vector>

class EvtParticle;

class EvtGenericDalitz : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override{};    //prob max will be set in init

    void decay( EvtParticle* p ) override;

    std::string getParamName( int i ) override;

  private:
    int _d1, _d2, _d3;
    std::vector<std::pair<EvtComplex, EvtDalitzReso>> _resonances;
};

#endif
