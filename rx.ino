#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11); // RX | TX

int righta = 9;
int rightb = 6;

int lefta = 3;
int leftb = 5;


unsigned long interval = millis();
int connection = 7;
void setup() {

  pinMode(connection,OUTPUT);
  digitalWrite(connection,HIGH);
  pinMode(righta,OUTPUT);
pinMode(rightb,OUTPUT);
pinMode(lefta,OUTPUT);
pinMode(leftb,OUTPUT);

analogWrite(righta,0);
analogWrite(rightb,0);
analogWrite(lefta,0);
analogWrite(leftb,0);
  
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(13,OUTPUT);
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
}


void forward(){

  analogWrite(righta,100);
  analogWrite(rightb,0);

  analogWrite(lefta,100);
  analogWrite(leftb,0);
}

void backward(){
    analogWrite(righta,0);
  analogWrite(rightb,100);

  analogWrite(lefta,0);
  analogWrite(leftb,100);
}

void left(){
    analogWrite(righta,120);
    analogWrite(rightb,0);

  analogWrite(lefta,0);
  analogWrite(leftb,120);
}
void right(){
  analogWrite(righta,0);
    analogWrite(rightb,120);

  analogWrite(lefta,120);
  analogWrite(leftb,0);
}

void stay(){
   analogWrite(righta,0);
    analogWrite(rightb,0);

  analogWrite(lefta,0);
  analogWrite(leftb,0);
}
unsigned long number = 0;
void loop() {
  // put your main code here, to run repeatedly:


if(millis() - interval >500){
  digitalWrite(connection,HIGH);
  stay();
  interval = millis();
}

if (BTSerial.available() >0){

  digitalWrite(connection,LOW);
  interval = millis();
  char data = BTSerial.read();
  Serial.println(data);
  if (data == 'F'){
    
    
    Serial.println("Forward");
    forward();
  }
  if (data == 'B'){
    
    
    Serial.println("Backwards");
    backward();
  }
  if (data == 'L'){
    
    
    Serial.println("Left");
    left();
  }
  if (data == 'R'){
   
    
    Serial.println("Right");
    right();
    
  }
  if (data == 'S'){
    
    
    Serial.println("STOP");
    stay();
  }
  
}
}
