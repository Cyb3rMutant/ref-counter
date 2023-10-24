#include "my_string.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    int *counter;
    {
        my_string s("hello world");
        counter = s.get_ref_counter();
    }
    std::cout << *counter << std::endl;
}
