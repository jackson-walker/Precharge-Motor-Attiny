//precharge and motor relay software
//version 1.0
//written and developed by Jackson Walker
//28-2-2017

    
  const int chrgLed = A1;
  const int onLineLed = 1;
  const int relayCtrl = A3;
  const int optoCtrl = A2;
  const int swCtrl = 0;
  int blinker = 0;
  bool ison = true;
  
void setup() {

  //set up the outputs and the input
  pinMode(chrgLed, OUTPUT); //red
  pinMode(onLineLed, OUTPUT); //green
  pinMode(relayCtrl, OUTPUT);
  pinMode(optoCtrl, OUTPUT);
  pinMode(swCtrl, INPUT);
  

 
  
}

void loop() {

    while (digitalRead(swCtrl) == HIGH)
    {
      
      if(blinker == 7000)  //blinks slow to indicate not latched
      {
        if(ison == true)
        {
          digitalWrite(chrgLed, LOW);
          ison = false;
        }
        else
        {
          digitalWrite(chrgLed,HIGH);
          ison = true;
        } 
        blinker = 0;
      }  // end outer if
      blinker = blinker + 1;  //memes      
    } //end while
    
  
    digitalWrite(optoCtrl, HIGH);
    digitalWrite(relayCtrl, HIGH);
    digitalWrite(chrgLed, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(onLineLed, HIGH);
    delay(250);              // wait for a second
    digitalWrite(chrgLed, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(onLineLed, LOW);

    delay(250);              // wait for a second

}
