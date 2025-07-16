#include <Arduino.h>
#include <stdint.h>

#include "servo_control.hpp"
#include "gcode_interpretation.hpp"
#include "lcd_control.hpp"
#include "file_reader.hpp"

char* current_instruction = "G28";
char** files = get_files();
const uint8_t num_files = sizeof(files) / sizeof(files[0]);

void setup() {
  Serial.begin(2000000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
