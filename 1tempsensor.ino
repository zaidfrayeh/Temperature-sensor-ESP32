const int red = 25;
const int orange = 27;
const int green = 26;
const int tempSensorPin = 34;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(tempSensorPin, INPUT);
  Serial.begin(115200); // Start the serial communication
}

void loop() {
 
  int sensorValue = analogRead(tempSensorPin);
  // Convert the analog reading (which goes from 0 - 4095) to a voltage (0 - 3.3V)
  float voltage = sensorValue * (3.3 / 4095.0);
  // Convert the voltage to temperature in Celsius
  float temperature = (voltage - 0.4) * 100; // Subtract the offset and convert
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(orange, LOW);

  if (temperature <= 21) {
    digitalWrite(orange, HIGH); // Cooler temperatures
  } else if (temperature > 21 && temperature <= 25) {
    digitalWrite(green, HIGH); // Moderate temperatures
  } else {
    digitalWrite(red, HIGH); // Warmer temperatures
  }

  delay(1000);  
}
