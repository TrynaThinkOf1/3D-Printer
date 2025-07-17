#pragma once

#include <stdint.h>

void raise_error(char* error_msg);

uint8_t get_num_files();
void get_file_names(char** files, const uint8_t num_files);

char* read_file(char* filename);