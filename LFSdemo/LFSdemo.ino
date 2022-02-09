#include<SoftwareSerial.h>
SoftwareSerial BTserial(10,11); // RX | TX
int a,b,c,d,e,f;
char A,B,C,D,E,F; 
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600);
  
  pinMode(2, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=analogRead(A5);
  b=analogRead(A4);
  c=analogRead(A3);
  d=analogRead(A2);
  e=analogRead(A1);
  f=analogRead(A0);

  digitalWrite(2, HIGH);

  if(a>500) A='B';
  else A='W';
  if(b>500) B='B';
  else B='W';
  if(c>500) C='B';
  else C='W';
  if(d>500) D='B';
  else D='W';
  if(e>500) E='B';
  else E='W';
  if(f>500) F='B';
  else F='W';

if(A=='B'&&B=='B'&&C=='W'&&D=='W'&&E=='B'&&F=='B'){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 10);
  analogWrite(enB, 10);
  }
  else {
    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
  
  Serial.print(A);
  Serial.print(B);
  Serial.write(C);
  Serial.write(D);
  Serial.write(E);
  Serial.write(F);
  Serial.println();
  BTserial.write(A);
  BTserial.write(B);
  BTserial.write(C);
  BTserial.write(D);
  BTserial.write(E);
  BTserial.write(F);
    BTserial.print(";");
    delay(500);

}
