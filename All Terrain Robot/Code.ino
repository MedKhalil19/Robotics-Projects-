#include <Bluepad32.h>

ControllerPtr myControllers[BP32_MAX_GAMEPADS];
// Define motor control pins
const int enA = 5;        // PWM pin for speed control
const int enB= 4;        // PWM pin for speed control
int up = 18;
int down = 19;
int left= 21;
int right= 22;
int R_xvalue;
int L_yvalue;

//set speeds to initially 0
int upSpeed = 0;
int downSpeed = 0;
int leftSpeed = 0;
int rightSpeed = 0;
// PWM settings
const int pwmChannelA=1;
const int pwmChannelB = 0; 
const int pwmFreq = 5000;
const int pwmResolution = 8;

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            Serial.printf("CALLBACK: Controller is connected, index=%d\n", i);
            myControllers[i] = ctl;
            break;
        }
    }
}

void onDisconnectedController(ControllerPtr ctl) {
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            Serial.printf("CALLBACK: Controller disconnected from index=%d\n", i);
            myControllers[i] = nullptr;
            break;
        }
    }
}

void dumpGamepad(ControllerPtr ctl) {
   /* Serial.printf(
        "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, "
        "misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
        ctl->index(),        // Controller Index
        ctl->dpad(),         // D-pad
        ctl->buttons(),      // bitmask of pressed buttons
        ctl->axisX(),        // (-511 - 512) left X Axis
        ctl->axisY(),        // (-511 - 512) left Y axis
        ctl->axisRX(),       // (-511 - 512) right X axis
        ctl->axisRY(),       // (-511 - 512) right Y axis
        ctl->brake(),        // (0 - 1023): brake button
        ctl->throttle(),     // (0 - 1023): throttle (AKA gas) button
        ctl->miscButtons(),  // bitmask of pressed "misc" buttons
        ctl->gyroX(),        // Gyro X
        ctl->gyroY(),        // Gyro Y
        ctl->gyroZ(),        // Gyro Z
        ctl->accelX(),       // Accelerometer X
        ctl->accelY(),       // Accelerometer Y
        ctl->accelZ()        // Accelerometer Z
    );*/
R_xvalue=ctl->axisRX();
L_yvalue= ctl->axisY(); 
}




void processGamepad(ControllerPtr ctl) {
    
    dumpGamepad(ctl);
}


void processControllers() {
    for (auto myController : myControllers) {
        if (myController && myController->isConnected() && myController->hasData()) {
            if (myController->isGamepad()) {
                processGamepad(myController);
            }
             else {
                Serial.println("Unsupported controller");
            }
        }
    }
}

// Arduino setup function. Runs in CPU 1
void setup() {
    Serial.begin(115200);


    Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
    const uint8_t* addr = BP32.localBdAddress();
    Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    // Setup the Bluepad32 callbacks
    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys();
    BP32.enableVirtualDevice(false);
    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode (up, OUTPUT);
    pinMode (down, OUTPUT);
    pinMode (right, OUTPUT);
    pinMode (left, OUTPUT);
   // PWM setup
   
// PWM setup
ledcSetup(pwmChannelA, pwmFreq, pwmResolution);
ledcAttachPin(enA, pwmChannelA);

ledcSetup(pwmChannelB, pwmFreq, pwmResolution);
ledcAttachPin(enB, pwmChannelB);

}
void stop (){
      // Stop the motor
     Serial.println("Stop"); 
     ledcWrite(pwmChannelA,0);
     ledcWrite(pwmChannelB,0);
    }
    // Function to control motor speed
     void controlSpeed(int dutyCycle) { 
      ledcWrite(pwmChannelA, dutyCycle); 
      ledcWrite(pwmChannelB, dutyCycle); 
      }

// Arduino loop function. Runs in CPU 1.
void loop() {
    // This call fetches all the controllers' data.
    // Call this function in your main loop.
    bool dataUpdated = BP32.update();
    if (dataUpdated)
        processControllers();
//map function
 //target=map(sorce,sorcelow,sorcehigh,targetlow,targethigh)
 upSpeed=map(L_yvalue,4,-512,0,255);
 downSpeed=map(L_yvalue,4,512,0,255);
 leftSpeed=map(R_xvalue,4,-512,0,255);
 rightSpeed=map(R_xvalue,4,512,0,255);
 
 if (R_xvalue<0) {
    Serial.println("left"); //turn left
    ledcWrite(pwmChannelA,leftSpeed); // Full speed
  ledcWrite(pwmChannelB,leftSpeed); // Full speed
    digitalWrite(up,HIGH);
    digitalWrite(down,LOW);
    digitalWrite (left,LOW);
    digitalWrite(right,HIGH);

 }
else  if (R_xvalue>4) {
    //turn left
    Serial.println("right");
    ledcWrite(pwmChannelA,rightSpeed); // Full speed
  ledcWrite(pwmChannelB,rightSpeed); // Full speed
    digitalWrite(up,LOW);
    digitalWrite(down,HIGH);
    digitalWrite(right,LOW);
    digitalWrite (left,HIGH);
 }

 else if(L_yvalue<-8){
  Serial.println("Forward"); 
  digitalWrite(up, HIGH);
  digitalWrite(down, LOW); 
  digitalWrite(left, HIGH);
  digitalWrite(right, LOW); 
  ledcWrite(pwmChannelA,upSpeed); // Full speed
  ledcWrite(pwmChannelB,upSpeed); // Full speed
 }
  else if(L_yvalue>8){
 //backward // Rotate motor backward
     Serial.println("Backward"); 
     digitalWrite(up, LOW); 
     digitalWrite(down, HIGH);
     digitalWrite(left, LOW);
     digitalWrite(right, HIGH); 
     ledcWrite(pwmChannelA,downSpeed); // Full speed
     ledcWrite(pwmChannelB,downSpeed); // Full speed
     
 }
 else{
    stop();
 }

    delay(50);
}

    
    