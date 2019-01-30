//--------------------------------------------------------------------------
//
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Module: EvtItgFourCoeffFcn.hh
//
// Description:
//      Class describing a function with Four vectors of coefficients.
//
// Modification history:
//
//    Jane Tinslay                March 21, 2001       Module created
//
//------------------------------------------------------------------------

#ifndef EVTITFOURCOEFFFCN_HH
#define EVTITFOURCOEFFFCN_HH

#include <vector>
#include "EvtGenModels/EvtItgAbsFunction.hh"

class EvtItgFourCoeffFcn: public EvtItgAbsFunction {

public:

  EvtItgFourCoeffFcn( double (*theFunction)(double, const std::vector<double> &, const std::vector<double> &, const std::vector<double> &, const std::vector<double> &),
		     double lowerRange, double upperRange, const std::vector<double> &coeffs1, const std::vector<double> &coeffs2, const std::vector<double> &coeffs3, const std::vector<double> &coeffs4);

  void setCoeff(int, int, double) override;
  double getCoeff(int, int) override;

protected:

  double myFunction(double x) const override;

private:

  // Data members
  double (*_myFunction)(double x, const std::vector<double> & coeffs1, const std::vector<double> & coeffs2, const std::vector<double> & coeffs3, const std::vector<double> & coeffs4);

  std::vector<double> _coeffs1;
  std::vector<double> _coeffs2;
  std::vector<double> _coeffs3;
  std::vector<double> _coeffs4;

};

#endif // EvtITGPTRFUNCTION_HH
