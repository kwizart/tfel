/*! 
 * \file  tmatrix_const_submatrix_view.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 27 déc. 2012
 */

#ifndef _LIB_TFEL_MATH_TMATRIX_CONST_SUBMATRIX_VIEW_H_
#define _LIB_TFEL_MATH_TMATRIX_CONST_SUBMATRIX_VIEW_H_ 

namespace tfel
{

  namespace math
  {

    template<unsigned short N,unsigned short M,
	     unsigned short I,unsigned short J,
	     unsigned short R,unsigned short C,
	     typename T>
    struct tmatrix_const_submatrix_view_expr
    {
      //! a simple typedef to the tmatrix runtime properties
      /*
       * This is a MatrixConcept requirement.
       */
      typedef EmptyRunTimeProperties RunTimeProperties;
      /*!
       * an alias defined for the constructor of the MatrixExpr
       */
      typedef const tmatrix<N,M,T> first_arg;
      //! a dummy structure
      struct invalid_argument;
      /*!
       * an alias defined for the constructor of the MatrixExpr
       */
      typedef invalid_argument second_arg;
      /*!
       * type of the tmatrix's values.
       * (this is a MatrixConcept requirement).
       */
      typedef T NumType;
      /*!
       * type of the tmatrix's values.
       * (this is a stl requirement).
       */
      typedef T value_type;
      /*!
       * type of a pointer to the value contained.
       * (this is a stl requirement).
       */
      typedef value_type* pointer;
      /*!
       * type of a const pointer to the value contained.
       * (this is a stl requirement).
       */
      typedef const value_type* const_pointer;
      /*!
       * type of a reference to the value contained.
       * (this is a stl requirement).
       */
      typedef value_type& reference;
      /*!
       * type of a const reference to the value contained.
       * (this is a stl requirement).
       */
      typedef const value_type& const_reference;
      /*!
       * type of the size of the container.
       * (this is a stl requirement).
       */
      typedef unsigned short size_type;
      /*!
       * type of the difference between two iterators.
       * (this is a stl requirement).
       */
      typedef ptrdiff_t difference_type;
      /*!
       * constructor
       * \param[in] m_ : the underlying matrix
       */      
      TFEL_MATH_INLINE
      tmatrix_const_submatrix_view_expr(const tmatrix<N,M,T>&);
      //! Return the RunTimeProperties of the tmatrix.
      /*
       * This is a MatrixConcept requirement.
       * \return const RunTimeProperties, the runtime properties of
       * the tmatrix
       */
      TFEL_MATH_INLINE
      RunTimeProperties
      getRunTimeProperties(void) const;
      /*!
       * \brief index operator.
       * This is a matrix concept requirement.
       * \param[in] i : index.
       * \param[in] j : column index.
       * \return a reference to the ith element of the submatrix.
       */
      TFEL_MATH_INLINE
      const T& 
      operator()(const unsigned short,
		 const unsigned short) const;

    private:
      
      //! reference to the underlying matrix
      const tmatrix<N,M,T>& m;

    };

    template<unsigned short N,unsigned short M,
	     unsigned short I,unsigned short J,
	     unsigned short R,unsigned short C,
	     typename T>
    struct tmatrix_const_submatrix_view
      : public MatrixExpr<tmatrix<R,C,T>, tmatrix_const_submatrix_view_expr<N,M,I,J,R,C,T> >
    {
      /*!
       * constructor
       * \param[in] m_ : the underlying matrix
       */      
      TFEL_MATH_INLINE
      tmatrix_const_submatrix_view(const tmatrix<N,M,T>&);
    };

  } // end of namespace math
  
} // end of namespace tfel

#include"TFEL/Math/Matrix/tmatrix_const_submatrix_view.ixx"

#endif /* _LIB_TFEL_MATH_TMATRIX_CONST_SUBMATRIX_VIEW_H */
