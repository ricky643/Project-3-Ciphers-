/*Ricardo Varona
CPSC 1071
4/3/2023
*/

#include <iostream>
#include <string>
#include "Cipher.h"
using namespace std;

// default constructor to set default key
Cipher::Cipher() {
	// initializng key to to one, two, three, four
	// calls set cipher which enques default key. 
	int callCipher[] = {1,2,3,4};
	setCipher(4, callCipher); 
}

// Function sets cipher value to be used in the queue given the size and key values
void Cipher::setCipher(int insize, int setKeys[]) {
	// clears default key
	key.clear();
	// sets size = to size declared in driver
	size = insize;
	
	// for the length of the size, checks if key goes over 25,
	// then uses modulo to ensure key will corrospond to the correct letter in a cipher
	for(int i = 0; i < size; i++) {
	       if(setKeys[i] > 25)  {
                       setKeys[i] = setKeys[i] % 26;
               }
	       // for the length of the size, checks if key goes under 25 ,
               // then uses modulo to ensure key will corrospond to the correct letter in a cipher
	       else if(setKeys[i] < -25) {
		       setKeys[i] = setKeys[i] % 26;
	       }
	       // enqueues each key value into the queue
	       key.enqueue(setKeys[i]);
	       // ensuring original key is stored at some point in an array
	       storeOriginalKey[i] = setKeys[i];
	}
}

// uses a pointer to point to the array where the original key is stored
int * Cipher::getCipher() {
	return storeOriginalKey;
}

// Purpose of fucntion is to encode a string passed through
string Cipher::encodeMessage(string in) {
	// declare needed variables to encode string in and print encoded string out
	int keyValue;
	string finalE = "";
	int collectLetter = 0;

	// sets each character in string to lowercase by cycling through each character for the length of thr string
	for(int i = 0; i < static_cast<int>(in.length()); i++) {
                        in[i] = tolower(in[i]);
	}
	// for the length of the string
	for(int i = 0; i < static_cast<int>(in.length()); i++ ) {
		// ensures ascii characters are lowercase letters between and z. Will exclude special characters
		if(in[i] >= 97 && in[i] <= 122) {
			// sets collectLetter value to character value in string in
			collectLetter = in[i];	
			// dequeues the queue and sets keyValue to the value that was in queue
			key.dequeue(keyValue);
			//adds the keyValue to the value retrieved in collect letter to properly encode each letter
			collectLetter += keyValue;
			// if the letter goes over the value of 122(z), then it will subtract the letter value by 26(corrosponds to letters in alphabet)
			if(collectLetter > 122) {
                                collectLetter = collectLetter - 26;
			}
			// if the letter goes below the value of 97, adds the letter value by 26(needed for when negative numbers are in queue)
			if(collectLetter < 97) {
				collectLetter = collectLetter + 26;
			}
			// enqueues the current key value into the queue 
			key.enqueue(keyValue);
			// static cast to char to have ascii values print our as characters
			finalE += static_cast<char>(collectLetter);
		}
	}
	// returns encoded string
	return finalE;
}

// Purpose of function is to decode a message by shifting letters back by the amount in the key
string Cipher::decodeMessage(string in) {
	// calls set cipher to get the original order of the key. Key order will be out of order otherwise since it was already used in encodeMessage
	setCipher(size, storeOriginalKey);
	// declare needed variables to decodeMessage	
	int keyValue;
        string finalDecode = "";
        // declare as int to correctly modify ascii values
        int collectLetter;

	// sets each character in string to lowercase by cycling through each character for the length of thr string
        for(int i = 0; i < static_cast<int>(in.length()); i++) {
                        in[i] = tolower(in[i]);
	}
	// for the length of the string
        for(int i = 0; i < static_cast<int>(in.length()); i++ ) {
		// ensures ascii characters are lowercase letters between and z. Will exclude special characters
                if(in[i] >= 97 && in[i] <= 122) {
			// sets collectLetter value to character value in string in
                        collectLetter = in[i];
			// dequeues the queue and sets keyValue to the value that was in queue
                        key.dequeue(keyValue);
			//subtracts the keyValue to the value retrieved in collect letter to properly decode each letter
                        collectLetter -= keyValue;
			// if the letter goes over the value of 122(z), then it will subtract the letter value by 26(corrosponds to letters in alphabet)
                        if(collectLetter > 122) {
                                collectLetter = collectLetter - 26;
                        }
			// if the letter goes below the value of 97, adds the letter value by 26(needed for when negative numbers are in queue)
                        if(collectLetter < 97) {
                                collectLetter = collectLetter + 26;
                        }
			// enqueues the current key value into the queue
                        key.enqueue(keyValue);
                        // static cast to char to have ascii values print our as characters
                        finalDecode += static_cast<char>(collectLetter);
                }
        }
	// returns decoded string
        return finalDecode;
}

	







