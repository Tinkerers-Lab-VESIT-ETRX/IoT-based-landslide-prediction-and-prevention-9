const int echo_pin=3;
const int ping_Pin=4;

void setup() {
    
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ping_Pin,OUTPUT);
pinMode(echo_pin,INPUT);

}

void loop() {
  long duration, inches, cm;
  
  digitalWrite(ping_Pin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(ping_Pin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(ping_Pin, LOW);
  
  duration = pulseIn(echo_pin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method
  
  
 
  
  Serial.print("cm=");
  Serial.print(cm);
  Serial.println();
  
  delay(500);
}
long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
  
}
