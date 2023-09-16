#include <SoftwareSerial.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38, 16, 2);
//SoftwareSerial Serial(2,3); 
char reading;int t_dis1=0,x;
const int IN[] = { 4, 5, 6, 7 };

void setup() {
  for(int i=0;i<sizeof(IN);i++)
  pinMode(IN[i], OUTPUT);
  
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
 // Serial.println("mm");
}

void loop() {
  if (Serial.available()>0) {
    reading = Serial.read();
    Serial.println(reading);
    if (reading== 'A') {
      lcd.clear();
      lcd.print("Forward");
      digitalWrite(IN[1], HIGH);
      digitalWrite(IN[3], HIGH);
      digitalWrite(IN[2], 0);
      digitalWrite(IN[0], 0);
    } else if (reading == 'B') {
      lcd.clear();
      lcd.print("Backward");
      digitalWrite(IN[0], HIGH);
      digitalWrite(IN[2], HIGH);
      digitalWrite(IN[1], 0);
      digitalWrite(IN[3], 0);
    } else if (reading == 'C') {
      lcd.clear();
      lcd.print("Stop");
      digitalWrite(IN[3], 0);
      digitalWrite(IN[0], 0);
      digitalWrite(IN[1], 0);
      digitalWrite(IN[2], 0);
    } else if (reading == '*') {
      lcd.clear();
      lcd.print("Left");
      digitalWrite(IN[3], HIGH);
      digitalWrite(IN[0], 0);
      digitalWrite(IN[1], 0);
      digitalWrite(IN[2], 0);
    } else if (reading == '#') {
      lcd.clear();
      lcd.print("Right");
      digitalWrite(IN[1], HIGH);
      digitalWrite(IN[0],0);
      digitalWrite(IN[3], 0);
      digitalWrite(IN[2], 0);
    }else if(reading >= '0'&& reading <='9'){ 
      while(x==0)x= Serial.parseInt();
      lcd.clear(); lcd.print("distance ="+String(x)+" cm");               
      }
    else if(reading == 'D'){x= Serial.parseInt();while(x==0)x= Serial.parseInt();
      lcd.clear();
      lcd.print("distance ="+String(x)+"cm");
      digitalWrite(IN[1], HIGH);
      digitalWrite(IN[3], HIGH);
      digitalWrite(IN[0], 0);
      digitalWrite(IN[2], 0);
      delay(x);
      digitalWrite(IN[3], 0);
      digitalWrite(IN[0], 0);
      digitalWrite(IN[1], 0);
      digitalWrite(IN[2], 0);
    }
  }
}
