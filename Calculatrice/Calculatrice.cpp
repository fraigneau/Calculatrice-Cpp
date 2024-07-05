#include <iostream>
#include <string>
#include <regex>
#include <cctype>
//#include <stdexcept>
#include "Fonction/source.h"

int main()
{

    //std::cin >> input;
    input = "12";
    parsing(input);
    saut(1);
    std::cout << nb;
    saut(5);

    for (int i = 0; i < 100; i++) {
        // toutes les positions possible d'operateur 
        int operateur_pos = get_operateur_pos(input);
        int next_operateur_pos = get_operateur_pos(input.substr(operateur_pos + 1, input.size()));
        int next_next_operateur_pos = get_operateur_pos(input.substr(next_operateur_pos + 1, input.size()));

        char operateur = input[operateur_pos];

        // Liste des 3 premier nombre
        std::string nb_1 = input.substr(0, operateur_pos);
        std::string nb_2 = input.substr(operateur_pos + 1, next_operateur_pos);
        std::string nb_3 = input.substr(next_operateur_pos + 1, next_next_operateur_pos);
        if (next_next_operateur_pos == 0) {
            nb_3 = input.substr(next_operateur_pos + 1, input.size());
        }
        if (next_operateur_pos == 0) {
            nb_2 = input.substr(operateur_pos + 1, input.size());
            nb_3 = "";
        }

        // Liste des 3 premier operateur 
        std::string op_1 = input.substr(operateur_pos, 1 );
        std::string op_2 = input.substr(next_operateur_pos, 1);
        std::string op_3 = input.substr(next_next_operateur_pos, 1);
        if (next_next_operateur_pos == 0) {
            op_3 = input.substr(next_operateur_pos + 1, input.size());
        }
        if (next_operateur_pos == 0) {
            nb_2 = input.substr(operateur_pos + 1, input.size());
            nb_3 = "";
        }

        std::cout << operateur_pos << next_operateur_pos << next_next_operateur_pos;
        saut(1);
        std::cout << nb_1 << nb_2 << nb_3;
        saut(1);
        std::cout << op_1 << op_2 << op_3;
        saut(2);


        if (checknombre(nb_1)) {
            std::cout << "[:] Premier nombre str " << nb_1;
            saut(1);
        }

        // 1er operateur et nombre
        if (verifop(op_1)) {

            std::cout << "[Index 1] de l'operateur positionner " << operateur_pos + 1 << " sur le string " << input << " = " << input.at(operateur_pos);
            saut(2);
            if (checknombre(nb_2) == false) {
                std::cout << "[:] Deuxieme nombre str " << nb_2;
                saut(1);
            }
        }
        else {
            std::cerr << "aucune operation";
            break;
        }
        // 2nd operateur et nombre
        if (verifop(op_2))
        {
            std::cout << "[Index 2] de second operateur positionner " << next_operateur_pos + 1 << " sur le string " << input << " = " << input.at(next_operateur_pos);
            saut(2);
            if (checknombre(nb_3)) {
                std::cout << "[:] Troisieme nombre str " << nb_3;
                saut(1);
            }
        }
        else {
            if (verifop(op_1)) {
                nb_2 = input.substr(operateur_pos + 1, input.size());
                std::cout << "[:] Deuxieme nombre str " << nb_2;
                saut(1);
            }
        }
        // 3eme operateur et nombre
        if (verifop(op_3))
        {
            std::cout << "[Index 3] de troisieme operateur positionner " << next_next_operateur_pos + 1 << " sur le string " << input << " = " << input.at(next_next_operateur_pos);
            saut(2);
        }
        else {
            if (verifop(op_2)) {
                nb_3 = input.substr(next_operateur_pos + 1, input.size());
                std::cout << "[:] Troisieme nombre str " << nb_3;
                saut(1);
            }
        }
        // debut des premier calcules 
        if(signeprio(op_1)) {

            saut(2);
            std::cout << "[=] resultat 1 : " << calculoperation(stringToInt(nb_1), op_1, stringToInt(nb_2));
            nb_1 = calculoperation(stringToInt(nb_1), op_1, stringToInt(nb_2));
            saut(2);
        }
        else {
            if (signeprio(op_2)) {
                saut(2);
                nb_2 = calculoperation(stringToInt(nb_2), op_2, stringToInt(nb_3));
                std::cout << "[=] resultat 1 : " << nb_2;
                saut(2);
                nb_1 = calculoperation(stringToInt(nb_1), op_1, stringToInt(nb_2));
                std::cout << "[=] resultat 2 : " << nb_1;
            }
        }
        break;
    }
}