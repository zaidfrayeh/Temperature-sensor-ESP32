# Temperature-sensor-ESP32
this is a Temperature sensor which gives out Digital values on the console as well as LEDS depending on the temperature range 
21C and below turns on the orange LED 
between 22 and 25 green 
26 and above is red 
I used the ESP32 controller with MCP 9701 TEMPERATURE SENSOR

https://github.com/zaidfrayeh/Temperature-sensor-ESP32/assets/170974361/d0f61687-5fe9-43dd-a92d-7dc9a07566b4
++++++++++++++++++++++++++++++++++++++CODE++++++++++++++++++++++++++++++++++++++++++++++++++


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
