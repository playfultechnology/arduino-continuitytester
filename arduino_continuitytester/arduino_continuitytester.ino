/**
 * Arduino code to determine continuity between every possible pair of an array of wires 
 * Very useful for, e.g. determining the wiring of an unknown controller, e.g. Playstation DDR dance pad
 */

// Total number of pins to identify
const byte numPins = 16;

// Array of pins to which wires are connected
byte pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, A0, A1, A2, A3, A4, A5};

// 2D array to store connections found between pins
byte connections[numPins][numPins];

void setup() {
  // Start a serial connection to display results in Arduino IDE serial monitor
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);
  // Initialise all pins as INPUT_PULLUPs
  for(int i=0; i<numPins; i++){
    pinMode(pins[i], INPUT_PULLUP);
  }
}

// This function tests continuity between two pins
bool isConnected(byte outputPin, byte inputPin){
  // Every pin is connected to itself....
  if(outputPin == inputPin) { return true; }

  // Set one pin as OUTPUT, and write a LOW signal to it
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  // Ensure the other pin is set as an INPUT_PULLUP
  pinMode(inputPin, INPUT_PULLUP);

  // If the pins are connected, the input pin will read the LOW signal from the output pin
  // Otherwise, it will read the HIGH 5V from the pullup resistor
  bool isConnected = !digitalRead(inputPin);

  // Reset the pin mode
  pinMode(outputPin, INPUT_PULLUP);

  // Return the result
  return isConnected; 
}

void loop() {
  // Loop over every pair of pins
  for(int i=0;i<numPins;i++){
    for(int j=0;j<numPins; j++){
      // Don't test a pin against itself
      if(i==j) { continue; }
      // Test whether the pins are connected
      bool nowConnected = isConnected(pins[i], pins[j]);
      // Is the result different from the previous state for these pins?
      if(nowConnected != connections[i][j]) {
        // Update the stored value
        connections[i][j] = nowConnected;
        // Print the state change to the serial monitor
        Serial.print("Arduino pins ");
        if(pins[j] > 13){ Serial.print("A"); Serial.print(pins[j]-14); }
        else { Serial.print(pins[j]); }
        Serial.print("->");
        if(pins[i] > 13){ Serial.print("A"); Serial.print(pins[i]-14); }
        else { Serial.print(pins[i]); }
        Serial.print(": ");
        Serial.println(connections[i][j] ? "connected" : "not connected");
      }
    }
  }

  delay(100);
}
