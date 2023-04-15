#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
	
void enkripto(string& plaintext, string& ciphertext, int key) {
    int gjatesia_plaintext = plaintext.length();
    int rreshta = gjatesia_plaintext/key;
    if(gjatesia_plaintext%key!=0) {
        rreshta++;
        plaintext += string(key-gjatesia_plaintext%key, 'X');
    }

   
}

void decrypt(string& plaintext, string& ciphertext, int key){
    int gjatesia_ciphertext = ciphertext.length();
    int rreshta = (gjatesia_ciphertext + key - 1)/key;
}