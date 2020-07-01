


int zeroc = 2 ;
int  triac = 3 ; 
int vresistor = A0; // variable resistor
int brightness;
int vrpower = 7; 
 
void setup()
{
  Serial.begin(9600); 
pinMode(triac, OUTPUT);
pinMode(vresistor, INPUT);
pinMode(vrpower, OUTPUT); 
digitalWrite(vrpower, HIGH); 
attachInterrupt(0, angle, RISING);
}
 
void loop(){}
 
void angle(){
  brightness = analogRead(vresistor);
  brightness = map(brightness,0,1023,0,10000); 
  Serial.println(brightness); 
  delayMicroseconds(brightness);
  digitalWrite(triac, HIGH);
  delayMicroseconds(50);
  digitalWrite(triac, LOW);
}
