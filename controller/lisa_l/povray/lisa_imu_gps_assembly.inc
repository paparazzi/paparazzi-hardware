
#include "lisa_imu_assembly.inc"
#include "booz_gps_no_ami_mag.pov"
#include "my_tools.inc"

// IMU reference point : center of base board

#macro LISA_IMU_GPS_ASSEMBLED(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot)
union {
//  object{  MY_TOOLS_AXIS(0,0,0,0,0,0)}	
  object{  LISA_IMU_ASSEMBLED(0,0,0,0,0,0, 1, 0)}
  object{  BOOZ_GPS_NO_AMI_MAG(0.000000,0,0.000000, 0, 0, 0) rotate<0,0,0>  translate(<-38, 21.5, -40>)}
  #if (1)
  object{  MY_TOOLS_STANDOFF(18,0,1) translate(<-21.2,2,-21.2>)}
  object{  MY_TOOLS_STANDOFF(18,0,1) translate(< 21.2,2,-21.2>)}
  object{  MY_TOOLS_STANDOFF(18,0,1) translate(<-21.2,2, 21.2>)}
  object{  MY_TOOLS_STANDOFF(18,0,1) translate(< 21.2,2, 21.2>)}
  #end
  translate(<mac_x_ver,mac_y_ver,mac_z_ver>)
  rotate(<mac_x_rot,mac_y_rot,mac_z_rot>)
}
#end