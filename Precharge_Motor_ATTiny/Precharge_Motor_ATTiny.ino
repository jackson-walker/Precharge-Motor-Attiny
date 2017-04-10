//precharge and motor relay software
//version 1.0
//written and developed by Jackson Walker
//28-2-2017

    
  const int chrgLed = A1;
  const int onLineLed = 1;
  const int relayCtrl = A3;
  const int optoCtrl = A2;
  const int swCtrl = 0;
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
    /////////////////////INIT DISCONNECT////////////////////
    digitalWrite(relayCtrl, LOW);
    digitalWrite(optoCtrl, LOW);
    digitalWrite(onLineLed, LOW);
    
    while (digitalRead(swCtrl) == HIGH) //while floating or high
    {
      delay(2000);
      digitalWrite(chrgLed,HIGH);
      delay(250);
      digitalWrite(chrgLed,LOW);
    
    } //end while
      
    prechargeFunc();
      
    while(digitalRead(swCtrl) == LOW) //relay control will be high
    {
      digitalWrite(chrgLed, LOW);
      digitalWrite(onLineLed, HIGH);
    } //end while swctrol low
}// end loop

void prechargeFunc()
{
  digitalWrite(optoCtrl HIGH); 
  blink(chrgLed, 25,0, 6);
  digitalWrite(relayCtrl, HIGH);
  delay(250); //overlapping for a 4th second to allow it to 
  digitalWrite(optoCtrl,LOW); //about 2.5 seconds
}

void blink(int sPin, int blinkDurationMS, int duration) //duration is 2x duration MS per blink cycle
{
  for(int x=0; x<= duration; x++)
  {
    digitalWrite(sPin, HIGH);
    delay(blinkDurationMS);
    digitalWrite(sPin, LOW);
    delay(blinkDurationMS);
  }
}

