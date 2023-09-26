/*Ricardo Varona
CPSC 1071
4/3/2023
*/

#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include "Queue.h"
using namespace std;

class Cipher{
	public:
		// Include default constructor, and all needed prototypes for functions used in Cipher.cpp
		Cipher();
		void setCipher(int, int[]);
		int * getCipher();
		string encodeMessage(string in);
		string decodeMessage(string in);
	private:
		// size and original key intitalized in header so that can easily be used throughout cipher.cpp.
		int size;
		// array size set to 100
        	int storeOriginalKey[100];
		// Queue object created in private so can easily be used throughout cipher.cpp and private outside file
		Queue key;

};
#endif
