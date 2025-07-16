#include "file_reader.hpp"


char** get_files() {

}

char* read_file(const char* filename) {

}

bool is_file_in_list(const char* filename) {
  for (int i = 0; i < num_files; ++i) {
    if (filename == files[i]) {
      return true;
    }
  }
  return false;
}