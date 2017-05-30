//precharge and motor relay software
//version 1.0
//written and developed by Jackson Walker
//225-5-2017

/*
 *This is the control software for the Ra X precharge board and relay control board
 * 
 * 
 * 
 */

    
  const int chrgLed = A1;
  const int onLineLed = 1;
  const int relayCtrl = A3;
  const int optoCtrl = A2;
  const int swCtrl = 0;
  
void setup() {

  //set up the outputs and the input
  pinMode(chrgLed, OUTPUT); //red
  pinMode(onLineLed, OUTPUT); //green
  pinMode(relayCtrl, OUTPUT);
  pinMode(optoCtrl, OUTPUT);
  pinMode(swCtrl, INPUT);

  
  digitalWrite(relayCtrl, LOW);
  digitalWrite(optoCtrl, LOW);
  digitalWrite(onLineLed, LOW);
  digitalWrite(chrgLed, LOW);
  while(digitalRead(swCtrl) == LOW) //if it's on during setup, it needs to be set to low before anything can happen
  {
      digitalWrite(onLineLed,HIGH);
      digitalWrite(chrgLed,HIGH);
      delay(80);
      digitalWrite(onLineLed,LOW);
      digitalWrite(chrgLed,LOW);
      delay(80);
  }
  
}

void loop() {
    /////////////////////INIT DISCONNECT////////////////////
    digitalWrite(relayCtrl, LOW);
    digitalWrite(optoCtrl, LOW);
    digitalWrite(onLineLed, LOW);
    digitalWrite(chrgLed,LOW);
    
    while (digitalRead(swCtrl) == HIGH) //while floating or high, also if we didn't already do inital switch loop
    {
      digitalWrite(chrgLed,HIGH);
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
  digitalWrite(optoCtrl, HIGH);
  if(digitalRead(swCtrl) == HIGH)  //if true, exit
  {
    blink(chrgLed,30,4);
    digitalWrite(optoCtrl, LOW); 
    digitalWrite(relayCtrl, LOW);
    digitalWrite(onLineLed, LOW);
    digitalWrite(chrgLed,LOW); 
    return;
  }
  blink(chrgLed, 250, 6);
  if(digitalRead(swCtrl) == HIGH)
  {
    blink(chrgLed,30,4);
    digitalWrite(optoCtrl, LOW); 
    digitalWrite(relayCtrl, LOW); 
    digitalWrite(onLineLed, LOW);
    digitalWrite(chrgLed,LOW);
    return;
  }
  digitalWrite(relayCtrl, HIGH);
  delay(250); //overlapping for a 4th second to allow it to 
  if(digitalRead(swCtrl) == HIGH)
  {
    blink(chrgLed,30,4);
    digitalWrite(optoCtrl, LOW); 
    digitalWrite(relayCtrl, LOW); 
    digitalWrite(onLineLed, LOW);
    digitalWrite(chrgLed,LOW);
    return;
  }
  digitalWrite(optoCtrl,LOW); //about 2.5 seconds
}

void blink(int sPin, int blinkDurationMS, int iCycles) //duration is 2x blinkDurationMS per cycle e.g. bdMS = 250 ms and cycles is 2 so total length will be 1 second
{
  for(int x=0; x<= iCycles; x++)
  {
    digitalWrite(sPin, HIGH);
    delay(blinkDurationMS);
    digitalWrite(sPin, LOW);
    delay(blinkDurationMS);
  }
}

void chkExit()
{
if(digitalRead(swCtrl) == HIGH)
  {
    blink(chrgLed,30,4);
    digitalWrite(optoCtrl, LOW); 
    digitalWrite(relayCtrl, LOW); 
    digitalWrite(onLineLed, LOW);
    digitalWrite(chrgLed,LOW);
    return;
  }
}




