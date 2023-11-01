#include <cstddef>

// Define a custom string class named 'my_string'
class my_string {
  public:
    // Default constructor: Initialize an empty 'my_string' object.
    //
    // Example:
    // ```
    // my_string str;
    // ```
    my_string();

    // Constructor: Initialize a string with the content of a C-style string 'd'
    //
    // Example:
    // ```
    // my_string str("Hello, World!");
    // ```
    my_string(const char *);

    // Copy constructor: Initialize a string by copying the content of another
    // my_string 's' and increment the ref count
    //
    // Example:
    // ```
    // my_string str1("Hello");
    // my_string str2(str1);
    // ```
    my_string(my_string const &s);

    // Copy assignment: Assign the content of another my_string 's' to this
    // my_string and adjusts the ref count for both objects acordingly
    //
    // Example:
    // ```
    // my_string str1("Hello");
    // my_string str2;
    // str2 = str1;
    // ```
    my_string &operator=(my_string const &s);

    // Destructor: Clean up the dynamically allocated memory for the string
    // No usage example needed; destructor is automatically called.
    ~my_string();

    // Get a character at a specified index 'i' in the string
    //
    // Example:
    // ```
    // my_string str("Example");
    // char character = str.get_char(3);  // character will be 'm'
    // ```
    char get_char(const int &i) const;

    // Set a character at a specified index 'i' in the string to 'c'
    //
    // Example:
    // ```
    // my_string str("Hello");
    // str.set_char(1, 'X');  // Modifies 'str' to be "HXllo"
    // ```
    void set_char(const int &i, const char &c);

    // Get the reference counter
    int *get_ref_counter() const;

    // Print the contents of the 'my_string' and its reference count to
    // standard output.
    //
    // Example:
    // ```
    // my_string str("Print Me");
    // str.print();  // Output: "Print Me"
    // ```
    void print() const;

  private:
    // Private data members:
    char *data;  // Pointer to store the sequence of characters (the string)
    size_t *len; // Integer to store the length of the string
    int *ref_counter; // Pointer to store the number of copies of the same
                      // object (used to check when to clear out memory)

    // Helper function to allocate memory for an empty string and sets ref count
    // to 1.
    void new_empty();

    // Helper function to copy the content of another 'my_string' into this
    // 'my_string'.
    void copy(my_string const &other);

    // Helper function to clear the string's data while checking for
    // references (used for managing dynamic memory).
    void clear_with_check();

    // Helper function to check if the index is within valid boundaries.
    void check_boundaries(const int &i) const;
};
