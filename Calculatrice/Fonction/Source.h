#pragma once 

std::string input;

int nb;
int nb_1; 
int nb_2; 
int nb_3;
int temp_1;
int temp_2;

std::string op_1;
std::string op_2;

int pos_op_1;
int pos_op_2;


char plus  = '+';
char moins = '-';
char mult  = '*';
char divi  = '/';
char egal  = '=';

void saut(int i) {
	for (int j = 0; j < i; j++) {
		std::cout << std::endl;
	}
}

void start() {
	std::cout << "calculatrice beta-0.5";
	saut(1);
	std::cout << "      x+y*z";
	saut(1);
	std::cout << "   [+, -, *, /] ";
	saut(2);
}

int addDigit(int nb, int add) {
	nb = nb * 10 + add;
	return nb;
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
		return 10;
	}
}

void parsing(std::string str) {
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
				pos_op_1 = i + 1;
				nb_1 = nb;
				nb = 0;
			}
			else if (op_2 == "") {
				op_2 = str[i];
				pos_op_2= i + 1;
				nb_2 = nb;
				nb = 0;
			}		
		}
		nb_3 = stringToInt(str.substr(pos_op_2 + 1, str.size()));
	}
}

void log() {
	std::cout << "[:] Premier nombre str " << nb_1;
	saut(1);
	std::cout << "[:] Premier operateur str " << op_1 << " sur la position : " << pos_op_1;
	saut(1);
	std::cout << "[:] second nombre str " << nb_2;
	saut(1);
	std::cout << "[:] second operateur str " << op_2 << " sur la position : " << pos_op_2;
	saut(1);
	std::cout << "[:] troisieme nombre str " << nb_3;
	saut(1);
}
