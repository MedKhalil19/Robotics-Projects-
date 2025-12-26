#define rm_s 3
#define r_s  4
#define m_s  5
#define l_s  6
#define lm_s  7


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(rm_s,INPUT);
   pinMode(r_s,INPUT);
   pinMode(m_s,INPUT);
   pinMode(l_s,INPUT);
   pinMode(lm_s,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print ("LFS: RM_S R_S M_S L_S LM_S  ==> "); 
     Serial.print (digitalRead(rm_s)); 
     Serial.print (" ");
     Serial.print (digitalRead(r_s)); 
     Serial.print (" ");
     Serial.print (digitalRead(m_s)); 
     Serial.print (" ");
     Serial.print (digitalRead(l_s)); 
     Serial.print (" ");
     Serial.print (digitalRead(lm_s)); 
     Serial.println ("  ==> ");
     delay(300);
}
