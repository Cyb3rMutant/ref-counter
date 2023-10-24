#include "rc.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Rc i(new int(3));
    std::cout << i;
    {
        Rc j(i);
        std::cout << j;
    }
    std::cout << i;
}
