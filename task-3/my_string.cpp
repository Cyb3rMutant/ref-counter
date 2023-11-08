#include "my_string.hpp" // Include the header file for the custom string class.

#include <cstddef>  // Include the header for 'std::size_t'.
#include <cstring>  // Include the header for string manipulation functions.
#include <iostream> // Include the header for input/output stream.

// Default constructor: Initialize an empty 'my_string' object.
my_string::my_string() { new_empty(); }

// Constructor: Initialize a string with the content of a C-style string 'd'
my_string::my_string(const char *d) {
    if (d) { // Check if the input C-style string is not null.
        len = new size_t(strlen(d)); // Calculate and store the string length.
        data = new char[*len];       // Allocate memory for the string data.
        strcpy(data, d); // Copy the input string into the allocated memory.

        ref_counter = new int(1); // Initialize the reference count to 1.
    } else {
        // If the input string is null, create an empty string with a reference
        // count of 1.
        new_empty();
    }
}

// Copy constructor: Initialize a string by copying the content of another
// my_string 's' and increment the ref count
my_string::my_string(my_string const &s) { copy(s); }

// Copy assignment: Assign the content of another my_string 's' to this
// my_string and adjusts the ref count for both objects acordingly
my_string &my_string::operator=(my_string const &s) {
    if (this != &s) {       // Check for self-assignment.
        clear_with_check(); // Decrement the reference count of the current
                            // string and clear it if its the last one.
        copy(s); // Copy the content and reference count from the source string.
    }
    return *this; // Return a reference to this string after assignment.
}

// Destructor: Clean up the dynamically allocated memory for the string
my_string::~my_string() { clear_with_check(); }

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

int *my_string::get_ref_counter() const { return ref_counter; }

// Print the contents of the 'my_string' and its reference count to standard
// output.
void my_string::print() const {
    std::cout << data << ' '; // Output the string data.
    std::cout << '[' << *ref_counter << ']'
              << std::endl; // Output the reference count.
}

// Helper function to allocate memory for an empty string and sets ref count
// to 1.
void my_string::new_empty() {
    len = new size_t(0);
    data = new char[*len]; // Allocate memory for an empty string.
    strcpy(data, "");
    ref_counter = new int(1); // Initialize the reference count to 1.
}

// Helper function to copy the content of another 'my_string' into this
// 'my_string'.
void my_string::copy(my_string const &other) {
    data = other.data;               // Share the data.
    len = other.len;                 // Share the length.
    ref_counter = other.ref_counter; // Share the reference count.
    (*ref_counter)++; // Increment the reference count to indicate sharing.
}

// Helper function to clear the string's data while checking for
// references (used for managing dynamic memory).
void my_string::clear_with_check() {
    // Decrement the ref count as the object is deleted and if it reaches 0, it
    // means all references are deleted so its time to free
    if (--(*ref_counter) == 0) {
        delete[] data; // Delete the string data.
        delete len;    // Delete the length.
    }
}

// Helper function to check if the index is within valid boundaries.
void my_string::check_boundaries(const int &i) const {
    if (i < 0 || i >= *len) { // Check if 'i' is out of valid bounds.
        throw std::out_of_range("index out of range"); // Throw an exception.
    }
}
