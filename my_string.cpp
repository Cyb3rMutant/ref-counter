#include "my_string.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

my_string::my_string() {
    data = new char;
    ref_counter = new int(1);
}

my_string::my_string(const char *d) {
    data = (char *)malloc(sizeof(d));
    strcpy(data, d);
    ref_counter = new int(1);
}

my_string::my_string(my_string const &s) {
    data = s.data;
    ref_counter = s.ref_counter;
    (*ref_counter)++;
}

char my_string::get_char(const int &i) const { return data[i]; }

void my_string::set_char(const int &i, const char &c) { data[i] = c; }

void my_string::print() const {
    std::cout << data << ' ';
    std::cout << '[' << *ref_counter << ']' << std::endl;
}

my_string::~my_string() {
    if (*ref_counter == 1) {
        free(data);
    } else {
        (*ref_counter)--;
    }
}
