#include <iostream>

// Template class for a reference-counted smart pointer
template <class T> class Rc {
  public:
    // Default constructor: Deleted to prevent creating an Rc without an object
    Rc() = delete;

    // Constructor: Initializes an 'Rc' with a pointer to any type of objects
    //
    // Example:
    // ```
    // Rc rc(new int(1));
    // ```
    Rc(T *o) {
        obj = o;              // Copy the pointer
        counter = new int(1); // Initialize the reference counter to 1
    }

    // Copy constructor: Initializes an 'Rc' by copying the content of another
    // 'Rc' and increments the counter
    //
    // Example:
    // ```
    // Rc rc1(new int(1));
    // Rc rc2(str1);
    // ```
    Rc(Rc const &rhs) { copy(rhs); }

    // Copy assignment: Assign the content of another 'Rc' to this and adjusts
    // the counter for both objects acordingly
    //
    // Example:
    // ```
    // Rc rc1(new int(1));
    // Rc rc2;
    // str2 = str1;
    // ```
    Rc &operator=(Rc const &rhs) {
        if (this != &rhs) {     // Check for self-assignment.
            clear_with_check(); // Decrement the reference count of the current
                                // object and clear it if its the last one
            copy(rhs); // Copy the content and reference count from the source
                       // object
        }
        return *this; // Return a reference to this object after assignment.
    }

    // Destructor: Decrements the reference count and deletes the object if
    // needed
    // No usage example needed; destructor is automatically called.
    ~Rc() { clear_with_check(); }

    // Overloaded arrow operator (->)
    T *operator->() { return obj; }

    // Friend function to overload the << operator for printing
    friend std::ostream &operator<<(std::ostream &out, Rc &s) {
        out << *(s.obj); // Output the object pointed to by Rc
        std::cout << " [" << *s.counter << "]"
                  << std::endl; // Output the reference count
        return out;
    }

  private:
    // Private data members:
    T *obj;       // Pointer to the managed object of type T
    int *counter; // Pointer to the reference count

    // Helper function to clear the object stored while checking for references
    // (usef for managing dynamic memory)
    void clear_with_check() {
        // Decrement the ref count as the object is deleted and if it reaches 0,
        // it means all references are deleted so its time to free
        if (--(*counter) == 0) {
            delete obj;     // Delete the object
            delete counter; // Delete the reference counter
        }
    }

    // Helper function to copy the contents of another 'Rc' into this
    void copy(Rc const &other) {
        obj = other.obj;         // Share the object
        counter = other.counter; // Share the counter
        (*counter)++;            // Increment the counter
    }
};
