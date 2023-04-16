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
    int rreshta = (gjatesia_ciphertext + key - 1)/key; // calculate number of rows

    // pad ciphertext with 'X' characters if necessary
    int extra = rreshta * key - gjatesia_ciphertext;
    if (extra > 0) {
        for (int i = 0; i < extra; i++) {
            ciphertext += 'X';
        }
    }

    // build decryption table
    char table[rreshta][key];
    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < row; j++) {
            table[j][i] = ciphertext[index];
            index++;
        }
    }
    
    // read plaintext from table
    plaintext = "";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < key; j++){
			plaintext += table[i][j];
		}
	}
	
    // remove trailing 'X' characters if necessary
    if (extra > 0) {
	    plaintext.erase(gjatesia_ciphertext);
    }
}

int main() {
	string plaintext = "Kyprogramkametefunksionu";
	string ciphertext = "";
	int key = 4;
	
	enkripto(plaintext, ciphertext, key);
	cout << "Teksti i enkriptuar: " << ciphertext << endl;
	
	string decryptedText = "";
        decrypt(decryptedText, ciphertext, key);
        cout << "Teksti i dekriptuar:  " << decryptedText << endl;

    return 0;
}
