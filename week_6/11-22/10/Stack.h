#ifndef STACK_H
#define STACK_H

enum MyErrors {
  err_a,
  err_b,
};

class Stack {
  public:
    Stack();
    void push(int number) throw (MyErrors);
    void pop() throw (MyErrors);
    int get_index();
    ~Stack();
  private:
    int* fixed_array;
    int number_of_elements = 0;
};

#endif // STACK_H
