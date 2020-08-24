#include "Header.h"
#include "functionPrototype.h"
#include "initial.h"
#include "alarm.h"
#include "indicator.h"
#include "operation.h"
void setup() {
  initial();
  lcd.begin(); //เรียกใช้ function begin()ของ object lcd เพื่อกำหนดค่าเริ่มต้นของการทำงานของจอ lcd
  lcd.setCursor(0,0);//กำหนดcusorการเขียนข้อมูลลงจอlcdให้เป็นบรรทัดแรกตัวอักษรแรก
  lcd.print("Initial Val");//ปริ้นขอความลองlcd
  digitalWrite(Y_indicator,indicator_on);//สั่งขา Y_indicator ให้เป็นสถานะ on เพื่อให้ led สีเหลืองติด
  //#ifdef debug
  //Serial.begin(9600);
  //Serial.printf("%d\n",10);
  //#endif
  delay(1000);//ดีเลย์ 1วิ
}

void loop() {
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Mole_curent_state=digitalRead(Mole_Lswitch);//อ่าสถานะของโมลว่ามีการกดหรือไม่ถ้าโมลมีการกดกันจะมีสถานะเป็น 0 เมื่อไม่มีการกดโมลจะมีสถานะ 1
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //เงือนไขถ้ามีการกดปุ่ม option จะมีการเปลี่ยนโหมดจากโหมด 0 เป็น โหมด 1 และถ้ากดปุ่ม option ซ้ำจะกลับคืนเป็นโหมด 0 ดังเดิม 
  //หลังจากเปลี่ยนโหมดแล้วจะทำการอ่านค่าจาก eeprom ไปเก็บในตัวแปร limiter_buffer
  if(button_Set_pin.ReadState() == LOW)
  {
    ++Mode;
    if(Mode>2)
      Mode=0;
    limiter_buffer = EEPROM.read(0);
    buffer_setMole_Temp = EEPROM.read(1);
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(millis()-pre_tempurature_time>=1000)//ดึงเวลาจาก timer ของ mcu ด้วยฟังชั่น millis() เพื่อมาตรวจสอบว่าเวลาผ่านไป 1 วิหรือไม่ถ้าผ่านไป 1 วิให้ทำการอ่านค่าอุณหภูมิ
  {
    Mole_celsius = thermocouple.readCelsius();//อ่านค่าอุณหภูมิเก็บไว้ในตัวแปร Mole_celsius
    pre_tempurature_time=millis();//ดึงเวลาจาก timer ของ mcu ด้วยฟังชั่น millis()มาเก็บไว้ในตัวแปร pre_tempurature_time เพื่อใช้ในการเปรียบเทียบเวลาครั้งถัดไป
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  alarm_check();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //#ifdef debug
  //Serial.printf("curent alarm %d\n",curent_alarm);
  //#endif
  //เงื่อนไขถ้าโมลไม่ถูกกดและAlarmจากระบบ pid เป็น 1 หรือก็คืออุณหภูมิอยู่ในช่วงที่ตั้งไว้ให้ led สีเขียวติดแดงดับ แต่หากไม่ใช่ให้แดงติดเขียวดับ
  lamp_indicator();
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Serial.println(Mode);
  //เงื่อนไขหากโหมดเป็นโหมด 1 จะเปลี่ยนการแสดงผลจากแสดงเวลานับถอยหลังและอุณหภูมิเป็นแสดงผลการตั้งค่าเเวลาในการนับถอยหลังแทน
  switch(Mode)
  {
    case 0:
    {
      Operation();
      break;
    }
    break;
    case 1:
    {
      opstion1_setting_time("Time Limiter Set","Value = ",&limiter_buffer,&time_limiter,0);
      break;
    }
    break;
    case 2:
    {
      opstion2_setting_temp("Temp Limiter Set","Value = ",&buffer_setMole_Temp,&setMole_Temp,1);
      break;    
    }
    default:
    break;
  }
  delay(5);
}
