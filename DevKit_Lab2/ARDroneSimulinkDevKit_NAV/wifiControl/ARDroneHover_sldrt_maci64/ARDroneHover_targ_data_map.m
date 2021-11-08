  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ARDroneHover_P)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ARDroneHover_P.PacketInput_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_P.PacketOutput_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_P.PacketOutput1_MaxMissedTicks
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_P.PacketInput_YieldWhenWaiting
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ARDroneHover_P.PacketOutput_YieldWhenWaiting
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ARDroneHover_P.PacketOutput1_YieldWhenWaiting
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ARDroneHover_P.PacketInput_PacketID
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_P.PacketOutput_PacketID
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_P.PacketOutput1_PacketID
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% ARDroneHover_P.commandsenabled_Value
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_P.commandsdisabled_Value
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_P.takeoff_Value
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_P.land_Value
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ARDroneHover_P.stop_Value
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ARDroneHover_P._Value
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ARDroneHover_P.UnitDelaytoavoidalgebraicloop_InitialCondition
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ARDroneHover_P.Constant1_Value
	  section.data(8).logicalSrcIdx = 20;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ARDroneHover_P.deg2rad_Gain
	  section.data(9).logicalSrcIdx = 21;
	  section.data(9).dtTransOffset = 9;
	
	  ;% ARDroneHover_P.deg2rad1_Gain
	  section.data(10).logicalSrcIdx = 22;
	  section.data(10).dtTransOffset = 10;
	
	  ;% ARDroneHover_P.InertialXrefm_Value
	  section.data(11).logicalSrcIdx = 23;
	  section.data(11).dtTransOffset = 11;
	
	  ;% ARDroneHover_P.InertialYrefm_Value
	  section.data(12).logicalSrcIdx = 24;
	  section.data(12).dtTransOffset = 12;
	
	  ;% ARDroneHover_P.Gain3_Gain
	  section.data(13).logicalSrcIdx = 25;
	  section.data(13).dtTransOffset = 13;
	
	  ;% ARDroneHover_P.Gain1_Gain
	  section.data(14).logicalSrcIdx = 26;
	  section.data(14).dtTransOffset = 14;
	
	  ;% ARDroneHover_P.Saturation1_UpperSat
	  section.data(15).logicalSrcIdx = 27;
	  section.data(15).dtTransOffset = 15;
	
	  ;% ARDroneHover_P.Saturation1_LowerSat
	  section.data(16).logicalSrcIdx = 28;
	  section.data(16).dtTransOffset = 16;
	
	  ;% ARDroneHover_P.Gain2_Gain
	  section.data(17).logicalSrcIdx = 29;
	  section.data(17).dtTransOffset = 17;
	
	  ;% ARDroneHover_P.Gain_Gain
	  section.data(18).logicalSrcIdx = 30;
	  section.data(18).dtTransOffset = 18;
	
	  ;% ARDroneHover_P.Saturation2_UpperSat
	  section.data(19).logicalSrcIdx = 31;
	  section.data(19).dtTransOffset = 19;
	
	  ;% ARDroneHover_P.Saturation2_LowerSat
	  section.data(20).logicalSrcIdx = 32;
	  section.data(20).dtTransOffset = 20;
	
	  ;% ARDroneHover_P.Headingrefrad_Value
	  section.data(21).logicalSrcIdx = 33;
	  section.data(21).dtTransOffset = 21;
	
	  ;% ARDroneHover_P.proportionalcontrolgainyaw_Gain
	  section.data(22).logicalSrcIdx = 34;
	  section.data(22).dtTransOffset = 22;
	
	  ;% ARDroneHover_P.Saturation3_UpperSat
	  section.data(23).logicalSrcIdx = 35;
	  section.data(23).dtTransOffset = 23;
	
	  ;% ARDroneHover_P.Saturation3_LowerSat
	  section.data(24).logicalSrcIdx = 36;
	  section.data(24).dtTransOffset = 24;
	
	  ;% ARDroneHover_P.Heightrefm_Value
	  section.data(25).logicalSrcIdx = 37;
	  section.data(25).dtTransOffset = 25;
	
	  ;% ARDroneHover_P.proportionalcontrolgain_Gain
	  section.data(26).logicalSrcIdx = 38;
	  section.data(26).dtTransOffset = 26;
	
	  ;% ARDroneHover_P.Saturation4_UpperSat
	  section.data(27).logicalSrcIdx = 39;
	  section.data(27).dtTransOffset = 27;
	
	  ;% ARDroneHover_P.Saturation4_LowerSat
	  section.data(28).logicalSrcIdx = 40;
	  section.data(28).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ARDroneHover_P.ManualSwitch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_P.ManualSwitch_CurrentSetting
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_P.Constant_Value
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ARDroneHover_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% ARDroneHover_B.TypeConversion
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_B.TypeConversion1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_B.TypeConversion2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_B.TypeConversion4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ARDroneHover_B.Constant1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ARDroneHover_B.Integrator
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% ARDroneHover_B.deg2rad
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% ARDroneHover_B.TypeConversion5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% ARDroneHover_B.TypeConversion6
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% ARDroneHover_B.TypeConversion7
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% ARDroneHover_B.deg2rad1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% ARDroneHover_B.InertialXrefm
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% ARDroneHover_B.InertialYrefm
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25;
	
	  ;% ARDroneHover_B.Saturation1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% ARDroneHover_B.Saturation2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% ARDroneHover_B.Clock
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% ARDroneHover_B.Clock1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% ARDroneHover_B.Vel_xy
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% ARDroneHover_B.yawOut
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% ARDroneHover_B.isFlying
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ARDroneHover_B.PacketInput_o1
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_B.RateTransition
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 2190;
	
	  ;% ARDroneHover_B.dataControl
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2192;
	
	  ;% ARDroneHover_B.frameOut
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 2342;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ARDroneHover_B.PacketInput_o2
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ARDroneHover_DW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_DW.yaw0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_DW.mode
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_DW.SequenceNumber
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ARDroneHover_DW.count
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ARDroneHover_DW.countHeader
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ARDroneHover_DW.countBuffer
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ARDroneHover_DW.hPrev
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% ARDroneHover_DW.PacketInput_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_DW.Euleranglesdeg_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ARDroneHover_DW.Heightm_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ARDroneHover_DW.InertialpotitionalongXem_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ARDroneHover_DW.InertialpotitionalongYem_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ARDroneHover_DW.ToWorkspace_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ARDroneHover_DW.headingdeg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ARDroneHover_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ARDroneHover_DW.PacketOutput_PWORK
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ARDroneHover_DW.PacketOutput1_PWORK
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 10;
	
	  ;% ARDroneHover_DW.ToWorkspace6_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ARDroneHover_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ARDroneHover_DW.frame
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ARDroneHover_DW.lastFrame
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 2186;
	
	  ;% ARDroneHover_DW.buffer
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 4372;
	
	  ;% ARDroneHover_DW.dataPrev
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 14372;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 291389460;
  targMap.checksum1 = 1528156739;
  targMap.checksum2 = 2797864482;
  targMap.checksum3 = 3949875066;

