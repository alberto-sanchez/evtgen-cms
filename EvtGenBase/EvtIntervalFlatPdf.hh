
/***********************************************************************
* Copyright 1998-2020 CERN for the benefit of the EvtGen authors       *
*                                                                      *
* This file is part of EvtGen.                                         *
*                                                                      *
* EvtGen is free software: you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by *
* the Free Software Foundation, either version 3 of the License, or    *
* (at your option) any later version.                                  *
*                                                                      *
* EvtGen is distributed in the hope that it will be useful,            *
* but WITHOUT ANY WARRANTY; without even the implied warranty of       *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
* GNU General Public License for more details.                         *
*                                                                      *
* You should have received a copy of the GNU General Public License    *
* along with EvtGen.  If not, see <https://www.gnu.org/licenses/>.     *
***********************************************************************/

#ifndef EVT_INTERVAL_FLAT_PDF_HH
#define EVT_INTERVAL_FLAT_PDF_HH

#include "EvtGenBase/EvtPdf.hh"
#include "EvtGenBase/EvtPoint1D.hh"

#include <assert.h>

/*
 * Uniform PDF defined on a 1D interval.
 */

class EvtIntervalFlatPdf : public EvtPdf<EvtPoint1D> {
  public:
    EvtIntervalFlatPdf( double min, double max );
    EvtIntervalFlatPdf( const EvtIntervalFlatPdf& other );
    EvtPdf<EvtPoint1D>* clone() const override;

    using EvtPdf<EvtPoint1D>::compute_integral;
    EvtValError compute_integral() const override;
    EvtPoint1D randomPoint() override;

  protected:
    double pdf( const EvtPoint1D& ) const override;

    double _min;
    double _max;
};

#endif
