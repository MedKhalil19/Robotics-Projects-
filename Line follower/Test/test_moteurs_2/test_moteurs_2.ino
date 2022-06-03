// Setup Motor A pins (Right)
#define ENA 13
#define IN1 11
#define IN2 12

// Setup Motor B pins (Left)
#define ENB 8
#define IN3 10
#define IN4 9

int speedA = 255;

void setup() {
  Serial.begin(9600);
// Setup Motor A code
   pinMode(ENA,OUTPUT);
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);

// Setup Motor B code   
   pinMode(ENB,OUTPUT);
   pinMode(IN3,OUTPUT);
   pinMode(IN3,OUTPUT);
   
//Config PWM motors
   digitalWrite(ENA,HIGH);
   digitalWrite(ENB,HIGH);}

// Setup movement functions
void forWard (int duration, int speed) {
  Serial.println("forward");
  analogWrite (IN1, speed);
  digitalWrite (IN2, LOW);
  analogWrite (IN3, speed);
  digitalWrite (IN4, LOW);
  delay(duration);
  
}
void backWard (int duration, int speed) {
  Serial.println("backWard");
  digitalWrite (IN1, LOW);
  analogWrite (IN2, speed);
  digitalWrite (IN3, LOW);
  analogWrite (IN4, speed);
  delay(duration);
  
}
void breakRobot (int duration){
  Serial.println("stop");
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay(duration);
  }

void loop(){
  forWard(3000,speedA);
  
  breakRobot(2000);
  
  backWard(3000,speedA);
}

   
