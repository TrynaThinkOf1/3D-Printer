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
#include <cstring>

#include "servo_control.hpp"
#include "gcode_interpretation.hpp"
#include "lcd_control.hpp"
#include "file_reader.hpp"

bool printing = false;

uint8_t num_files;

char current_instruction[5]; // so that it can hold up to the longest instruction + terminator ('M999\0')
char current_file_name[33]; // so that it can store the max length file name of a FAT32 disk + terminator

// char current_page[5]; // I don't plan to have page names longer than 4 characters, but we'll see

void raise_error(char* error_msg) {
  Serial.println(error_msg);
}

void setup() {
  Serial.begin(2000000);
  while (!Serial) {
    ; // this will ensure that Serial is initialized before everything else
  }

  if (!SD.begin(5)) { // GPIO 5 is the ESP32 pin which is connected to the CS (ChipSelect) port on the SD card reader
    raise_error("Could not connect to SD card reader!");
    exit(1);
  }
  /*
  const uint8_t num_files = get_num_files();
  char files[num_files][32]; // 32 character file names are typical for SD cards
  char* file_ptrs[num_files];
  for (uint8_t i = 0; i < num_files; ++i) {
    file_ptrs[i] = files[i];
  }
  get_file_names(file_ptrs, num_files);
  */
  num_files = get_num_files();

  char* files[num_files];
  get_file_names(files);
}

void loop() {
  // put your main code here, to run repeatedly:

}
