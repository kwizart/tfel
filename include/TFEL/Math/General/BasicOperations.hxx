/*!
 * \file   include/TFEL/Math/General/BasicOperations.hxx
 * \author Thomas Helfer
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATH_BASICOPERATIONS_HXX
#define LIB_TFEL_MATH_BASICOPERATIONS_HXX 1

#include <functional>
#include <type_traits>

#include "TFEL/Config/TFELConfig.hxx"
#include "TFEL/TypeTraits/IsScalar.hxx"
#include "TFEL/TypeTraits/IsComplex.hxx"
#include "TFEL/TypeTraits/IsUnaryOperator.hxx"
#include "TFEL/TypeTraits/Promote.hxx"
#include "TFEL/Math/Forward/Complex.hxx"
#include "TFEL/Math/General/ComputeBinaryResult.hxx"
#include "TFEL/Math/General/ComputeUnaryResult.hxx"

#define TFEL_MATH_RESULT_TYPE_(X, Y)                                         \
  /*!                                                                        \
   * \brief Partial specialisation for X and Y                               \
   */                                                                        \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpPlus> {  \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
  /*!                                                                        \
   * \brief Partial specialisation for X and Y                               \
   */                                                                        \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpMinus> { \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
                                                                             \
  /*!                                                                        \
   * \brief Partial specialisation for X and Y                               \
   */                                                                        \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpMult> {  \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
                                                                             \
  /*!                                                                        \
   * \brief Partial specialisation for X and Y                               \
   */                                                                        \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpDiv> {   \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  }

#define TFEL_MATH_RESULT_TYPE(X)                                              \
  TFEL_MATH_RESULT_TYPE_(X, unsigned short);                                  \
  TFEL_MATH_RESULT_TYPE_(X, unsigned int);                                    \
  TFEL_MATH_RESULT_TYPE_(X, long unsigned int);                               \
  TFEL_MATH_RESULT_TYPE_(X, short);                                           \
  TFEL_MATH_RESULT_TYPE_(X, int);                                             \
  TFEL_MATH_RESULT_TYPE_(X, long int);                                        \
  TFEL_MATH_RESULT_TYPE_(X, float);                                           \
  TFEL_MATH_RESULT_TYPE_(X, double);                                          \
  TFEL_MATH_RESULT_TYPE_(X, long double);                                     \
  /*!                                                                         \
   * \brief Partial specialisation for X                                      \
   * \see   UnaryResultType                                                   \
   */                                                                         \
  template <>                                                                 \
  struct UnaryComputeBinaryOperationResult<ScalarTag, UnaryOperatorTag, X,    \
                                           OpNeg> {                           \
    typedef tfel::typetraits::Promote<X, short>::type type;                   \
  };                                                                          \
  /*!                                                                         \
   * \brief Partial specialisation for X                                      \
   * \see   UnaryResultType                                                   \
   */                                                                         \
  template <>                                                                 \
  struct UnaryComputeBinaryOperationResult<ScalarTag, UnaryOperatorTag,       \
                                           Complex<X>, OpNeg> {               \
    typedef tfel::typetraits::Promote<Complex<X>, Complex<short>>::type type; \
  }

#define TFEL_MATH_RESULT_TYPE_COMPLEX_(X, Y)                                 \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpPlus> {  \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
                                                                             \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpMinus> { \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
                                                                             \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpMult> {  \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  };                                                                         \
                                                                             \
  template <>                                                                \
  struct ComputeBinaryOperationResult<ScalarTag, ScalarTag, X, Y, OpDiv> {   \
    typedef tfel::typetraits::Promote<X, Y>::type type;                      \
  }

#define TFEL_MATH_RESULT_TYPE_COMPLEX(X) \
  TFEL_MATH_RESULT_TYPE_(X, Complex<X>); \
  TFEL_MATH_RESULT_TYPE_(Complex<X>, X); \
  TFEL_MATH_RESULT_TYPE_(Complex<X>, Complex<X>)

namespace tfel ::math {

  struct OpPlus {
    /*
     * Add its two arguments.
     * \see ComputeBinaryResult.
     */
    template <typename T1, typename T2>
    static constexpr auto apply(T1&& a, T2&& b)
        -> BinaryOperationHandler<decltype(a), decltype(b), OpPlus> {
      return std::forward<T1>(a) + std::forward<T2>(b);
    }
  };

  struct OpMinus {
    /*
     * Substract its two arguments.
     * \see ComputeBinaryResult.
     */
    template <typename T1, typename T2>
    static constexpr auto apply(T1&& a, T2&& b)
        -> BinaryOperationHandler<decltype(a), decltype(b), OpMinus> {
      return std::forward<T1>(a) - std::forward<T2>(b);
    }

  };  // end of OpMinus

  struct OpMult {
    /*
     * Multiply its two arguments.
     * \see ComputeBinaryResult
     */
    template <typename T1, typename T2>
    static constexpr auto apply(T1&& a, T2&& b)
        -> BinaryOperationHandler<decltype(a), decltype(b), OpMult> {
      return std::forward<T1>(a) * std::forward<T2>(b);
    }
  };  // end of OpMult

  struct OpDiv {
    /*!
     * Divide the two arguments
     * \see ComputeBinaryResult.
     */
    template <typename T1, typename T2>
    static constexpr auto apply(T1&& a, T2&& b)
        -> BinaryOperationHandler<decltype(a), decltype(b), OpDiv> {
      return std::forward<T1>(a) / std::forward<T2>(b);
    }
  };  // end of OpDiv

  struct OpNeg {
    template <typename T1>
    static constexpr auto apply(T1&& a)
        -> UnaryOperationHandler<decltype(a), OpNeg> {
      return -std::forward<T1>(a);
    }
  };

  struct OpDotProduct {};  // end of struct OpDotProduct

  struct OpDiadicProduct {};

}  // end of namespace tfel::math

namespace tfel::typetraits {

  /*
   * Partial Specialisation for OpNeg
   */
  template <>
  struct IsUnaryOperator<tfel::math::OpNeg> {
    static constexpr bool cond = true;
  };

}  // namespace tfel::typetraits

namespace tfel::math {

  TFEL_MATH_RESULT_TYPE(unsigned short);
  TFEL_MATH_RESULT_TYPE(unsigned int);
  TFEL_MATH_RESULT_TYPE(long unsigned int);
  TFEL_MATH_RESULT_TYPE(short);
  TFEL_MATH_RESULT_TYPE(int);
  TFEL_MATH_RESULT_TYPE(long int);
  TFEL_MATH_RESULT_TYPE(float);
  TFEL_MATH_RESULT_TYPE(double);
  TFEL_MATH_RESULT_TYPE(long double);

  template <typename T>
  constexpr std::enable_if_t<tfel::typetraits::isScalar<T>() &&
                                 (!tfel::typetraits::IsComplex<T>::cond),
                             T>
  conj(const T src) {
    return src;
  }

  template <typename T>
  constexpr std::enable_if_t<tfel::typetraits::isScalar<T>() &&
                                 (!tfel::typetraits::IsComplex<T>::cond),
                             T>
  real(const T src) {
    return src;
  }

  TFEL_MATH_RESULT_TYPE_COMPLEX(unsigned short);
  TFEL_MATH_RESULT_TYPE_COMPLEX(unsigned int);
  TFEL_MATH_RESULT_TYPE_COMPLEX(long unsigned int);
  TFEL_MATH_RESULT_TYPE_COMPLEX(short);
  TFEL_MATH_RESULT_TYPE_COMPLEX(int);
  TFEL_MATH_RESULT_TYPE_COMPLEX(long int);
  TFEL_MATH_RESULT_TYPE_COMPLEX(float);
  TFEL_MATH_RESULT_TYPE_COMPLEX(double);
  TFEL_MATH_RESULT_TYPE_COMPLEX(long double);

}  // end of namespace tfel::math

#endif /* LIB_TFEL_MATH_BASICOPERATIONS_HXX */
