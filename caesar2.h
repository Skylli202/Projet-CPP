#ifndef CAESAR2_H
#define CAESAR2_H

#include <cstring>

using namespace std;

#include "encrypt.h"

class Caesar2: public Encrypt {
public:
	// Constructeur
	Caesar2();

	// Getter
	// Setter

	// Method
	string encode(int);
	string decode(int);
};

#endif