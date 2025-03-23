#include "functions.h"

string cypherAtb(string text, int max) {
    for (char& c : text) c = max - c + 1;
    return text;
}

string decypherAtb(string text, int max) {
    for (char& c : text) c = max - c + 1;
    return text;
}

void atbash(string data) {
    string newWord = data;
    cout << "Atbash" << endl;

    newWord = (act_cel == 0) ? cypherAtb(newWord, LEN) : decypherAtb(newWord, LEN);

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
