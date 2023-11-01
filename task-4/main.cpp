#include "my_string.hpp"
#include "rc.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Rc s(new my_string("hello world"));
    std::cout << s;
    {
        Rc t = s;
        std::cout << s;
        std::cout << s;
        std::cout << s->get_char(1) << std::endl;
        std::cout << s;
        std::cout << s;
    }
    s->set_char(1, 'E');
    std::cout << s;
}
