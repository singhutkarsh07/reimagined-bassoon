//Gas sensor
float sensor=A1;
float gas_value;
float gas_value_threshold=700;
//Distance sensor 
#define trigPin 9
#define echoPin 10
int Buzzer = 8; // Connect buzzer pin to 8
int ledPin= 6;  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   //dist sensor
   pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);

  //gas sensor
  pinMode(sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 


//Gas sensor
gas_value=analogRead(sensor);
Serial.print("Amount of gas present in PPM: ");
Serial.print(gas_value);
Serial.println("");


//Dist sensor

 digitalWrite(trigPin, HIGH);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2 ;
    //when distance is greater than or equal to 50 OR less than or equal to 0,the buzzer and LED are off
  if (distance <= 50 && distance >= 0) 
        {
        Serial.print("Object detected at: ");
        Serial.print(distance);
        Serial.println(" ");
        Serial.println(" ");
        digitalWrite(Buzzer,HIGH);
        digitalWrite(ledPin,HIGH);
        }
  else{
       Serial.print("No object detected and distance is: ");
        Serial.print(distance);
        Serial.println(" ");
        Serial.println(" ");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
  }

}
