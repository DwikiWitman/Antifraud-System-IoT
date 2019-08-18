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
const byte interruptPin = 2;
int isActiveKeypad = 0;
String str;
String str3;
String str4;
String ch = "X";
String qr_code = "0016";
String id_stylist = "";
const int fraud_time = 90;
const int extend_time = 30;
int pinKursi[] = {A0, A1, A2};
int pinLed[] = {A5, A6, A7};
int timeLeft[] = {0, 0, 0};
//int counter = 0;
char keymapNumber[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


unsigned long previousMillis[] = {0, 0, 0, 0, 0};
int interval[] = {0, 0, 0, 0, 0};
String str2;
String kursi_temp;
