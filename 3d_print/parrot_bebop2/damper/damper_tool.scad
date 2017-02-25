difference() {
  union() {
    cylinder(h=10, r=7, $fn=36);
    translate([0,0,10]) cylinder(h=6, r=4.3, $fn=36);
    translate([0,0,10]) cylinder(h=1, r=5.3, $fn=36);
  }
  union() {
    /* cross */
    translate([0,0,16.5]) cube(size=[2,10,5], center=true);;
    translate([0,0,16.5]) cube(size=[10,2,5], center=true);;
    /* top sphere */
    translate([0,0,45.5]) sphere(r=30, $fn=36);
    /* main bore */
    translate([0,0,14]) cylinder(h=5, r=2.6, $fn=36);
    /* small bore */
    translate([0,0,13]) cylinder(h=5, r=1, $fn=36);
    /* 4x grip */
    translate([11,0,-1]) cylinder(h=12, r=5, $fn=36);
    translate([-11,0,-1]) cylinder(h=12, r=5, $fn=36);
    translate([0,11,-1]) cylinder(h=12, r=5, $fn=36);
    translate([0,-11,-1]) cylinder(h=12, r=5, $fn=36);
    /* adapter */
    translate([0,0,11]) rotate_extrude(convexity=10, $fn = 100)
      translate([5.3, 0, 0])
        circle(r = 1, $fn = 100);      
  }
}