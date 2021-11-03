//================JOSTIC MANUAL CONTROL

int joyVert = A5;
int joyHorz = A4;

int motorSpeed1 = 0;
int motorSpeed2 = 0;

int joyposVert = 512;
int joyposHorz = 512;

//===================LDR AUTO CONTROL
// switch //SETTING LDRS
int lTL = A0;
int lTR = A1;
int lBL = A2;
int lBR = A3;

//SETTING MOTOR INPUTS PINS
int enA = 9;
int enB = 10;
int IN1 = 8;
int IN2 = 7;
int IN3 = 5;
int IN4 = 4;

//SETTING MODE INDICATOR

int onAuto = 3;
int onAlgo = 2;

int switch1Pin = 12;

//SETTING MANUAL VAR

int valueX = 0;
int posValueX = 0;
int valueY = 0;
int posValueY = 0;

int TR = 0;
int TL = 0;
int BR = 0;
int BL = 0;

int avT = 0;
int avB = 0;
int avL = 0;
int avR = 0;

int onoffswitch = 0;

void mAstop(){
  digitalWrite(enA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void mBstop(){
  digitalWrite(enB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void setup() {
  // Set all the motor control pins to outputs:
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  pinMode(onAuto,OUTPUT);
  pinMode(onAlgo,OUTPUT);
  
  pinMode (12, INPUT);
  pinMode (13, INPUT);

  //==================LDR PINS
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
  
  pinMode (8, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (4, OUTPUT);

}

void loop() {
  //================================GET JOYSTICK POSITIONS (X,Y) 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  digitalWrite(onAuto, LOW);
  digitalWrite(onAlgo, LOW);
  
  onoffswitch = digitalRead(switch1Pin);
  
 while  (onoffswitch == LOW  ){ 
  //READING JOYSTIK POSITION
  digitalWrite(onAuto, LOW);
  //digitalWrite(onAlgo, HIGH);
   
  joyposVert = analogRead(joyVert);
  joyposHorz = analogRead(joyHorz);
  
  //================================SET Y POSITION  MOTOR A
  if (joyposVert < 400){
   mBstop();
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);

   //Motor speed
   joyposVert = joyposVert - 400;
   joyposVert = joyposVert * -1;
   
  //Convert to range 0-255
   motorSpeed1 = map(joyposVert,0,400,0,255);
   
   onoffswitch = digitalRead(switch1Pin);
  }
   else if (joyposVert > 600){
   mBstop();
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   
   motorSpeed1 = map(joyposVert,600,1023,0,255);
   onoffswitch = digitalRead(switch1Pin);
   }
   else{
   //Stopped
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   motorSpeed1 = 0;
   onoffswitch = digitalRead(switch1Pin);
  }

  //================================SET X POSITION  MOTOR B
  if (joyposHorz < 400){
   mAstop();
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);

   //Motor speed
   joyposHorz = joyposHorz - 400;
   joyposHorz = joyposHorz * -1;
   
  //Convert to range 0-255
   joyposHorz = map(joyposHorz,0,400,0, 255);
  
   motorSpeed2 = motorSpeed2 + joyposHorz;
   
   if(motorSpeed2 < 0)motorSpeed2 = 0;
   if(motorSpeed2 > 255)motorSpeed2 = 255;
   
   onoffswitch = digitalRead(switch1Pin);
  }
   else if (joyposHorz > 600){
   mAstop();
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   
   joyposHorz = map(joyposHorz,0,400,0, 255);
   
    motorSpeed2 = motorSpeed2 + joyposHorz;
   
   if(motorSpeed2 < 0)motorSpeed2 = 0;
   if(motorSpeed2 > 255)motorSpeed2 = 255;
   
   onoffswitch = digitalRead(switch1Pin);
   }
   else{
   //Stopped
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
  onoffswitch = digitalRead(switch1Pin);
  }

   //Prevent buzz 
   if(motorSpeed1<8)motorSpeed1 = 0;
   if(motorSpeed2<8)motorSpeed2 = 0;
   onoffswitch = digitalRead(switch1Pin);

 }
 onoffswitch = digitalRead(switch1Pin);

  //====================================AUTOMATICAL PANEL LDR

 while (onoffswitch == HIGH){

  //READ ANALOG 
  TL = analogRead(A0);
  TR = analogRead(A1);
  BL = analogRead(A2);
  BR = analogRead(A3);
  
  digitalWrite(onAuto, HIGH);
  digitalWrite(onAlgo, LOW);
  onoffswitch = digitalRead(switch1Pin);
  
  //AVERAGE LDRS
  //X
  avR = (TR+BR)/2;
  avL = (TL+BL)/2;
  
  //TREATING SIGNAL FROM LDRS
   //X AXIS
  valueX = avL - avR;
  posValueX = abs(valueX); 

  if (posValueX > 35){
      if (valueX > 0) {
      motorSpeed2 = 10;
      digitalWrite(IN4, HIGH);
    //motorSpeed2 = map(joyposHorz,0,50,0,50);
   //Prevent buzz 
      delay(200);
       }
      else if (valueX < 0) {
      motorSpeed2 = 10;
      digitalWrite(IN3, HIGH);
     //motorSpeed2 = map(joyposHorz,0,50,0,50);
      delay(200);
       }
  onoffswitch = digitalRead(switch1Pin);
  }
  else if(posValueX <= 35){
      motorSpeed2 = 0;
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, LOW);
      onoffswitch = digitalRead(switch1Pin);
  }   
  //AVERAGE LDRS
  //Y
  avT = (TR+TL)/2;
  avB = (BR+BL)/2;
  
  //TREATING SIGNAL FROM LDRS
   //Y AXIS
  valueY = avT - avB;
  posValueY = abs(valueY); 

  if (posValueY > 35){
      if (valueY > 0) {
      motorSpeed1 = 10;
      digitalWrite(IN2, HIGH);
   // motorSpeed1 = map(joyposHorz,0,50,0,50);
   //Prevent buzz 
   if(motorSpeed1<20)motorSpeed1 = 0;
      delay(200);
       }
      else if (valueY < 0) {
      motorSpeed1 = 10;
      digitalWrite(IN1, HIGH);
     //motorSpeed1 = map(joyposHorz,0,50,0,50);
   if(motorSpeed1<20)motorSpeed1 = 0;
      delay(200);
       }
  onoffswitch = digitalRead(switch1Pin);
  }
  else if(posValueY <= 35){
      motorSpeed1 = 0;
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      onoffswitch = digitalRead(switch1Pin);
  } 
  
  }//WHILE END
  
 }
 
