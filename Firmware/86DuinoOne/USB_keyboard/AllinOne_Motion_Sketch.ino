#include <Servo86.h>
#include <KeyboardController.h>

Servo myservo25;
Servo myservo26;
Servo myservo27;
Servo myservo28;
Servo myservo30;
Servo myservo31;
Servo myservo32;
Servo myservo33;
Servo myservo35;
Servo myservo36;
Servo myservo37;
Servo myservo38;

ServoOffset myoffs;

ServoFrame _86ME_HOME;

ServoFrame walking_frm0;
ServoFrame walking_frm1;
ServoFrame walking_frm2;
ServoFrame walking_frm3;
ServoFrame walking_frm4;
ServoFrame walking_frm5;

ServoFrame walking_line_frm0;
ServoFrame walking_line_frm1;
ServoFrame walking_line_frm2;
ServoFrame walking_line_frm3;
ServoFrame walking_line_frm4;
ServoFrame walking_line_frm5;

ServoFrame left_frm0;
ServoFrame left_frm1;
ServoFrame left_frm2;
ServoFrame left_frm3;
ServoFrame left_frm4;
ServoFrame left_frm5;

ServoFrame right_frm0;
ServoFrame right_frm1;
ServoFrame right_frm2;
ServoFrame right_frm3;
ServoFrame right_frm4;
ServoFrame right_frm5;

ServoFrame home_frm0;

ServoFrame home2_frm0;

USBHost usb;
KeyboardController keyboard(usb);
char current_key = 0;
void keyPressed(){current_key = keyboard.getOemKey();}
void keyReleased(){current_key = 0;}
static int keys_state[128];
static int key_press[128] = {0};
int key_state(int k)
{
  if(current_key==k && !key_press[k])
  {
	key_press[k] = 1;
	return 0;
  }
  else if(current_key==k && key_press[k])
  {
    key_press[k] = 1;
    return 1;
  }
  else if(current_key!=k && key_press[k])
  {
    key_press[k] = 0;
    return 2;
  }
  return 3;
}


void setup()
{

  myservo25.attach(25);
  myservo26.attach(26);
  myservo27.attach(27);
  myservo28.attach(28);
  myservo30.attach(30);
  myservo31.attach(31);
  myservo32.attach(32);
  myservo33.attach(33);
  myservo35.attach(35);
  myservo36.attach(36);
  myservo37.attach(37);
  myservo38.attach(38);


  walking_frm0.positions[0] = 1736;
  walking_frm0.positions[1] = 1425;
  walking_frm0.positions[2] = 1450;
  walking_frm0.positions[3] = 1439;
  walking_frm0.positions[4] = 1780;
  walking_frm0.positions[5] = 2022;
  walking_frm0.positions[6] = 1490;
  walking_frm0.positions[7] = 1854;
  walking_frm0.positions[8] = 1780;
  walking_frm0.positions[9] = 1300;
  walking_frm0.positions[10] = 1600;
  walking_frm0.positions[11] = 1442;

  walking_frm1.positions[0] = 1558;
  walking_frm1.positions[1] = 1425;
  walking_frm1.positions[2] = 1450;
  walking_frm1.positions[3] = 1439;
  walking_frm1.positions[4] = 1592;
  walking_frm1.positions[5] = 2022;
  walking_frm1.positions[6] = 1490;
  walking_frm1.positions[7] = 1854;
  walking_frm1.positions[8] = 1501;
  walking_frm1.positions[9] = 1300;
  walking_frm1.positions[10] = 1600;
  walking_frm1.positions[11] = 1442;

  walking_frm2.positions[0] = 1588;
  walking_frm2.positions[1] = 1425;
  walking_frm2.positions[2] = 1635;
  walking_frm2.positions[3] = 1439;
  walking_frm2.positions[4] = 1592;
  walking_frm2.positions[5] = 2022;
  walking_frm2.positions[6] = 1678;
  walking_frm2.positions[7] = 1854;
  walking_frm2.positions[8] = 1501;
  walking_frm2.positions[9] = 1300;
  walking_frm2.positions[10] = 1838;
  walking_frm2.positions[11] = 1442;

  walking_frm3.positions[0] = 1558;
  walking_frm3.positions[1] = 1216;
  walking_frm3.positions[2] = 1635;
  walking_frm3.positions[3] = 1671;
  walking_frm3.positions[4] = 1592;
  walking_frm3.positions[5] = 1708;
  walking_frm3.positions[6] = 1678;
  walking_frm3.positions[7] = 1512;
  walking_frm3.positions[8] = 1501;
  walking_frm3.positions[9] = 1498;
  walking_frm3.positions[10] = 1838;
  walking_frm3.positions[11] = 1130;

  walking_frm4.positions[0] = 1558;
  walking_frm4.positions[1] = 1216;
  walking_frm4.positions[2] = 1454;
  walking_frm4.positions[3] = 1671;
  walking_frm4.positions[4] = 1592;
  walking_frm4.positions[5] = 1708;
  walking_frm4.positions[6] = 1489;
  walking_frm4.positions[7] = 1512;
  walking_frm4.positions[8] = 1501;
  walking_frm4.positions[9] = 1498;
  walking_frm4.positions[10] = 1629;
  walking_frm4.positions[11] = 1130;

  walking_frm5.positions[0] = 1722;
  walking_frm5.positions[1] = 1216;
  walking_frm5.positions[2] = 1454;
  walking_frm5.positions[3] = 1671;
  walking_frm5.positions[4] = 1736;
  walking_frm5.positions[5] = 1708;
  walking_frm5.positions[6] = 1489;
  walking_frm5.positions[7] = 1512;
  walking_frm5.positions[8] = 1722;
  walking_frm5.positions[9] = 1498;
  walking_frm5.positions[10] = 1629;
  walking_frm5.positions[11] = 1130;

  walking_line_frm0.positions[0] = 1425;
  walking_line_frm0.positions[1] = 1120;
  walking_line_frm0.positions[2] = 1715;
  walking_line_frm0.positions[3] = 1585;
  walking_line_frm0.positions[4] = 1700;
  walking_line_frm0.positions[5] = 1802;
  walking_line_frm0.positions[6] = 1526;
  walking_line_frm0.positions[7] = 1628;
  walking_line_frm0.positions[8] = 1367;
  walking_line_frm0.positions[9] = 1555;
  walking_line_frm0.positions[10] = 1903;
  walking_line_frm0.positions[11] = 1163;

  walking_line_frm1.positions[0] = 1425;
  walking_line_frm1.positions[1] = 1120;
  walking_line_frm1.positions[2] = 1468;
  walking_line_frm1.positions[3] = 1585;
  walking_line_frm1.positions[4] = 1700;
  walking_line_frm1.positions[5] = 1802;
  walking_line_frm1.positions[6] = 1236;
  walking_line_frm1.positions[7] = 1628;
  walking_line_frm1.positions[8] = 1367;
  walking_line_frm1.positions[9] = 1555;
  walking_line_frm1.positions[10] = 1671;
  walking_line_frm1.positions[11] = 1193;

  walking_line_frm2.positions[0] = 1773;
  walking_line_frm2.positions[1] = 1120;
  walking_line_frm2.positions[2] = 1454;
  walking_line_frm2.positions[3] = 1585;
  walking_line_frm2.positions[4] = 1903;
  walking_line_frm2.positions[5] = 1802;
  walking_line_frm2.positions[6] = 1410;
  walking_line_frm2.positions[7] = 1628;
  walking_line_frm2.positions[8] = 1628;
  walking_line_frm2.positions[9] = 1512;
  walking_line_frm2.positions[10] = 1685;
  walking_line_frm2.positions[11] = 1193;

  walking_line_frm3.positions[0] = 1773;
  walking_line_frm3.positions[1] = 1251;
  walking_line_frm3.positions[2] = 1309;
  walking_line_frm3.positions[3] = 1483;
  walking_line_frm3.positions[4] = 1903;
  walking_line_frm3.positions[5] = 1889;
  walking_line_frm3.positions[6] = 1135;
  walking_line_frm3.positions[7] = 1729;
  walking_line_frm3.positions[8] = 1628;
  walking_line_frm3.positions[9] = 1294;
  walking_line_frm3.positions[10] = 1628;
  walking_line_frm3.positions[11] = 1309;

  walking_line_frm4.positions[0] = 1454;
  walking_line_frm4.positions[1] = 1251;
  walking_line_frm4.positions[2] = 1410;
  walking_line_frm4.positions[3] = 1526;
  walking_line_frm4.positions[4] = 1680;
  walking_line_frm4.positions[5] = 1889;
  walking_line_frm4.positions[6] = 1265;
  walking_line_frm4.positions[7] = 1729;
  walking_line_frm4.positions[8] = 1512;
  walking_line_frm4.positions[9] = 1294;
  walking_line_frm4.positions[10] = 1657;
  walking_line_frm4.positions[11] = 1323;

  walking_line_frm5.positions[0] = 1628;
  walking_line_frm5.positions[1] = 1251;
  walking_line_frm5.positions[2] = 1729;
  walking_line_frm5.positions[3] = 1526;
  walking_line_frm5.positions[4] = 1680;
  walking_line_frm5.positions[5] = 1889;
  walking_line_frm5.positions[6] = 1758;
  walking_line_frm5.positions[7] = 1729;
  walking_line_frm5.positions[8] = 1555;
  walking_line_frm5.positions[9] = 1294;
  walking_line_frm5.positions[10] = 1903;
  walking_line_frm5.positions[11] = 1323;

  left_frm0.positions[0] = 1560;
  left_frm0.positions[1] = 1059;
  left_frm0.positions[2] = 1630;
  left_frm0.positions[3] = 1715;
  left_frm0.positions[4] = 1580;
  left_frm0.positions[5] = 1729;
  left_frm0.positions[6] = 1666;
  left_frm0.positions[7] = 1860;
  left_frm0.positions[8] = 1530;
  left_frm0.positions[9] = 1222;
  left_frm0.positions[10] = 1816;
  left_frm0.positions[11] = 1541;

  left_frm1.positions[0] = 1560;
  left_frm1.positions[1] = 1059;
  left_frm1.positions[2] = 1449;
  left_frm1.positions[3] = 1715;
  left_frm1.positions[4] = 1580;
  left_frm1.positions[5] = 1729;
  left_frm1.positions[6] = 1476;
  left_frm1.positions[7] = 1860;
  left_frm1.positions[8] = 1530;
  left_frm1.positions[9] = 1222;
  left_frm1.positions[10] = 1666;
  left_frm1.positions[11] = 1541;

  left_frm2.positions[0] = 1845;
  left_frm2.positions[1] = 1059;
  left_frm2.positions[2] = 1449;
  left_frm2.positions[3] = 1715;
  left_frm2.positions[4] = 1845;
  left_frm2.positions[5] = 1729;
  left_frm2.positions[6] = 1476;
  left_frm2.positions[7] = 1860;
  left_frm2.positions[8] = 1787;
  left_frm2.positions[9] = 1222;
  left_frm2.positions[10] = 1666;
  left_frm2.positions[11] = 1541;

  left_frm3.positions[0] = 1845;
  left_frm3.positions[1] = 1406;
  left_frm3.positions[2] = 1449;
  left_frm3.positions[3] = 1390;
  left_frm3.positions[4] = 1845;
  left_frm3.positions[5] = 2034;
  left_frm3.positions[6] = 1476;
  left_frm3.positions[7] = 1651;
  left_frm3.positions[8] = 1787;
  left_frm3.positions[9] = 1642;
  left_frm3.positions[10] = 1666;
  left_frm3.positions[11] = 1338;

  left_frm4.positions[0] = 1599;
  left_frm4.positions[1] = 1406;
  left_frm4.positions[2] = 1449;
  left_frm4.positions[3] = 1390;
  left_frm4.positions[4] = 1638;
  left_frm4.positions[5] = 2034;
  left_frm4.positions[6] = 1476;
  left_frm4.positions[7] = 1651;
  left_frm4.positions[8] = 1551;
  left_frm4.positions[9] = 1642;
  left_frm4.positions[10] = 1666;
  left_frm4.positions[11] = 1338;

  left_frm5.positions[0] = 1599;
  left_frm5.positions[1] = 1406;
  left_frm5.positions[2] = 1744;
  left_frm5.positions[3] = 1390;
  left_frm5.positions[4] = 1638;
  left_frm5.positions[5] = 2034;
  left_frm5.positions[6] = 1773;
  left_frm5.positions[7] = 1651;
  left_frm5.positions[8] = 1551;
  left_frm5.positions[9] = 1642;
  left_frm5.positions[10] = 1860;
  left_frm5.positions[11] = 1338;

  right_frm0.positions[0] = 1560;
  right_frm0.positions[1] = 1323;
  right_frm0.positions[2] = 1715;
  right_frm0.positions[3] = 1294;
  right_frm0.positions[4] = 1580;
  right_frm0.positions[5] = 2048;
  right_frm0.positions[6] = 1729;
  right_frm0.positions[7] = 1541;
  right_frm0.positions[8] = 1530;
  right_frm0.positions[9] = 1758;
  right_frm0.positions[10] = 1802;
  right_frm0.positions[11] = 1004;

  right_frm1.positions[0] = 1560;
  right_frm1.positions[1] = 1323;
  right_frm1.positions[2] = 1429;
  right_frm1.positions[3] = 1294;
  right_frm1.positions[4] = 1580;
  right_frm1.positions[5] = 2048;
  right_frm1.positions[6] = 1467;
  right_frm1.positions[7] = 1541;
  right_frm1.positions[8] = 1530;
  right_frm1.positions[9] = 1758;
  right_frm1.positions[10] = 1618;
  right_frm1.positions[11] = 1004;

  right_frm2.positions[0] = 1860;
  right_frm2.positions[1] = 1323;
  right_frm2.positions[2] = 1419;
  right_frm2.positions[3] = 1294;
  right_frm2.positions[4] = 1831;
  right_frm2.positions[5] = 2048;
  right_frm2.positions[6] = 1467;
  right_frm2.positions[7] = 1541;
  right_frm2.positions[8] = 1802;
  right_frm2.positions[9] = 1758;
  right_frm2.positions[10] = 1617;
  right_frm2.positions[11] = 1004;

  right_frm3.positions[0] = 1860;
  right_frm3.positions[1] = 1106;
  right_frm3.positions[2] = 1419;
  right_frm3.positions[3] = 1599;
  right_frm3.positions[4] = 1831;
  right_frm3.positions[5] = 1497;
  right_frm3.positions[6] = 1467;
  right_frm3.positions[7] = 1860;
  right_frm3.positions[8] = 1802;
  right_frm3.positions[9] = 1294;
  right_frm3.positions[10] = 1617;
  right_frm3.positions[11] = 1309;

  right_frm4.positions[0] = 1526;
  right_frm4.positions[1] = 1106;
  right_frm4.positions[2] = 1419;
  right_frm4.positions[3] = 1599;
  right_frm4.positions[4] = 1580;
  right_frm4.positions[5] = 1497;
  right_frm4.positions[6] = 1467;
  right_frm4.positions[7] = 1860;
  right_frm4.positions[8] = 1512;
  right_frm4.positions[9] = 1294;
  right_frm4.positions[10] = 1617;
  right_frm4.positions[11] = 1309;

  right_frm5.positions[0] = 1526;
  right_frm5.positions[1] = 1106;
  right_frm5.positions[2] = 1758;
  right_frm5.positions[3] = 1599;
  right_frm5.positions[4] = 1580;
  right_frm5.positions[5] = 1497;
  right_frm5.positions[6] = 1773;
  right_frm5.positions[7] = 1860;
  right_frm5.positions[8] = 1512;
  right_frm5.positions[9] = 1294;
  right_frm5.positions[10] = 1918;
  right_frm5.positions[11] = 1309;

  home_frm0.positions[0] = 1560;
  home_frm0.positions[1] = 1150;
  home_frm0.positions[2] = 1450;
  home_frm0.positions[3] = 1490;
  home_frm0.positions[4] = 1580;
  home_frm0.positions[5] = 1870;
  home_frm0.positions[6] = 1490;
  home_frm0.positions[7] = 1720;
  home_frm0.positions[8] = 1530;
  home_frm0.positions[9] = 1440;
  home_frm0.positions[10] = 1600;
  home_frm0.positions[11] = 1250;

  home2_frm0.positions[0] = 1560;
  home2_frm0.positions[1] = 1150;
  home2_frm0.positions[2] = 1450;
  home2_frm0.positions[3] = 1490;
  home2_frm0.positions[4] = 1580;
  home2_frm0.positions[5] = 1870;
  home2_frm0.positions[6] = 1490;
  home2_frm0.positions[7] = 1720;
  home2_frm0.positions[8] = 1530;
  home2_frm0.positions[9] = 1440;
  home2_frm0.positions[10] = 1600;
  home2_frm0.positions[11] = 1250;

  _86ME_HOME.positions[0] = 1560;
  _86ME_HOME.positions[1] = 1150;
  _86ME_HOME.positions[2] = 1450;
  _86ME_HOME.positions[3] = 1490;
  _86ME_HOME.positions[4] = 1580;
  _86ME_HOME.positions[5] = 1870;
  _86ME_HOME.positions[6] = 1490;
  _86ME_HOME.positions[7] = 1720;
  _86ME_HOME.positions[8] = 1530;
  _86ME_HOME.positions[9] = 1440;
  _86ME_HOME.positions[10] = 1600;
  _86ME_HOME.positions[11] = 1250;

  myoffs.setOffsets();

  _86ME_HOME.playPositions(0);
}

void loop()
{
  usb.Task();
  keys_state[26] = key_state(26);
  keys_state[4] = key_state(4);
  keys_state[7] = key_state(7);
  if(keys_state[26] == 1)
  {
    walking_frm0.playPositions(300);
    while(isServoMultiMoving() == true);
    walking_frm1.playPositions(150);
    while(isServoMultiMoving() == true);
    walking_frm2.playPositions(150);
    while(isServoMultiMoving() == true);
    walking_frm3.playPositions(300);
    while(isServoMultiMoving() == true);
    walking_frm4.playPositions(150);
    while(isServoMultiMoving() == true);
    walking_frm5.playPositions(150);
    while(isServoMultiMoving() == true);
  }
  if(0)
  {
    walking_line_frm0.playPositions(500);
    while(isServoMultiMoving() == true);
    walking_line_frm1.playPositions(250);
    while(isServoMultiMoving() == true);
    walking_line_frm2.playPositions(250);
    while(isServoMultiMoving() == true);
    walking_line_frm3.playPositions(500);
    while(isServoMultiMoving() == true);
    walking_line_frm4.playPositions(250);
    while(isServoMultiMoving() == true);
    walking_line_frm5.playPositions(250);
    while(isServoMultiMoving() == true);
  }
  if(keys_state[4] == 1)
  {
    left_frm0.playPositions(300);
    while(isServoMultiMoving() == true);
    left_frm1.playPositions(150);
    while(isServoMultiMoving() == true);
    left_frm2.playPositions(150);
    while(isServoMultiMoving() == true);
    left_frm3.playPositions(300);
    while(isServoMultiMoving() == true);
    left_frm4.playPositions(150);
    while(isServoMultiMoving() == true);
    left_frm5.playPositions(150);
    while(isServoMultiMoving() == true);
  }
  if(keys_state[7] == 1)
  {
    right_frm0.playPositions(300);
    while(isServoMultiMoving() == true);
    right_frm1.playPositions(150);
    while(isServoMultiMoving() == true);
    right_frm2.playPositions(150);
    while(isServoMultiMoving() == true);
    right_frm3.playPositions(300);
    while(isServoMultiMoving() == true);
    right_frm4.playPositions(150);
    while(isServoMultiMoving() == true);
    right_frm5.playPositions(150);
    while(isServoMultiMoving() == true);
  }
  if(0)
  {
    home_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
  }
  if(0)
  {
    home2_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
  }
}
