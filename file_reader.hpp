#pragma once
#include <stdint.h>

extern const uint8_t num_files;
extern char** files;

bool is_file_in_list();

char** get_files(); // this func reads all the files on the SD card and returns a list of their names

char* read_file(const char& filename);