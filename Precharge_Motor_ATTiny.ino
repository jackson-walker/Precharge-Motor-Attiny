//precharge and motor relay software
//version 1.0
//written and developed by Jackson Walker
//28-2-2017

    
  const int chrgLed = A1;
  const int onLineLed = 1;
  const int relayCtrl = A3;
  const int optoCtrl = A2;
  const int swCtrl = 0;
  
void setup() {

  //set up the outputs and the input
  pinMode(chrgLed, OUTPUT);
  pinMode(onLineLed, OUTPUT);
  pinMode(relayCtrl, OUTPUT);
  pinMode(optoCtrl, OUTPUT);
  pinMode(swCtrl, INPUT);

 
  
}

void loop() {

    
  // put your main code here, to run repeatedly:
    digitalWrite(optoCtrl, HIGH);
    digitalWrite(relayCtrl, HIGH);
    digitalWrite(chrgLed, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(onLineLED, HIGH);
    delay(250);              // wait for a second
    digitalWrite(chrgLed, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(onLineLED, LOW);

    delay(250);              // wait for a second

}
