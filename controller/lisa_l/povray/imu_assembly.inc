
#include "booz_imu.pov"
#include "booz_imu_xz.pov"
#include "booz_imu_yz.pov"
#include "my_tools.inc"

// IMU reference point : center of base board

#macro BOOZ_IMU_ASSEMBLED(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot)
union {
//  object{  MY_TOOLS_AXIS(0,0,0,0,0,0)}	
  object{  BOOZ_IMU(0,0,0,0,0,0) translate(<-80, 0, -50>)}
  object{  BOOZ_IMU_XZ(0,0,0,0,0,0) rotate(<-90,-90,0>) translate(<-11.5,-3,-6.55>)}  // short vboard
  object{  BOOZ_IMU_YZ(0,0,0,0,0,0) rotate(<-90,0,0>) translate(<-18.,-3,10.5>)} // long vboard
  translate(<mac_x_ver,mac_y_ver,mac_z_ver>)
  rotate(<mac_x_rot,mac_y_rot,mac_z_rot>)
}
#end