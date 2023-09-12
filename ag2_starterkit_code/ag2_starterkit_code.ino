// Define the constants
const float VCC = 5.0;  
const float alpha = 9.0 / 10000.0;
const float beta = 1.0 / 25.0;
const float offset = 0.0; // Offset parameter to adjust the 0 point (0 kPa). Adjust as needed based on your calibration data.

const int sensorPin = A0;  

void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog voltage from the sensor
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - VCC)
  float voltage = sensorValue * (VCC / 1023.0);

  // Calculate the pressure using the formula
  float pressure = ((voltage / VCC - beta) / alpha) - offset;

  // Print the pressure value to the Serial Monitor
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" kPa");

  // Wait for 100ms before reading again
  delay(100);
}
