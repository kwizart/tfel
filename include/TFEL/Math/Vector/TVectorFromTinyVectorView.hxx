/*!
 * \file   include/TFEL/Math/Vector/TVectorFromTinyVectorView.hxx
 * \brief  TVectorFromTVectorView
 * 
 * \author Helfer Thomas
 * \date   16 oct 2008
 */

#ifndef _LIB_TFEL_MATH_TVECTORFROMTINYVECTORVIEW_HXX_
#define _LIB_TFEL_MATH_TVECTORFROMTINYVECTORVIEW_HXX_ 

#include"TFEL/Metaprogramming/StaticAssert.hxx"

#include"TFEL/Math/General/EmptyRunTimeProperties.hxx"
#include"TFEL/Math/Vector/VectorUtilities.hxx"
#include"TFEL/Math/Vector/VectorConcept.hxx"
#include"TFEL/Math/Vector/VectorExpr.hxx"
#include"TFEL/Math/tvector.hxx"
#include"TFEL/Math/tmatrix.hxx"

namespace tfel
{
  
  namespace math
  {

    /*!
     *  TVector From Tiny Vector
     * \param N  : space dimension
     * \param Mn : underlying tiny vector size
     * \param In : starting index in the underlying tiny vector
     * \param T  : value type
     */
    template<unsigned short N, unsigned short Mn,
	     unsigned short In,typename T>
    struct TVectorFromTinyVectorViewExpr
    {}; // end of struct TVectorFromTinyMatrixColumnViewExpr

    /*!
     *  TVector From Tiny Vector expression
     * \param N  : space dimension
     * \param Mn : underlying tiny vector size
     * \param In : starting index in the underlying tiny vector
     * \param T  : value type
     */
    template<unsigned short N, unsigned short Mn,
	     unsigned short In,typename T>
    struct TvectorExpr<tvector<N,T>,TVectorFromTinyVectorViewExpr<N,Mn,In,T> >
      : public TvectorConcept<TvectorExpr<tvector<N,T>,TVectorFromTinyVectorViewExpr<N,Mn,In,T> > >,
	public tvector_base<TvectorExpr<tvector<N,T>,TVectorFromTinyVectorViewExpr<N,Mn,In,T> >,N,T>
    {
      typedef EmptyRunTimeProperties RunTimeProperties;
      typedef typename tvector<N,T>::value_type      value_type;      
      typedef typename tvector<N,T>::pointer	   pointer;	    
      typedef typename tvector<N,T>::const_pointer   const_pointer; 
      typedef typename tvector<N,T>::reference	   reference;	    
      typedef typename tvector<N,T>::const_reference const_reference;
      typedef typename tvector<N,T>::size_type 	   size_type;	    
      typedef typename tvector<N,T>::difference_type difference_type;

      typedef tvector<Mn,T>           first_arg;
      typedef tfel::meta::InvalidType second_arg;

      RunTimeProperties
      getRunTimeProperties() const
      {
	return RunTimeProperties();
      }

      TvectorExpr(tvector<Mn,T>& v_)
	: v(v_)
      {} // end of TvectorExpr

      const T&
      operator()(const unsigned short i) const
      {
	return this->v(In+i);
      } // end of operator() const

      T&
      operator()(const unsigned short i)
      {
	return this->v(In+i);
      } // end of operator()

      const T&
      operator[](const unsigned short i) const
      {
	return this->v(In+i);
      } // end of operator[] const

      T&
      operator[](const unsigned short i)
      {
	return this->v(In+i);
      } // end of operator[]

      //! using tvector_base::operator=
      using tvector_base<TVectorExpr,N,T>::operator=;

    protected:

      tvector<Mn,T>& v;

    private:

      /*!
       * Simple checks
       */
      TFEL_STATIC_ASSERT((N==1u)||(N==2u)||(N==3u));
      TFEL_STATIC_ASSERT((In<Mn));
      TFEL_STATIC_ASSERT((N<=Mn-In));

    }; // end of struct TVectorExpr

    template<unsigned short N,
	     unsigned short Mn,
	     unsigned short In,
	     typename T = double>
    struct TVectorFromTinyVectorView
    {
      typedef TvectorExpr<tvector<N,T>,TVectorFromTinyVectorViewExpr<N,Mn,In,T> > type;
    }; // end of struct TVectorFromTinyVectorView
    
  } // end of namespace math

} // end of namespace tfel

#endif /* _LIB_TFEL_MATH_TVECTORFROMTINYVECTORVIEW_HXX */

