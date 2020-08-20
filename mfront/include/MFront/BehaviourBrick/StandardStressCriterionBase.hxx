/*!
 * \file   MFront/BehaviourBrick/StandardStressCriterionBase.hxx
 * \brief
 * \author Thomas Helfer
 * \date   25/03/2020
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_BEHAVIOURBRICK_STANDARDSTRESSCRITERIONBASE_HXX
#define LIB_MFRONT_BEHAVIOURBRICK_STANDARDSTRESSCRITERIONBASE_HXX

#include <map>
#include <memory>
#include "MFront/MFrontConfig.hxx"
#include "MFront/BehaviourBrick/StressCriterionBase.hxx"

namespace mfront {

  // forward declaration
  struct AbstractBehaviourDSL;

  namespace bbrick {

    // forward declaration
    struct OptionDescription;

    /*!
     * \brief an helper class used to build a stress criterion.
     * This class is meant to interface criterion described
     * in the TFEL/Material library.
     * The criterion is assumed to be uncoupled with the porosity evolution.
     */
    struct MFRONT_VISIBILITY_EXPORT StandardStressCriterionBase
        : StressCriterionBase {
      /*!
       * \brief constructor
       * \param[in] n: name of the stress criterion
       */
      StandardStressCriterionBase(const std::string& n);

      std::string computeElasticPrediction(
          const std::string&,
          const BehaviourDescription&,
          const StressPotential&) const override;
      void initialize(BehaviourDescription&,
                      AbstractBehaviourDSL&,
                      const std::string&,
                      const DataMap&,
                      const Role) override;
      void endTreatment(BehaviourDescription&,
                        const AbstractBehaviourDSL&,
                        const std::string&,
                        const Role) override;
      std::string computeCriterion(const std::string&,
                                   const BehaviourDescription&,
                                   const StressPotential&) const override;
      std::string computeNormal(const std::string&,
                                const BehaviourDescription&,
                                const StressPotential&,
                                const Role) const override;
      std::string computeNormalDerivative(const std::string&,
                                          const BehaviourDescription&,
                                          const StressPotential&,
                                          const Role) const override;
      bool isCoupledWithPorosityEvolution() const override final;
      PorosityEffectOnFlowRule getPorosityEffectOnEquivalentPlasticStrain()
          const override final;
      //! destructor
      ~StandardStressCriterionBase() override;

     private:
      //! \brief name of the stress criterion
      const std::string name;
      //! \brief material properties
      std::map<std::string, BehaviourDescription::MaterialProperty> mps;
    };  // end of StandardStressCriterionBase

  }  // end of namespace bbrick

}  // end of namespace mfront

#endif /* LIB_MFRONT_BEHAVIOURBRICK_STANDARDSTRESSCRITERIONBASE_HXX */
