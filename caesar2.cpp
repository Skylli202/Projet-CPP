using namespace std;

#include "caesar2.h"

Caesar2::Caesar2(){
	this->m_plain = "";
	this->m_cipher = "";
}

string Caesar2::encode(int key){
	/* RAPPEL :
	 * 		Cette fois-ci l'encodage prend en compte l'intégralité de la table ASCII.
	 *		Caractère minuscule, majuscule, ponctuation etc... (mais pas les accents, ils ne sont pas codés sur la table ASCII)
	 *		Le code va donc du caractère 32 à 126 (inclus)
	 */

	string str = "";

	for(int i=0; i < this->m_plain.length(); i++){
		char c = this->m_plain.at(i);

		// Listener
		//cout << "c (" << i << ") : " << c;


		if((c > 31) && (c < 127)){
			c = ((c-' ')+key)%('~'-' '+1)+' ';
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		// Listener
		//cout << " | " << c << endl;

		str = str + c;


	}
	this->m_cipher = str;
	return this->m_cipher;
}

string Caesar2::decode(int key){
	/* RAPPEL :
	 * 		Cette fois-ci l'encodage prend en compte l'intégralité de la table ASCII.
	 *		Caractère minuscule, majuscule, ponctuation etc... (mais pas les accents, ils ne sont pas codés sur la table ASCII)
	 *		Le code va donc du caractère 32 à 126 (inclus)
	 */

	string str = "";

	for(int i=0; i < this->m_plain.length(); i++){
		char c = this->m_plain.at(i);

		if((c > 31) && (c < 127)){
			c = ((c-'~')-0)%('~'-' '+1)+'~';
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		str = str + c;


	}
	this->m_plain = str;
	return this->m_plain;
}