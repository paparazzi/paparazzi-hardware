
#include "lisa_l_0.101.pov"
#include "imu_assembly.inc"
#include "my_tools.inc"

// IMU reference point : center of base board

#macro LISA_IMU_ASSEMBLED(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot, screw_top, screw_bottom)
union {
//  object{  MY_TOOLS_AXIS(0,0,0,0,0,0)}	
  object{  LISA_L_0_101(0,0,0,0,0,0) translate(<-80, 0, -50>)}
  object{  BOOZ_IMU_ASSEMBLED(0,0,0,0,0,0) rotate(<180,90,0>) translate(<0,12,0>)}
  #if (0)
  object{  MY_TOOLS_STANDOFF(12) translate(<-15,0,-15>)}
  object{  MY_TOOLS_STANDOFF(12) translate(< 15,0,-15>)}
  object{  MY_TOOLS_STANDOFF(12) translate(<-15,0, 15>)}
  object{  MY_TOOLS_STANDOFF(12) translate(< 15,0, 15>)}
  #else
  #local my_x = 21.92;
  object{  MY_TOOLS_NEW_STANDOFF(screw_top, screw_bottom)  rotate y*-45 translate(<-my_x,0,-my_x>)}
  object{  MY_TOOLS_NEW_STANDOFF(screw_top, screw_bottom)  rotate y*45 translate( <-my_x, 0, my_x>)}
  object{  MY_TOOLS_NEW_STANDOFF(screw_top, screw_bottom)  rotate y*-135 translate(<my_x,0,-my_x>)}
  object{  MY_TOOLS_NEW_STANDOFF(screw_top, screw_bottom)  rotate y*135 translate(< my_x,0, my_x>)}
  #end
  translate(<mac_x_ver,mac_y_ver,mac_z_ver>)
  rotate(<mac_x_rot,mac_y_rot,mac_z_rot>)
}
#end