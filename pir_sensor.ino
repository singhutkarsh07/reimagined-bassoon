int in1 = 9;
int sensor = 8;
unsigned long t=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(sensor, INPUT);
  
  
  digitalWrite(in1,HIGH);
  
}


void loop() 
{
  digitalWrite(in1,HIGH);
  if(digitalRead(sensor)==HIGH)
  {
   t=millis();
   while(millis()<(t+5000))
   {
   digitalWrite(in1,LOW);
     if((millis()>(t+2300))&&(digitalRead(sensor)==HIGH))
      {
       t=millis();
      }
   }
  }
}
