#include "rc.hpp"
#include <iostream>

struct Point {
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    // Test with int data type
    {
        Rc<int> rc1(new int(42));
        std::cout << *rc1 << std::endl; // Should print "42"

        Rc<int> rc2(rc1);
        std::cout << *rc2 << std::endl; // Should print "42"

        Rc<int> rc3(new int);
        rc3 = rc2;
        std::cout << *rc3 << std::endl; // Should print "42"

        // The reference count for the integer object should be 3.
        std::cout << rc1; // Should print "42 [3]"
        std::cout << rc2; // Should print "42 [3]"
        std::cout << rc3; // Should print "42 [3]"
    }

    // Test with double data type
    {
        Rc<double> rc1(new double(3.14159));
        std::cout << *rc1 << std::endl; // Should print "3.14159"

        Rc<double> rc2(rc1);
        std::cout << *rc2 << std::endl; // Should print "3.14159"

        Rc<double> rc3(new double);
        rc3 = rc2;
        std::cout << *rc3 << std::endl; // Should print "3.14159"

        // The reference count for the double object should be 3.
        std::cout << rc1; // Should print "3.14159 [3]"
        std::cout << rc2; // Should print "3.14159 [3]"
        std::cout << rc3; // Should print "3.14159 [3]"
    }

    // Test with a custom data type (a simple struct)
    {
        Rc<Point> rc1(new Point{1, 2});
        std::cout << rc1->x << ", " << rc1->y
                  << std::endl; // Should print "1, 2"

        Rc<Point> rc2(rc1);
        std::cout << rc2->x << ", " << rc2->y
                  << std::endl; // Should print "1, 2"

        Rc<Point> rc3(new Point);
        rc3 = rc2;
        std::cout << rc3->x << ", " << rc3->y
                  << std::endl; // Should print "1, 2"

        // The reference count for the Point object should be 3.
        std::cout << rc1; // Should print "1, 2 [3]"
        std::cout << rc2; // Should print "1, 2 [3]"
        std::cout << rc3; // Should print "1, 2 [3]"
    }

    return 0;
} // The destructors for rc1, rc2, and rc3 will be automatically called
