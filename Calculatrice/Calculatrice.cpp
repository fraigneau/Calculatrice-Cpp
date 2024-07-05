#include <iostream>
#include <string>
#include <regex>
#include <cctype>
//#include <stdexcept>
#include "Fonction/source.h"

int main()
{

    //std::cin >> input;
    input = "123+456/789";
    parsing(input);
    saut(1);
    std::cout << nb_1;
    saut(1);
    std::cout << nb_2;
    saut(1);
    std::cout << nb_3;
    saut(1);
    std::cout << op_1;
    saut(1);
    std::cout << op_2;
    saut(1);
    std::cout << op_3;
    saut(1);

    saut(5);

    for (int i = 0; i < input.size(); i++) {
        
            std::cout << "[:] Premier nombre str " << nb_1;
            saut(1);
            std::cout << "[:] Premier operateur str " << op_1;
            saut(1);
            std::cout << "[:] second nombre str " << nb_2;
            saut(1);
            std::cout << "[:] second operateur str " << op_2;
            saut(1);
            std::cout << "[:] troisieme nombre str " << nb_3;
            saut(1);
            std::cout << "[:] troisieme operateur str " << op_3;
            saut(1);
        break;
    }
}