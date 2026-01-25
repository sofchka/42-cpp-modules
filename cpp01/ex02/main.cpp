#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain; // Pointer to the string variable
    std::string& stringREF = brain; // Reference is an alias to the string variable
//     Reference                       | Pointer

//     Second name (alias)             | Separate variable with an address
//     Must be initialized             | Can be uninitialized / nullptr
//     Cannot change what it refers to | Can point to something else
//     Used like a normal variable     | Needs * to access value

    std::cout << "Address of brain variable: " << &brain << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl << std::endl;

    std::cout << "Value of brain variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

    // std::string noBrain = "NO BRAIN";
    // stringPTR = &noBrain; // Changing pointer to point to a different string variable
    // //stringREF = noBrain; // the same as brain = noBrain; (modifies the original variable)

    // std::cout << "\nAfter changing the stringPTR to point to noBrain:\n";
    // std::cout << "Value of brain variable: " << brain << std::endl;
    // std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    // std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

    // brain = "BRAIN HAS CHANGED";
    // std::cout << "\nAfter changing the brain variable:\n";
    // std::cout << "Value of brain variable: " << brain << std::endl;
    // std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    // std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

    return 0;
}