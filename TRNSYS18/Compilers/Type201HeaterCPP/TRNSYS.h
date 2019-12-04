// ---------------------------------------------------------------------------------------------------------------------
// TRNSYS.h: C++ Header file for TRNSYS 17 type structure
// This file declares all the global functions available to C / C++ TRNSYS Types
// ---------------------------------------------------------------------------------------------------------------------

// --- Kernel subroutines ----------------------------------------------------------------------------------------------

extern "C" __declspec(dllimport) void _cdecl FOUNDBADINPUT(int* Input, char* Severity, char* Message, size_t Sevlen, size_t Messlen);
extern "C" __declspec(dllimport) void _cdecl FOUNDBADPARAMETER(int* Param, char* Severity, char* Message, size_t Sevlen, size_t Messlen);
extern "C" __declspec(dllimport) void _cdecl INITREPORTINTEGRAL(int* index, char* intName, char* instUnit, char* intUnit, size_t LenName, size_t LenUnit, size_t LUnit2);
extern "C" __declspec(dllimport) void _cdecl INITREPORTMINMAX(int* index, char* minmaxName, char* minmaxUnit, size_t LenName, size_t LenUnit);
extern "C" __declspec(dllimport) void _cdecl INITREPORTTEXT(int* index, char* txtName, char* txtVal, size_t LenName, size_t LenVal);
extern "C" __declspec(dllimport) void _cdecl INITREPORTVALUE(int* index, char* valName, double* valVal, char* valUnit, size_t LenName, size_t LenUnit);
extern "C" __declspec(dllimport) int _cdecl  READNEXTCHAR(int* lun);
extern "C" __declspec(dllimport) void _cdecl SETDESIREDDISCRETECONTROLSTATE(int* i, int* j);
extern "C" __declspec(dllimport) void _cdecl SETDYNAMICARRAYINITIALVALUE(int* i, double* Value);
extern "C" __declspec(dllimport) void _cdecl SETDYNAMICARRAYVALUETHISITERATION(int* i, double* Value);
extern "C" __declspec(dllimport) void _cdecl SETINPUTUNITS(int* i, char* String, size_t len);
extern "C" __declspec(dllimport) void _cdecl SETITERATIONMODE(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFDERIVATIVES(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFDISCRETECONTROLS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFINPUTS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFOUTPUTS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFPARAMETERS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFREPORTVARIABLES(int* nInt, int* nMinMax, int* nVals, int* nText);
extern "C" __declspec(dllimport) void _cdecl SETNUMBERSTOREDVARIABLES(int* Nrequested_Static, int* Nrequested_Dynamic);
extern "C" __declspec(dllimport) void _cdecl SETNUMERICALDERIVATIVE(int* i, double* Value);
extern "C" __declspec(dllimport) void _cdecl SETOUTPUTUNITS(int* i, char* String, size_t len);
extern "C" __declspec(dllimport) void _cdecl SETOUTPUTVALUE(int* i, double* Value);
extern "C" __declspec(dllimport) void _cdecl SETSTATICARRAYVALUE(int* i, double* Value);
extern "C" __declspec(dllimport) void _cdecl SETTYPEVERSION(int* i);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_ERRORFOUND(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETCONVERGENCETOLERANCE(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETCURRENTTYPE(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETCURRENTUNIT(void);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETDECKFILENAME(char* dck, size_t len);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETDYNAMICARRAYVALUELASTTIMESTEP(int* i);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETFORMAT(char* label, size_t llen, int* iunit, int* no);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETINPUTVALUE(int* i);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISENDOFTIMESTEP(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISFIRSTCALLOFSIMULATION(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISINCLUDEDINSSR(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISLASTCALLOFSIMULATION(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISREREADPARAMETERS(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISSTARTTIME(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISVERSIONSIGNINGTIME(void);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETLABEL(char* label, size_t llen, int* iunit, int* no);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETLUFILENAME(char* name, size_t llen, int* lu);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETMAXDESCRIPLENGTH(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETMAXLABELLENGTH(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETMAXPATHLENGTH(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMINIMUMTIMESTEP(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNEXTAVAILABLELOGICALUNIT(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFDERIVATIVES(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFINPUTS(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFLABELS(int* i);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFOUTPUTS(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFPARAMETERS(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETNUMERICALSOLUTION(int* i);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETOUTPUTVALUE(int* i);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETPARAMETERVALUE(int* i);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETPREVIOUSCONTROLSTATE(int* i);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONSTARTTIME(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONSTOPTIME(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONTIME(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONTIMESTEP(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSTATICARRAYVALUE(int* i);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETTIMESTEPITERATION(void);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSINPUTFILEDIR(char* dir, size_t len);
extern "C" __declspec(dllimport) char* _cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSROOTDIR(char* dir, size_t len);
extern "C" __declspec(dllimport) void _cdecl UPDATEREPORTINTEGRAL(int* index, double* intVal);
extern "C" __declspec(dllimport) void _cdecl UPDATEREPORTMINMAX(int* index, double* newVal);

//  --- TRNSYS subroutines  ---------------------------------------------------------------

extern "C" __declspec(dllimport) void _cdecl FLUID_PROPERTIES(char* units, double prop[], int* nref, int* itype, int* iflagr, size_t len);
extern "C" __declspec(dllimport) void _cdecl GETHORIZONTALRADIATION(double* Time, int* mode_rad, int* mode_shape, double rad_input[], double* rhog, double* slope, double* azimuth, int* mode_track, int* mode_tilt, double* latitude, double* alt, double* shift, int* i_solartime, double* SolConst, double* td1, double* td2, double solar[], int* ierror_rad);
extern "C" __declspec(dllimport) void _cdecl GETTILTEDRADIATION(double* Time, double* rhog, double* slope, double* azimuth, int* mode_track, int* mode_tilt, double* alt, double* SolConst, double solar[], int* ierror_rad);
extern "C" __declspec(dllimport) void _cdecl INTERPOLATEDATA(int* LUdd, int* NINDdd, int NXdd[], int* NYdd, double Xdd[], double Ydd[]);
extern "C" __declspec(dllimport) void _cdecl MESSAGES(int* errorCode, char* message, char* severity, int* unitNo, int* typeNo, size_t n, size_t m);
extern "C" __declspec(dllimport) void _cdecl MOISTAIRPROPERTIES(int* CurUnit, int* CurType, int* iunits, int* mode, int* wbmd, double psydat[], int* emode, int* status);
extern "C" __declspec(dllimport) void _cdecl SOLVEDIFFEQ(double* aa, double* bb, double* Ti, double* Tf, double* Tbar);
extern "C" __declspec(dllimport) void _cdecl STEAM_PROPERTIES(char* units, double prop[], int* itype, int* ierrst, size_t len);


// --- Short aliases for functions included in module TrnsysFunctions + lowercase variants of kernel routines ----------

// ---------------------------------------------------------------------------------------------------------------------

#define errorFound						    TRNSYSFUNCTIONS_mp_ERRORFOUND   
#define	foundBadInput				        FOUNDBADINPUT
#define	foundBadParameter			        FOUNDBADPARAMETER
#define getConvergenceTolerance			    TRNSYSFUNCTIONS_mp_GETCONVERGENCETOLERANCE
#define getCurrentType					    TRNSYSFUNCTIONS_mp_GETCURRENTTYPE    
#define getCurrentUnit					    TRNSYSFUNCTIONS_mp_GETCURRENTUNIT    
#define getDeckFileName					    TRNSYSFUNCTIONS_mp_GETDECKFILENAME        
#define getDynamicArrayValueLastTimestep	TRNSYSFUNCTIONS_mp_GETDYNAMICARRAYVALUELASTTIMESTEP    
#define getFormat						    TRNSYSFUNCTIONS_mp_GETFORMAT               
#define getInputValue					    TRNSYSFUNCTIONS_mp_GETINPUTVALUE    
#define getIsEndOfTimestep				    TRNSYSFUNCTIONS_mp_GETISENDOFTIMESTEP    
#define getIsFirstCallofSimulation		    TRNSYSFUNCTIONS_mp_GETISFIRSTCALLOFSIMULATION    
#define getIsIncludedInSSR				    TRNSYSFUNCTIONS_mp_GETISINCLUDEDINSSR  
#define getIsLastCallofSimulation		    TRNSYSFUNCTIONS_mp_GETISLASTCALLOFSIMULATION    
#define getIsReReadParameters			    TRNSYSFUNCTIONS_mp_GETISREREADPARAMETERS    
#define getIsStartTime					    TRNSYSFUNCTIONS_mp_GETISSTARTTIME    
#define getIsVersionSigningTime			    TRNSYSFUNCTIONS_mp_GETISVERSIONSIGNINGTIME    
#define getLabel						    TRNSYSFUNCTIONS_mp_GETLABEL               
#define getLUFileName					    TRNSYSFUNCTIONS_mp_GETLUFILENAME      
#define getMaxDescripLength				    TRNSYSFUNCTIONS_mp_GETMAXDESCRIPLENGTH    
#define getMaxLabelLength				    TRNSYSFUNCTIONS_mp_GETMAXLABELLENGTH      
#define getMaxPathLength				    TRNSYSFUNCTIONS_mp_GETMAXPATHLENGTH       
#define getMinimumTimestep				    TRNSYSFUNCTIONS_mp_GETMINIMUMTIMESTEP     
#define getNextAvailableLogicalUnit		    TRNSYSFUNCTIONS_mp_GETNEXTAVAILABLELOGICALUNIT
#define getNumberOfDerivates			    TRNSYSFUNCTIONS_mp_GETNUMBEROFDERIVATIVES    
#define getNumberOfInputs				    TRNSYSFUNCTIONS_mp_GETNUMBEROFINPUTS    
#define getNumberOfLabels				    TRNSYSFUNCTIONS_mp_GETNUMBEROFLABELS               
#define getNumberOfOutputs				    TRNSYSFUNCTIONS_mp_GETNUMBEROFOUTPUTS    
#define getNumberOfParameters			    TRNSYSFUNCTIONS_mp_GETNUMBEROFPARAMETERS    
#define getNumericalSolution			    TRNSYSFUNCTIONS_mp_GETNUMERICALSOLUTION    
#define getOutputValue					    TRNSYSFUNCTIONS_mp_GETOUTPUTVALUE    
#define getParameterValue				    TRNSYSFUNCTIONS_mp_GETPARAMETERVALUE    
#define getPreviousControlState			    TRNSYSFUNCTIONS_mp_GETPREVIOUSCONTROLSTATE    
#define getSimulationStartTime			    TRNSYSFUNCTIONS_mp_GETSIMULATIONSTARTTIME 
#define getSimulationStopTime			    TRNSYSFUNCTIONS_mp_GETSIMULATIONSTOPTIME  
#define getSimulationTime				    TRNSYSFUNCTIONS_mp_GETSIMULATIONTIME 
#define getSimulationTimeStep			    TRNSYSFUNCTIONS_mp_GETSIMULATIONTIMESTEP  
#define getStaticArrayValue				    TRNSYSFUNCTIONS_mp_GETSTATICARRAYVALUE    
#define getTimestepIteration			    TRNSYSFUNCTIONS_mp_GETTIMESTEPITERATION    
#define getTrnsysInputFileDir			    TRNSYSFUNCTIONS_mp_GETTRNSYSINPUTFILEDIR  
#define getTrnsysRootDir				    TRNSYSFUNCTIONS_mp_GETTRNSYSROOTDIR       
#define	initReportIntegral				    INITREPORTINTEGRAL
#define	initReportMinMax				    INITREPORTMINMAX
#define	initReportText					    INITREPORTTEXT
#define	initReportValue					    INITREPORTVALUE
#define	readNextChar					    READNEXTCHAR
#define	setDesiredDiscreteControlState	    SETDESIREDDISCRETECONTROLSTATE
#define	setDynamicArrayInitialValue		    SETDYNAMICARRAYINITIALVALUE
#define	setDynamicArrayValueThisIteration	SETDYNAMICARRAYVALUETHISITERATION
#define	setInputUnits					    SETINPUTUNITS
#define	setIterationMode				    SETITERATIONMODE
#define	setNumberofDerivatives		 	    SETNUMBEROFDERIVATIVES
#define	setNumberofDiscreteControls		    SETNUMBEROFDISCRETECONTROLS
#define	setNumberofInputs				    SETNUMBEROFINPUTS
#define	setNumberofOutputs				    SETNUMBEROFOUTPUTS
#define	setNumberofParameters			    SETNUMBEROFPARAMETERS
#define	setNumberOfReportVariables		    SETNUMBEROFREPORTVARIABLES
#define	setNumberStoredVariables		    SETNUMBERSTOREDVARIABLES
#define	setNumericalDerivative			    SETNUMERICALDERIVATIVE
#define	setOutputUnits					    SETOUTPUTUNITS
#define	setOutputValue					    SETOUTPUTVALUE
#define	setStaticArrayValue				    SETSTATICARRAYVALUE
#define	setTypeVersion					    SETTYPEVERSION
#define	updateReportIntegral			    UPDATEREPORTINTEGRAL
#define	updateReportMinMax				    UPDATEREPORTMINMAX

#define fluid_properties                    FLUID_PROPERTIES
#define getHorizontalRadiation              GETHORIZONTALRADIATION
#define getTiltedRadiation                  GETTILTEDRADIATION
#define interpolateData                     INTERPOLATEDATA
#define messages                            MESSAGES
#define moistAirProperties                  MOISTAIRPROPERTIES
#define solveDiffEq                         SOLVEDIFFEQ
#define steam_properties                    STEAM_PROPERTIES