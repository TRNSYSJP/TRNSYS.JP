// ---------------------------------------------------------------------------------------------------------------------
// TRNSYS.h: C++ Header file for TRNSYS 17
// This file declares all the global functions available to C / C++ TRNSYS Types
// ---------------------------------------------------------------------------------------------------------------------

// --- Kernel subroutines ----------------------------------------------------------------------------------------------

//extern "C" __declspec(dllimport) void _stdcall TYPECK(int* IOPT,int info[],int* ni,int* np,int* nd);
extern "C" __declspec(dllimport) void _cdecl TYPECK(int* IOPT,int info[],int* ni,int* np,int* nd);
//extern "C" __declspec(dllimport) void _stdcall SETSTORAGESIZE(int* NSTORE,int info[]);
extern "C" __declspec(dllimport) void _cdecl SETSTORAGESIZE(int* NSTORE,int info[]);
//extern "C" __declspec(dllimport) void _stdcall SETSTORAGEVARS(double* STORE_IN,int* NSTORE,int info[]);
extern "C" __declspec(dllimport) void _cdecl SETSTORAGEVARS(double* STORE_IN,int* NSTORE,int info[]);
//extern "C" __declspec(dllimport) void _stdcall GETSTORAGEVARS(double* STORE_OUT,int* NSTORE,int info[]);
extern "C" __declspec(dllimport) void _cdecl GETSTORAGEVARS(double* STORE_OUT,int* NSTORE,int info[]);
//extern "C" __declspec(dllimport) void _stdcall MESSAGES(int* errorCode,char* message, char* severity, int* unitNo, int* typeNo, int n, int m);
extern "C" __declspec(dllimport) void _cdecl MESSAGES(int* errorCode,char* message, char* severity, int* unitNo, int* typeNo, int n, int m);
//qcd
extern "C" __declspec(dllimport) void _cdecl SETTYPEVERSION(int* ver);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFPARAMETERS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFINPUTS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFDERIVATIVES(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFOUTPUTS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETNUMBEROFDISCRETECONTROLS(int* i);
extern "C" __declspec(dllimport) void _cdecl SETITERATIONMODE(int* i);
extern "C" __declspec(dllimport) void _cdecl SETOUTPUTVALUE(int* i ,double* value);
extern "C" __declspec(dllimport) void _cdecl SETNUMBERSTOREDVARIABLES(int* nstatic,int* ndynamic);
extern "C" __declspec(dllimport) void _cdecl SETDYNAMICARRAYINITIALVALUE(int* i,double* value);
extern "C" __declspec(dllimport) void _cdecl SETDYNAMICARRAYVALUETHISITERATION(int* i,double* value);

// --- Functions to access TRNSYS global variables ---------------------------------------------------------------------

// Function names are decorated with the Fortran module name. Short aliases are defined here below
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMAXDESCRIPLENGTH(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMAXFILEWIDTH(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMAXLABELLENGTH(void); 
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMAXPATHLENGTH(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETNMAXSTORAGESPOTS(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_ERRORFOUND(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETDECKFILENAME(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETLABEL(int, int);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETLISTINGFILELOGICALUNIT(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETMINIMUMTIMESTEP(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETNMAXWARNINGS(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETNTIMESTEPS(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETNUMBEROFERRORS(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONSTARTTIME(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONSTOPTIME(void);
extern "C" __declspec(dllimport) double	_cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONTIMESTEP(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSEXEDIR(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSINPUTFILEDIR(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSROOTDIR(void);
extern "C" __declspec(dllimport) char*	_cdecl TRNSYSFUNCTIONS_mp_GETTRNSYSUSERLIBDIR(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETVERSIONNUMBER(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETCONVERGENCETOLERANCE(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETNEXTAVAILABLELOGICALUNIT(void);
//qcd
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETCURRENTUNIT(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETCURRENTTYPE(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISSTARTTIME(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISVERSIONSIGNINGTIME(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISLASTCALLOFSIMULATION(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISENDOFTIMESTEP(void);
extern "C" __declspec(dllimport) int _cdecl TRNSYSFUNCTIONS_mp_GETISFIRSTCALLOFSIMULATION(void);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETDYNAMICARRAYVALUELASTTIMESTEP(int* n);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETPARAMETERVALUE (int* n);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETINPUTVALUE(int* n);
extern "C" __declspec(dllimport) double _cdecl TRNSYSFUNCTIONS_mp_GETSIMULATIONTIME(void); 



//extern "C" __declspec(dllimport) int    _cdecl TRNSYSFUNCTIONS_mp_GETLUW(void);

// --- Short aliases for functions included in module TrnsysFunctions + lowercase variants of kernel routines ----------

// ---------------------------------------------------------------------------------------------------------------------
#define typeck							TYPECK
#define	setStorageSize					SETSTORAGESIZE
#define	setStorageVars					SETSTORAGEVARS
#define	getStorageVars					GETSTORAGEVARS
#define getMaxDescripLength				TRNSYSFUNCTIONS_mp_GETMAXDESCRIPLENGTH    
#define getmaxFileWidth					TRNSYSFUNCTIONS_mp_GETMAXFILEWIDTH        
#define getMaxLabelLength				TRNSYSFUNCTIONS_mp_GETMAXLABELLENGTH      
#define getMaxPathLength				TRNSYSFUNCTIONS_mp_GETMAXPATHLENGTH       
#define getnMaxStorageSpots				TRNSYSFUNCTIONS_mp_GETNMAXSTORAGESPOTS    
#define ErrorFound						TRNSYSFUNCTIONS_mp_ERRORFOUND             
#define getDeckFileName					TRNSYSFUNCTIONS_mp_GETDECKFILENAME        
#define getLabel						TRNSYSFUNCTIONS_mp_GETLABEL               
#define getListingFileLogicalUnit		TRNSYSFUNCTIONS_mp_GETLISTINGFILELOGIC    
#define getMinimumTimestep				TRNSYSFUNCTIONS_mp_GETMINIMUMTIMESTEP     
#define getnMaxWarnings					TRNSYSFUNCTIONS_mp_GETNMAXWARNINGS        
#define getnTimeSteps					TRNSYSFUNCTIONS_mp_GETNTIMESTEPS          
#define getNumberOfErrors				TRNSYSFUNCTIONS_mp_GETNUMBEROFERRORS      
#define getSimulationStartTime			TRNSYSFUNCTIONS_mp_GETSIMULATIONSTARTTIME 
#define getSimulationStopTime			TRNSYSFUNCTIONS_mp_GETSIMULATIONSTOPTIME  
#define getSimulationTimeStep			TRNSYSFUNCTIONS_mp_GETSIMULATIONTIMESTEP  
#define getTrnsysExeDir					TRNSYSFUNCTIONS_mp_GETTRNSYSEXEDIR        
#define getTrnsysInputFileDir			TRNSYSFUNCTIONS_mp_GETTRNSYSINPUTFILEDIR  
#define getTrnsysRootDir				TRNSYSFUNCTIONS_mp_GETTRNSYSROOTDIR       
#define getTrnsysUserLibDir				TRNSYSFUNCTIONS_mp_GETTRNSYSUSERLIBDIR    
#define getVersionNumber				TRNSYSFUNCTIONS_mp_GETVERSIONNUMBER       
#define getConvergenceTolerance			TRNSYSFUNCTIONS_mp_GETCONVERGENCETOLERANCE
#define getNextAvailableLogicalUnit		TRNSYSFUNCTIONS_mp_GETNEXTAVAILABLELOGICALUNIT
//qcd
#define getCurrentUnit					TRNSYSFUNCTIONS_mp_GETCURRENTUNIT
#define getCurrentType					TRNSYSFUNCTIONS_mp_GETCURRENTTYPE
#define setTypeVersion					SETTYPEVERSION
#define getIsVersionSigningTime			TRNSYSFUNCTIONS_mp_GETISVERSIONSIGNINGTIME
#define getIsLastCallofSimulation		TRNSYSFUNCTIONS_mp_GETISLASTCALLOFSIMULATION
#define getIsFirstCallfSimulation		TRNSYSFUNCTIONS_mp_GETISFIRSTCALLOFSIMULATION
#define getIsStartTime					TRNSYSFUNCTIONS_mp_GETISSTARTTIME
#define getIsEndOfTimestep				TRNSYSFUNCTIONS_mp_GETISENDOFTIMESTEP
#define setIterationMode				SETITERATIONMODE
#define setNumberStoredVariables		SETNUMBERSTOREDVARIABLES
#define setNumberofParameters			SETNUMBEROFPARAMETERS
#define setNumberofInputs				SETNUMBEROFINPUTS
#define setNumberofOutputs				SETNUMBEROFOUTPUTS
#define setNumberofDerivatives			SETNUMBEROFDERIVATIVES
#define setNumberofDiscreteControls		SETNUMBEROFDISCRETECONTROLS
#define setOutputValue					SETOUTPUTVALUE
#define setDynamicArrayInitialValue		SETDYNAMICARRAYINITIALVALUE
#define setDynamicArrayValueThisIteration		SETDYNAMICARRAYVALUETHISITERATION
#define getDynamicArrayValueLastTimestep		TRNSYSFUNCTIONS_mp_GETDYNAMICARRAYVALUELASTTIMESTEP
#define getParameterValue				TRNSYSFUNCTIONS_mp_GETPARAMETERVALUE
#define getInputValue					TRNSYSFUNCTIONS_mp_GETINPUTVALUE
#define getSimulationTime				TRNSYSFUNCTIONS_mp_GETSIMULATIONTIME