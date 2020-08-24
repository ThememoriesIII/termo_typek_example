#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <Arduino.h>
#include <max6675.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "Debounce\debounce.h" //https://github.com/ThememoriesIII/DebounceButton follow and like if you like my code
#include "Config\config.h"

//สร้าง object ชื่อ lcd เพื่อเรียกใช้งาน lcd จาก library LiquidCrystal_I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);
//สร้าง object ชื่อ thermocouple เพื่อเรียกใช้งาน max6675 termocuple type k เพื่ออ่านค่าอุณหภูมิจาก library max6675.h
MAX6675 thermocouple(thermoCLK,thermoCS,thermoDO);
///สร้าง object ชื่อ button_Set_pin button_up_pin และ button_down_pin เพื่อเรียกใช้งาน DEBOUNCE ปุ่มกด จาก library DEBOUNCE.h
DEBOUNCE button_Set_pin(Set_pin, delaydebounce,HIGH,HIGH);
DEBOUNCE button_up_pin(up_pin, delaydebounce,HIGH,HIGH);
DEBOUNCE button_down_pin(down_pin, delaydebounce,HIGH,HIGH);

boolean Mole_curent_state=0; //ตัวแปรสำหรับเก็บสถานะของโมลว่ามีการประกบกันหรือไม่
float Mole_celsius = 0; //ตัวแปรสำหรับอุณหภูมิของโมล
byte buffer_setMole_Temp=0;
byte setMole_Temp = 0;
byte curent_alarm = 0;

unsigned long pre_time = 0; //ตัวแปรสำหรับเก็บค่าเวลาที่ใช้ในการตรวจสอบการเวลาการเริ่มนับถอยหลัง
byte time_limiter = 7 ;//millisec //ตัวแปรสำหรับเก็บค่านับถอยหลัง
byte limiter_buffer = 0;//ตัวแปลที่ใช้ในการอ่านค่านับถอยหลังที่เก็บใน eeprom
byte Mode = 0; //ตัวแปรเก็บสถานะเพื่อใช้เปลี่ยนรูปแบบการแสดงผล lcd จากโหมดตั้งค่าเวลานับถอยหลังกับโหมดนับถอยหลัง

unsigned long pre_tempurature_time = 0; //ตัวแปรสำหรับเก็บค่าเวลาที่ใช้ในการตรวจสอบการเวลาการเริ่มต้นอ่านค่าอุณหภูมิ
#endif
