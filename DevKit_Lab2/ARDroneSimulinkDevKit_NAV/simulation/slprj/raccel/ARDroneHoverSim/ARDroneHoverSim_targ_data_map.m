  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (rtP)
    ;%
      section.nData     = 56;
      section.data(56)  = dumData; %prealloc
      
	  ;% rtP.timeDelay
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.StateSpace_A
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.StateSpace_B
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rtP.StateSpace_C
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtP.StateSpace_InitialCondition
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.deg2rad1_Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.StateSpace1_A
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtP.StateSpace1_B
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.StateSpace1_C
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% rtP.StateSpace1_InitialCondition
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% rtP.deg2rad_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% rtP.StateSpace4_A
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtP.StateSpace4_B
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% rtP.StateSpace4_C
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% rtP.StateSpace4_InitialCondition
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% rtP.deg2rad2_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 22;
	
	  ;% rtP.StateSpace5_A
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% rtP.StateSpace5_B
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% rtP.StateSpace5_C
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 27;
	
	  ;% rtP.StateSpace5_InitialCondition
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 29;
	
	  ;% rtP.Constant1_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtP.deg2rad_Gain_ac0spr3vlb
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% rtP.deg2rad1_Gain_nt4gyxjmbp
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% rtP.RTrans4_InitialCondition
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% rtP.Saturation1_UpperSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% rtP.Saturation1_LowerSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 36;
	
	  ;% rtP.RTrans3_InitialCondition
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% rtP.Saturation2_UpperSat
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% rtP.Saturation2_LowerSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 39;
	
	  ;% rtP.RTrans2_InitialCondition
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 40;
	
	  ;% rtP.Saturation3_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 41;
	
	  ;% rtP.Saturation3_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 42;
	
	  ;% rtP.RTrans1_InitialCondition
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 43;
	
	  ;% rtP.Saturation4_UpperSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 44;
	
	  ;% rtP.Saturation4_LowerSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 45;
	
	  ;% rtP.StateSpace2_A
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 46;
	
	  ;% rtP.StateSpace2_B
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 47;
	
	  ;% rtP.StateSpace2_C
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 48;
	
	  ;% rtP.StateSpace2_InitialCondition
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 49;
	
	  ;% rtP.StateSpace3_A
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 50;
	
	  ;% rtP.StateSpace3_B
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% rtP.StateSpace3_C
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% rtP.StateSpace3_InitialCondition
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% rtP.totalcommunicationtimedelay_MaxDelay
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% rtP.totalcommunicationtimedelay_InitOutput
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 55;
	
	  ;% rtP.InertialXrefm_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 59;
	
	  ;% rtP.InertialYrefm_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 60;
	
	  ;% rtP.Gain2_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 61;
	
	  ;% rtP.Gain_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 62;
	
	  ;% rtP.Headingrefrad_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 63;
	
	  ;% rtP.proportionalcontrolgainyaw_Gain
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 64;
	
	  ;% rtP.Heightrefm_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 65;
	
	  ;% rtP.proportionalcontrolgain_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 66;
	
	  ;% rtP.Gain3_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 67;
	
	  ;% rtP.Gain1_Gain
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (rtB)
    ;%
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% rtB.hbl52k43sz
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.cofx0wimtn
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.afymbnqbja
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.hwfrmz5f3r
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.e0dwz0nd0f
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.k2pexa1jcv
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.grcjjbltf4
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.f5dnmxffg4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.kqhgmm5uqn
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtB.lj3rhp5vml
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtB.lheu1wj2gf
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtB.ct0lfakgvx
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtB.lo0eaoyvmd
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtB.mqxjcbkpjz
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtB.j3kljood4v
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtB.ny5cfobxq4
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtB.cllqdyv02v
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtB.d04rtlng0c
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtB.mhwrae3jwj
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtB.oz1y4s2hbk
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtB.edlokp5332
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtB.m32nvwcf2p
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtB.kwpff2ydjd
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 29;
	
	  ;% rtB.le5u5iq05u
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 30;
	
	  ;% rtB.lcppzkdajf
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 31;
	
	  ;% rtB.mtdunn0hxq
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 32;
	
	  ;% rtB.ic5el12kf2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 33;
	
	  ;% rtB.karkyytmd2
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 34;
	
	  ;% rtB.ky1idomaqy
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% rtB.mq1at2ouk5
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 36;
	
	  ;% rtB.ayqkbl03wb
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
	  ;% rtB.mrnorbqaqm
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 38;
	
	  ;% rtB.gb1cjjlaov
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 1;
    
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.dzkln1ywkn
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.cilee0gxli
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.omsjx15qkl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.o0kw0astte
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.fusksw1re2.modelTStart
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.ncfoovoi12.LoggedData
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bsp21xrd1m.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.pcayyc2dsa.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.f4msh5lxk5.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.gki5ebwyhe.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ncnf0zgwn3.TUbufferPtrs
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.aks53l4lnr
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.phswmmvrn3.Tail
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 1862538803;
  targMap.checksum1 = 1285932175;
  targMap.checksum2 = 1195978743;
  targMap.checksum3 = 2431553248;

