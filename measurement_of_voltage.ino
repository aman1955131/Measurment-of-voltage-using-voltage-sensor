int analogPin = A0; // Analog input pin connected to VOUT of ZMPT101B module
float Vin_max = 50.0; // Maximum voltage to be measured (50V DC in this case)
float Vout_max = 5.0; // Maximum output voltage range of voltage divider circuit (5V for Arduino analog input)
float Rdiv = 10.0; // Equivalent resistance of voltage divider circuit (10kohm + 10kohm in this case)

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(analogPin); // Read analog input value
  float Vout = sensorValue * 5.0 / 1023.0; // Convert analog input value to voltage
  float Vin = Vout / Vscale; // Calculate input voltage using scaling factor
  Serial.print("Input voltage: ");
  Serial.print(Vin);
  Serial.println(" V");
  delay(1000); // Wait for 1 second
}

// Function to calculate scaling factor based on voltage divider circuit and ZMPT101B module input voltage range
float Vscale() {
  return Vin_max / Vout_max / Rdiv;
}
