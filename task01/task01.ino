#define ledPin1 11
#define ledPin2 10
#define ledPin3 9
#define ledPin4 6
#define ledPin5 5
#define ledPin6 3

#define interval_333 333
#define interval_33 33
#define interval_3 3
#define interval_133 133

 
// For each
// 333ms / 33ms / 3ms / 333mcs / 133mcs
 
int ledState = LOW;
 
long leds[6][3];
 
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
 
  leds[0][0] = ledPin1;// pin index
  leds[1][0] = ledPin2; 
  leds[2][0] = ledPin3;
  leds[3][0] = ledPin4;
  leds[4][0] = ledPin5;
  leds[5][0] = ledPin6;
 
  for(int i = 0; i<6; ++i){
    leds[i][1] = LOW;// pin voltage(state)
    leds[i][2] = 0;// pin micros/millis last
  }
 
  Serial.begin(9600);
}
 
void loop() {
  for(int i = 0; i < 6; ++i){
      Blink(leds[i][0], i);
  }

//Blink(leds[3][0], 3);
}
 
void Blink(int led, int ledIndex){
  
//  if(ledIndex == 3){
//  Serial.print("Led power : ");
//  Serial.print(leds[ledIndex][1]);
//  Serial.print("LedIndex : ");
//  Serial.print(ledIndex);
//  Serial.print("Millis : ");
//  Serial.print(millis());
//  Serial.print(" | ");
//  Serial.print("Micros : ");
//  Serial.print(micros());
//  Serial.print(" | ");
//  Serial.print('\n');
//    Serial.print(leds[ledIndex][2]);
//  Serial.print('\n');
//  }
  long currentMillis = millis();
  long currentMicros = micros();
 
  switch(led) {
        case ledPin1:  //11
        if(currentMillis - leds[ledIndex][2] > interval_333 ){
          if(leds[ledIndex][1] == HIGH){
            leds[ledIndex][1] = LOW;
          }
          else{
            leds[ledIndex][1] = HIGH;
          }
          leds[ledIndex][2] = currentMillis;
        }
        digitalWrite(ledPin1, leds[ledIndex][1]);
            break;
 
        case ledPin2:
        if(currentMillis - leds[ledIndex][2] > interval_33){
          if(leds[ledIndex][1] == HIGH){
            leds[ledIndex][1] = LOW;
          }
          else{
            leds[ledIndex][1] = HIGH;
          }
          leds[ledIndex][2] = currentMillis;
        }
        digitalWrite(ledPin2, leds[ledIndex][1]);
            break;
 
        case ledPin3:
        if(currentMillis - leds[ledIndex][2] > interval_3){
          if(leds[ledIndex][1] == HIGH){
            leds[ledIndex][1] = LOW;
          }
          else{
            leds[ledIndex][1] = HIGH;
          }
          leds[ledIndex][2] = currentMillis;
        }
        digitalWrite(ledPin3, leds[ledIndex][1]);
            break;
 
        case ledPin4:
        if(currentMicros - leds[ledIndex][2] > interval_333){
          if(leds[ledIndex][1] == HIGH){
            leds[ledIndex][1] = LOW;
          }
          else{
            leds[ledIndex][1] = HIGH;
          }
          Serial.print('\n');
          Serial.print(currentMicros - leds[ledIndex][2]);
          Serial.print('\n');
          
          leds[ledIndex][2] = currentMicros;
        }
        digitalWrite(ledPin4, leds[ledIndex][1]);
            break;
 
        case ledPin5:
        if(currentMicros - leds[ledIndex][2] > interval_133){
          if(leds[ledIndex][1] == HIGH){
            leds[ledIndex][1] = LOW;
          }
          else{
            leds[ledIndex][1] = HIGH;
          }
          leds[ledIndex][2] = currentMicros;
        }
        digitalWrite(ledPin5, leds[ledIndex][1]);
            break;
 
//        case ledPin6:
//        if(currentMicros - leds[ledIndex][2] > 1){
//          if(leds[ledIndex][1] == HIGH){
//            leds[ledIndex][1] = LOW;
//          }
//          else{
//            leds[ledIndex][1] = HIGH;
//          }
//          leds[ledIndex][2] = currentMicros;
//        }
//        digitalWrite(ledPin6, leds[ledIndex][1]);
//            break;
    }
}
 
