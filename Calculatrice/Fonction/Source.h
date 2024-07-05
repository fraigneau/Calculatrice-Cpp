#pragma once 

std::string input;

int nb;
int nb_1; 
int nb_2; 
int nb_3;

std::string op;
std::string op_1;
std::string op_2;
std::string op_3;

int nombre_t0 = 0;
int nombre_t1 = 0;
int nombre_t2 = 0;

char plus  = '+';
char moins = '-';
char mult  = '*';
char divi  = '/';
char egal  = '=';


void start() {
	std::cout << "calculatrice beta-0.3" << std::endl;
	std::cout << "    [+, -, *, /] " << std::endl;
}

void saut(int i){
	for (int j = 0; j < i; j++) {
		std::cout << std::endl;
	}
}

int get_operateur_pos(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == plus)
			return i;
		if (input[i] == moins)
			return i;
		if (input[i] == mult)
			return i;
		if (input[i] == divi)
			return i;
	}
	return 0;
}

void nb_maj(int j, char k)
{
	std::cout << "[MAJ] Nombre_t"<< k << " mis a jour : " << j;
	saut(1);
}

bool checknombre(const std::string& str) {
	std::regex numberpaterne("\\d+");
	return std::regex_search(str, numberpaterne);
}

bool checksigne(const std::string& str) {
	std::regex signepaterne("[+\\-/*]");
	return std::regex_search(str, signepaterne);
}

bool signeprio(const std::string& str) {
	std::regex signepriopaterne("[/*]");
	return std::regex_search(str, signepriopaterne);
}

int verifop(std::string str) {
	if (checknombre(str)) {
		str = "";
		return false;
	}
	else if (checksigne(str)) {
		return true;
	}
	else {
		str = "";
		std::cout << "une erreur sur le string " << str << "est survenue";
		return 10; 
	}
}

int stringToInt(const std::string& str) {
	try {
		return std::stoi(str);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Argument invalide: " << e.what() << std::endl;
		return 0;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Valeur hors de portee: " << e.what() << std::endl;
		return 0; 
	}
}

std::string intToString(int i) {
	return std::to_string(i);
}

int calculoperation(int j,const std::string& str, int k) {
	if (str == "+") {
		return j + k ;
	}
	else if (str == "-") {
		return j - k ;
	}
	else if (str == "*") {
		return j * k ;
	}
	else if (str == "/") {
		return j / k ;
	}
	else {
		std::cerr << "pb sur un operateur";
		return 10;
	}
}

int addDigit(int nb, int add) {
	nb = nb * 10 + add;
	return nb;
}

int parsing(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (checknombre(str.substr(i, 1))) {
			std::cout << "Le caractere " << str[i] << " est un chiffre.";
			saut(1);
			nb = addDigit(nb, stringToInt(str.substr(i, 1)));
		}
		else if (checksigne(str.substr(i, 1))) {
			std::cout << "Le caractere " << str[i] << " est un operateur.";
			saut(1);
			if (op_1 == "") {
				op_1 = str[i];
				nb_1 = nb;
				nb = 0;
			}
			else if (op_2 == "") {
				op_2 = str[i];
				nb_2 = nb;
				nb = 0;
			}
			else if (op_3 == "") {
				op_3 = str[i];
				nb_3 = nb;
				nb = 0;
			}		
		}
	}
	
	return 1;
}
