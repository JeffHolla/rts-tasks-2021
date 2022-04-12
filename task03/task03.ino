# define EN 8 // stepper motor enable , active low
# define X_DIR 5 // X -axis stepper motor direction control
# define Y_DIR 6 // y -axis stepper motor direction control
# define Z_DIR 7 // z axis stepper motor direction control
# define X_STP 2 // x -axis stepper control
# define Y_STP 3 // y -axis stepper control
# define Z_STP 4 // z -axis stepper control
# define SPEED_INTERVAL 20

struct Engine{
  bool dir;
  int stepperPin;
  unsigned long previousMicros;
  unsigned long interval; 
  int state;
};

struct Engine engines[] = {
  false, X_STP, 0, SPEED_INTERVAL, LOW,
  false, Z_STP, 0, SPEED_INTERVAL, LOW
};

void setup () {
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  //pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);

//  Serial.begin(9600);
}

// -----------------------------------------
//
// Сделать на таймерах!
//
// -----------------------------------------
void loop () {
  
  unsigned long currentMicros = micros();
//
//  Serial.print(currentMicros);
//  Serial.print('\n');
//  
  digitalWrite (engines[0].stepperPin, false);
  digitalWrite (engines[1].stepperPin, false);
    
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 100; j++)
  {
    delayMicroseconds (50);
//      Serial.print("Engine [");
//      Serial.print(i);
//      Serial.print("], Micros of this Engine = ");
//      Serial.print(engines[i].previousMicros);
//      Serial.print('\n');
//      Serial.print("Engine state = ");
//      Serial.print(engines[i].state); 
//      Serial.print('\n');
//      
      delayMicroseconds (20);
      digitalWrite(engines[i].stepperPin, HIGH);
      delayMicroseconds (20);
      digitalWrite(engines[i].stepperPin, LOW);
    }
  }
}
