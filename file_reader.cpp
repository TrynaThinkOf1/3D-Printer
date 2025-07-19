#include "file_reader.hpp"

#include <SD.h>

uint8_t get_num_files() {
  uint8_t count = 0;
  File root = SD.open("/");

  while (true) {
    File entry = root.openNextFile("");
    if (!entry) {
      break;
    }
    if (!entry.isDirectory()) {
      count++;
    }
    entry.close();
  }
  root.close();
  return count;
}
/*
void get_file_names(char** files, const uint8_t num_files) {
  uint8_t index = 0;
  File root = SD.open("/");

  while (index < num_files) {
    File entry = root.openNextFile("");
    if (!entry) {
      break;
    }
    if (!entry.isDirectory()) {
      strcpy(files[index], entry.name());
      index++;
    }
    entry.close();
  }
  root.close();
}
*/
void get_file_names(char** files) {
  uint8_t index = 0;

  File root = SD.open("/");

  while (index < num_files) {
    File entry = root.openNextFile();
    if (!entry) { // out of files
      break;
    }
    if (!entry.isDirectory()) {
      files[index] = const_cast<char*>(entry.name());
      index++;
    }
    entry.close();
  }
  root.close();
}


char* read_file(char* filename) {
  File file = SD.open(filename);
  if (!file) {
    raise_error("File does not exist");
    return nullptr;
  }

  size_t size = file.size();
  char* buffer = (char*) malloc(size + 1); // (char*) type casts what would be a void* so that we can store a string more easily | malloc(size + 1) adds memory on the heap than can store the file + '\0' (null byte for storing strings)
  if (!buffer) {
    raise_error("Failed to allocate memory for file");
    return nullptr;
  }
  file.readBytes(buffer, size);
  buffer[size] = '\0'; // add the null terminator for safe string
  file.close();
  return buffer;
}