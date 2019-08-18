// set pin numbers for output devices:
const int led1 = A5;
const int led2 = A6;
const int led3 = A7;

const int relay[] = {A0, A1, A2};
//const int ESP8266_CHPD = 1;
// Variables will change:
int led1State = LOW;                    // ledState used to set the LED1
int led2State = LOW;                    // ledState used to set the LED2
int led3State = LOW;                    // ledState used to set the LED3
int relayState[] = {HIGH, HIGH, HIGH};  // Relay State - (Disconnected)

#define BUFFER_SIZE 256          // Set the Buffer Size (should be updated According to Arduino Board Type) 
char buffer[BUFFER_SIZE];

float previousMillis[] = {0, 0, 0, 0, 0};
float interval[] = {0, 0, 0, 0, 0};
String tempor = "";

const byte numRows = 4;               // keypad: four rows
const byte numCols = 4;               // keypad: four columns
char keymap[numRows][numCols] = {     // keypad: [numRows][numCols]
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {A15, A14, A13, A12}; // keypad: connect to the row pinouts of the keypad (Rows 0 to 3)
byte colPins[numCols] = {A11, A10, A9, A8}; // keypad: connect to the column pinouts of the keypad (Columns 0 to 3)
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
String ch = "X";
