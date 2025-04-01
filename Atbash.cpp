#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

string processAtbash(string text) {
    for (char& c : text) {
        if (isprint(c)) {
            c = LEN - c;
        }
    }
    return text;
}

void atbash(string& data) {
    cout << "Atbash Cipher\n";
    string result = processAtbash(data);

    if (type_inp == "1") {
        cout << (act_cel == 0 ? "Encoded: " : "Decoded: ") << result << endl;
    } else {
        string filename = act_cel == 0 ? "ciphertext.txt" : "deciphertext.txt";
        ofstream file(filename);
        if (file) {
            file << result;
            cout << "File saved: " << filename << endl;
        } else {
            cerr << "Error creating file!" << endl;
        }
    }
}
