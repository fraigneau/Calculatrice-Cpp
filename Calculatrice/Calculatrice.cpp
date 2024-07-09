#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "Fonction/source.h"

int main()
{
    start();
    //std::cin >> input;
    input = "2/3";
    parsing(input);
    saut(2);
    log();
    

    saut(2);

    for (int i = 0; i < input.size(); i++) {
        if (signeprio(op_2)) {
            temp_1 = calculoperation(nb_2, op_2, nb_3);
            std::cout << "[1] la premiere operation : " << nb_2 << op_2 << nb_3 << egal << temp_1;
            saut(1);
            temp_2 = calculoperation(nb_1, op_1, temp_1);
            std::cout << "[1] la seconde operation : " << nb_1 << op_1 << temp_1 << egal << temp_2;
            saut(1);
        }
        else if (checksigne(op_2)) {
            temp_1 = calculoperation(nb_1, op_1, nb_2);
            std::cout << "[2] la premiere operation : " << nb_1 << op_1 << nb_2 << egal << temp_1;
            saut(1);
            temp_2 = calculoperation(temp_1, op_2, nb_3);
            std::cout << "[2] la seconde operation : " << temp_1 << op_2 << nb_3 << egal << temp_2;
            saut(1);
        }
        else {
            temp_2 = calculoperation(nb_1, op_1, nb_2);
            std::cout << "[3] la premiere operation : " << nb_1 << op_1 << nb_2 << egal << temp_2;
            saut(1);
        }
        
        std::cout << "le resultat de l operation " << input << " " << "est : " << temp_2;
        saut(3);
            
        break;
    }
}