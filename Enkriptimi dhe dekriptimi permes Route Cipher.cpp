#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
		Tani do të krijojmë një funksion i cili do të enkriptojë plaintextin tonë përmes enkriptimit Route Cipher.
		Enkriptimi Route Cipher kryhet me anë të matricës,pra duke e marre gjdo karakter te plaintextit dhe vendosur
		në një pozitë të matricës. 
		Kolonat dhe rreshtat e matricës i caktojmë si ne vijim: Kolonat janë të barabarta me çelësin të cilin e vendosim
		ne.Ndërsa rreshtat i caktojmë duke pjestuar gjatësin e plaintextit me çelësin.
*/	

void enkripto(string& plaintext, string& ciphertext, int key) {
    int gjatesia_plaintext = plaintext.length();
    int rreshta = gjatesia_plaintext/key;
    if(gjatesia_plaintext%key!=0) {
        rreshta++;
         //Pozitat që mbesin të zbrasta i mbushim me X(ose çfarëdo vlere që vendosim) 
        plaintext += string(key-gjatesia_plaintext%key, 'X');
    }
    	//lexojmë ciphertextin
    for(int i=0; i<key; i++) {
        for(int j=0; j<rreshta; j++) {
            ciphertext += plaintext[j*key+i];
        }
    }
   
}

void decrypt(string& plaintext, string& ciphertext, int key){
    
    int gjatesia_ciphertext = ciphertext.length();
    int rreshta = (gjatesia_ciphertext + key - 1)/key;

    int extra = rreshta * key - gjatesia_ciphertext;
    if (extra > 0) {
        for (int i = 0; i < extra; i++) {
            ciphertext += 'X';
        }
    }
}

int main() {
	string plaintext = "Kyprogramkametefunksionu";
	string ciphertext = "";
	int key = 4;
	
	enkripto(plaintext, ciphertext, key);
	cout << "Teksti i enkriptuar: " << ciphertext << endl;
}
