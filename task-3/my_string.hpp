#include <iostream>
class my_string {
  public:
    my_string();
    my_string(const char *);
    my_string(my_string const &s);
    my_string &operator=(my_string const &s);
    ~my_string();

    char get_char(const int &i) const;
    void set_char(const int &i, const char &c);
    void print() const;

    int *get_ref_counter() const;

  private:
    int *ref_counter;
    int *len;
    char *data;

    void new_empty();
    void copy(my_string const &other);
    void clear_with_check();
};
