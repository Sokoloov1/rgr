#include "functions.h"

using namespace std;

int funMod(int simbl, int numkey, int quaAlp) {
    int sunNum = simbl + numkey;
    return sunNum % quaAlp;
}

string funCrypGro(string word, string key) {
    string cryp_word;
    for (size_t i = 0; i < word.size(); i++) {
        int value = funMod(word[i], key[i % key.size()] - 48, LEN);
        cryp_word.push_back(value < 33 ? value + 33 : value);
    }
    return cryp_word;
}

string funEncrypGro(string word, string key) {
    string encryp_word;
    for (size_t i = 0; i < word.size(); i++) {
        int key_val = key[i % key.size()] - 48;
        int value = word[i] - key_val;
        encryp_word.push_back(value < 32 ? -1 - (33 - value) + 1 : value);
    }
    return encryp_word;
}

void gronsfeld(string data) {
    string newWord = data;
    cout << "Gronsfeld" << endl;
    string key = "12945";
    
    if (act_cel == 0) {
        newWord = funCrypGro(data, key);
    } else if (act_cel == 1) {
        newWord = funEncrypGro(newWord, key);
    }

    if (type_inp == "1") {
        cout << (act_cel == 0 ? "The encoded message: " : "The decoded message: ") << newWord << endl;
    } else {
        ofstream File(act_cel == 0 ? "ciphertext.txt" : "deciphertext.txt");
        File << newWord;
        File.close();
        cout << "File created" << endl;
    }
    act_cel = -1;
}
