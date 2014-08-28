/*! 
 * \file  include/TFEL/Math/Kriging/KrigingErrors.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 10 avr 2009
 */

#ifndef _LIB_TFEL_MATH_KRINGINGERRORS_H_
#define _LIB_TFEL_MATH_KRINGINGERRORS_H_ 

#include<stdexcept>

#include"TFEL/Config/TFELConfig.hxx"

namespace tfel
{

  namespace math
  {

    struct TFELMATHKRIGING_VISIBILITY_EXPORT KrigingErrorInvalidLength
      : public std::runtime_error
    {
      KrigingErrorInvalidLength();
    }; // end of struct KrigingErrorInvalidLength

    struct TFELMATHKRIGING_VISIBILITY_EXPORT KrigingErrorNoDataSpecified
      : public std::runtime_error
    {
      KrigingErrorNoDataSpecified();
    }; // end of struct KrigingErrorNoDataSpecified

    struct TFELMATHKRIGING_VISIBILITY_EXPORT KrigingErrorInsufficientData
      : public std::runtime_error
    {
      KrigingErrorInsufficientData();
    }; // end of struct KrigingErrorInsufficientData

  } // end of namespace math

} // end of namespace tfel

#endif /* _LIB_TFEL_MATH_KRINGINGERRORS_H */

