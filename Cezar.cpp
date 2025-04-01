#include "functions.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>

using namespace std;

char processCaesarChar(char c, int step, bool encrypt) {
    if (!isalpha(c)) return c;
    
    char base = islower(c) ? 'a' : 'A';
    int shift = encrypt ? step : -step;
    return base + (c - base + shift + 26) % 26;
}

void cezar(string& data) {
    cout << "Caesar Cipher\n";
    
    int step;
    cout << "Enter key (1-25): ";
    while (!(cin >> step) || step < 1 || step > 25) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid key! Enter 1-25: ";
    }
    cin.ignore();

    string result;
    for (char c : data) {
        result += processCaesarChar(c, step, act_cel == 0);
    }

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
