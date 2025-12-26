// Setup Motor A (front and rear) pins
#define PIN_R1 3
#define PIN_R2 4
#define PIN_R_enable 2

// Setup Motor B (front and rear) pins
#define PIN_L1 5
#define PIN_L2 6
#define PIN_L_enable 7


//line follower
#define rm_sensor 8
#define r_sensor 9
#define m_sensor 10
#define l_sensor 11
#define lm_sensor 12
#define MAX 100
#define kp 15
#define kd 5

const int Maxe = 110;
int speedA =MAX ;int speedB =MAX;
int lasterror = 0;
int error = 0;

void setup() {
  // Configure the pin modes for each drive motor
  pinMode (PIN_R1, OUTPUT);
  pinMode (PIN_R2, OUTPUT);
  pinMode (PIN_L1, OUTPUT);
  pinMode (PIN_L2, OUTPUT);
  pinMode (PIN_R_enable, OUTPUT);
  pinMode (PIN_L_enable, OUTPUT);
  digitalWrite (PIN_L_enable, HIGH);
  digitalWrite (PIN_R_enable, HIGH);
  //line follower setup
  pinMode (rm_sensor, INPUT);
  pinMode (r_sensor, INPUT);
  pinMode (m_sensor, INPUT);
  pinMode (l_sensor, INPUT);
  pinMode (lm_sensor, INPUT);
}

void loop() {
followLine();     
     
}
// Create motor functions

void motorAforward(int speed) {
  analogWrite (PIN_R1, speed);
  digitalWrite (PIN_R2, LOW);
}
void motorBforward(int speed) {
  digitalWrite (PIN_L1, LOW);
  analogWrite (PIN_L2, speed);
}
void motorAbackward(int speed) {
  digitalWrite (PIN_R1, LOW);
  analogWrite (PIN_R2, speed);
}
void motorBbackward(int speed) {
  analogWrite (PIN_L1, speed);
  digitalWrite (PIN_L2, LOW);
}
void motorAstop() {
  digitalWrite (PIN_R1, HIGH);
  digitalWrite (PIN_R2, HIGH);
}
void motorBstop() {
  digitalWrite (PIN_L1, HIGH);
  digitalWrite (PIN_L2, HIGH);
}
void motorAcoast() {
  digitalWrite (PIN_R1, LOW);
  digitalWrite (PIN_R2, LOW);
}
void motorBcoast() {
  digitalWrite (PIN_L1, LOW);
  digitalWrite (PIN_L2, LOW);
}

// Setup movement functions

void forward (int duration, int speed) {
  motorAforward(speed);
  motorBforward(speed);
  delay (duration);
}
void backward (int duration, int speed) {
  motorAbackward(speed);
  motorBbackward(speed);
  delay (duration);
}
void left (int duration, int speedA, int speedB) {
  motorAbackward(speedA);
  motorBforward(speedB);
  delay (duration);
}
void right (int duration, int speedA, int speedB) {
  motorAforward(speedA);
  motorBbackward(speedB);
  delay (duration);
}
void coast (int duration) {
  motorAcoast();
  motorBcoast();
  delay (duration);
}
void breakRobot (int duration) {
  motorAstop();
  motorBstop();
  delay (duration);
}
void followLine(){
 int sensor_RM = digitalRead(rm_sensor);
 int sensor_R = digitalRead(r_sensor);
 int sensor_M = digitalRead(m_sensor);
 int sensor_L = digitalRead(l_sensor);
 int sensor_LM = digitalRead(lm_sensor);
  lasterror = error;
   if((error == -6)||(error == -5)||(error == -4)|| (error == -3)||(error == -2)||(error == -1)){
      right(1,speedA,speedB);
    }
    else if ((error == 8)||(error == 7)||(error == 6)||(error == 5)||(error == 4)||(error == 3)||(error == 2)||(error == 1)){
     left(1,speedA,speedB);
    }
    else if((error == 9)||(error == 0)){
     forward(1,Maxe);
    }
 if(sensor_LM == 0 && sensor_L == 0 && sensor_M == 0 && sensor_R == 0 && sensor_RM == 1 ){
    error = -4;
  }else if((sensor_LM == 0) && sensor_L == 0 && sensor_M == 0 && sensor_R == 1&& sensor_RM == 1){
    error = -3 ;
  }else if((sensor_LM == 0) && sensor_L == 0 && sensor_M == 0 && sensor_R == 1 && sensor_RM == 0){
    error = -2;
  }else if((sensor_LM == 0) && sensor_L == 0 && sensor_M == 1 && sensor_R == 1&& sensor_RM == 0){
    error = -1;
  }else if((sensor_LM == 0) && sensor_L == 0 && sensor_M == 1 && sensor_R == 0&& sensor_RM == 0){
    error = 0;
  }else if((sensor_LM == 0) && sensor_L == 1 && sensor_M == 1 && sensor_R == 0&& sensor_RM == 0){
    error = 1;
  }else if((sensor_LM == 0) && sensor_L == 1 && sensor_M == 0 && sensor_R == 0&& sensor_RM == 0){
    error = 2;
  }else if((sensor_LM == 1) && sensor_L == 1 && sensor_M == 0 && sensor_R == 0&& sensor_RM == 0){
    error = 3;
  }else if((sensor_LM == 1) && sensor_L == 0 && sensor_M == 0 && sensor_R == 0&& sensor_RM == 0){
    error = 4 ;}

  if((error == -5)||(error == -4)|| (error == -3)||(error == -2)||(error == -1)){
      right(1,speedA,speedB);
    }
    else if ((error == 8)||(error == 7)||(error == 6)||(error == 5)||(error == 4)||(error == 3)||(error == 2)||(error == 1)){
      left(1,speedA,speedB);
    }
    else if((error == 9)||(error == 0)){
      forward(1,Maxe);
    }
  
 ////////////////////////////////  INVERTED LOGIC     MOTORA --- > right
 speedA = MAX - error*kp - kd*lasterror;
 speedB = MAX + error*kp + kd*lasterror;  
 }
