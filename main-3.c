#include <kipr/wombat.h>
//Functions

//Move forward function
void move(int speed, int time) {
    motor(2,speed);
    motor(1, speed);
    msleep(time);
	motor(1,0);
    motor(2,0);
    msleep(700);
}
//Left turn function
void turn_left(int time) {

    motor(1,100);
    motor(2,0);
    msleep(time);
	motor(1,0);
    motor(2,0);
    msleep(700);
}
//Right turn function
void turn_right(int time) {

    motor(2,100);
    motor(1,0);
    msleep(time);
	motor(1,0);
    motor(2,0);
    msleep(700);
}
//Disable motor function
void disable_motors() {
    motor(3,0);
    motor(0,0);

}
//Stop/wait function
void stop(int time) {
    motor(1,0);
    motor(2,0);
    msleep(time);
}
//Claw movement function
void claw(int pos) {
    motor(1,0);
    motor(2,0);
    set_servo_position(2,pos);
    msleep(700);
	motor(1,0);
    motor(2,0);
    msleep(700);
}
//Hand movement function
void hand(int pos) {
    motor(1,0);
    motor(2,0);
    set_servo_position(3,pos);
    msleep(700);
	motor(1,0);
    motor(2,0);
    msleep(700);
}
//Full speed function
void full_speed(int time) {
    motor(1,100);
    motor(2,94);
    msleep(time);
    motor(0,0);
    motor(2,0);
    msleep(600);
}

//Wheel 1 = Right Wheel
//Wheel 2 = Left Wheel
//Servo 2 = Claw, Lower Pos = Close claw more
//Servo 3 = Hand, Lower Pos = Move hand up more
//stop function used to insure the robot doesn't mess up
//When full/high speed is needed, set left motor to 94 and right motor to 100 as if both = 100 it will veer to right.
int main()
{
    enable_servos();
    claw(1680);//opens claw to collect poms
	hand(1724);//Brings hand down 
    //Ensure that the claw doesn't scathe the ground
    
    //First 3 orange poms
	move(50,400);//Moves forward to the first pom
    turn_right(925);//Turns to get the other pom
    move(70, 800);//Moves forward to get the third pom
    hand(1745);//brings hand down fully to ensure grabbing
    claw(385);//Picks up the poms
    hand(1550);//Brings hand up slightly to not hit the pallet
    turn_right(950);//Turns to place poms 
    move(-70,700);//Move back to not hit black line
    hand(1733);//Brings hand fully down to make sure poms don't land on the black line
    claw(1700); //Releases Poms
    
    //Next 3 blue poms
    turn_left(200);//Turns left a little to avoid flicking up pom
    hand(600);//Brings hand up to turn
    turn_left(935);//Turns to the closest blue pom
    hand(1730);//Brings hand down
    move(70,1900);//moves into the first blue pom
    turn_right(365);//Turns to the 2 other poms
    move(-50,300);//moves back to stop the poms from getting stuck
    move(70,2250);//Gets the 3 blue pom into the claw
    claw(580);//Closes claw to grab poms
    turn_left(2000);//moves poms over to the left
    move(50,300);//moves forward to not drag poms when going for green cube
    claw(1500);//Releases poms
    move(-50,1050);//moves back
	hand(1400); //moves hand up to open door
    turn_right(2300);//Turns to the botguy door
    claw(860);//closes claw to open door
    move(100,1650);//move into door to open it
    move(-70,1650);//moves backward to avoid hitting things
    turn_left(270);//turns to move around doors
    move(-50,502);//moves backward to avoid hitting botguy
    hand(1560);//brings hand down to grab botguy
    claw(1400);//Opens claw to grab botguy
    turn_left(275);//turn left to get botguy
    move(70,1550);//moves foward to grab botguy
    claw(280);//grabs botguy
    hand(1400);//moves botguy up
    move(-65,5500);//moves backwards towards starting box
    turn_left(2905);//turns right to place botguy
    hand(1650);//brings hand down to place botguy
    claw(1700);//releases botguy
    return 0;
}