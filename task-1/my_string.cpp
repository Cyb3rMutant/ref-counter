#include "my_string.hpp" // Include the header file for the custom string class.

#include <cstring>   // Include the header for string manipulation functions.
#include <iostream>  // Include the header for input/output stream.
#include <stdexcept> // Include the header for exception handling.

// Default constructor: Initialize an empty 'my_string' object.
my_string::my_string() { new_empty(); }

// Constructor: Initialize a string with the content of a C-style string 'd'
my_string::my_string(const char *d) {
    if (d) {                  // If 'd' is not nullptr, copy its content.
        len = strlen(d);      // Calculate and store the string length.
        data = new char[len]; // Allocate memory for the string data.
        strcpy(data, d); // Copy the input string into the allocated memory.
    } else {             // If 'd' is nullptr, initialize an empty string.
        new_empty();
    }
}

// Copy constructor: Initialize a string by copying the content of another
// my_string 's'
my_string::my_string(my_string const &s) { copy(s); }

// Copy assignment: Assign the content of another my_string 's' to this
// my_string
my_string &my_string::operator=(my_string const &s) {
    if (this != &s) { // If the source and target strings are different objects.
        copy(s);      // Copy the content of 's' into this string.
    }
    return *this; // Return a reference to this string after assignment.
}

// Destructor: unimplemented
my_string::~my_string() {}

// Get a character at a specified index 'i' in the string
char my_string::get_char(const int &i) const {
    check_boundaries(i); // Check if 'i' is within valid boundaries.
    return data[i];      // Return the character at index 'i'.
}

// Set a character at a specified index 'i' in the string to 'c'
void my_string::set_char(const int &i, const char &c) {
    check_boundaries(i); // Check if 'i' is within valid boundaries.
    data[i] = c;         // Set the character at index 'i' to 'c'.
}

// Print the contents of the 'my_string' to standard output.
void my_string::print() const { std::cout << data << std::endl; }

// Helper function to allocate memory for an empty string.
void my_string::new_empty() {
    len = 0;
    data = new char[len];
    strcpy(data, "");
}

// Helper function to copy the content of another 'my_string' into this
// 'my_string'.
void my_string::copy(my_string const &other) {
    data = other.data; // Share the data.
    len = other.len;   // Share the length.
}

// Helper function to check if the index is within valid boundaries.
void my_string::check_boundaries(const int &i) const {
    if (i < 0 || i >= len) { // Check if 'i' is out of valid bounds.
        throw std::out_of_range("index out of range"); // Throw an exception.
    }
}
