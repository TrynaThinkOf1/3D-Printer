#pragma once

extern char[] files;

char[] get_files(); // this func reads all the files on the SD card and returns a list of their names
files = get_files();

char* read_file(const char& filename);