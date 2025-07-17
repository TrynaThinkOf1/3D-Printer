/*
PIN SETUP (these will not be defined as integer variables and must be used as literals):
  SD CARD {
    DO - GPIO 19
    DI - GPIO 23
    CLK - GPIO 18
    CS - GPIO 5
  }
*/

#include <Arduino.h>
#include <stdint.h>
#include <SD.h>
#include <SPI.h>

#include "servo_control.hpp"
#include "gcode_interpretation.hpp"
#include "lcd_control.hpp"
#include "file_reader.hpp"

bool printing = false;

char* current_instruction = "G28";
char* current_file = "";

void raise_error(char* error_msg) {
  Serial.println(error_msg);
}

void setup() {
  Serial.begin(2000000);
  while (!Serial) {
    ; // this will ensure that Serial is initialized before everything else
  }

  if (!SD.begin(5)) { // GPIO 5 is the pin which the CS pin on the SD card reader is connected to
    exit(1);
  }
  
  const uint8_t num_files = get_num_files();
  char files[num_files][32]; // 32 character file names are typical for SD cards
  char* file_ptrs[num_files];
  for (uint8_t i = 0; i < num_files; ++i) {
    file_ptrs[i] = files[i];
  }
  get_file_names(file_ptrs, num_files);

  char* file = read_file("something.gcode");
  free(file); // read_file() uses malloc to create a pointer to a place on the heap
}

void loop() {
  // put your main code here, to run repeatedly:

}
