/*! 
 * \file  tests/Material/FiniteStrainBehaviourTangentOperator.cxx
 * \brief
 * \author Helfer Thomas
 * \brief 12 juin 2014
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include"TFEL/Tests/TestCase.hxx"
#include"TFEL/Tests/TestProxy.hxx"
#include"TFEL/Tests/TestManager.hxx"

#include"TFEL/Math/st2tost2.hxx"
#include"TFEL/Math/t2tost2.hxx"
#include"TFEL/Material/FiniteStrainBehaviourTangentOperator.hxx"

struct FiniteStrainBehaviourTangentOperator
  : public tfel::tests::TestCase
{
  FiniteStrainBehaviourTangentOperator()
    : tfel::tests::TestCase("TFEL/Math",
			    "FiniteStrainBehaviourTangentOperator")
  {} // end of FiniteStrainBehaviourTangentOperator
  tfel::tests::TestResult
  execute()
  {
    using namespace std;
    using namespace tfel::math;
    using tfel::material::FiniteStrainBehaviourTangentOperator;
    FiniteStrainBehaviourTangentOperator<3u,double> Dt;
    st2tost2<3u,double> De(1.);
    Dt = De;
    return this->result;
  } // end of execute
};

TFEL_TESTS_GENERATE_PROXY(FiniteStrainBehaviourTangentOperator,
			  "FiniteStrainBehaviourTangentOperator");

int main(void)
{
  using namespace std;
  using namespace std;
  using namespace tfel::tests;
  using namespace tfel::utilities;
  auto& manager = TestManager::getTestManager();
  manager.addTestOutput(cout);
  manager.addXMLTestOutput("CubicSpline.xml");
  TestResult r = manager.execute();
  if(!r.success()){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
} // end of main

