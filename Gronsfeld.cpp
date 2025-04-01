#include "functions.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const string DEFAULT_KEY = "12945";

int charToDigit(char c) {
    return isdigit(c) ? c - '0' : 0;
}

char processGronsfeldChar(char c, int key_digit, bool encrypt) {
    if (!isprint(c)) return c;
    
    int shift = encrypt ? key_digit : -key_digit;
    int result = c + shift;
    
    // Коррекция для печатных символов (33-126)
    const int MIN_PRINT = 33;
    result = MIN_PRINT + (result - MIN_PRINT + 94) % 94;
    return static_cast<char>(result);
}

void gronsfeld(string& data) {
    cout << "Gronsfeld Cipher\n";
    
    string key;
    cout << "Enter key (digits only, empty for default): ";
    getline(cin, key);
    
    if (key.empty()) key = DEFAULT_KEY;
    key.erase(remove_if(key.begin(), key.end(), 
             [](char c) { return !isdigit(c); }), key.end());
    if (key.empty()) key = DEFAULT_KEY;

    string result;
    for (size_t i = 0; i < data.size(); ++i) {
        int key_digit = charToDigit(key[i % key.size()]);
        result += processGronsfeldChar(data[i], key_digit, act_cel == 0);
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
