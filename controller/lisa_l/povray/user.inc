/********************************************************************************************************************************************
// Molex 53398 ( 1.25 pitch, vertical feeding, SMD )
********************************************************************************************************************************************/
#macro USER_CON_SMD_MOLEX_53398_GND(n)
union{
        #local L = n * 1.25 + 1.75;
        #local h = 4.7;
        #local l = 3.7;

        #local pin =
        union{
          box{<-0.18, 0.01 ,-0.35><0.18, 3.65, 0.35> translate<0, 0, -1.65>}
          cylinder {<0, 0, -0.35> <0, 0, 0.35> 0.18  scale < 1, 2, 1> translate <0, 3.65, -1.65>}
	  box{<-0.18,0.2,1.0><0.18,0.8,-1.8> }
	  box{<-0.18,0.0,1.0><0.18,0.8,1.5> }
        }

        //Pins
        union{
          #local i = 0;
          #while(i<n)
	  object{pin translate<-(n-1)*1.25/2+i*1.25,0,0>}
          #local i = i + 1;
          #end
	  object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,180,0> translate<-L/2+0.15,0.125,-1.7> } // solder tabs
          object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,0,0>   translate< L/2-0.15,0.125,-1.7> } // 
	  texture{col_silver}
        }
	//	box{<-5.075, 0.01, 0><5.075,0.02, -3>       texture{pigment{Gray30}}} // helper aka pcboard pattern
        #if (1)
        object{
	  difference{  
	    box{<-(L+3)/2, 0.01, 0><(L+3)/2,4.7, -3.7>}        // body bounding
	    box{<  (L)/2, 2.4, 0.1>< (L+4)/2,4.8, -3.8>}       // most outer cutout
	    box{< -(L)/2, 2.4, 0.1><-(L+4)/2,4.8, -3.8>}       // most outer cutout 2
	    box{<  (L)/2+0.01, -0.01, 0.1>< (L+4)/2,4.8, -0.6>}     // most outer cutout
	    box{< -(L)/2+0.01, -0.01, 0.11><-(L+4)/2,4.8, -0.6>}     // most outer cutout 2
	    box{< -(L)/2+0.6, 1.5, -0.5><(L)/2-0.6,4.8, -3.3>} // big center hole
	    box{< -(L)/2+1.6, 1.51,  0.11><(L)/2-1.6,4.8, -3.29>} // second big center hole
	    box{< -(L)/2+0.6, -0.1,  0.1><(L)/2-0.6,0.3, -3.8>} // lower hole
            #local i = 1;
            #while(i<n+1)
	    box{<-0.3,0.2,0.1> <0.3,0.7,-3.8> translate<-(n+1)*1.25/2+i*1.25,0,0>}
            #local i = i + 1;
            #end	  }
	  translate<0.,0.,0.85> texture{pigment{White}}  
	}
        #end

}
#end
#macro USER_CON_SMD_MOLEX_53398_2()
object{USER_CON_SMD_MOLEX_53398_GND(2)}
#end
#macro USER_CON_SMD_MOLEX_53398_3()
object{USER_CON_SMD_MOLEX_53398_GND(3)}
#end
#macro USER_CON_SMD_MOLEX_53398_4()
object{USER_CON_SMD_MOLEX_53398_GND(4)}
#end
#macro USER_CON_SMD_MOLEX_53398_5()
object{USER_CON_SMD_MOLEX_53398_GND(5)}
#end
#macro USER_CON_SMD_MOLEX_53398_6()
object{USER_CON_SMD_MOLEX_53398_GND(6)}
#end
#macro USER_CON_SMD_MOLEX_53398_7()
object{USER_CON_SMD_MOLEX_53398_GND(7)}
#end
#macro USER_CON_SMD_MOLEX_53398_8()
object{USER_CON_SMD_MOLEX_53398_GND(8)}
#end
#macro USER_CON_SMD_MOLEX_53398_9()
object{USER_CON_SMD_MOLEX_53398_GND(9)}
#end
#macro USER_CON_SMD_MOLEX_53398_10()
object{USER_CON_SMD_MOLEX_53398_GND(10)}
#end
#macro USER_CON_SMD_MOLEX_53398_11()
object{USER_CON_SMD_MOLEX_53398_GND(11)}
#end
#macro USER_CON_SMD_MOLEX_53398_12()
object{USER_CON_SMD_MOLEX_53398_GND(12)}
#end
#macro USER_CON_SMD_MOLEX_53398_13()
object{USER_CON_SMD_MOLEX_53398_GND(13)}
#end
#macro USER_CON_SMD_MOLEX_53398_14()
object{USER_CON_SMD_MOLEX_53398_GND(14)}
#end
#macro USER_CON_SMD_MOLEX_53398_15()
object{USER_CON_SMD_MOLEX_53398_GND(15)}
#end




/********************************************************************************************************************************************
// MPX6115 pressure sensor
********************************************************************************************************************************************/
#macro USER_MPXH6115AC6T1()
union{
  object {
    Round_Box(<-4.25,0,-4.25>, <4.25,4.8,4.25>, 1, 0) // body
    texture{pigment{Gray30}}
  }
  object {
    difference{
      cylinder{<0,4.8,0><0,9.7,0>1.5}                 // port
      cylinder{<0,4.8,0><0,9.8,0>1.}
    }
    texture{pigment{Gray30}} 
  }
}
#end

/********************************************************************************************************************************************
// MPX6115 pressure sensor
********************************************************************************************************************************************/
#macro USER_MPXV5004DP()
union{
  object {
    Round_Box(<-6.,0,-6.>, <6.,9.7,6.>, 1, 0) // body
    texture{pigment{Gray30}}
  }
  #local port =
  object {
    difference{
      cylinder{<0,0.,0><0,0., 6.35>1.5}                 // port
      cylinder{<0,0.,0><0,0., 6.45>1. }
    }
    texture{pigment{Gray30}} 
  }
  object { port  translate<2.15 ,0.75,-12>}
  object { port  translate<-2.15,8.95,-12>}
}
#end

/********************************************************************************************************************************************
// PTH08080WAH switching power supply module
********************************************************************************************************************************************/
#macro USER_PTH_TH()
union{
  object {
    box{<-7.62,2.5,-6.35> <7.62,4.,6.35>} // body
    texture{pigment{rgb<0.117647,0.243137,0.015686>}}
  }
  #local pin =
  object {
    cylinder{<0,0.1,0><0,-5.55,0>0.5}
    translate<-7.62,4,-6.35>
    texture{Gold_Texture}
  }
  union{
    object {pin translate<1.52,0.,2.79>} // pin 1
    object {pin translate<1.52,0.,6.35>} // pin 2
    object {pin translate<1.52,0.,9.91>} // pin 3
    object {pin translate<13.71,0.,1.52>} // pin 4
    object {pin translate<13.71,0,11.17>} // pin 5
  }
  object {CAP_SMD_CHIP_1206(DarkWood) rotate y*90 translate <-3.5,4,3>} // CAP
  object {CAP_SMD_CHIP_1206(DarkWood) rotate y*90 translate <-3.5,4,-3>} // CAP
  object {Round_Box(<-3.5,0,-3.5>,<3.5,3.5,3.5>,1,0) translate <2,4,0>  texture{pigment{Gray30}}} // COIL
}
#end

/********************************************************************************************************************************************
// 
********************************************************************************************************************************************/
#macro SPC_CTS_CRYSTAL(value)
  union{
    superellipsoid { <0.15, 0.15> scale <2.7, 0.455,1.7> translate <0, 0.6+0.455, 0> texture{T_Brass_5A} }
    superellipsoid { <0.15, 0.15> scale <2.55, 0.55,1.55> translate <0, 0.6+0.55, 0> texture{T_Brass_5A} }
    superellipsoid { <0.15, 0.15> scale <2.5, 0.61,1.5> translate <0, 0.6+0.61, 0> texture{T_Brass_5A} }
    
    box{<-2.3,1.8,-1><+2.3,1.83,+1> pigment{Gray50}}
    box{<-2,1.8,-1.3><+2,1.83,+1.3> pigment{Gray50}}
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,+1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,-1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,+1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,-1> pigment{Gray50}}    
    text {ttf global_fontfile_arial_bold "CTS" 0.05, 0 pigment{Gray30} scale <1,0,.8> rotate<90,0,0> translate<-2,1.84,+0.4>}  // Marking
    text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Gray20} scale <0.8,1,1> rotate<90,0,0> translate<-1.5,1.84,-0.9>}  // Marking
    translate <0, -0.55, 0.>
  }
#end

/*******************************************************************************/
// Analog device ADXL320 accelerometer
/*******************************************************************************/
#macro USER_ADXL320()
union {
  difference {
    object {
      box{<-2,0,-2><2,1.45,2>}     // Body
      pigment{Gray30}
    } 
    cylinder{<0,1.35,0><0,1.55,0>0.2 translate<-1.5,0,1.5> texture{col_silver}}
  }
  object {
    text {ttf besch_font "ADXL" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-1,1.46,0>}
    pigment { White }
  }
}
#end

/*******************************************************************************/
// Analog device ADXR gyro
/*******************************************************************************/
#macro USER_ADXR_GYRO()
union{
  object {
    box{<-3.5,0,-3.5><3.5,2.5,3.5>}     // Body
    pigment{rgb(<0.400, 0.320, 0.220>)}
  }
  object {
    text {ttf besch_font "ADXRS300" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-2,2.51,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// PNI MS2100 magnetometer
/*******************************************************************************/
#macro USER_QFN20()
union{
  difference {
    object {
      box{<-3.5,0,-3.5><3.5,1.35,3.5>}     // Body
      pigment{Gray30}
    }
    cylinder{<0,1.25,0><0,1.45,0>0.2 translate<-2.5,0,2.5> texture{col_silver}}
  }
  object {
    text {ttf besch_font "MS2100" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-2,1.36,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// ADG3308 level shifter
/*******************************************************************************/
#macro USER_LFCSP_20()
union {
  intersection {
    box{<-2.,0,-2.><2.,0.2,2.>}             // Body
    box{<-2.6,0,-2.6><2.6,0.3,2.6> rotate y*45} // Cut corners
    pigment{Gray30}
  }
  intersection {
    box{<-1.8,0.2,-1.8><1.8,0.85,1.8>}     
    box{<-2.4,0,-2.4><2.4,0.3,2.4> rotate y*45} // Cut corners
    pigment{Gray30}
  }}
#end

/*******************************************************************************/
// PCA9306 level shifter
/*******************************************************************************/
#macro USER_IC_SMD_TSSOP8_B3(value,logo)
object{IC_SMD_GRND(3.,3.,1,4.,4,4,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.45,0,logo) translate z*-0.8}
#end

/*******************************************************************************/
// TXS0102DCU
/*******************************************************************************/
#macro USER_IC_SMD_US8(value,logo)
object{IC_SMD_GRND(2.,2.3,1,3.1,4,4,0.5,0.5,0.21,0.21,0.15,0.1,0,1,0,0.5,0.25,0,logo)}
#end


/*******************************************************************************/
// Overo connector
/*******************************************************************************/
#macro USER_OVERO_AVX5602()

#local pin = 
  union {
    object {
      TOOLS_RECT_BOGEN(0.2,95, 0.1, 0.17,1.25, 0.7)
      translate x*-1
      texture{col_gold}
    }
//    box {<0.,0,-0.085><0.5,0.2,0.085>} 
  }
union {
  union {
    difference {
      box {<-2.,0,-8.05><2.,0.8,8.05>} 
      box {<-1.,0.2,-7.5><1.,0.9,7.5>} 
    }
    #local BOSS_DZ=7.5;
    object{cylinder {<0,0,0><0,-0.45,0> 0.25} translate < 0.9,0,-BOSS_DZ> } // boss 1
    object{cylinder {<0,0,0><0,-0.45,0> 0.25} translate <-0.9,0, BOSS_DZ> } // boss 2
    pigment{Gray30}
  }
  union {
    #local NBPIN = 35;
    #local PITCH = 0.4;
    #local i = 0;
    #while(i<NBPIN)
      object{pin translate<2,0,(i-NBPIN/2+0.5)*PITCH>}
      object{pin rotate y*180 translate<-2,0,(i-NBPIN/2+0.5)*PITCH>}
    #local i = i + 1;
    #end   
  }  
}
#end

#macro USER_OVERO_CON()
union {
  #local OFFSET=-22.85;
  #local DX=38.3;
  object{USER_OVERO_AVX5602() translate <OFFSET,0,0>}
  object{USER_OVERO_AVX5602() translate <OFFSET+DX,0,0>}
}
#end

/*******************************************************************************/
// Duo LED
/*******************************************************************************/
#macro USER_DUO_LED()
union {
  object{box {<-1.,0,-0.625>   <1.,0.2,0.625>}  pigment{Gray30}} 
  object{box {<-0.7,0.2,-0.5><0.7,0.8,-0.1>}   pigment{rgb<1,0,0>}} 
  object{box {<-0.7,0.2, 0.1><0.7,0.8,0.5>} pigment{rgb<0,1,0>}} 
}
#end

/*******************************************************************************/
// Ceramic GPS patch antenna
/*******************************************************************************/
#macro USER_GPS_PATCH_ANT_20()
union{
  object {
    box{<-10,0,-10><10,4.2,10>}      // Ceramic
    pigment{rgb(<0.400, 0.320, 0.220>)}
  }
  object {
    box{<-7.5,0,-7.5><7.5,4.21,7.5>} // Metal
    rotate<0, 2.5, 0>
    texture{col_silver}
  }
  sphere{ <-2, 3.5, -2> 1.5 texture{col_silver}}
}
#end



/*******************************************************************************/
// Ceramic GPS helix antenna
/*******************************************************************************/
#macro USER_SL1300()
union{
  object {
    cylinder{<0,0,4.04><0,0,12.04> 3.8}   // Ceramic
    pigment{rgb(<0.400, 0.320, 0.220>)}
  }
  object {
    cylinder{<0,0,0><0,0,4.04> 3.8}       // Balun
    texture{col_gold}
  }
  object {                                // hat
    difference {
       box{<-2.75,-2.75,12.24><2.75,2.75,12.88>}
       #local _d = 4.75;
       cylinder{<_d,_d,12.0><_d,_d,13> 4}
       cylinder{<_d,-_d,12.0><_d,-_d,13> 4}
       cylinder{<-_d,_d,12.0><-_d,_d,13> 4}
       cylinder{<-_d,-_d,12.0><-_d,-_d,13> 4}
    }      
    rotate z*45	
    texture{pigment{ForestGreen}} finish{F_MetalB} 
  }
  union {
    cylinder{<0,0,-2.5><0,0,0.0> 0.22 translate <0,0,0>}      // pins
    cylinder{<0,0,-2.5><0,0,0.0> 0.05 translate <1.015,0,0>}      
    cylinder{<0,0,-2.5><0,0,0.0> 0.05 translate <-1.015,0,0>}      
    texture{col_gold}
  }
  translate z*1  // origin is 1mm below base of ceramic 
}
#end

/*******************************************************************************/
// Ublox GPS chip
/*******************************************************************************/
#macro USER_AMY_5()
union{
  object {
    box{<-4,0,-3.25><4,1.2,3.25>}      // Ceramic
    pigment{Gray30}
  }
  text {
   ttf global_fontfile_arial_bold "GPS" 0.05, 0 pigment { White }
   scale <1,0,.8> rotate<90,0,0> translate<-2,1.22,+0.4>
  }  // Marking
}
#end

/*******************************************************************************/
// ST triple accel/mag LSM303DLH
/*******************************************************************************/
#macro USER_LGA_28()
union{
  object {
    box{<-2.5,0,-2.5><2.5,1.,2.5>} 
    pigment{Gray30}
  }
  text {
   ttf global_fontfile_arial_bold "ACCEL" 0.05, 0 pigment { White }
   scale <1,0,.8> rotate<90,90,0> translate<0,1.01,1.3>
  }  // Marking
  text {
   ttf global_fontfile_arial_bold "MAG" 0.05, 0 pigment { White }
   scale <1,0,.8> rotate<90,90,0> translate<-1,1.01,1.3>
  }  // Marking
}
#end

/*******************************************************************************/
// ST triple gyro LYPR540AH
/*******************************************************************************/
#macro USER_LGA_28L()
union{
  object {
    box{<-3.75,0,-2.2><3.75,1.1,2.2>}
    pigment{Gray30}
  }
  text {
   ttf global_fontfile_arial_bold "Gyro" 0.05, 0 pigment { White }
   scale <1,0,.8> rotate<90,180,0> translate<1,1.12,0.6>
  }  // Marking
}
#end

/*******************************************************************************/
// STM32F103RBH6 in TFBGA-64 package
/*******************************************************************************/
#macro USER_TFBGA64()
union{
  object {
    box{<-2.5,0,-2.5><2.5,1.1,2.5>}
    pigment{Gray30}
  }
  text {
   ttf global_fontfile_arial_bold "MCU" 0.05, 0 pigment { White }
   scale <1,0,.8> rotate<90,180,0> translate<1.5,1.12,0>
  }  // Marking
}
#end

/*******************************************************************************/
// ASE oscillator
/*******************************************************************************/
#macro USER_ASE_OSCILLATOR(value)
union{
  difference {
    box{<-1.6,0,-1.25>    <+1.6,0.8,+1.25>  pigment{Gray30}}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.3 translate < 1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate < 1.6,0,-1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0,-1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <0.,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <0.,0,-1.25>}
  }
  box{<-1.4,0.8,-1.05>  <+1.4,0.95,+1.05> texture{col_gold}}
  box{<-1.3,0.95,-0.95><+1.3,1.,+0.95>   texture{col_silver}}
  
  text {ttf global_fontfile_arial_bold "ASE" 0.05, 0 pigment{Gray30} scale <0.8,1.,.7> rotate<90,0,0> translate<-0.8,1.01,+0.1>}  // Marking
  text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Gray20} scale <0.6,1,0.6> rotate<90,0,0> translate<-0.8,1.01,-0.8>}  // Marking
  }
#end

/*******************************************************************************/
// Hirose DM3B SD socket
/*******************************************************************************/
#macro USER_DM3B()
union{
  #local _L = 15.95;
  #local _l = 13.85;
  #local _h = 1.84;
  #local _dz = 1;
  union {
    difference {
      box{<-_l/2,0,_dz><_l/2,_h, _dz-_L>}
      box{<-5.5+1,-0.1,_dz-1><+5.5+1,1.75, _dz-_L-1>}
      #local i = 0;
      #while(i<8)
      object { MY_TOOLS_YROUNDED_BOX(0.6, _h, 6 , 0.3) translate <i*1.1-2.8,0.1+_h/2,-3>}
      #local i = i + 1;
      #end
    }
   texture{Brushed_Aluminum}
  }
  text {ttf global_fontfile_arial_bold "MicroSD" 0.05, 
        0 pigment{Gray30} scale <2.,2.,2.> rotate<90,180,0> translate<5.,_h+0.1,-9>}  // Marking
//  MY_TOOLS_AXIS(0,0,0,0,0,0)
}
#end


/*******************************************************************************/
// SCP1000 barometer
/*******************************************************************************/
#macro USER_SCP1000()
union {
    union{
      intersection {
      cone {<0,0,0> 3.0 <0,0.7,0> 3.05}
      box{<-2.3,0,-3.051><2.3,0.71,3.051>}
    }
    cone {<0,0.7,0> 3.05 <0,1.05,0> 3.0}
    difference {
      cylinder {<0,1.05,0>  <0,1.7,0> 2.65}
      box{<-0.75,1.4,-0.75> <0.75,1.75,0.75> translate z*1.7}
    }
    texture{pigment{Gray50}}
  }
  text {ttf global_fontfile_arial_bold "BARO" 0.05, 0 pigment{White} 
    scale <1,0,.8> rotate<90,0,0> translate<-1.5,1.71,-0.5>
  }
}
#end

/*******************************************************************************/
// ads1114 ADC
/*******************************************************************************/
#macro USER_PQFP_N10()
union{
  difference {
    object {
      box{<-1.,0,-0.75><1.,0.4,0.75>}     // Body
      pigment{Gray30}
    }
    cylinder{<0,1.25,0><0,1.45,0>0.2 translate<-2.5,0,2.5> texture{col_silver}}
  }
  object {
    text {ttf besch_font "ads114" 0.5, 0 rotate<90,0,0> scale 0.5 translate<-1,0.41,0>}
    pigment { White }
  }
  translate<0,0.05,0>
}
#end

/*******************************************************************************/
// ads1114 ADC
/*******************************************************************************/
#macro USER_ABM8(value)
union{
  difference {
    box{<-1.6,0,-1.25>    <+1.6,0.8,+1.25>  pigment{Gray30}}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.3 translate < 1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate < 1.6,0,-1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0,-1.25>}
  }
  box{<-1.4,0.8,-1.05>  <+1.4,0.95,+1.05> texture{col_gold}}
  box{<-1.3,0.95,-0.95><+1.3,1.,+0.95>   texture{col_silver}}
  
  text {ttf global_fontfile_arial_bold "ABM8" 0.05, 0 pigment{Gray30} scale <0.8,1.,.7> rotate<90,0,0> translate<-0.8,1.01,+0.1>}  // Marking
  text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Gray20} scale <0.6,1,0.6> rotate<90,0,0> translate<-0.8,1.01,-0.8>}  // Marking
  }
#end