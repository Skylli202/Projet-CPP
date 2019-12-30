#include <iostream>
#include <string>

using namespace std;

#include "encrypt.h"
#include "caesar.h"
#include "caesar2.h"

//prototypage
void menu();
void testConstructeur();
void testLecture();
void testEcriture();
void testEncode();
void testDecode();
void testEncodeCaesar();
void testDecodeCaesar();
void testEncodeVariableCaesar();
void testDecodeVariableCaesar();
void testEncodeCaesar2();
void testDecodeCaesar2();

string askFile();
int askKey();


int main(){
	menu();
}

// Menu
void menu(){
	cout << "************" << endl;
	cout << "*** MENU ***" << endl;
	cout << "************" << endl << endl;
	cout << "Que souhaitez-vous tester ?" << endl
		<< "   1. constructeur" << endl
		<< "   2. lecture d'un fichier" << endl
		<< "   3. ecriture dans un fichier" << endl
		<< "   4. encode" << endl
		<< "   5. decode" << endl << endl
		<< "CAESAR : " << endl
		<< "   6. encode basique (key = 3)" << endl
		<< "   7. decode basique (key = 3)" << endl
		<< "   8. encode avec clef modifiable" << endl
		<< "   9. decode avec clef modifiable" << endl << endl
		<< "CAESAR2 : " << endl
		<< "   10. encode" << endl
		<< "   11. decode" << endl;

	int input;
	cin >> input;

	switch(input) {
		case 1 : testConstructeur();
				break;
		case 2 : testLecture();
				break;
		case 3 : testEcriture();
				break;
		case 4 : testEncode();
				break;
		case 5 : testDecode();
				break;
		case 6 : testEncodeCaesar();
				break;
		case 7 : testDecodeCaesar();
				break;
		case 8 : testEncodeVariableCaesar();
				break;
		case 9 : testDecodeVariableCaesar();
				break;
		case 10 : testEncodeCaesar2();
				break;
		case 11 : testDecodeCaesar2();
				break;
		default: cout << "Incorrect input value.\n Run again the program.\n Exiting..." << endl;
	}
}


// Corps des fonctions de test...

void testConstructeur(){
	// Testons le constructeur de la classe Encrypt
	Encrypt e;

	// Le constructeur initialise à "" les 2 membres de la classe.
	// Vérifions le :
	bool plain = e.get_plain() == "";
	bool cipher = e.get_cipher() == "";

	cout << "La variable membre plain est égale à la chaine vide : " << plain << endl;
	cout << "La variable membre plain est égale à la chaine vide : " << cipher << endl;
	cout << "RAPPEL :  0 == false | 1 == true" << endl;
}

void testLecture(){
	// Testons la lecture d'un fichier
	Encrypt e;

	e.read(true, "test_textFile/testRead.txt");
	e.read(false, "test_textFile/testRead.txt");

	cout << e.toString() << endl;
}

void testEcriture(){
	// Testons l'écriture dans un fichier
	Encrypt e;

	// Affectons à nos variables membres le texte stocker dans notre fichier texte.
	e.read(true, "test_textFile/testRead.txt");
	e.read(false, "test_textFile/testRead.txt");

	// Puis ecrivons le dans le fichier texte out.
	e.write(true,"test_textFile/testEcriturePlain.txt");
	e.write(false,"test_textFile/testEcritureCipher.txt");
}

void testEncode(){
	// Testons la methode encode
	Encrypt e;

	// Affectons à la variable membre m_plain une valeur (lecture d'un fichier)
	e.read(true, "test_textFile/testRead.txt");

	// Mais rien à m_cipher, a ce stade m_cipher vaut donc : "", la chaîne vide. Due au constructeur par défaut.
	// Appelons encode à présent...
	string returnedValue = e.encode();

	/* Normalement après l'éxécution de la méthode encode :
	 * 		- m_plain n'a pas été modifier et vaut ce qui a été lu dans le fichier.
	 *		- m_cipher vaut m_plain 
	 *		- returnedValue vaut ce qui a été stocker dans m_cipher (donc m_plain)	 		
	 */

	bool encodeIsWorking = e.get_plain() == returnedValue;
	cout << "La fonction a elle fonctionner correctement : " << encodeIsWorking << endl;
	cout << "Pour les détails, cf commentaire de la fonction testEncode() dans main.cpp" << endl;
	cout << "RAPPEL :  0 == false | 1 == true" << endl;
}

void testDecode(){
	// Testons la methode decode, raisonnement inverse à la méthode encode
	Encrypt e;

	// Affectons à la variable membre m_cipher une valeur (lecture d'un fichier)
	e.read(false, "test_textFile/testRead.txt");

	// Mais rien à m_plain, a ce stade m_plain vaut donc : "", la chaîne vide. Due au constructeur par défaut.
	// Appelons encode à présent...
	string returnedValue = e.decode();

	/* Normalement après l'éxécution de la méthode decode :
	 * 		- m_cipher n'a pas été modifier et vaut ce qui a été lu dans le fichier.
	 *		- m_plain vaut m_cipher 
	 *		- returnedValue vaut ce qui a été stocker dans m_plain (donc m_cipher)	 		
	 */

	bool encodeIsWorking = e.get_cipher() == returnedValue;
	cout << "La fonction a elle fonctionner correctement : " << encodeIsWorking << endl;
	cout << "Pour les détails, cf commentaire de la fonction testDecode() dans main.cpp" << endl;
	cout << "RAPPEL :  0 == false | 1 == true" << endl;
}

void testEncodeCaesar(){
	// Testons l'encodage par la méthode Caesar, cf in caesar.cpp les conditions de cette méthode
	Caesar c;

	c.read(true, "test_textFile/inputCaesarBasic.txt");

	cout << "e.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode();
	cout << "str (après encode) : " << str << endl;

	cout << "RAPPEL : Seul les caractères minuscules sont traitées." << endl;
}

void testDecodeCaesar(){
	// Testons l'encodage par la méthode Caesar, cf in caesar.cpp les conditions de cette méthode
	Caesar c;

	c.read(true, "test_textFile/inputCaesarBasic.txt");

	cout << "e.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode();
	cout << "str (après encode) : " << str << endl;

	str = c.decode();
	cout << "str (après decode) : " << str << endl;

	cout << "RAPPEL : Seul les caractères minuscules sont traitées." << endl;
}

void testEncodeVariableCaesar(){
	// Testons l'encodage par la méthode Caesar, cf in caesar.cpp les conditions de cette méthode
	Caesar c;

	c.read(true, "test_textFile/inputCaesarBasic.txt");

	// La clef renseigner doit être un nombre entier positif ou nul. Aucune vérification n'est faites.
	int key;
	cout << "Veuiller renseigner la clef de cryptage" << endl;
	cin >> key;

	cout << "e.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode(key);
	cout << "str (après encode) : " << str << endl;

	cout << "RAPPEL : Seul les caractères minuscules sont traitées." << endl;
}

void testDecodeVariableCaesar(){
	// Testons l'encodage par la méthode Caesar, cf in caesar.cpp les conditions de cette méthode
	Caesar c;

	c.read(true, "test_textFile/inputCaesarBasic.txt");

	// La clef renseigner doit être un nombre entier positif ou nul. Aucune vérification n'est faites.
	int key;
	cout << "Veuiller renseigner la clef de cryptage" << endl;
	cin >> key;

	cout << "e.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode(key);
	cout << "str (après encode) : " << str << endl;

	str = c.decode(key);
	cout << "str (après decode) : " << str << endl;

	cout << "RAPPEL : Seul les caractères minuscules sont traitées." << endl;
}

void testEncodeCaesar2(){
	// Testons l'encodage par la méthode Caesar, cf in caesar2.cpp les conditions de cette méthode
	Caesar2 c;

	//string filePath = askFile();
	//string filePath = "test_textFile/inputCaesarBasic.txt";
	string filePath = "test_textFile/inputCaesarProf.txt";
	c.read(true, filePath);

	int key = askKey();

	cout << "c.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode(key);
	cout << "str (après encode) : " << str << endl;
}

void testDecodeCaesar2(){
	// Testons l'encodage par la méthode Caesar, cf in caesar2.cpp les conditions de cette méthode
	Caesar2 c;

	//string filePath = askFile();
	//string filePath = "test_textFile/inputCaesarBasic.txt";
	string filePath = "test_textFile/inputCaesarProf.txt";
	c.read(true, filePath);

	int key = askKey();

	cout << "c.get_plain : " << c.get_plain() << endl;

	string str = c.get_plain();
	cout << "str (avant encode) : " << str << endl;

	str = c.encode(key);
	cout << "str (après encode) : " << str << endl;

	str = c.decode(key);
	cout << "str (après decode) : " << str << endl;
}

string askFile(){
	string filePath = "";
	cout << "chemin vers votre fichier texte (.txt),\n   ne dois pas inclure le ./\n   vous vous trouvez dans le répertoire ou ce trouve main.cpp" << endl;
	cin >> filePath;

	return filePath;
}

int askKey(){
	int key;
	cout << "Veuiller renseigner la clef de cryptage.\n elle doit être positive ou nul." << endl;
	cin >> key;

	if(key<0)
		key = askKey();

	return key;
}