using namespace std;

#include "caesar.h"

Caesar::Caesar(){
	this->m_plain = "";
	this->m_cipher = "";
}

string Caesar::encode(){
	/*
	 * RAPPEL : 
	 * 		D'après le sujet, m_plain est constitué UNIQUEMENT de minuscule.
	 *		Les espaces et la ponctuation sont ignorés.
	 *		Le décallage est de 3.
	 */

	const int key = 3;
	string str_cipher = "";

	for(int i = 0; i < m_plain.length(); i++){
		char c = m_plain.at(i);

		// Listener
		//cout << "c (" << i << ") : " << c << endl;

		if((c > 96) && (c < 123)){
			c = ((c-'a')+key)%('z'-'a'+1)+'a'; // On décalle de 3 en fesant attention que si l'on dépasse, on retombe au début de l'alphabet (ex: z+3 -> c)
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		str_cipher = str_cipher + c;
	}

	this->m_cipher = str_cipher;
	// D'apès la définition de la méthode encode dans la partie un du sujet, elle doit renvoyé m_cipher
	return this->m_cipher;
}

string Caesar::decode(){
	/*
	 * RAPPEL : 
	 * 		D'après le sujet, m_plain est constitué UNIQUEMENT de minuscule.
	 *		Les espaces et la ponctuation sont ignorés.
	 *		Le décallage est de 3.
	 */

	const int key = 3;
	string str_plain = "";

	for(int i = 0; i < m_cipher.length(); i++){
		char c = m_cipher.at(i);

		// Listener
		//cout << "c (" << i << ") : " << c << endl;

		if((c > 96) && (c < 123)){
			c = ((c-'z')-key)%('z'-'a'+1)+'z'; // On recule de 3 en fesant attention que si l'on dépasse, on retombe au début de l'alphabet (ex: c-3 -> z)
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		str_plain = str_plain + c;
	}

	this->m_plain = str_plain;
	// D'apès la définition de la méthode encode dans la partie un du sujet, elle doit renvoyé m_cipher
	return this->m_plain;
}

string Caesar::encode(int key){
	/*
	 * RAPPEL : 
	 * 		D'après le sujet, m_plain est constitué UNIQUEMENT de minuscule.
	 *		Les espaces et la ponctuation sont ignorés.
	 *		Le décallage est maintenant passer en paramètre.
	 */

	string str_cipher = "";

	for(int i = 0; i < m_plain.length(); i++){
		char c = m_plain.at(i);

		// Listener
		//cout << "c (" << i << ") : " << c << endl;

		if((c > 96) && (c < 123)){
			c = ((c-'a')+key)%('z'-'a'+1)+'a'; // On décalle de 3 en fesant attention que si l'on dépasse, on retombe au début de l'alphabet (ex: z+3 -> c)
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		str_cipher = str_cipher + c;
	}

	this->m_cipher = str_cipher;
	// D'apès la définition de la méthode encode dans la partie un du sujet, elle doit renvoyé m_cipher
	return this->m_cipher;
}

string Caesar::decode(int key){
	/*
	 * RAPPEL : 
	 * 		D'après le sujet, m_plain est constitué UNIQUEMENT de minuscule.
	 *		Les espaces et la ponctuation sont ignorés.
	 *		Le décallage est maintenant passer en paramètre.
	 */

	string str_plain = "";

	for(int i = 0; i < m_cipher.length(); i++){
		char c = m_cipher.at(i);

		// Listener
		//cout << "c (" << i << ") : " << c << endl;

		if((c > 96) && (c < 123)){
			c = ((c-'z')-key)%('z'-'a'+1)+'z'; // On recule de 3 en fesant attention que si l'on dépasse, on retombe au début de l'alphabet (ex: c-3 -> z)
		} else {
			// Le caractère n'est pas une lettre minuscule
		}

		str_plain = str_plain + c;
	}

	this->m_plain = str_plain;
	// D'apès la définition de la méthode encode dans la partie un du sujet, elle doit renvoyé m_cipher
	return this->m_plain;
}