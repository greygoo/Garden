$BAR=[15.70,16,16];
$DISTANCE=10;
$WALL=2;
$DRILLHOLE=1;
$SCREWHEAD=3;
$MOTOR=[28.57, 24.5 + $SCREWHEAD, 42.7];
$MOTORFRONT=10;

//CONNECTING DRILLHOLES
module drillholes(){
    $DRILLHOLE_OFFSET=[$BAR[1]/4 + $WALL,($BAR[1]/2), -($DISTANCE + $BAR[2])];

    translate([$DRILLHOLE_OFFSET[0],$DRILLHOLE_OFFSET[1],$DRILLHOLE_OFFSET[2]]){
        rotate([90,0,0]){
            cylinder(4*$WALL,$DRILLHOLE,$DRILLHOLE, center=true);
        }
    }

    translate([-$DRILLHOLE_OFFSET[0],$DRILLHOLE_OFFSET[1],$DRILLHOLE_OFFSET[2]]){
        rotate([90,0,0]){
            cylinder(4*$WALL,$DRILLHOLE,$DRILLHOLE, center=true);
        }
    }

    translate([$DRILLHOLE_OFFSET[0],$DRILLHOLE_OFFSET[1],$DRILLHOLE_OFFSET[2]-2*$DISTANCE]){
        rotate([90,0,0]){
            cylinder(4*$WALL,$DRILLHOLE,$DRILLHOLE, center=true);
        }
    }

    translate([-$DRILLHOLE_OFFSET[0],$DRILLHOLE_OFFSET[1],$DRILLHOLE_OFFSET[2]-2*$DISTANCE]){
        rotate([90,0,0]){
            cylinder(4*$WALL,$DRILLHOLE,$DRILLHOLE, center=true);
        }
    }
}

module barconnector(){
    //BARCONNECTOR
    difference(){
        cube($BAR + [0,2*$WALL,2*$WALL], center=true);
        cube($BAR, center=true);
        translate([0,0,$BAR[2]/2+$WALL/2]){
            cylinder($WALL,$DRILLHOLE,$DRILLHOLE, center=true);
        }
    }
    //DISTANCEBLOCK
    translate([0,$BAR[1]/2,-($BAR[2]/2 + $WALL + 2*$DISTANCE)]){
        cube([$BAR[0], 2*$WALL, 4*$DISTANCE], center=true);
    }
}




//MOTORBLOCK
module motorblock(){
    translate([0, ($BAR[1]/2 + $MOTOR[1]/2 + 2*$WALL), -($BAR[2]/2 + $MOTOR[2]/2 + $WALL + $DISTANCE)]){
        difference(){
            translate([0,0,-$WALL]){
                cube($MOTOR + [2*$WALL,2*$WALL,2*$WALL], center=true);
            }
            cube($MOTOR, center=true);
            translate([0,0,-($MOTOR[2]/2 + 2*$WALL)]){
                #cylinder(2*$WALL, $MOTORFRONT/2, $MOTORFRONT/2);
            }
        }
    }
}

difference(){
    barconnector();
    drillholes();
}

/*difference(){
    motorblock();
    translate([0,$WALL,0]) drillholes();
}*/

/*difference(){
    cylinder(20,5.65/2,5.6/2);
    cylinder(20,2.4/2,2.4/2);
}*/