int mot1=9;
int mot2=6;
int mot3=5;
int mot4=3;

int enA=2;
int enB=10;
int leftIR=13;
int rightIR=12;
int voltIR=1;

int Left;
int Right;

void LEFT (void);
void RIGHT (void);
void STOP (void);

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);

  pinMode(leftIR,INPUT);
  pinMode(rightIR,INPUT);

  digitalWrite(voltIR,HIGH);
  
  
}

void loop() 
{
 
analogWrite(mot1,255);
analogWrite(mot2,0);
analogWrite(mot3,255);
analogWrite(mot4,0);

while(1)
{
  Left=digitalRead(leftIR);
  Right=digitalRead(rightIR);
  
  if(Left==0 && Right==1)
  LEFT();
  else if(Right==0 && Left==1)
  RIGHT();
}
}

void LEFT (void)
{
   analogWrite(mot3,0);
   analogWrite(mot4,30);
   
   
   while(Left==0)
   {
    Left=digitalRead(leftIR);
    Right=digitalRead(rightIR);
    if(Right==0)
    {
      int lprev=Left;
      int rprev=Right;
      STOP();
      while(lprev==Left&&rprev==Right)
      {
         Left=digitalRead(leftIR);
         Right=digitalRead(rightIR);
      }
    }
    analogWrite(mot1,255);
    analogWrite(mot2,0); 
   }
   analogWrite(mot3,255);
   analogWrite(mot4,0);
}

void RIGHT (void)
{
   analogWrite(mot1,0);
   analogWrite(mot2,30);

   while(Right==0)
   {
    Left=digitalRead(leftIR);
    Right=digitalRead(rightIR);
    if(Left==0)
    {
      int lprev=Left;
      int rprev=Right;
     STOP();
      while(lprev==Left&&rprev==Right)
      {
         Left=digitalRead(leftIR);
         Right=digitalRead(rightIR);
      }
    }
    analogWrite(mot3,255);
    analogWrite(mot4,0);
    }
   analogWrite(mot1,255);
   analogWrite(mot2,0);
}
void STOP (void)
{
analogWrite(mot1,0);
analogWrite(mot2,0);
analogWrite(mot3,0);
analogWrite(mot4,0);
  
}
