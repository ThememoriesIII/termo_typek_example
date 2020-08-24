#include "functionPrototype.h"
void Option_base(char* string_col0, char* string_col1, byte* buffer_variable, byte* true_variable, byte index) {
  if (button_up_pin.ReadState() == LOW)
    ++(*buffer_variable);
  if (button_down_pin.ReadState() == LOW)
    --(*buffer_variable);
  if (*buffer_variable > 255 || *buffer_variable < 0)
    *buffer_variable = 0;
  if (*true_variable != *buffer_variable)
  {
    EEPROM.write(index, *buffer_variable);
    *true_variable = *buffer_variable;
  }
  //กำหนดcusorการเขียนข้อมูลลงจอlcdให้เป็นบรรทัดแรกตัวอกษรแรกั
  lcd.setCursor(0, 0);
  //แสผงผลข้้อความ TEMP Limiter Set ที่บรรทัดแรก
  lcd.printf("%s", string_col0);
  //กำหนดcusorการเขียนข้อมูลลงจอlcdให้เป็นบรรทัดที่สองตัวอกษรแรกั
  lcd.setCursor(0, 1);
  //แสผงผลข้้อความ Value = และค่าที่คั้งใหม่ ที่บรรทัดแรก ตัวอย่าง Value = 001
  lcd.printf("%s%03d", string_col1, buffer_setMole_Temp);
}
void Operation()
{
  if (Mole_curent_state == HIGH) //เงื่อไขถ้าสถานะของโมลไม่มีการกดหรือสถานะ HIGH ให้ทำการแสดงผลและสั่งให้ relay ที่คอบคุม buzzer และ heater ไม่ให้มีการ trig
  {
    pre_time = millis(); //ใช้คำสั่ง millis() ดึงค่าเวลาจาก mcu เพื่อใช้ในการตรวจสอบเวลาในการรับถอยหลัง
    time_limiter = limiter_buffer;//ค่าสูงสุดในการรับถอยหลังเท่ากับค่าที่อ่านได้จาก eeprom
    // สั่ง relay ของขา relay_pin ไม่ให้ทำงาน ตัว load ต่อกับ nc และ common ทำให้ ssr ยังทำงานปกติและนำกระแสและเพิ่มอุณหภูมิในฮีทเตอร์
    digitalWrite(relay_pin, relay_off);
    // สั่ง relay ของขา budzer_pin ไม่ให้ทำงาน ตัว load ต่อกับ no และ common เมื่อ relay ไม่ทำงานทำให้ no และ common ไม่ต่อหากันทำให้ไม่ครบวงจรbuzzerจะไม่ส่งเสียง
    digitalWrite(budzer_pin, relay_off);
    lcd.setCursor(0, 0); //กำหนดcusorการเขียนข้อมูลลงจอlcdให้เป็นบรรทัดแรกตัวอักษรแรก
    lcd.printf("TimeOut:%08d", (int)time_limiter); //แสดงผลข้อความ TimeOutตามด้วยเวลานับถอยหลัง ตัวอย่าง TimeOut:00000001
  }
  else //เงื่อไขถ้าสถานะของโมล่มีการกดหรือสถานะ LOW ให้ทำการแสดงผลนับเวลาถอยหลังและสั่งให้ relay ที่คอบคุม buzzer และ heater ให้มีการ trig เมื่อนับถอยหลังเกินเวลาที่กำหนด
  {
    if (millis() - pre_time >= 1000) //ใช้ฟังชั่นmillis()ดึงเวลาจาก mcu มาเพื่อตรวจสอบว่าเวลาผ่านไปแล้ว 1วิหรือไม่หากผ่านไปแล้วให้ลบค่า time_limiter ลง 1
    {
      time_limiter = time_limiter - 1;
      if (time_limiter <= 0) //เงื่อไขเพื่อป้องกัน time_limiter ไม่ให้เป็นค่าติดลบ
      {
        //Serial.printf("Make time limiter = 0");
        time_limiter = 0;
      }
      pre_time = millis(); //ใช้ฟังชั่นmillis()ดึงเวลาจาก mcu มาเก็บไว้ในตัวแปร pre_time เพื่อเปรียบเทียบเวลาครั้งถัดไป
    }

    if (time_limiter >= 0) //ถ้าtime_limiterหรือก็คือเวลานับถอยหลังยังไม่เป็น 0 ให้แสดงผลการนับถอยหลัง
    {
      //sprintf(lcd_row_buffer[0],"TimeOut:%08d",(int)time_limiter);
      lcd.setCursor(0, 0);
      lcd.printf("TimeOut:%08d", (int)time_limiter);
      //lcd.print(lcd_row_buffer[0]);
      if (curent_alarm == HIGH && Mole_curent_state == LOW) //เช็คสถานะของ Alarm จากระบบ Pid ว่าอุณหภูมิพร้อมหรือไม่หากพร้ิมให้ led สีเขียวติดและแดงดับ
      {
        digitalWrite(G_indicator, indicator_on);
        digitalWrite(R_indicator, indicator_off);
      }
    }
    if (time_limiter == 0) //เงื่อไขหากเวลานับถอยหลังเหลือ 0 แล้วยังไม่มีการยกโมลขึ้นให้ทำการสั่งให่ relay ทำงานเพื่อตัดวงจร และแสดงไฟled สีแดงติดและสีเขียวดับ
    {
      // สั่ง relay ให้ทำงาน ตัว load ต่อกับ nc และ common ถ้า relay ทำงาน ขา common จะถูกผลักไปหาขา no ทำให้ไม่ครบวงจรทำให้ ssr หยุดทำงานและ heater จะหยุดทำงานด้วยเช่นกัน
      digitalWrite(relay_pin, relay_on);
      // สั่ง relay ให้ทำงาน ตัว load ต่อกับ no และ common ถ้า relay ทำงาน ขา common จะถูกผลักไปหาขา no ทำให้ครบวงจร buzzer จะทำงานและส่งเสียง
      digitalWrite(budzer_pin, relay_on);
      digitalWrite(G_indicator, indicator_off); //สั่ง led เขียวดับ
      digitalWrite(R_indicator, indicator_on); //สั่ง led แดงติด
    }
  }
  // sprintf(lcd_row_buffer[1],"MoleTemp:%04f   ",Mole_celsius);
  //กำหนดcusorการเขียนข้อมูลลงจอlcdให้เป็นบรรทัดที่สองตัวอกษรแรกั
  lcd.setCursor(0, 1);
  lcd.printf("MoleTemp:%04.2f   ", Mole_celsius);
  //Serial.printf("MoleTemp:%04.2f   ",Mole_celsius);
  //lcd.print(lcd_row_buffer[1]);
}
