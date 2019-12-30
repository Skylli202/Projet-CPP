using namespace std;

#include "encrypt.h"

// Constructeur de la class Encrypted
Encrypt::Encrypt(){
	this->m_plain = "";
	this->m_cipher = "";
}

// Getter
string Encrypt::get_plain() const{
	return this->m_plain;
}

string Encrypt::get_cipher() const{
	return this->m_cipher;
}
// Setter


// Method
// ----- Lecture ------
bool Encrypt::read(bool isPlain, string filename){
	// Ouverture d'un fichier en lecture
	ifstream myStream("./" + filename);  
	
	// Tout est prêt pour la lecture
	if(myStream)
	{
	    // Création d'un variable temporaire pour lire le fichier
	    string str;

	    // Lecture du fichier tant qu'il y en a une ligne...
      	while(getline(myStream, str)) {
      		if(isPlain){
      			this->m_plain += str + "\n" ;
      		} else {
      			this->m_cipher += str + "\n";
      		}
      	}
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	    return false;
	}


	return true;
}

// ----- ecriture ------
bool Encrypt::write(bool isPlain, string filename){
	ofstream myStream("./"+filename);

	// Tout est prêt pour l'écriture
	if(myStream){
		if(isPlain){
			myStream << this->m_plain << endl;
		} else {
			myStream << this->m_cipher << endl;
		}
	} else {
		cout << "ERREUR: Impossible d'ouvrir le fichier en écriture." << endl;
	    return false;
	}
	
	myStream.close();
	return true;
}

string Encrypt::encode(){
	this->m_cipher = this->m_plain;
	return this->m_cipher;
}

string Encrypt::decode(){
	this->m_plain = this->m_cipher;
	return this->m_plain;
}

string Encrypt::toString(){
	string res = "";
	res += "m_plain : \n" + this->m_plain;
	res += "\n";
	res += "m_cipher : \n" + this->m_cipher;
	return res;
}

