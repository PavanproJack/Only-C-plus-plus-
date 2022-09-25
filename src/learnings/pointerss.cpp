#include "../include/learnings/pointerss.h"
#include <iostream>

int* p_int_variable{};
double* p_double_variable{};
char* p_char_variable{nullptr};

int *p_var{nullptr}, var{89};

int x{45};
double y{34.0};

const char* p_char_pointer{"Hello"};

char new_char_array_[] = {"Hello World"};

void initialise_pointers() {
  p_int_variable = &x;
  std::cout << *p_int_variable << std::endl;
  std::cout << p_int_variable << std::endl;
  std::cout << p_char_pointer << std::endl;

  //   std::cout << *p_char_pointer << std::endl;

  //   *p_char_pointer = 'B';
  //   std::cout << p_char_pointer << std::endl;
  new_char_array_[0] = 'B';
  std::cout << new_char_array_ << std::endl;
  std::cout << *new_char_array_ << std::endl;

  const char* message{"Hello World!"};
  std::cout << "message : " << message << std::endl;

// de-referencing a char pointer always points to the first character of the array
  std::cout << "message : " << *message << std::endl;   
}