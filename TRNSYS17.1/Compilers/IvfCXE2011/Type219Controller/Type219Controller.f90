      Subroutine Type219

! Object: Aircon controller
! Simulation Studio Model: Type219Controller
! 

! Author: YY
! Editor: YY
! Date:	 9 15, 2013
! last modified: 9 15, 2013
! 
! 
! *** 
! *** Model Parameters 
! *** 
!			Rho	kg/m^3 [0;+Inf]
!			Cp	J/kg.K [0;+Inf]

! *** 
! *** Model Inputs 
! *** 
!			Tg	C [-Inf;+Inf]
!			Ts	C [-Inf;+Inf]
!			Te	C [-Inf;+Inf]

! *** 
! *** Model Outputs 
! *** 
!			Q	kW [0;+Inf]
!			P	kW [0;+Inf]
!			V	m^3/hr [0;+Inf]
!			To	C [-Inf;+Inf]

! *** 
! *** Model Derivatives 
! *** 

! (Comments and routine interface generated by TRNSYS Studio)
!************************************************************************

!-----------------------------------------------------------------------------------------------------------------------
! This TRNSYS component skeleton was generated from the TRNSYS studio based on the user-supplied parameters, inputs, 
! outputs, and derivatives.  The user should check the component formulation carefully and add the content to transform
! the parameters, inputs and derivatives into outputs.  Remember, outputs should be the average value over the timestep
! and not the value at the end of the timestep; although in many models these are exactly the same values.  Refer to 
! existing types for examples of using advanced features inside the model (Formats, Labels etc.)
!-----------------------------------------------------------------------------------------------------------------------


      Use TrnsysConstants
      Use TrnsysFunctions

!-----------------------------------------------------------------------------------------------------------------------

!DEC$Attributes DLLexport :: Type219

!-----------------------------------------------------------------------------------------------------------------------
!Trnsys Declarations
      Implicit None

      Double Precision Timestep,Time
      Integer CurrentUnit,CurrentType


!    PARAMETERS
      DOUBLE PRECISION Rho
      DOUBLE PRECISION Cp
      DOUBLE PRECISION Scale

!    INPUTS
      DOUBLE PRECISION Tg
      DOUBLE PRECISION Tsensor
      DOUBLE PRECISION Tex

!     μΖp
      DOUBLE PRECISION deltaT
      DOUBLE PRECISION Q
      DOUBLE PRECISION P
      DOUBLE PRECISION V
      DOUBLE PRECISION Tout
      
      
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Get the Global Trnsys Simulation Variables
      Time=getSimulationTime()
      Timestep=getSimulationTimeStep()
      CurrentUnit = getCurrentUnit()
      CurrentType = getCurrentType()
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Set the Version Number for This Type
      If(getIsVersionSigningTime()) Then
		Call SetTypeVersion(17)
		Return
      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Do Any Last Call Manipulations Here
      If(getIsLastCallofSimulation()) Then
		Return
      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Perform Any "After Convergence" Manipulations That May Be Required at the End of Each Timestep
      If(getIsEndOfTimestep()) Then
		Return
      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Do All of the "Very First Call of the Simulation Manipulations" Here
      If(getIsFirstCallofSimulation()) Then

		!Tell the TRNSYS Engine How This Type Works
		Call SetNumberofParameters(3)           !The number of parameters that the the model wants
		Call SetNumberofInputs(3)                   !The number of inputs that the the model wants
		Call SetNumberofDerivatives(0)         !The number of derivatives that the the model wants
		Call SetNumberofOutputs(4)                 !The number of outputs that the the model produces
		Call SetIterationMode(1)                             !An indicator for the iteration mode (default=1).  Refer to section 8.4.3.5 of the documentation for more details.
		Call SetNumberStoredVariables(0,0)                   !The number of static variables that the model wants stored in the global storage array and the number of dynamic variables that the model wants stored in the global storage array
		Call SetNumberofDiscreteControls(0)               !The number of discrete control functions set by this model (a value greater than zero requires the user to use Solver 1: Powell's method)

		Return

      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Do All of the First Timestep Manipulations Here - There Are No Iterations at the Intial Time
      If (getIsStartTime()) Then
      Rho   = getParameterValue(1)
      Cp    = getParameterValue(2)
      Scale = getParameterValue(3)


      Tg = GetInputValue(1)
      Tsensor = GetInputValue(2)
      Tex = GetInputValue(3)

	
   !Check the Parameters for Problems (#,ErrorType,Text)
   !Sample Code: If( PAR1 <= 0.) Call FoundBadParameter(1,'Fatal','The first parameter provided to this model is not acceptable.')

   !Set the Initial Values of the Outputs (#,Value)
		Call SetOutputValue(1, 0) ! Q
		Call SetOutputValue(2, 0) ! P
		Call SetOutputValue(3, 0) ! V
		Call SetOutputValue(4, 0) ! To


   !If Needed, Set the Initial Values of the Static Storage Variables (#,Value)
   !Sample Code: SetStaticArrayValue(1,0.d0)

   !If Needed, Set the Initial Values of the Dynamic Storage Variables (#,Value)
   !Sample Code: Call SetDynamicArrayValueThisIteration(1,20.d0)

   !If Needed, Set the Initial Values of the Discrete Controllers (#,Value)
   !Sample Code for Controller 1 Set to Off: Call SetDesiredDiscreteControlState(1,0) 

		Return

      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!ReRead the Parameters if Another Unit of This Type Has Been Called Last
      If(getIsReReadParameters()) Then
		!Read in the Values of the Parameters from the Input File
      Rho   = getParameterValue(1)
      Cp    = getParameterValue(2)
      Scale = getParameterValue(3)
		
      EndIf
!-----------------------------------------------------------------------------------------------------------------------

!Read the Inputs
      Tg = GetInputValue(1)
      Tsensor = GetInputValue(2)
      Tex = GetInputValue(3)
		

	!Check the Inputs for Problems (#,ErrorType,Text)
	!Sample Code: If( IN1 <= 0.) Call FoundBadInput(1,'Fatal','The first input provided to this model is not acceptable.')
 
      If(ErrorFound()) Return
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!    *** PERFORM ALL THE CALCULATION HERE FOR THIS MODEL. ***
!-----------------------------------------------------------------------------------------------------------------------

	!-----------------------------------------------------------------------------------------------------------------------
	!If Needed, Get the Previous Control States if Discrete Controllers are Being Used (#)
	!Sample Code: CONTROL_LAST=getPreviousControlState(1)
	!-----------------------------------------------------------------------------------------------------------------------

	!-----------------------------------------------------------------------------------------------------------------------
	!If Needed, Get the Values from the Global Storage Array for the Static Variables (#)
	!Sample Code: STATIC1=getStaticArrayValue(1)
	!-----------------------------------------------------------------------------------------------------------------------

	!-----------------------------------------------------------------------------------------------------------------------
	!If Needed, Get the Initial Values of the Dynamic Variables from the Global Storage Array (#)
	!Sample Code: T_INITIAL_1=getDynamicArrayValueLastTimestep(1)
	!-----------------------------------------------------------------------------------------------------------------------

	!-----------------------------------------------------------------------------------------------------------------------
	!Perform All of the Calculations Here to Set the Outputs from the Model Based on the Inputs

	!Sample Code: OUT1=IN1+PAR1


	!If the model requires the solution of numerical derivatives, set these derivatives and get the current solution
	!Sample Code: T1=getNumericalSolution(1)
	!Sample Code: T2=getNumericalSolution(2)
	!Sample Code: DTDT1=3.*T2+7.*T1-15.
	!Sample Code: DTDT2=-2.*T1+11.*T2+21.
	!Sample Code: Call SetNumericalDerivative(1,DTDT1)
	!Sample Code: Call SetNumericalDerivative(2,DTDT2)


      deltaT = Tsensor-Tg !deltaT
!Tex1 = S_EX1
      
      !deltaT©ηβ[\ΝQ[kW]AΑοdΝP[kW]AΚV[m3/h]πίι
      if(deltaT>=2.0d0) then
          Q = 4.5d0 !β[\Ν
          P = 1.0d0 !ΑοdΝ
          V = 1000.0d0 !Κ
      else if (deltaT <= -1.0d0) then
          Q = 0.0d0 !β[\Ν
          P = 0.0d0 !ΑοdΝ
          V = 0.9d0 !Κ
      else
          Q = 0.25d0*deltaT**3-0.5d0*deltaT**2+1.25d0*deltaT+2.0d0 !β[\Ν
          P = 0.0556d0*deltaT**3-0.1111d0*deltaT**2+0.2778d0*deltaT+0.4444d0 !ΑοdΝ 
          V = 36.833d0*deltaT**3-55.5d0*deltaT**2+241.67d0*deltaT+444.0d0 !Κ
      endif
      
      
      !XP[έθieXgpj
      Q = Q*Scale
      P = P*Scale
      V = V*Scale
      
      
      ! o·x[C]
      if(V > 0.0d0) then
        Tout = Tex-(Q*1000*3.6*1000)/(Rho*Cp*V)
      else
        !Tout = 0.0d0
        Tout = Tsensor
      endif
      

      
      

!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!Set the Outputs from this Model (#,Value)
		Call SetOutputValue(1, Q) ! Q
		Call SetOutputValue(2, P) ! P
		Call SetOutputValue(3, V) ! V
		Call SetOutputValue(4, Tout) ! Tout

!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!If Needed, Store the Desired Disceret Control Signal Values for this Iteration (#,State)
!Sample Code:  Call SetDesiredDiscreteControlState(1,1)
!-----------------------------------------------------------------------------------------------------------------------

!-----------------------------------------------------------------------------------------------------------------------
!If Needed, Store the Final value of the Dynamic Variables in the Global Storage Array (#,Value)
!Sample Code:  Call SetValueThisIteration(1,T_FINAL_1)
!-----------------------------------------------------------------------------------------------------------------------
 
      Return
      End
!-----------------------------------------------------------------------------------------------------------------------

