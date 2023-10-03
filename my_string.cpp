#include "my_string.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

my_string::my_string() { data = new char; }

my_string::my_string(const char *d) {
    data = (char *)malloc(sizeof(d));
    strcpy(data, d);
}

my_string::my_string(my_string const &s) { data = s.data; }

char my_string::get_char(const int &i) const { return data[i]; }

void my_string::set_char(const int &i, const char &c) { data[i] = c; }

void my_string::print() const { std::cout << data << std::endl; }

my_string::~my_string() {}
