/*Ricardo Varona
CPSC 1071
4/3/2023
*/

// needed c++ header files and namespace std
#include <iostream>
#include <string>
#include "Queue.h"
#include "Cipher.h"
using namespace std; 


// Main purpose is to serve as a driver and pass array size and values to setCipher
int main(void) {
	// create cipher object called test
	Cipher test;
	// declare array with set size and key
	int array[4] =  {1, 2, 3, 4};
	// pass size and keys by calling setCipher
	test.setCipher(4, array);
	// pointer created to get key value
	int* cipher = test.getCipher();
	// create printCipher array to store keyValues into an array which I can print out
	int printCipher[4] = {cipher[0], cipher[1], cipher[2], cipher[3]};
	// prints out key as shown in sample output
	cout<<"Key: [";
	for(int i = 0; i < 4; i++) {
		cout<<printCipher[i];
		if(i < 3) {
		cout<<", ";
		}
	}
	cout<<"]"<<endl;
	// prints out message to be encoded and encoded message in proper format
	string testString ="Secret Message!";
	string output = test.encodeMessage(testString);
	cout<<"Encoding: "<<testString<<endl;
	cout<<"Encoded: "<<output<<endl<<endl;
	
	// prints out key, message to be decoded, and decoded message in proper format
	string output2 = test.decodeMessage(output);
	cout<<"Key: [";
        for(int i = 0; i < 4; i++) {
                cout<<printCipher[i];
                if(i < 3) {
                cout<<", ";
                }
        }
        cout<<"]"<<endl;
	cout<<"Decoding: "<<output<<endl;
	cout<<"Decoded: "<<output2;

	
}	
