#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
LiquidCrystal lcd2(13, 12, 11, 10, 9, 8);

#define echoPin 1  
#define trigPin 0
int led = A0;

long duration;  
int distance;


void setup(){
lcd.begin(20,4);
lcd2.begin(16,2);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode (led , OUTPUT);

}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 mili
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in mili 
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  lcd.setCursor(0,0);
  lcd.print("Air: 1atm PM: 2.5   ");
  
  
  lcd.setCursor(0,1);
  lcd.print("Soil:70F Moisture:25% ");

  lcd.setCursor(0,2);
  lcd.print("UV Index: 4 ");

  lcd.setCursor(2,3);
  lcd.print("Reading The data");

  lcd.setCursor(10,3);
  lcd.print(distance);


  lcd2.setCursor(0,0);
  lcd2.print("Rotation:        ");
  
  lcd2.setCursor(10,0);
  lcd2.print(distance);

  lcd2.setCursor(0,1);
  lcd2.print("Speed: 692,000km ");

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 

}
