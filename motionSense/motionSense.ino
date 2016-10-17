
//Trevor Gould

//#include <Process.h>

const int motionPin = 2; //Pin connected to the first motion detector
//const int motionPin1 = 4; //Pin connected to the second motion sensor 
const int ledPin = 13; //Led will turn on when video is played

void setup() {

  Serial.begin(9600);
  // The PIR sensor's output signal is an open-collector, 
  // so a pull-up resistor is required:
  pinMode(motionPin, INPUT_PULLUP);
  //pinMode(motionPin1, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
}
/*
void pinFunc(char x, int proximity){
  if (proximity == LOW){ // If the sensor's output goes low, motion is detected
    digitalWrite(ledPin, HIGH);
    Serial.print(x); 
    Serial.print("\n");
    Serial.print("Done");
    Serial.print("\n");
    delay(5000);
  }

}
*/
void loop() {
  delay(5000);//Gives time for motion sensor to start up, otherwise too sensitive 
  int proximity = digitalRead(motionPin);//Avoid declaring any global variables
  //int proximity1 = digitalRead(motionPin1);
  
  if (proximity == LOW){ // If the sensor's output goes low, motion is detected
    digitalWrite(ledPin, HIGH);
    Serial.print("c"); 
    Serial.print("\n");
    Serial.print("Done");
    Serial.print("\n");
    delay(5000);
    
  }/*else if(proximity1 == LOW){
    digitalWrite(ledPin, HIGH);
    Serial.print("d"); 
    Serial.print("\n");
    Serial.print("Done");
    Serial.print("\n");
    delay(5000);
  
    
  }*/
  else{
    digitalWrite(ledPin, LOW);
    
  }
}
