#include <Keypad.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38, 16, 2);
//SoftwareSerial Serial(2,3); 
int x=0;
char k[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};
byte rpins[4] = {4, 5, 6, 7};
byte cpins[4] = {8, 9, 10, 11};
Keypad kay(makeKeymap(k), rpins, cpins, 4, 4);
char myk;
int t_dis1=0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop() {
myk = kay.getKey();
  if(myk){
Serial.write(myk);
  if (myk== 'A') {
      lcd.clear();
      lcd.print("Forward");}
     else if (myk == 'B') {
      lcd.clear();
      lcd.print("Backward");}
    else if (myk == 'C') {
      lcd.clear();
      lcd.print("Stop");}
    else if (myk == '*') {
      lcd.clear();
      lcd.print("Left");}
     else if (myk == '#') {
      lcd.clear();
       lcd.print("Right");}
  else if (myk >= '0' && myk <= '9'){
    int t_dis = myk - '0';
    t_dis1 = (t_dis1 * 10) + t_dis;
     lcd.clear();
   lcd.print("distance ="+String(t_dis1)+" cm");Serial.print(t_dis1);}
  else if (myk == 'D') {
      x=(t_dis1*20);lcd.clear();
    lcd.print("distance ="+String(x)+"cm");
     Serial.print(x);
    }
  }
}    

