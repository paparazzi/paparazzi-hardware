#include "tools.inc"
#include "textures.inc"

#macro MY_TOOLS_AXIS(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot)
object {
  union {
    union {
      cylinder{<0.,0.,0.><25.,0.,0.> 0.1}
      text { ttf "timrom.ttf" "X" 1, 0 scale <2,2,2> translate(<20, 0, 0>)}
      texture{ pigment{rgb<1,0,0>}}
    }   
    union {
      cylinder{<0.,0,0.><0.,25.,0.> 0.1}
      text { ttf "timrom.ttf" "Y" 1, 0 scale <2,2,2> translate(<0, 20, 0>)}
      texture{ pigment{rgb<0,1,0>}}
    }   
    union {
      cylinder{<0.,0,0.><0.,0.,25.> 0.1}
      text { ttf "timrom.ttf" "Z" 1, 0 scale <2,2,2> translate(<0, 0, 20>)}
      texture{ pigment{rgb<0,0,1>}}
    }   
  translate(<mac_x_ver,mac_y_ver,mac_z_ver>)
  rotate(<mac_x_rot,mac_y_rot,mac_z_rot>)	
  }
} 
#end

#macro MY_TOOLS_YROUNDED_BOX(_X,_Y,_Z,_R)
  difference {
  #local round_corner =
    #local _epsilon = 0.0001;
    difference {
      box{<0,-_Y/2-0.1,0> <_R+_epsilon,_Y/2+0.1,_R+_epsilon> }
      cylinder {<0,-_Y/2-0.2,0><0,_Y/2+0.2,0> _R}
    }    
  box{<-_X/2,-_Y/2,-_Z/2> <_X/2,_Y/2,_Z/2> }
  object { round_corner              translate <   _X/2-_R,  0,   _Z/2-_R>}
  object { round_corner rotate y*90  translate <   _X/2-_R,  0, -(_Z/2-_R)>}
  object { round_corner rotate y*180 translate < -(_X/2-_R), 0, -(_Z/2-_R)>}
  object { round_corner rotate y*270 translate < -(_X/2-_R), 0,   _Z/2-_R>}
  }
  
#end


#macro MY_TOOLS_CIRC_ARROW(_radius, _color,  _arr_opening)
object {
  #local _arr_opening_rad = _arr_opening*pi/180;
  #local _arr_width = 5;
  #local _arr_thick = 2;
  #local _arr_or = _radius + _arr_width;
  intersection {
    union {
      difference {
        torus { _radius, _arr_width }
          intersection {
            plane{-z, 0}
            plane{<-sin(_arr_opening_rad), 0, cos(_arr_opening_rad)> 0}
          }
      }
    cone {<0, 0, 0>, 2 *_arr_width, <0, 0, 2 *_arr_width>, 0.0 translate x*_radius}
    cone {<0, 0, 0>, 2 *_arr_width, <0, 0, -2 *_arr_width>, 0.0 translate x*_radius rotate -y*_arr_opening}
    }
    intersection {
      plane{y, _arr_thick/2}
      plane{-y, --_arr_thick/2}
    }
  }
  texture {pigment{_color}}
}
#end

#macro MY_TOOLS_PEN()
  #local _len = 175;
  #local _lead_len = 17;
  #local M = 4;
  #local A = 7.;
  union{                                // body
      intersection {
        box {<-A/2, _lead_len,-2*M>, <+A/2,_len,2*M> }
        box {<-A/2, _lead_len,-2*M>, <+A/2,_len,2*M> rotate -60*y}
        box {<-A/2, _lead_len,-2*M>, <+A/2,_len,2*M> rotate +60*y}
        texture {pigment{rgb<0,1,0>}}
      }
      union {
        intersection {
          intersection {
            box {<-A/2, 0,-2*M>, <+A/2,_lead_len,2*M> }
            box {<-A/2, 0,-2*M>, <+A/2,_lead_len,2*M> rotate -60*y}
            box {<-A/2, 0,-2*M>, <+A/2,_lead_len,2*M> rotate +60*y}
            texture {pigment{rgb<0,1,0>}}
          }
          cone {
            <0,5,0> 1.1 <0,_lead_len,0> 3.9
          texture {White_Wood}
          }
        }
        cone {
          <0,0,0> 0 <0,5,0> 1.1
        texture {pigment{Gray30}}
        }
      }
    }
#end


#macro MY_TOOLS_STANDOFF(_height, bot, top)
union{
    intersection {
      #local M = 3;
      #local A = 5.5;
      #local B = 2.4;
      //3 boxes for hexagonal shape
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> }
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> rotate -60*y}
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> rotate +60*y}
      texture {pigment{rgb<0,0,1>}}
    }
   #if (bot)
   object{ TOOLS_SCREW(3, 5, 1, Gray30 )  rotate z*180 translate y*-2 }
   #end
   #if (top)
   object{ TOOLS_SCREW(3, 5, 1, Gray30 )    translate(<0, _height+1.5, 0>)}
//   object{ TOOLS_NUT (M, 1, rgb<0,0,1>)  translate(<0, _height, 0>)}
   #end
}
#end

#macro ROUNDED_TAB(W, HD)
 difference{
    box {<-W/2, 0,-W/2>, <0.7*W,2,W/2>}
    cylinder {<0, -0.1, 0>, <0,2.1,0> HD/2}
    difference{
      box {<-W/2-0.1, -0.1,-W/2-0.1>, <0,2.1,W/2+0.1>}
      cylinder {<0, -0.2, 0>, <0,2.2,0> W/2}
    }
  }
#end

#macro MY_TOOLS_NEW_STANDOFF(screw_top, screw_bottom)
union{
  #local W = 6;
  #local DX = 9.76;
  #local DY = 10.;
  #local HD = 3;
  #local a = atan2(DY,DX-1.2*W);
  #local l = sqrt((DX-1.2*W)*(DX-1.2*W)+DY*DY)+0.29*W; 	
  union {
    box {<0, 0,-W/2>, <l,2,W/2> rotate z*a*180/3.14 translate x*(0.7*W)}
    object{ROUNDED_TAB(W, HD)}
    object{ROUNDED_TAB(W, HD) rotate y*180 translate <DX, DY, 0>}
    pigment{rgb<1,0,0>}
  }
  #if (screw_bottom)
  object{ TOOLS_SCREW(3, 5, 1, Gray30 ) translate y*2 }
  #end
  #if (screw_top)
  object{ TOOLS_SCREW(2.5, 5, 1, Gray30 ) translate <DX, 2+DY+1.5,0> }
  #end
}
#end

#macro MY_TOOLS_OVERO()
  
#end


#macro MY_TOOLS_MOTOR()
  union {
    cylinder {<0, 4, 0><0, 21, 0> 14 texture{col_gold} }
    torus { 10, 4 translate y*21 texture{pigment{ForestGreen}} finish{F_MetalB} }
    torus { 10, 4 translate y*4 texture{pigment{ForestGreen}} finish{F_MetalB} }
    cylinder {<0, 24, 0><0, 28, 0> 8 pigment{Black} finish{F_MetalB} }
    cylinder { <0,28,0> <0,32,0> 130
     pigment { rgbf <0.5,0.9,1,0.95> } // A blue-tinted glass
     finish
     { phong 0.9 phong_size 40  // A highlight
       reflection 0.2  // Glass reflects a bit
     }
     interior
     { ior 1.5 // Glass refraction
     }
   }
 }
#end

#macro MY_TOOLS_MKK()
  #local x1 = 4;
  #local x2 = 13;
  #local x3 = 46;
  #local x4 = 17;
  #local arm = 
  union {
    difference {
    box {<0.,-5.,-5.><215.,5.,5.>} 
    box {<-1.,-4.,-4.><216.,4.,4.>} 
    cylinder {<x1, -6, 0><x1, 6, 0> 1.5}
    cylinder {<x2, -6, 0><x2, 6, 0> 1.5}
    cylinder {<x3, -6, 0><x3, 6, 0> 1.5}
    texture{col_silver}
    }
    object{ MY_TOOLS_STANDOFF(10, 0, 0) translate <x2,6,0>}
    object{ MY_TOOLS_MOTOR() translate <200,5,0>}
  }
  #local hole_plate =
  union {
    #local x5 = (x1 + x4) / sqrt(2);
    cylinder {<x5, -1, x5><x5, 2, x5> 1.5}
    #local x6 = (x2 + x4) / sqrt(2);
    cylinder {<x6, -1, x6><x6, 2, x6> 1.5}
    #local x7 = (x3 + x4) / sqrt(2);
    cylinder {<x7, -1, x7><x7, 2, x7> 1.5}
    #local x1 = 15;
    #local z1 = x1 - 4 * sqrt(2);
    #local x2 = 60 - 8 * sqrt(2);
    #local z2 = x2 - 4 * sqrt(2);
    prism {
      linear_spline
      -1, 2, 4,
      <x1,z1>, <x2,z2>, <x2,-z2>, <x1,-z1>  //outer rim
    }
  }
  #local plate =
  difference {
    box {<-60.,0.,-60.><60.,1.,60.>} 
    object{ hole_plate }
    object{ hole_plate rotate y*90}
    object{ hole_plate rotate y*180}
    object{ hole_plate rotate y*270}
    cylinder {<0, -1, 0><0, 2, 0> 6}
    texture{pigment{Gray30}}
  }
  union {
    object{ arm translate <x4,0,0>}
    object{ arm translate <x4,0,0> rotate <0,90,0>}
    object{ arm translate <x4,0,0> rotate <0,180,0>}
    object{ arm translate <x4,0,0> rotate <0,270,0>}
    object{ plate translate <0,5,0> rotate <0,45,0> }
    object{ plate translate <0,-6,0> rotate <0,45,0> }
 }
#end


#declare CarbonTexture  =
   texture{
    pigment{color rgb<0.06,0.23,0.23>} //
    finish { phong 1 reflection 0.1}
    }
   texture{
    pigment{
     image_map{ png "textures/carbon.png"
     map_type 0 // 0=planar, 1=spherical, 2=cylindrical, 5=torus
     interpolate 2
      // 0=none, 1=linear, 2=bilinear, 4=normalized distance
//     once //
     transmit 215, 1 // Palette, Amount |
  // transmit all Amount
    }
  }
  finish { diffuse 0.9 phong 1}
  scale <2,2,2> rotate<0,0,6> translate<-5.8,0.00,0>
  } // end of texture  ------------------


#macro MY_TOOLS_ASCTEC()
#local flank = object {
  prism {
    linear_spline
    -5, 5,
53,
<331.420898, 252.075195>,
<346.069336, 253.295898>,
<382.080078, 220.947266>,
<401.000977, 214.843750>,
<421.142578, 216.064453>,
<487.060547, 252.075195>,
<526.123047, 275.878906>,
<554.809570, 311.279297>,
<567.626953, 351.562500>,
<567.626953, 394.897461>,
<567.626953, 439.453125>,
<568.237305, 469.360352>,
<597.534180, 469.360352>,
<597.534180, 429.687500>,
<613.403320, 430.297852>,
<613.403320, 340.576172>,
<609.130859, 298.461914>,
<592.041016, 261.840820>,
<565.185547, 227.661133>,
<522.460938, 187.988281>,
<470.581055, 139.160156>,
<430.908203, 101.928711>,
<383.911133, 59.204102>,
<362.548828, 39.672852>,
<353.393555, 34.179688>,
<332.641602, 33.569336>,
<332.641602, 65.307617>,
<283.813477, 65.307617>,
<260.009766, 68.969727>,
<234.985352, 83.007813>,
<73.242188, 238.647461>,
<47.607422, 277.709961>,
<36.010742, 317.382813>,
<35.400391, 469.360352>,
<66.528320, 469.970703>,
<65.917969, 427.856445>,
<83.007813, 429.077148>,
<83.007813, 316.772461>,
<93.383789, 297.241211>,
<111.694336, 287.475586>,
<129.394531, 288.696289>,
<147.094727, 293.579102>,
<164.794922, 297.241211>,
<180.664063, 296.020508>,
<196.533203, 291.137695>,
<200.805664, 275.878906>,
<205.078125, 245.971680>,
<219.116211, 222.778320>,
<236.816406, 207.519531>,
<259.399414, 195.312500>,
<277.099609, 185.546875>,
<331.420898, 185.546875>,
<331.420898, 252.075195>
}
scale 0.127 texture{pigment{Gray30}} finish{F_MetalB} rotate <0,0,90> translate <0,-20,-67.5>}
#local arm = object {
  union {
    box { <0,-2.75,-7.5><168,2.75,7.5> translate <19,19.5,0>   texture { CarbonTexture }}
    cylinder {<0, -2.75, 0><0, 2.75, 0> 19 translate<170,19.5,0>   texture { CarbonTexture }}
    cylinder {<0, -8, 0><0, 8, 0> 14 translate<170,29.,0>  texture{pigment{Blue}} } // motor
    cylinder { <0,-2,0> <0,2,0> 100 translate <170,41.,0>                           // prop
      pigment { rgbf <0.5,0.9,1,0.95> } // A blue-tinted glass
      finish
      { phong 0.9 phong_size 40  // A highlight
        reflection 0.2  // Glass reflects a bit
      }
      interior
      { ior 1.5 // Glass refraction
      }
    }
    object{ MY_TOOLS_STANDOFF(6, 0, 0) translate <31.,22.,0>}
  }
}
#local top_plate = object {
  difference {
     #local my_r=20;
     #local my_x = my_r + 5;
     box { <-26,-0.6,-26><26,0.6,26> }
     cylinder {<0, -3, 0><0, 3, 0> 1.5}
     cylinder {<my_x, -3, my_x><my_x, 3, my_x> my_r}
     cylinder {<my_x, -3, -my_x><my_x, 3, -my_x> my_r}
     cylinder {<-my_x, -3, my_x><-my_x, 3, my_x> my_r}
     cylinder {<-my_x, -3, -my_x><-my_x, 3, -my_x> my_r}
     #local my_r2 = 5;
     #local my_rounded_end =
       difference {
         box { <26-my_r2,-1,-my_r2-1><27,1,my_r2+1>}
         cylinder {<26-my_r2, -3, 0><26-my_r2, 3, 0> my_r2}
       }
     object{my_rounded_end}
     object{my_rounded_end rotate y*90}
     object{my_rounded_end rotate y*180}
     object{my_rounded_end rotate y*270}
  }
  texture {CarbonTexture }
}
#local center_plate = object {
  difference {
    #local diag = 103;
    #local side = diag/sqrt(2)/2;
    #local my_r=43;
    #local my_x = my_r + 27;
    box {<-side,-0.6,-side><side,0.6,side>}
    cylinder {<0, -3, 0><0, 3, 0> 1.5}
    cylinder {<my_x, -3, 0><my_x, 3, 0> my_r}
    cylinder {<my_x, -3, 0><my_x, 3, 0> my_r rotate y*90}
    cylinder {<my_x, -3, 0><my_x, 3, 0> my_r rotate y*180}
    cylinder {<my_x, -3, 0><my_x, 3, 0> my_r rotate y*270}
  }
  rotate y*45 
  translate y*+22.7
  texture { CarbonTexture }
}
union {
  object { flank }
//  #local foo=8;
//  box {<-1.,0.,-foo><1.,72.5,foo> translate y*-15}  // calibration flank
  object { flank rotate y*90}
  object { flank rotate y*180}
  object { flank rotate y*270}
  object { arm }
//  box {<-170.,21.,-1><170.,23.,1>  texture {pigment{rgb<1,0,0>}}}  // calibration arm
  object { arm rotate y*90}
  object { arm rotate y*180}
  object { arm rotate y*270}
  object { center_plate }
  object { top_plate translate <0,56,0>}
  object { top_plate translate <0,-11,0>}
}
#end


#macro MY_TOOLS_JOBY_TEXT()
  union {
    text { ttf "StayPuft.ttf" "J by"       1, 0 scale <12,12,3> rotate x*50  }

    #local d = 0.79;
    #local a = 0.95;
    #local b = 2.2;
    union {
	// top
//     cylinder {< a , -1,  b>< a , 1,  b> d } 
//     cylinder {<-a , -1,  b><-a , 1,  b> d } 
	// bottom
//     cylinder {< a , -1, -b>< a , 1, -b> d } 
//     cylinder {<-a , -1, -b><-a , 1, -b> d } 
	// right
//     cylinder {< b , -1,  a>< b , 1,  a> d } 
//     cylinder {< b , -1, -a>< b , 1, -a> d } 
	// left
//     cylinder {<-b , -1,  a><-b , 1,  a> d } 
//     cylinder {<-b , -1, -a><-b , 1, -a> d } 

	// top
     sphere {< a , 0,  b> d } 
     sphere {<-a , 0,  b> d } 
	// bottom
     sphere {< a , 0, -b> d } 
     sphere {<-a , 0, -b> d } 
	// right
     sphere {< b , 0,  a> d } 
     sphere {< b , 0, -a> d } 
	// left
     sphere {<-b , 0,  a> d } 
     sphere {<-b , 0, -a> d } 
     
     rotate x*-40 translate(<7.2 , -4, 5>)
    }
  }
#end