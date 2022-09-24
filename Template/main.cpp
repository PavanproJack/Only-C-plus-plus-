#include<iostream>
#include<string>



consteval int get_value(){
    return 3;
}


int main(){
    constexpr int value = get_value();
    std::cout<< "Value is : " << value << std::endl;

    int age {27}, full_age {32};
    std::string name;
    std::string fullname;
    
    // std::cin>> 
    std::cout<< "age is : " << age << std::endl;

    // for prinitng  errors to console
    std::cerr << "Error: sth went wrong here : " << std::endl;
    // for printing logs to console
    std::clog << "A sample warning message here " << std::endl;

    // for getting multiple inputs in a single line
    // std::cin >> name >> age;     // This has problem if you input any space in the name. 
    // std::cin >> "Enter Name : " >> name >> "Enter Age : " >> age; 

    std::getline(std::cin, fullname);
    std::cin >> full_age;


    // std::cout << "Hey " << name << " you are : " << age << "years old " << std::endl;
    std::cout << "Hey " << fullname << " you are : " << full_age << "years old " << std::endl;


    return 0;
}


