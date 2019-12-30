#ifndef CAESAR_H
#define CAESAR_H

#include <cstring>

using namespace std;

#include "encrypt.h"

class Caesar: public Encrypt {
public:
	// Constructeur
	Caesar();

	// Getter
	// Setter

	// Method
	string encode();
	string decode();
	string encode(int);
	string decode(int);
	bool check();
};

#endif