#include "my_string.hpp"
#include <iostream>

int main() {
    // Create a my_string instance with "Hello" and print its reference count.
    my_string s1("Hello");
    s1.print(); // Output: Hello [1]

    {
        // Create a new my_string instance in a nested scope by copying s1.
        my_string s2 = s1;
        s2.print(); // Output: Hello [2]
    }

    // s2 goes out of scope, so its reference count decreases.
    s1.print(); // Output: Hello [1]

    {
        // Create a new my_string instance in a nested scope with "World".
        my_string s3("World");
        s3.print(); // Output: World [1]

        // Assign s3 to s1 within the scope.
        s1 = s3;
        s1.print(); // Output: World [2]
    }

    // s3 goes out of scope, and its reference count decreases.
    s1.print(); // Output: World [1]

    // Create a new my_string with an empty string and print its reference
    // count.
    my_string s4;
    s4.print(); // Output:  [1]

    {
        // Assign s4 to s1 within a scope.
        s1 = s4;
        s1.print(); // Output:  [2]
    }

    // s4 goes out of scope, and its reference count decreases.
    s1.print(); // Output:  [1]

    return 0;
}
