#pragma once
#ifndef INITIAL_H
#define INITIAL_H
#include "Header.h"
void initial();
void Operation();
void alarm_check();
void lamp_indicator();
void Option_base(char* string_col0, char* string_col1,byte* buffer_variable,byte* true_variable,byte index);
typedef void (*Option)(char* string_col0, char* string_col1,byte* buffer_variable,byte* true_variable,byte index);
Option opstion1_setting_time = Option_base;
Option opstion2_setting_temp = Option_base;
#endif