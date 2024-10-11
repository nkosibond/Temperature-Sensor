// C++ code
//
int i = 0;
 
int buttonState = 0;
int buttonPin = 5;
int redLed = 2;
int yellowLed = 3;
int greenLed = 4;
const int tempsensorPin = A0;
const float baselineTemp = 21.0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  
  /*digitalWrite(redLed, HIGH);
  delay(3000);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(3000);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(3000);
  digitalWrite(greenLed, LOW);*/
}

void loop()
{
  int sensorVal = analogRead(tempsensorPin);
  Serial.println(sensorVal);
  
  
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  
  Serial.print(", Volts: ");
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  
  buttonState = digitalRead(buttonPin);
  
  //green light goes on when temp below 20
  if (temperature < 20) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } //yellow light goes on when temp between 20 and 30
  else if (temperature >= 20 && temperature < 30) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  } //red light goes on when temp above 30
  else if(temperature > 30) {
    for (int i = 0; i < 1000; ++i) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(200);
    digitalWrite(redLed, LOW);
      delay(200);}
}

  
  //button will switch everything Off
  if (buttonState, LOW) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    temperature = 0;
    sensorVal =0;
    voltage = 0;
  }
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}