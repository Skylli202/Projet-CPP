#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Encrypt {
protected:
	string m_plain;
 	string m_cipher;

private:
	// if anything to add in private

public:
	// Constructor
	Encrypt();

	// Getter
	string get_plain() const;
	string get_cipher() const;

	// Setter

	// Method
 	bool read(bool isPlain, string filename);
 	bool write(bool isPlain, string filename);
 	string encode();
 	string decode();
 	string toString();

};

#endif