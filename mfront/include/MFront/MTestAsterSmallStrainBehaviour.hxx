/*! 
 * \file  mfront/include/MFront/MTestAsterSmallStrainBehaviour.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 07 avril 2013
 */

#ifndef _LIB_MFRONT_MTESTASTERSMALLSTRAINBEHAVIOUR_H_
#define _LIB_MFRONT_MTESTASTERSMALLSTRAINBEHAVIOUR_H_ 

#include"TFEL/Config/TFELConfig.hxx"
#include"TFEL/System/ExternalFunctionsPrototypes.hxx"
#include"MFront/MTestAsterStandardBehaviour.hxx"

namespace mfront
{

  /*!
   * A class to handle mechanical beheaviours written using the aster
   * interface
   */
  struct TFEL_VISIBILITY_LOCAL MTestAsterSmallStrainBehaviour
    : public MTestAsterStandardBehaviour
  {
    /*!
     * \param[in] h : modelling hypothesis
     * \param[in] l : library name
     * \param[in] b : behaviour name
     */
    MTestAsterSmallStrainBehaviour(const tfel::material::ModellingHypothesis::Hypothesis h,
				   const std::string&,
				   const std::string&);
    /*!
     * \param[out] v : initial values of the driving variables
     */
    virtual void
    getDrivingVariablesDefaultInitialValues(tfel::math::vector<real>&) const;
    //! destructor
    virtual ~MTestAsterSmallStrainBehaviour();
  protected:
    /*!
     * \brief call the mechanical behaviour
     * \param[out] s1    : stresses at the end of the time step
     * \param[out] iv1   : internal state variables at the end of the time step
     * \param[in]  r     : rotation matrix
     * \param[in]  e0    : strain at the beginning of the time step
     * \param[in]  de    : strain increment
     * \param[in]  s0    : stresses at the beginning of the time step
     * \param[in]  mp    : material properties
     * \param[in]  iv0   : internal state variables at the beginning of the time step
     * \param[in]  ev0   : external state variables at the beginning of the time step
     * \param[in]  dev   : external state variables increments
     * \param[in]  h     : modelling hypothesis
     * \param[in]  dt    : time increment
     * \param[in]  ktype : type of the stiffness matrix
     * \param[in] b : if true, integrate the behaviour over the time
     * step, if false compute a prediction of the stiffness matrix
     */
    virtual bool
    call_behaviour(tfel::math::matrix<real>&,
		   tfel::math::vector<real>&,
		   tfel::math::vector<real>&,
		   const tfel::math::tmatrix<3u,3u,real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::math::vector<real>&,
		   const tfel::material::ModellingHypothesis::Hypothesis,
		   const real,
		   const MTestStiffnessMatrixType::mtype,
		   const bool) const;
  }; // end of struct MTestBehaviour
  
} // end of namespace mfront

#endif /* _LIB_MFRONT_MTESTASTERSMALLSTRAINBEHAVIOUR_H */

