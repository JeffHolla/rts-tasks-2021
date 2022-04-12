# define ENABLE_PIN 8 // stepper motor enable , active low
# define X_DIR 5 // X -axis stepper motor direction control
# define Y_DIR 6 // y -axis stepper motor direction control
# define Z_DIR 7 // z axis stepper motor direction control
# define X_STP 2 // x -axis stepper control
# define Y_STP 3 // y -axis stepper control
# define Z_STP 4 // z -axis stepper control
# define SPEED_INTERVAL 20

#include <TaskManagerIO.h>

bool isEnabledPinX = false;
bool isEnabledPinZ = false;

void ChangeStateX() {
    digitalWrite(X_STP, isEnabledPinX);
    isEnabledPinX = !isEnabledPinX;           
}

void ChangeStateZ() {
    digitalWrite(Z_STP, isEnabledPinZ);
    isEnabledPinZ = !isEnabledPinZ;           
}

void setup() {
  pinMode (X_DIR, OUTPUT); 
  pinMode (X_STP, OUTPUT);
  pinMode (Z_DIR, OUTPUT); 
  pinMode (Z_STP, OUTPUT);
  
  pinMode (ENABLE_PIN, OUTPUT);
  
  digitalWrite (ENABLE_PIN, LOW);
  
  taskManager.scheduleFixedRate(SPEED_INTERVAL, ChangeStateX, TIME_MICROS);
  taskManager.scheduleFixedRate(SPEED_INTERVAL, ChangeStateZ, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}