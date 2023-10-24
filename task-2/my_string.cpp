#include "my_string.hpp"
#include <cstring>
#include <iostream>

my_string::my_string() { new_empty(); }

my_string::my_string(const char *d) {
    if (d) {
        len = new int(strlen(d));
        data = new char[*len];
        strcpy(data, d);

        ref_counter = new int(1);
    } else {
        new_empty();
    }
}

my_string::my_string(my_string const &s) { copy(s); }

my_string &my_string::operator=(my_string const &s) {
    if (this != &s) {
        clear_with_check();
        copy(s);
    }
    return *this;
}

my_string::~my_string() { clear_with_check(); }

char my_string::get_char(const int &i) const {
    if (i < 0 || i >= *len) {
        throw std::out_of_range("index out of range");
    }
    return data[i];
}

void my_string::set_char(const int &i, const char &c) {
    if (i < 0 || i >= *len) {
        throw std::out_of_range("index out of range");
    }
    data[i] = c;
}

void my_string::print() const {
    std::cout << data << ' ';
    std::cout << '[' << *ref_counter << ']' << std::endl;
}

void my_string::new_empty() {
    data = new char[1];
    ref_counter = new int(1);
}

void my_string::copy(my_string const &other) {
    data = other.data;
    len = other.len;
    ref_counter = other.ref_counter;
    (*ref_counter)++;
}

void my_string::clear_with_check() {
    if (--(*ref_counter) == 0) {
        delete data;
        delete ref_counter;
    }
}
