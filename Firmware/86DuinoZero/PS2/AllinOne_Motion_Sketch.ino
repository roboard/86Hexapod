#include <Servo86.h>
#include <PS2X_lib.h>

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;
Servo myservo11;
Servo myservo12;
Servo myservo13;

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
ServoFrame walking_line_frm6;
ServoFrame walking_line_frm7;

ServoFrame left_frm0;
ServoFrame left_frm1;
ServoFrame left_frm2;
ServoFrame left_frm3;
ServoFrame left_frm4;
ServoFrame left_frm5;
ServoFrame left_frm6;
ServoFrame left_frm7;

ServoFrame right_frm0;
ServoFrame right_frm1;
ServoFrame right_frm2;
ServoFrame right_frm3;
ServoFrame right_frm4;
ServoFrame right_frm5;
ServoFrame right_frm6;
ServoFrame right_frm7;

ServoFrame home_frm0;

ServoFrame home2_frm0;

PS2X ps2x;

void setup()
{

  ps2x.config_gamepad(0, 1, 43, 44, false, false);

  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6);
  myservo7.attach(7);
  myservo8.attach(8);
  myservo9.attach(9);
  myservo10.attach(10);
  myservo11.attach(11);
  myservo12.attach(12);
  myservo13.attach(13);


  walking_frm0.positions[0] = 1442;
  walking_frm0.positions[1] = 1600;
  walking_frm0.positions[2] = 1300;
  walking_frm0.positions[3] = 1780;
  walking_frm0.positions[4] = 1854;
  walking_frm0.positions[5] = 1490;
  walking_frm0.positions[6] = 2022;
  walking_frm0.positions[7] = 1780;
  walking_frm0.positions[8] = 1439;
  walking_frm0.positions[9] = 1450;
  walking_frm0.positions[10] = 1425;
  walking_frm0.positions[11] = 1736;

  walking_frm1.positions[0] = 1442;
  walking_frm1.positions[1] = 1600;
  walking_frm1.positions[2] = 1300;
  walking_frm1.positions[3] = 1501;
  walking_frm1.positions[4] = 1854;
  walking_frm1.positions[5] = 1490;
  walking_frm1.positions[6] = 2022;
  walking_frm1.positions[7] = 1592;
  walking_frm1.positions[8] = 1439;
  walking_frm1.positions[9] = 1450;
  walking_frm1.positions[10] = 1425;
  walking_frm1.positions[11] = 1588;

  walking_frm2.positions[0] = 1442;
  walking_frm2.positions[1] = 1838;
  walking_frm2.positions[2] = 1300;
  walking_frm2.positions[3] = 1501;
  walking_frm2.positions[4] = 1854;
  walking_frm2.positions[5] = 1678;
  walking_frm2.positions[6] = 2022;
  walking_frm2.positions[7] = 1592;
  walking_frm2.positions[8] = 1439;
  walking_frm2.positions[9] = 1635;
  walking_frm2.positions[10] = 1425;
  walking_frm2.positions[11] = 1588;

  walking_frm3.positions[0] = 1130;
  walking_frm3.positions[1] = 1838;
  walking_frm3.positions[2] = 1498;
  walking_frm3.positions[3] = 1501;
  walking_frm3.positions[4] = 1512;
  walking_frm3.positions[5] = 1678;
  walking_frm3.positions[6] = 1708;
  walking_frm3.positions[7] = 1592;
  walking_frm3.positions[8] = 1671;
  walking_frm3.positions[9] = 1635;
  walking_frm3.positions[10] = 1216;
  walking_frm3.positions[11] = 1558;

  walking_frm4.positions[0] = 1130;
  walking_frm4.positions[1] = 1629;
  walking_frm4.positions[2] = 1498;
  walking_frm4.positions[3] = 1501;
  walking_frm4.positions[4] = 1512;
  walking_frm4.positions[5] = 1489;
  walking_frm4.positions[6] = 1708;
  walking_frm4.positions[7] = 1592;
  walking_frm4.positions[8] = 1671;
  walking_frm4.positions[9] = 1454;
  walking_frm4.positions[10] = 1216;
  walking_frm4.positions[11] = 1558;

  walking_frm5.positions[0] = 1130;
  walking_frm5.positions[1] = 1629;
  walking_frm5.positions[2] = 1498;
  walking_frm5.positions[3] = 1722;
  walking_frm5.positions[4] = 1512;
  walking_frm5.positions[5] = 1489;
  walking_frm5.positions[6] = 1708;
  walking_frm5.positions[7] = 1736;
  walking_frm5.positions[8] = 1671;
  walking_frm5.positions[9] = 1454;
  walking_frm5.positions[10] = 1216;
  walking_frm5.positions[11] = 1722;

  walking_line_frm0.positions[0] = 1250;
  walking_line_frm0.positions[1] = 1600;
  walking_line_frm0.positions[2] = 1440;
  walking_line_frm0.positions[3] = 1530;
  walking_line_frm0.positions[4] = 1720;
  walking_line_frm0.positions[5] = 1490;
  walking_line_frm0.positions[6] = 1870;
  walking_line_frm0.positions[7] = 1580;
  walking_line_frm0.positions[8] = 1490;
  walking_line_frm0.positions[9] = 1450;
  walking_line_frm0.positions[10] = 1150;
  walking_line_frm0.positions[11] = 1560;

  walking_line_frm1.positions[0] = 1250;
  walking_line_frm1.positions[1] = 1816;
  walking_line_frm1.positions[2] = 1440;
  walking_line_frm1.positions[3] = 1530;
  walking_line_frm1.positions[4] = 1720;
  walking_line_frm1.positions[5] = 1715;
  walking_line_frm1.positions[6] = 1870;
  walking_line_frm1.positions[7] = 1580;
  walking_line_frm1.positions[8] = 1490;
  walking_line_frm1.positions[9] = 1671;
  walking_line_frm1.positions[10] = 1150;
  walking_line_frm1.positions[11] = 1560;

  walking_line_frm2.positions[0] = 1163;
  walking_line_frm2.positions[1] = 1903;
  walking_line_frm2.positions[2] = 1555;
  walking_line_frm2.positions[3] = 1367;
  walking_line_frm2.positions[4] = 1628;
  walking_line_frm2.positions[5] = 1526;
  walking_line_frm2.positions[6] = 1802;
  walking_line_frm2.positions[7] = 1700;
  walking_line_frm2.positions[8] = 1585;
  walking_line_frm2.positions[9] = 1715;
  walking_line_frm2.positions[10] = 1120;
  walking_line_frm2.positions[11] = 1425;

  walking_line_frm3.positions[0] = 1193;
  walking_line_frm3.positions[1] = 1671;
  walking_line_frm3.positions[2] = 1555;
  walking_line_frm3.positions[3] = 1367;
  walking_line_frm3.positions[4] = 1628;
  walking_line_frm3.positions[5] = 1236;
  walking_line_frm3.positions[6] = 1802;
  walking_line_frm3.positions[7] = 1700;
  walking_line_frm3.positions[8] = 1585;
  walking_line_frm3.positions[9] = 1468;
  walking_line_frm3.positions[10] = 1120;
  walking_line_frm3.positions[11] = 1425;

  walking_line_frm4.positions[0] = 1193;
  walking_line_frm4.positions[1] = 1685;
  walking_line_frm4.positions[2] = 1512;
  walking_line_frm4.positions[3] = 1628;
  walking_line_frm4.positions[4] = 1628;
  walking_line_frm4.positions[5] = 1410;
  walking_line_frm4.positions[6] = 1802;
  walking_line_frm4.positions[7] = 1903;
  walking_line_frm4.positions[8] = 1585;
  walking_line_frm4.positions[9] = 1454;
  walking_line_frm4.positions[10] = 1120;
  walking_line_frm4.positions[11] = 1773;

  walking_line_frm5.positions[0] = 1309;
  walking_line_frm5.positions[1] = 1628;
  walking_line_frm5.positions[2] = 1294;
  walking_line_frm5.positions[3] = 1628;
  walking_line_frm5.positions[4] = 1729;
  walking_line_frm5.positions[5] = 1135;
  walking_line_frm5.positions[6] = 1889;
  walking_line_frm5.positions[7] = 1903;
  walking_line_frm5.positions[8] = 1483;
  walking_line_frm5.positions[9] = 1309;
  walking_line_frm5.positions[10] = 1251;
  walking_line_frm5.positions[11] = 1773;

  walking_line_frm6.positions[0] = 1323;
  walking_line_frm6.positions[1] = 1657;
  walking_line_frm6.positions[2] = 1294;
  walking_line_frm6.positions[3] = 1512;
  walking_line_frm6.positions[4] = 1729;
  walking_line_frm6.positions[5] = 1265;
  walking_line_frm6.positions[6] = 1889;
  walking_line_frm6.positions[7] = 1680;
  walking_line_frm6.positions[8] = 1526;
  walking_line_frm6.positions[9] = 1410;
  walking_line_frm6.positions[10] = 1251;
  walking_line_frm6.positions[11] = 1454;

  walking_line_frm7.positions[0] = 1323;
  walking_line_frm7.positions[1] = 1903;
  walking_line_frm7.positions[2] = 1294;
  walking_line_frm7.positions[3] = 1555;
  walking_line_frm7.positions[4] = 1729;
  walking_line_frm7.positions[5] = 1758;
  walking_line_frm7.positions[6] = 1889;
  walking_line_frm7.positions[7] = 1680;
  walking_line_frm7.positions[8] = 1526;
  walking_line_frm7.positions[9] = 1729;
  walking_line_frm7.positions[10] = 1251;
  walking_line_frm7.positions[11] = 1628;

  left_frm0.positions[0] = 1250;
  left_frm0.positions[1] = 1600;
  left_frm0.positions[2] = 1440;
  left_frm0.positions[3] = 1530;
  left_frm0.positions[4] = 1720;
  left_frm0.positions[5] = 1490;
  left_frm0.positions[6] = 1870;
  left_frm0.positions[7] = 1580;
  left_frm0.positions[8] = 1490;
  left_frm0.positions[9] = 1450;
  left_frm0.positions[10] = 1150;
  left_frm0.positions[11] = 1560;

  left_frm1.positions[0] = 1250;
  left_frm1.positions[1] = 1816;
  left_frm1.positions[2] = 1440;
  left_frm1.positions[3] = 1530;
  left_frm1.positions[4] = 1720;
  left_frm1.positions[5] = 1666;
  left_frm1.positions[6] = 1870;
  left_frm1.positions[7] = 1580;
  left_frm1.positions[8] = 1490;
  left_frm1.positions[9] = 1630;
  left_frm1.positions[10] = 1150;
  left_frm1.positions[11] = 1560;

  left_frm2.positions[0] = 1541;
  left_frm2.positions[1] = 1816;
  left_frm2.positions[2] = 1222;
  left_frm2.positions[3] = 1530;
  left_frm2.positions[4] = 1860;
  left_frm2.positions[5] = 1666;
  left_frm2.positions[6] = 1729;
  left_frm2.positions[7] = 1580;
  left_frm2.positions[8] = 1715;
  left_frm2.positions[9] = 1630;
  left_frm2.positions[10] = 1059;
  left_frm2.positions[11] = 1560;

  left_frm3.positions[0] = 1541;
  left_frm3.positions[1] = 1666;
  left_frm3.positions[2] = 1222;
  left_frm3.positions[3] = 1530;
  left_frm3.positions[4] = 1860;
  left_frm3.positions[5] = 1476;
  left_frm3.positions[6] = 1729;
  left_frm3.positions[7] = 1580;
  left_frm3.positions[8] = 1715;
  left_frm3.positions[9] = 1449;
  left_frm3.positions[10] = 1059;
  left_frm3.positions[11] = 1560;

  left_frm4.positions[0] = 1541;
  left_frm4.positions[1] = 1666;
  left_frm4.positions[2] = 1222;
  left_frm4.positions[3] = 1787;
  left_frm4.positions[4] = 1860;
  left_frm4.positions[5] = 1476;
  left_frm4.positions[6] = 1729;
  left_frm4.positions[7] = 1845;
  left_frm4.positions[8] = 1715;
  left_frm4.positions[9] = 1449;
  left_frm4.positions[10] = 1059;
  left_frm4.positions[11] = 1845;

  left_frm5.positions[0] = 1338;
  left_frm5.positions[1] = 1666;
  left_frm5.positions[2] = 1642;
  left_frm5.positions[3] = 1787;
  left_frm5.positions[4] = 1651;
  left_frm5.positions[5] = 1476;
  left_frm5.positions[6] = 2034;
  left_frm5.positions[7] = 1845;
  left_frm5.positions[8] = 1390;
  left_frm5.positions[9] = 1449;
  left_frm5.positions[10] = 1406;
  left_frm5.positions[11] = 1845;

  left_frm6.positions[0] = 1338;
  left_frm6.positions[1] = 1666;
  left_frm6.positions[2] = 1642;
  left_frm6.positions[3] = 1551;
  left_frm6.positions[4] = 1651;
  left_frm6.positions[5] = 1476;
  left_frm6.positions[6] = 2034;
  left_frm6.positions[7] = 1638;
  left_frm6.positions[8] = 1390;
  left_frm6.positions[9] = 1449;
  left_frm6.positions[10] = 1406;
  left_frm6.positions[11] = 1599;

  left_frm7.positions[0] = 1338;
  left_frm7.positions[1] = 1860;
  left_frm7.positions[2] = 1642;
  left_frm7.positions[3] = 1551;
  left_frm7.positions[4] = 1651;
  left_frm7.positions[5] = 1773;
  left_frm7.positions[6] = 2034;
  left_frm7.positions[7] = 1638;
  left_frm7.positions[8] = 1390;
  left_frm7.positions[9] = 1744;
  left_frm7.positions[10] = 1406;
  left_frm7.positions[11] = 1599;

  right_frm0.positions[0] = 1250;
  right_frm0.positions[1] = 1600;
  right_frm0.positions[2] = 1440;
  right_frm0.positions[3] = 1530;
  right_frm0.positions[4] = 1720;
  right_frm0.positions[5] = 1490;
  right_frm0.positions[6] = 1870;
  right_frm0.positions[7] = 1580;
  right_frm0.positions[8] = 1490;
  right_frm0.positions[9] = 1450;
  right_frm0.positions[10] = 1150;
  right_frm0.positions[11] = 1560;

  right_frm1.positions[0] = 1250;
  right_frm1.positions[1] = 1802;
  right_frm1.positions[2] = 1440;
  right_frm1.positions[3] = 1530;
  right_frm1.positions[4] = 1720;
  right_frm1.positions[5] = 1729;
  right_frm1.positions[6] = 1870;
  right_frm1.positions[7] = 1580;
  right_frm1.positions[8] = 1490;
  right_frm1.positions[9] = 1715;
  right_frm1.positions[10] = 1150;
  right_frm1.positions[11] = 1560;

  right_frm2.positions[0] = 1004;
  right_frm2.positions[1] = 1802;
  right_frm2.positions[2] = 1758;
  right_frm2.positions[3] = 1530;
  right_frm2.positions[4] = 1541;
  right_frm2.positions[5] = 1729;
  right_frm2.positions[6] = 2048;
  right_frm2.positions[7] = 1580;
  right_frm2.positions[8] = 1294;
  right_frm2.positions[9] = 1715;
  right_frm2.positions[10] = 1323;
  right_frm2.positions[11] = 1560;

  right_frm3.positions[0] = 1004;
  right_frm3.positions[1] = 1618;
  right_frm3.positions[2] = 1758;
  right_frm3.positions[3] = 1530;
  right_frm3.positions[4] = 1541;
  right_frm3.positions[5] = 1467;
  right_frm3.positions[6] = 2048;
  right_frm3.positions[7] = 1580;
  right_frm3.positions[8] = 1294;
  right_frm3.positions[9] = 1429;
  right_frm3.positions[10] = 1323;
  right_frm3.positions[11] = 1560;

  right_frm4.positions[0] = 1004;
  right_frm4.positions[1] = 1617;
  right_frm4.positions[2] = 1758;
  right_frm4.positions[3] = 1802;
  right_frm4.positions[4] = 1541;
  right_frm4.positions[5] = 1467;
  right_frm4.positions[6] = 2048;
  right_frm4.positions[7] = 1831;
  right_frm4.positions[8] = 1294;
  right_frm4.positions[9] = 1419;
  right_frm4.positions[10] = 1323;
  right_frm4.positions[11] = 1860;

  right_frm5.positions[0] = 1309;
  right_frm5.positions[1] = 1617;
  right_frm5.positions[2] = 1294;
  right_frm5.positions[3] = 1802;
  right_frm5.positions[4] = 1860;
  right_frm5.positions[5] = 1467;
  right_frm5.positions[6] = 1497;
  right_frm5.positions[7] = 1831;
  right_frm5.positions[8] = 1599;
  right_frm5.positions[9] = 1419;
  right_frm5.positions[10] = 1106;
  right_frm5.positions[11] = 1860;

  right_frm6.positions[0] = 1309;
  right_frm6.positions[1] = 1617;
  right_frm6.positions[2] = 1294;
  right_frm6.positions[3] = 1512;
  right_frm6.positions[4] = 1860;
  right_frm6.positions[5] = 1467;
  right_frm6.positions[6] = 1497;
  right_frm6.positions[7] = 1580;
  right_frm6.positions[8] = 1599;
  right_frm6.positions[9] = 1419;
  right_frm6.positions[10] = 1106;
  right_frm6.positions[11] = 1526;

  right_frm7.positions[0] = 1309;
  right_frm7.positions[1] = 1918;
  right_frm7.positions[2] = 1294;
  right_frm7.positions[3] = 1512;
  right_frm7.positions[4] = 1860;
  right_frm7.positions[5] = 1773;
  right_frm7.positions[6] = 1497;
  right_frm7.positions[7] = 1580;
  right_frm7.positions[8] = 1599;
  right_frm7.positions[9] = 1758;
  right_frm7.positions[10] = 1106;
  right_frm7.positions[11] = 1526;

  home_frm0.positions[0] = 1250;
  home_frm0.positions[1] = 1600;
  home_frm0.positions[2] = 1440;
  home_frm0.positions[3] = 1530;
  home_frm0.positions[4] = 1720;
  home_frm0.positions[5] = 1490;
  home_frm0.positions[6] = 1870;
  home_frm0.positions[7] = 1580;
  home_frm0.positions[8] = 1490;
  home_frm0.positions[9] = 1450;
  home_frm0.positions[10] = 1150;
  home_frm0.positions[11] = 1560;

  home2_frm0.positions[0] = 1250;
  home2_frm0.positions[1] = 1600;
  home2_frm0.positions[2] = 1440;
  home2_frm0.positions[3] = 1530;
  home2_frm0.positions[4] = 1720;
  home2_frm0.positions[5] = 1490;
  home2_frm0.positions[6] = 1870;
  home2_frm0.positions[7] = 1580;
  home2_frm0.positions[8] = 1490;
  home2_frm0.positions[9] = 1450;
  home2_frm0.positions[10] = 1150;
  home2_frm0.positions[11] = 1560;

  _86ME_HOME.positions[0] = 1250;
  _86ME_HOME.positions[1] = 1600;
  _86ME_HOME.positions[2] = 1440;
  _86ME_HOME.positions[3] = 1530;
  _86ME_HOME.positions[4] = 1720;
  _86ME_HOME.positions[5] = 1490;
  _86ME_HOME.positions[6] = 1870;
  _86ME_HOME.positions[7] = 1580;
  _86ME_HOME.positions[8] = 1490;
  _86ME_HOME.positions[9] = 1450;
  _86ME_HOME.positions[10] = 1150;
  _86ME_HOME.positions[11] = 1560;

  myoffs.setOffsets();

  _86ME_HOME.playPositions(0);
}

void loop()
{
  ps2x.read_gamepad();
  if(ps2x.Button(PSB_PAD_UP) && !ps2x.ButtonPressed(PSB_PAD_UP))
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
    walking_line_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
    walking_line_frm1.playPositions(1000);
    while(isServoMultiMoving() == true);
    int walking_line_repeat_0 = 0;
    flag_walking_line_repeat_0:

      walking_line_frm2.playPositions(500);
      while(isServoMultiMoving() == true);
      walking_line_frm3.playPositions(250);
      while(isServoMultiMoving() == true);
      walking_line_frm4.playPositions(250);
      while(isServoMultiMoving() == true);
      walking_line_frm5.playPositions(500);
      while(isServoMultiMoving() == true);
      walking_line_frm6.playPositions(250);
      while(isServoMultiMoving() == true);
      walking_line_frm7.playPositions(250);
      while(isServoMultiMoving() == true);
    goto flag_walking_line_repeat_0;
  }
  if(0)
  {
    left_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
    left_frm1.playPositions(250);
    while(isServoMultiMoving() == true);
    int left_repeat_0 = 0;
    flag_left_repeat_0:

      left_frm2.playPositions(300);
      while(isServoMultiMoving() == true);
      left_frm3.playPositions(150);
      while(isServoMultiMoving() == true);
      left_frm4.playPositions(150);
      while(isServoMultiMoving() == true);
      left_frm5.playPositions(300);
      while(isServoMultiMoving() == true);
      left_frm6.playPositions(150);
      while(isServoMultiMoving() == true);
      left_frm7.playPositions(150);
      while(isServoMultiMoving() == true);
    goto flag_left_repeat_0;
  }
  if(0)
  {
    right_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
    right_frm1.playPositions(300);
    while(isServoMultiMoving() == true);
    int right_repeat_0 = 0;
    flag_right_repeat_0:

      right_frm2.playPositions(300);
      while(isServoMultiMoving() == true);
      right_frm3.playPositions(150);
      while(isServoMultiMoving() == true);
      right_frm4.playPositions(150);
      while(isServoMultiMoving() == true);
      right_frm5.playPositions(300);
      while(isServoMultiMoving() == true);
      right_frm6.playPositions(150);
      while(isServoMultiMoving() == true);
      right_frm7.playPositions(150);
      while(isServoMultiMoving() == true);
    goto flag_right_repeat_0;
  }
  if(ps2x.ButtonPressed(PSB_PAD_UP))
  {
    home_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
  }
  if(ps2x.ButtonReleased(PSB_PAD_UP))
  {
    home2_frm0.playPositions(1000);
    while(isServoMultiMoving() == true);
  }
}
