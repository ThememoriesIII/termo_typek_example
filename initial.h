#include "functionPrototype.h"

void initial(){
  pinMode(relay_pin,OUTPUT);//กำหนดขา relay_pin เป็น OUTPUT
  pinMode(budzer_pin,OUTPUT);//กำหนดขา budzer_pin เป็น OUTPUT
  digitalWrite(relay_pin,relay_off); //สั่ง relay ขา relay_pin ให้ไม่ทำงาน 
  digitalWrite(budzer_pin,relay_off);//สั่ง relay ขา budzer_pin ให้ไม่ทำงาน
  
  pinMode(R_indicator,OUTPUT);//กำหนดขา R_indicator เป็น OUTPUT
  pinMode(Y_indicator,OUTPUT);//กำหนดขา Y_indicator เป็น OUTPUT
  pinMode(G_indicator,OUTPUT);//กำหนดขา G_indicator เป็น OUTPUT
  digitalWrite(R_indicator,indicator_off); //สั่ง led ขา R_indicator ให้ไม่ทำงาน
  digitalWrite(Y_indicator,indicator_off); //สั่ง led ขา Y_indicator ให้ไม่ทำงาน
  digitalWrite(G_indicator,indicator_off); //สั่ง led ขา G_indicator ให้ไม่ทำงาน
  
  pinMode(Mole_Lswitch,INPUT);//กำหนดขา Mole_Lswitch เป็น INPUT
  pinMode(input_alarm,INPUT);//กำหนดขา input_alarm เป็น INPUT

  button_Set_pin.setup(); //เรียกใช้ function setup()ของ object debounce เพื่อกำหนดค่าเริ่มต้นของการ debounce ปุ่ม
  button_up_pin.setup(); //เรียกใช้ function setup()ของ object debounce เพื่อกำหนดค่าเริ่มต้นของการ debounce ปุ่ม
  button_down_pin.setup(); //เรียกใช้ function setup()ของ object debounce เพื่อกำหนดค่าเริ่มต้นของการ debounce ปุ่ม

  limiter_buffer = EEPROM.read(0); //อ่านค่าจาก bufferตำแหน่งที่ 0 เก็บไว้ในตัวแปรlimiter_buffer
  if(limiter_buffer>0&&limiter_buffer<=255) // เงื่อไนถ้า limiter_buffer อยู่ในช่วง 0-255 ให้ตัวแปร time_limiter = limiter_buffer
    time_limiter = limiter_buffer;
  
  buffer_setMole_Temp = EEPROM.read(1); //อ่านค่าจาก bufferตำแหน่งที่ 0 เก็บไว้ในตัวแปรlimiter_buffer
  if(buffer_setMole_Temp>0&&buffer_setMole_Temp<=255) // เงื่อไนถ้า limiter_buffer อยู่ในช่วง 0-255 ให้ตัวแปร time_limiter = limiter_buffer
    setMole_Temp = (float)buffer_setMole_Temp;
}
