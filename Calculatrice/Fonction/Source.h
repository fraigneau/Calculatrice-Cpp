#pragma once 

int nb;
int nombre_t0 = 0;
int nombre_t1 = 0;
int nombre_t2 = 0;

char plus  = '+';
char moins = '-';
char mult  = '*';
char divi  = '/';
char egal  = '=';

std::string input;

void start() {
	std::cout << "calculatrice beta-0.3" << std::endl;
	std::cout << "    [+, -, *, /] " << std::endl;
}

void saut(int k){
	for (int j = 0; j < k; j++) {
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
	}
}

int addDigit(int nb, int add) {
	nb = nb * 10 + add;
	return nb;
}

int parsing(std::string& str) {
	for (int i = 0; i < str.size(); i++) {
		if (std::isdigit(str[i])) {
			std::cout << "Le caractere " << str[i] << " est un chiffre.";
			saut(1);
			nb = addDigit(nb, stringToInt(str));
			std::cout << nb;
			saut(1);
			return nb;
		}
		else if (checksigne(str)) {
			std::cout << "Le caractere " << str[i] << " est un operateur." << std::endl;
			saut(1);
			i++;
		}
	}
}
