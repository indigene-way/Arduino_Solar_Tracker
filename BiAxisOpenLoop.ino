//================JOSTIC MANUAL CONTROL
int joyVert = A5;
int joyHorz = A4;
int motorSpeed1 = 0;
int motorSpeed2 = 0;
int joyposVert = 512;
int joyposHorz = 512;
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
int onoffswitch = 0;
void mAstop(){
  digitalWrite(enA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);}
void mBstop(){
  digitalWrite(enB, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);}

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

  //====================================AUTOMATICAL PANEL CODE
  //While ON AUTO
  
  int i = 0;//Compteur AUTO CODE
  int j = 0;
 while (onoffswitch == HIGH){
  
  digitalWrite(onAuto, HIGH);
  digitalWrite(onAlgo, LOW);
  onoffswitch = digitalRead(switch1Pin);
     while (i < 10 && j < 9 && onoffswitch == HIGH){   
        //AZIMUT AXIS
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        onoffswitch = digitalRead(switch1Pin); 
        delay(78);       
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);      
        //ELEVATION AXIS     
      if (j < 6){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);        
        onoffswitch = digitalRead(switch1Pin);  
        delay(60.5);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        onoffswitch = digitalRead(switch1Pin);
      }      
      onoffswitch = digitalRead(switch1Pin);   
      if (j >= 6){ 
      digitalWrite(IN2, HIGH);
      digitalWrite(IN1, LOW);
     onoffswitch = digitalRead(switch1Pin); 
      delay(20.5);
        digitalWrite(IN2, LOW);
        digitalWrite(IN1, LOW);
     onoffswitch = digitalRead(switch1Pin);
      }
      delay(1000);
       i = i + 1;
       j = j + 1;
      onoffswitch = digitalRead(switch1Pin);
  }//WHILE END
  if (i >= 8 &&  onoffswitch == HIGH){ 
  digitalWrite(IN3, HIGH); 
    onoffswitch = digitalRead(switch1Pin);  
   delay(937.5);  
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   
   digitalWrite(IN1, HIGH);   
   delay(550.8);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW); 
     onoffswitch = digitalRead(switch1Pin);
   delay(6000);
   i = 0;
   j = 0;
     onoffswitch = digitalRead(switch1Pin);
  }
     onoffswitch = digitalRead(switch1Pin);
 }}
 
