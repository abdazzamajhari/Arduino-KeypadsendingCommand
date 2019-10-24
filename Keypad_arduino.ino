#include <Keypad.h>

//before you verify and upload you need to add libraries
//Tools -> manage libraries -> search for Keypad by Mark Standley and Alexander Brevig

//define ROWS and COLUMNS in your numpad, in here i use 4x4 Membran keypad
const byte ROWS = 4;
const byte COLS = 4;

//define the key map on the keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

//jumper connection with your arduino
byte rowPins[ROWS] = {9,8,7,6}; 
byte colPins[COLS] = {5,4,3,2};

//command for library forkeypad
//initializes an instance of the keypad class
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup(){
  Serial.begin(9600); //initializing serial monitor
}

//if key is pressed, the key is stored in 'keypressed' variable
//if key is not equal to 'NO_KEY', then this key is printed out
void loop(){
  char keypressed = keypad.getKey();
  if (keypressed != NO_KEY){
    Serial.println(keypressed);
  }
}
