#include "functions.h"

string cypher(string text, int step, int max) {
    for (char& c : text) c = (c + step) % max;
    return text;
}

string decypher(string text, int step, int max) {
    for (char& c : text) c = (c - step) % max;
    return text;
}

void cezar(string data) {
    string newWord = data;
    cout << "Cezar" << endl;

    int step;
    cout << "Enter the key value: ";
    cin >> step;

    newWord = (act_cel == 0) ? cypher(newWord, step, LEN) : decypher(newWord, step, LEN);

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
