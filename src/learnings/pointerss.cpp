// TODO: reference additional headers your program requires here

#include "../include/learnings/pointerss.h"
#include <iostream>

int* p_int_variable{};
double* p_double_variable{};
char* p_char_variable{nullptr};

int *p_var{nullptr}, var{89};

int x{45};
double y{34.0};

int* hj {&x};

char new_char_array_[] {"Hello World"};

const char* p_char_pointer{"Hello"};

const char* predictions[] { 
    "Hello", "Pavan", "Kavvuri"
};

// for declaring just characters
char character{'J'};  

//----- Compiler error: declaring variable of type 'char' with type 'const char
// char character_str{"KELLO"};  

// Prints array of characters ABC
char character_array_1[]{'A', 'B', 'C'};  

//--- Compiler error- excess elements. Character array is only array of charactrs(can be one string) not array of strings
// char character_array_2[]{"HELL", "ELL","LL"};  

// Prints PELLO
char character_array[] {"PELLO"};

// ------------------- using const char



    char char_array__ [] [5] { "a lot of kinds running in the backyard!", "a lot of empty beer bootles on your work table.",  "you Partying too much with kids wearing weird clothes."};

    char predictions2 [] [90] {
        "a lot of kinds running in the backyard!",
        "a lot of empty beer bootles on your work table.",
        "you Partying too much with kids wearing weird clothes.",
        "you running away from something really scary",
        "clouds gathering in the sky and an army standing ready for war",
        "dogs running around in a deserted empty city",
        "a lot of cars stuck in a terrible traffic jam",
        "you sitting in the dark typing lots of lines of code on your dirty computer",
        "you yelling at your boss. And oh no! You get fired!",
        "you laughing your lungs out. I've never seen this before.",
        ", huum, I don't see anything",
        "you drinking wine"
    };






void initialise_pointers() {

  // std::cout<<p_char_pointer<<std::endl;
  // std::cout<<&p_char_pointer<<std::endl;
  // std::cout<<*p_char_pointer<<std::endl;
  // std::cout<<"--------------------------"<<std::endl;
  // std::cout<<predictions<<std::endl;
  // std::cout<<&predictions<<std::endl;
  // std::cout<<*predictions<<std::endl;

  std::cout<< character <<std::endl;
  std::cout<< character_array <<std::endl;
  std::cout<< character_array_1 <<std::endl;
  // std::cout<< character_array_2 <<std::endl;   //Compiler error

  // std::cout<<character_str_1<<std::endl;

}

[[deprecated]] void foo() { std::cout << "Hello " << std::endl; }