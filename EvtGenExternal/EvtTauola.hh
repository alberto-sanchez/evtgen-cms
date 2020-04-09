//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C)  2011      University of Warwick, UK
//
// Description: Use the Tauola external generator for tau decays
//
// Modification history:
//
//    John Back    May 2011   Module created
//
//------------------------------------------------------------------------

#ifndef EVTTAUOLA_HH
#define EVTTAUOLA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;
class EvtAbsExternalGen;
class EvtDecayBase;

class EvtTauola : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  protected:
    EvtAbsExternalGen* _tauolaEngine = nullptr;

  private:
};

#endif
