#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LiquidCrystal_I2C.h>

Adafruit_ADXL345_Unified accel(12345);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const float displacementScale = 0.5;
const float accelerationScale = 0.01;
const int calibrationSamples = 100; // Number of samples for calibration
const float vibrationThreshold = 0.5; // Adjust this threshold based on your environment

bool isCalibrated = false;
float initialAcceleration = 0.0;
unsigned long calibrationStartTime = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);

  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while (1);
  }

  accel.setRange(ADXL345_RANGE_16_G);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating...");
  calibrate();
}

void loop() {
  if (isCalibrated) {
    displayReadings();
  }
}

void calibrate() {
  float sumAcceleration = 0.0;

  // Collect samples for calibration
  for (int i = 0; i < calibrationSamples; ++i) {
    sensors_event_t event;
    if (accel.getEvent(&event)) {
      sumAcceleration += event.acceleration.x;
      delay(10); // Delay between samples
    }
  }

  // Calculate the average acceleration
  initialAcceleration = sumAcceleration / calibrationSamples;
  isCalibrated = true;
  Serial.println("Calibration completed.");
  delay(200);
}

void displayReadings() {
  sensors_event_t event;
  if (accel.getEvent(&event)) {
    float acceleration_x = event.acceleration.x - initialAcceleration;

    // Only display readings when the vibration exceeds the threshold
    if (abs(acceleration_x) > vibrationThreshold) {
      float displacement = displacementScale * 0.5 * acceleration_x * millis() * millis() / 1000.0 / 1000.0;

      Serial.print("Acceleration: ");
      Serial.print(acceleration_x);
      Serial.print(" m/s²\t");

      Serial.print("Displacement: ");
      Serial.print(displacement * 1000, 2);
      Serial.println(" mm");

      delay(200);

      lcd.clear();
      delay(10);
      lcd.setCursor(0, 0);
      lcd.print("Disp: ");
      lcd.print(displacement * 1000, 2);
      lcd.print(" mm");

      lcd.setCursor(0, 1);
      lcd.print("Accln: ");
      lcd.print(acceleration_x, 2);
      lcd.print(" m/s²");

      delay(500);
    }
  }
}

