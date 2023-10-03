#include <cstring>
#include <iostream>

using namespace std;

class my_string {
  public:
    my_string();
    my_string(const char *);
    my_string(my_string const &s);
    my_string &operator=(my_string const &s) { return *this; }
    ~my_string();

    char get_char(const int &i) const;
    void set_char(const int &i, const char &c);
    void print() const;

  private:
    char *data;
    int *ref_counter = 0;
};
