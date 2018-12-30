#define trigPin 9
#define echoPin 10
int Buzzer = 8; // Connect buzzer pin to 8
int ledPin= 6;  //Connect LEd pin to 6
int duration, distance; //to measure the distance and time taken 
float sensor=A0;
float gas_value;
float threshold = 1000;

void setup() {
        Serial.begin (9600); 
        //Define the output and input objects(devices)
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);
        pinMode(sensor,INPUT);
}

void loop() {
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    gas_value=analogRead(sensor);
  if (gas_value >= threshold || gas_value <= 0)
        { 
        Serial.println(gas_value);
        digitalWrite(Buzzer,HIGH);
        digitalWrite(ledPin,HIGH);
        }
  else {
        Serial.println("gas level out of range");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);    
  }
    //when distance is greater than or equal to 50 OR less than or equal to 0,the buzzer and LED are off
  if (distance >= 50 || distance <= 0) 
        {  
        Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        Serial.println("object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);        //prints the distance if it is between the range 0 to 200
        tone(Buzzer,400);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin,HIGH);
       }
}
