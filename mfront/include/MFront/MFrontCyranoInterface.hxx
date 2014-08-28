/*!
 * \file   mfront/include/MFront/MFrontCyranoInterface.hxx
 * \brief  This file declares the MFrontCyranoInterface class
 * \author Helfer Thomas
 * \date   17 Jan 2007
 */

#ifndef _LIB_MFRONTCYRANOINTERFACE_H_
#define _LIB_MFRONTCYRANOINTERFACE_H_ 

#include<string>
#include<fstream>

#include"MFront/InterfaceBase.hxx"
#include"MFront/MFrontUMATInterfaceBase.hxx"

namespace mfront{

  /*!
   * Interface for behaviours for use in the Cast3M finite element
   * code.
   * 
   * The name of this interface comes to the fact that the Cast3M
   * choose to use an interface for user defined behaviours closed to
   * the umat interface of the Abaqus finite element solver. However,
   * conventions of Cast3M makes those two interfaces incompatibles.
   */
  struct MFrontCyranoInterface
    : public MFrontUMATInterfaceBase,
      protected InterfaceBase
  {

    static std::string 
    getName(void);

    MFrontCyranoInterface();
    /*!
     * \param[in] mb : mechanical behaviour description
     */
    virtual std::map<std::string,std::vector<std::string> >
    getGlobalIncludes(const MechanicalBehaviourDescription&) const;
    /*!
     * \param[in] mb : mechanical behaviour description
     */
    virtual std::map<std::string,std::vector<std::string> >
    getGeneratedSources(const MechanicalBehaviourDescription&) const;
    /*!
     * \param[in] mb : mechanical behaviour description
     */
    virtual std::vector<std::string>
    getGeneratedIncludes(const MechanicalBehaviourDescription&) const;
    /*!
     * \param[in] mb : mechanical behaviour description
     */
    virtual std::map<std::string,std::vector<std::string> >
    getLibrariesDependencies(const MechanicalBehaviourDescription&) const;
    /*!
     * write interface specific includes
     * \param[in] out : output file
     * \param[in] mb  : mechanical behaviour description
     */
    virtual void 
    writeInterfaceSpecificIncludes(std::ofstream&,
				   const MechanicalBehaviourDescription&) const;
    
    virtual std::pair<bool,tfel::utilities::CxxTokenizer::TokensContainer::const_iterator>
    treatKeyword(const std::string&,
		 tfel::utilities::CxxTokenizer::TokensContainer::const_iterator,
		 const tfel::utilities::CxxTokenizer::TokensContainer::const_iterator);
    /*!
     * \brief write output files
     * \param[in] mb        : mechanical behaviour description
     * \param[in] fd        : mfront file description
     */
    virtual void
    endTreatement(const MechanicalBehaviourDescription&,
		  const MFrontFileDescription&) const;
    /*!
     * \brief write output files
     * \param[in] mb : mechanical behaviour description
     * \param[in] fd : mfront file description
     * \param[in] h  : modelling hypothesis
     */
    virtual void
    reset(void);

    ~MFrontCyranoInterface();
    
  protected:

    static int
    getModellingHypothesisIdentifier(const Hypothesis);

    virtual std::string
    getLibraryName(const MechanicalBehaviourDescription&) const;

    virtual std::string
    getInterfaceName(void) const;

    /*!
     * \return the name of the function generated by the Cyrano interface
     * \param[in] n : name of the behaviour as defined by interface
     *                (generally taking into account the material
     *                 and the behaviour name)
     */
    virtual std::string
    getFunctionName(const std::string&) const;

    std::string
    getBehaviourName(const std::string&,
		     const std::string&) const;

    virtual std::string
    getUmatFunctionName(const std::string&,
			const std::string&) const;
    /*!
     * \return a pair which first member gives the position of the
     * material properties in the values given through the interface
     * and whose second members is an offset giving the number of
     * imposed material properties.
     * \param[in] mb : mechanical behaviour description
     * \param[in] h  : modelling hypothesis
     */
    virtual std::pair<std::vector<UMATMaterialProperty>,
		      SupportedTypes::TypeSize>
    buildMaterialPropertiesList(const MechanicalBehaviourDescription&,
				const Hypothesis) const;
    
    virtual void
    writeMTestFileGeneratorSetModellingHypothesis(std::ostream&) const;
    /*!
     * \param[in] out  : output file
     * \param[in] name : name of the behaviour 
     * \param[in] h    : modelling hypothesis
     * \param[in] mb   : behaviour description
     * \param[in] fd   : file description
     */
    virtual void
    writeUMATxxAdditionalSymbols(std::ostream&,
				 const std::string&,
				 const Hypothesis,
				 const MechanicalBehaviourDescription&,
				 const MFrontFileDescription&) const;

    virtual void
    writeCyranoFortranFunctionDefine(std::ostream&,
				     const std::string&) const;

    virtual void
    writeCyranoFunctionDeclaration(std::ostream&,
				   const std::string&) const;

    /*!
     * \brief write the standard cyrano function
     * \param[in] out : ouptut file
     * \param[in] n   : name of the behaviour as defined by interface
     *                  (generally taking into account the material
     *                   and the behaviour name)
     * \param[in] mb  : behaviour description
     */
    virtual void
    writeStandardCyranoFunction(std::ostream&,
				const std::string&,
				const MechanicalBehaviourDescription&) const;

    /*!
     * \brief write a  specialisation of the CyranoTraits class
     * \param[in] out : ouptut file
     * \param[in] mb  : behaviour description
     * \param[in] h   : modelling hypothesis
     */
    virtual void
    writeCyranoBehaviourTraits(std::ostream&,
			       const MechanicalBehaviourDescription&,
			       const Hypothesis) const;

    virtual std::string
    getModellingHypothesisTest(const Hypothesis) const;

    std::set<tfel::material::ModellingHypothesis::Hypothesis>
    getModellingHypothesesToBeTreated(const MechanicalBehaviourDescription&) const;

    bool useTimeSubStepping;

    bool doSubSteppingOnInvalidResults;

    unsigned short maximumSubStepping;

  }; // end of MFrontCyranoInterface

} // end of namespace mfront

#endif /* _LIB_MFRONTCYRANOINTERFACE_H */
