#include <PS2X_lib.h>

#include <Servo.h>

Servo myservo;
PS2X ps2x;
int  on = 0;
int pos = 0;
int error = 1;
byte type = 0;
byte vibrate = 0;

int escPin = 52; //Signal pin from ESC

unsigned long currentMillis, previousMillis;
int min_throttle = 1000;
int max_throttle = 2000;

//int LY = 0,l3 = 0, f = 0, ey = 0;

void setup() {

  Serial.begin(115200);

  myservo.attach(escPin, 1000, 2000); //54,128

  error = ps2x.config_gamepad(47, 51, 49, 53, false, false);
  //LY = ps2x.Analog(PSS_LY);
  //l3 = ps2x.ButtonPressed(PSB_CROSS);
  //ey = LY - 127;
  initProcedure();

}

void loop() {

  if (error == 0)
  {
    ps2x.read_gamepad(false, vibrate);
    //LY = ps2x.Analog(PSS_LY);
    //f = map(LY, 127 + ey, 255, 1000, 2000);
    //f = constrain(f, 1000, 2000);

    if (ps2x.ButtonPressed(PSB_PAD_UP)) {

      myservo.write(1500);
      delay(15);
    }
  }
}
void initProcedure() {
  myservo.write(1000);
  delay(15);
}
