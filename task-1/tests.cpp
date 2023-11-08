#include "my_string.hpp"
#include <cassert>
#include <iostream>

int main() {
    // Test the default constructor
    my_string str1;
    str1.print(); // The string should be empty.

    // Test the constructor with a C-style string
    const char *cstr = "Hello, World!";
    my_string str2(cstr);
    assert(str2.get_char(0) == 'H');
    assert(str2.get_char(7) == 'W');

    // Test the copy constructor
    my_string str3 = str2;
    assert(str3.get_char(0) == 'H');
    assert(str3.get_char(7) == 'W');

    // Test the copy assignment operator
    my_string str4;
    str4 = str2;
    assert(str4.get_char(0) == 'H');
    assert(str4.get_char(7) == 'W');

    // Test setting and getting characters
    str4.set_char(7, 'X');
    assert(str4.get_char(7) == 'X');

    // Test printing the string
    std::cout << "str4: ";
    str4.print();

    // Test out of range index
    bool exceptionThrown = false;
    try {
        str4.get_char(100); // Out of range index throws an exception.
    } catch (const std::out_of_range &e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
