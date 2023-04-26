int mesure_distance_cm(byte trig_pin,byte dist_pin)
{
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin,LOW);
  int value = (pulseIn(dist_pin,HIGH)/2/29.1+2);
  if (value>255) { value=255; }
  delay(200);
  return value;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(6,INPUT);
  pinMode(8,OUTPUT);
  pinMode(10,INPUT);
  pinMode(3,OUTPUT);  
  pinMode(2,OUTPUT);
  pinMode(12,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (mesure_distance_cm(4,6) >= 30) {
    digitalWrite(3, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(12, LOW); 
    //delay(5000);
  } else {
    digitalWrite(3, HIGH);
    delay(5000);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    delay(5000);
    digitalWrite(2, LOW);
    digitalWrite(12, HIGH);
    delay(16000);
    digitalWrite(12, LOW);
  }
}
