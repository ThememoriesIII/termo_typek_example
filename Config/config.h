#ifndef CONFIG_H
#define CONFIG_H
///////////กำหนดชื่อตัวแปรเพื่อใช้เป็นตัวแทนขา i/o เพื่อให้ง่ายต่อการใช้งาน
#define thermoDO 4 //กำหนดตัวแปรเพื่อ thermoDO มีค่าเท่ากับ 4 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define thermoCS 5 //กำหนดตัวแปรเพื่อ thermoCS มีค่าเท่ากับ 5 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define thermoCLK 6 //กำหนดตัวแปรเพื่อ thermoCLK มีค่าเท่ากับ 6 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย

#define R_indicator 7 //กำหนดตัวแปรเพื่อ R_indicator มีค่าเท่ากับ 7 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define Y_indicator 8 //กำหนดตัวแปรเพื่อ Y_indicator มีค่าเท่ากับ 8 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define G_indicator 9 //กำหนดตัวแปรเพื่อ G_indicator มีค่าเท่ากับ 9 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย

#define Set_pin 10 //กำหนดตัวแปรเพื่อ Set_pin มีค่าเท่ากับ 10 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define up_pin 11 //กำหนดตัวแปรเพื่อ up_pin มีค่าเท่ากับ 11 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define down_pin 12 //กำหนดตัวแปรเพื่อ down_pin มีค่าเท่ากับ 12 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย

#define Mole_Lswitch 2 //กำหนดตัวแปรเพื่อ Mole_Lswitch มีค่าเท่ากับ 2 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define input_alarm 3 //กำหนดตัวแปรเพื่อ input_alarm มีค่าเท่ากับ 3 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย

#define relay_pin A0 //กำหนดตัวแปรเพื่อ relay_pin มีค่าเท่ากับ A0 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
#define budzer_pin A1 //กำหนดตัวแปรเพื่อ budzer_pin มีค่าเท่ากับ A1 เพื่อใช้กำหนดชื่อขาขา i/o เพื่อให้ใช้งานได้ง่าย
/// ค่า delay สำหรับ debounce ปุ่มกด
#define delaydebounce 50 //millisec


#define relay_on LOW //กำหนดตัวแปร relay_on = low เพื่อให้ง่ายต่อความเข้าใจสถานะ LOW HIGH
#define relay_off HIGH //กำหนดตัวแปร relay_off = HIGH เพื่อให้ง่ายต่อความเข้าใจสถานะ LOW HIGH

#define indicator_on HIGH //กำหนดตัวแปร indicator_on = HIGH เพื่อให้ง่ายต่อความเข้าใจสถานะ LOW HIGH
#define indicator_off LOW //กำหนดตัวแปร indicator_off = LOW เพื่อให้ง่ายต่อความเข้าใจสถานะ LOW HIGH

#endif