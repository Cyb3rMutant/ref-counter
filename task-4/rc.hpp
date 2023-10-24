#include <iostream>

template <class T> class Rc {
  public:
    Rc() = delete;

    Rc(T *o) {
        obj = o;
        counter = new int(1);
    }

    Rc(Rc const &rhs) { copy(rhs); }

    Rc &operator=(Rc const &rhs) {
        if (this != rhs) {
            clear_with_check();
            copy(rhs);
        }
        return *this;
    }

    ~Rc() { clear_with_check(); }

    T &operator*() { return *obj; }

    T *operator->() { return obj; }

    friend std::ostream &operator<<(std::ostream &out, Rc &s) {
        out << *(s.obj);
        std::cout << " [" << *s.counter << "]" << std::endl;
        return out;
    }

  private:
    T *obj;
    int *counter;

    void clear_with_check() {
        if (--(*counter) == 0) {
            delete obj;
            delete counter;
        }
    }
    void copy(Rc const &other) {
        obj = other.obj;
        counter = other.counter;
        (*counter)++;
    }
};
