#include <Keypad.h>
#include <LiquidCrystal.h>
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns
int c=0;
int re=0;
int pos = 0;
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pin_rows[ROW_NUM] = {4,5,6,7}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {1,2,3}; //connect to the column pinouts of the keypad
int relay=8;
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
String password = "1234"; // change your password here
String input_password;
void setup(){
  lcd.begin(16, 2);
  input_password.reserve(32);
  pinMode(relay,OUTPUT);
}
void loop(){
  char key = keypad.getKey();
  if (key)
  {
    lcd.print("*");
    input_password+=key;
    c++;
  }
  if(c==4)
  {
  check(input_password);
  }
}
void check(String p)
{
  if(p==password)
  {
    lcd.setCursor(0, 0);
    lcd.clear();
    delay(500);
    lcd.print("pass correct");
    digitalWrite(relay,LOW);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    c=0;
    input_password="";
  } 
  else if(p=="****")
  {
    lcd.setCursor(0, 0);
    lcd.clear();
    delay(500);
    lcd.print("LOCKED");
    digitalWrite(relay,HIGH);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    c=0;
    input_password="";
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.clear();
    delay(500);
    lcd.print("pass incorrect");                                                                                                                                                 
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    c=0;
    input_password="";
  }
}
