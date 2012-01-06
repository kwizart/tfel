/*!
 * \file   ScalarVectorExprWithoutConstIteratorSpecialisation.ixx
 * \brief  This file partially specialises the ScalarVectorExprWithoutConstIterator and VectorScalarExprWithoutConstIterator classes for usual operations.
 * \see    NO_EXPRESSION_TEMPLATE_SPECIALISATION 
 * \author Helfer Thomas
 * \date   11 Sep 2006
 */

#ifndef _LIB_TFEL_SCALARVECTOREXPRWITHOUTCONSTITERATORSPECIALISATION_I_
#define _LIB_TFEL_SCALARVECTOREXPRWITHOUTCONSTITERATORSPECIALISATION_I_ 

namespace tfel{

  namespace math {

    /*
     * \brief Partial Specialisation for OpMult.
     */
    template<typename A, typename B>
    class ScalarVectorExprWithoutConstIterator<A,B,OpMult>
    {
      
      TFEL_STATIC_ASSERT((tfel::typetraits::IsScalar<A>::cond));
      TFEL_STATIC_ASSERT((tfel::meta::Implements<B,VectorConcept>::cond));
  
      typedef typename VectorTraits<B>::NumType   NumTypeB;
      typedef typename VectorTraits<B>::IndexType IndexType;
      
      static const bool IsBTemporary = tfel::typetraits::IsTemporary<B>::cond;

      const A  a;
      typename tfel::meta::IF<IsBTemporary,const B,const B&>::type b;
      const typename B::RunTimeProperties RTP;
      
      ScalarVectorExprWithoutConstIterator();

    public:
      
      typedef typename ComputeBinaryResult<A,NumTypeB,OpMult>::Handle NumType;

      static std::string getName(void){
	using namespace tfel::utilities;
	using namespace std;
	return string("ScalarVectorExprWithoutConstIterator<")+Name<A>::getName()+string(",")+Name<B>::getName()+string(",")+Name<OpMult>::getName()+string(">");
      }

    protected:

      typedef A first_arg;
      typedef B second_arg;
      typedef typename B::RunTimeProperties RunTimeProperties;

      typedef NumType        value_type;                                                
      typedef NumType*       pointer;	    						
      typedef const NumType* const_pointer; 						
      typedef NumType&       reference;	    						
      typedef const NumType& const_reference;						
      typedef IndexType      size_type;	    						
      typedef ptrdiff_t      difference_type;

      TFEL_MATH_INLINE ScalarVectorExprWithoutConstIterator(const A l, const B& r)
	: a(l), b(r), RTP(r.getRunTimeProperties())
      {}

      TFEL_MATH_INLINE ScalarVectorExprWithoutConstIterator(const ScalarVectorExprWithoutConstIterator<A,B,OpMult>& src)
	: a(src.a), b(src.b),RTP(src.RTP)
      {}
      
      TFEL_MATH_INLINE const NumType 
      operator()(const IndexType i) const 
      {
	return a*b(i);
      }

    public:

      TFEL_MATH_INLINE const RunTimeProperties 
      getRunTimeProperties(void) const 
      {                                                         
	return RTP;                                             
      }                                                         
      
    };

    /*
     * \brief Partial Specialisation for OpMult.
     */
    template<typename A, typename B>
    class VectorScalarExprWithoutConstIterator<A,B,OpMult>
    {
      
      TFEL_STATIC_ASSERT((tfel::meta::Implements<A,VectorConcept>::cond));
      TFEL_STATIC_ASSERT((tfel::typetraits::IsScalar<B>::cond));
      
      typedef typename VectorTraits<A>::NumType   NumTypeA;
      typedef typename VectorTraits<A>::IndexType IndexType;
      
      static const bool IsATemporary = tfel::typetraits::IsTemporary<A>::cond;

      typename tfel::meta::IF<IsATemporary,const A,const A&>::type a;
      const B b;

      const typename A::RunTimeProperties RTP;      

      VectorScalarExprWithoutConstIterator();

    public:

      typedef typename ComputeBinaryResult<NumTypeA,B,OpMult>::Handle NumType;
      
      static std::string getName(void){
	using namespace std;
	using namespace tfel::utilities;
	return string("VectorScalarExprWithoutConstIterator<")+Name<A>::getName()+string(",")+Name<B>::getName()+string(",")+Name<OpMult>::getName()+string(">");
      }

    protected:

      typedef A first_arg;
      typedef B second_arg;
      typedef typename A::RunTimeProperties RunTimeProperties;

      typedef NumType        value_type;                                                
      typedef NumType*       pointer;	    						
      typedef const NumType* const_pointer; 						
      typedef NumType&       reference;	    						
      typedef const NumType& const_reference;						
      typedef IndexType      size_type;	    						
      typedef ptrdiff_t      difference_type;

      TFEL_MATH_INLINE VectorScalarExprWithoutConstIterator(const A& l, const B r)
	: a(l), b(r), RTP(l.getRunTimeProperties())
      {}

      TFEL_MATH_INLINE VectorScalarExprWithoutConstIterator(const VectorScalarExprWithoutConstIterator<A,B,OpMult>& src)
	: a(src.a), b(src.b),RTP(src.RTP)
      {}
      
      TFEL_MATH_INLINE const NumType 
      operator()(const IndexType i) const 
      {
	return a(i)*b;
      }
      
    public:

      TFEL_MATH_INLINE const RunTimeProperties 
      getRunTimeProperties(void) const 
      {                                                         
	return RTP;                                             
      }                                                  
      
    };

    /*
     * \brief Partial Specialisation for OpDiv.
     */
    template<typename A, typename B>
    class VectorScalarExprWithoutConstIterator<A,B,OpDiv>
    {
      
      TFEL_STATIC_ASSERT((tfel::meta::Implements<A,VectorConcept>::cond));
      TFEL_STATIC_ASSERT((tfel::typetraits::IsScalar<B>::cond));
      
      typedef typename VectorTraits<A>::NumType   NumTypeA;
      typedef typename VectorTraits<A>::IndexType IndexType;
      
      static const bool IsATemporary = tfel::typetraits::IsTemporary<A>::cond;

      typename tfel::meta::IF<IsATemporary,const A,const A&>::type a;
      const B b;

      const typename A::RunTimeProperties RTP;      

      VectorScalarExprWithoutConstIterator();

    public:

      typedef typename ComputeBinaryResult<NumTypeA,B,OpDiv>::Handle NumType;
      
      static std::string getName(void){
	using namespace std;
	using namespace tfel::utilities;
	return string("VectorScalarExprWithoutConstIterator<")+Name<A>::getName()+string(",")+Name<B>::getName()+string(",")+Name<OpDiv>::getName()+string(">");
      }

    protected:

      typedef A first_arg;
      typedef B second_arg;
      typedef typename A::RunTimeProperties RunTimeProperties;

      typedef NumType        value_type;                                                
      typedef NumType*       pointer;	    						
      typedef const NumType* const_pointer; 						
      typedef NumType&       reference;	    						
      typedef const NumType& const_reference;						
      typedef IndexType      size_type;	    						
      typedef ptrdiff_t      difference_type;

      TFEL_MATH_INLINE VectorScalarExprWithoutConstIterator(const A& l, const B r)
	: a(l), b(r), RTP(l.getRunTimeProperties())
      {}

      TFEL_MATH_INLINE VectorScalarExprWithoutConstIterator(const VectorScalarExprWithoutConstIterator<A,B,OpDiv>& src)
	: a(src.a), b(src.b),RTP(src.RTP)
      {}
      
      TFEL_MATH_INLINE const NumType 
      operator()(const IndexType i) const 
      {
	return a(i)/b;
      }
      
    public:

      TFEL_MATH_INLINE const RunTimeProperties 
      getRunTimeProperties(void) const 
      {                                                         
	return RTP;                                             
      }                                                  
      
    };
    
  } // end of namespace math

} // end of namespace tfel


#endif /* _LIB_TFEL_SCALARVECTOREXPRWITHOUTCONSTITERATORSPECIALISATION_I_ */

