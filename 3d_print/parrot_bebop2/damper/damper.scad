difference() {
  union(){
    /* main cylinder */
    cylinder(h=16.5, r=4.5, $fn=18);
    /* main sphere */
    translate([0,0,8.5]) resize(newsize=[16,16,11]) sphere(r=16, $fn=36);
  }
  union(){
    /* lower bore */
    translate([0,0,-1]) cylinder(h=3, r=2.5, $fn=18);
    /* main bore */
    translate([0,0,1]) cylinder(h=16.5, r=3, $fn=18);
    /* upper bore */
    translate([0,0,14.5]) cylinder(h=3, r=3.5, $fn=18);
  }
}