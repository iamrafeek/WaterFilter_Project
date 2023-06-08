

int IRsensor = 3;
int hd;
int percentwater;
int relaypin =9;
int diff;
int LED = 13;
int i=1;


#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(relaypin, OUTPUT);
  pinMode (IRsensor, INPUT);
  pinMode (LED, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
  
}


void loop()
{
    int statussensor = digitalRead(IRsensor);
    ucs();
  
    if (statussensor == 0 && distance >3 ){
      digitalWrite(LED, HIGH);
      digitalWrite(relaypin, LOW);
      
      
      

   }
   else if( distance<3){
     digitalWrite(relaypin, HIGH);
   }

 
  else if(statussensor == 1)
  {
    digitalWrite(LED, LOW); // LED Low
    i=1;
    digitalWrite(relaypin, HIGH);
  }
  
}
void ucs() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
}