// ==========================
// Stepper Motor Control Code 
// ==========================

const uint8_t ySTEP_PIN = 3;  // Arduino pin connected to STEP for Y-axis
const uint8_t yDIR_PIN  = 6;  // Arduino pin connected to DIR for Y-axis

const uint8_t xSTEP_PIN = 2;  // Arduino pin connected to STEP
const uint8_t xDIR_PIN = 5;   // Arduino pin connected to DIR

const uint8_t zSTEP_PIN = 4;  // Arduino pin connected to STEP for Z-axis
const uint8_t zDIR_PIN  = 7;  // Arduino pin connected to DIR for Z-axis

const uint8_t moistureSensorPin = A0; // Analog pin for soil moisture sensor
const uint8_t pumpPin = 8;          // Digital pin for water pump relay

// Stepper motor parameters
const unsigned long STEPS_PER_MM = 40;         // Number of steps needed to move 1 mm

const int STEP_DELAY_US = 1000;  // Microsecond delay between step pulses (controls speed)
const uint8_t fw =1;
const uint8_t bw =0;
void setup() {
  pinMode(pumpPin, OUTPUT);      // Set pump pin as output
  //Serial.begin(9600);            // Start serial communication 

  pinMode(xSTEP_PIN, OUTPUT);  // Set x-axis STEP pin as output
  pinMode(xDIR_PIN, OUTPUT);   // Set x-axis DIR pin as output
  pinMode(ySTEP_PIN, OUTPUT);  // Set y-axis STEP pin as output
  pinMode(yDIR_PIN, OUTPUT);   // Set y-axis DIR pin as output
  pinMode(zSTEP_PIN, OUTPUT);  // Set Z-axis STEP pin as output
  pinMode(zDIR_PIN, OUTPUT);   // Set Z-axis DIR pin as output

}

void loop() {
  for (uint8_t i=0; i<5; i++){
  moveStepper(xSTEP_PIN, xDIR_PIN,10, fw);  // Move forward 10 meters
  delay(1000); 
  for (uint8_t i=0; i<8; i++)
  {
  moveStepper(ySTEP_PIN,yDIR_PIN,10, fw);  // Move forward 10 meters
  delay(1000);
  moveStepper(zSTEP_PIN, zDIR_PIN,70, fw);          
  delay(3000);
  moisture();
    moveStepper(zSTEP_PIN, zDIR_PIN,70, bw);  
  } 
  moveStepper(xSTEP_PIN, xDIR_PIN,10, fw);          
   delay(1000); 
  for (uint8_t i=8; i>0; i--)
  {
  moveStepper(ySTEP_PIN,yDIR_PIN,10, bw);   // Move backward 10 meters
  delay(1000);  
  moveStepper(zSTEP_PIN, zDIR_PIN,70, fw);          
  delay(3000);
  moisture();
    moveStepper(zSTEP_PIN, zDIR_PIN,70, bw);  
  }              // Wait 1 second
  }
  moveStepper(xSTEP_PIN, xDIR_PIN,100, bw);          
  delay(1000);
}

// Moves the stepper motor for the given number of steps in a direction
void moveStepper(uint8_t Step_pin,uint8_t dir_pin, uint8_t dis, uint8_t direction) {
  uint16_t steps = 40*dis;
  digitalWrite(dir_pin, direction);  // Set motor direction
  for (uint16_t i = 0; i < steps; i++) {
    digitalWrite(Step_pin, HIGH);    // Create step pulse
    delayMicroseconds(STEP_DELAY_US);
    digitalWrite(Step_pin, LOW);
    delayMicroseconds(STEP_DELAY_US);
  }
}

void moisture(){
  uint8_t moistureValue = analogRead(moistureSensorPin); // Read moisture value
  //Serial.print("Moisture: ");
  //Serial.println(moistureValue);

if (moistureValue < 300) {
    digitalWrite(pumpPin, LOW);  // Turn pump ON if soil is dry
    //Serial.println("Pump ON");
    delay(5000); // Pump for 5 seconds (adjust as needed)
    digitalWrite(pumpPin, HIGH); // Turn pump OFF
    Serial.println("Pump OFF");
    delay(60000); // Wait 60 seconds before next reading
  } else if (moistureValue > 600) {
      digitalWrite(pumpPin, HIGH);
      Serial.println("Pump OFF");
      delay(60000); // Wait 60 seconds before next reading
  } else {
      digitalWrite(pumpPin, HIGH); //Turn pump OFF if soil is moist
      Serial.println("Pump OFF");
      delay(60000); // Wait 60 seconds before next reading
  }
}
