#include "my_string.hpp"
#include "rc.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    my_string s("hello world");
    s.print();
    {
        my_string t = s;
        s.print();
        t.print();
        std::cout << s.get_char(1) << std::endl;
        s.print();
        t.print();
    }
    s.set_char(1, 'E');
    s.print();
}
