const int buttonPin = 2;
const int ledD = 3;

String input;
int pwm = 0;

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(ledD, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() {
    if(Serial.available()){
        input = Serial.readStringUntil('\n');
        Serial.print("You typed: " );
        Serial.println(input);
        pwm = input.toInt();
        Serial.println(pwm);
    }
  
  //delay(1000);

  
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    // turn LED on:
    //Serial.println("On");
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage LOW
    analogWrite(ledD, pwm);
    //digitalWrite(ledD, HIGH);    // turn the LED off by making the voltage LOW
    
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   // Serial.println("Off");
    analogWrite(ledD, 0);
    //digitalWrite(ledD, LOW);    // turn the LED off by making the voltage LOW
  }
}
