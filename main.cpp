#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "functions.h"

using namespace std;

int act_cel = -1;
string type_inp = "";
const int LEN = 126;  // Максимальный печатный ASCII символ (~)

unsigned int simple_hash(const string& str) {
    unsigned int hash = 0;
    for (char c : str) hash = hash * 31 + c;
    return hash;
}

bool is_password_correct() {
    const unsigned int correct_hash = 2090756198; // Хэш для "mypassword"
    int attempts = 3;
    
    while (attempts--) {
        cout << "Password (" << attempts+1 << " attempts left): ";
        string input;
        cin >> input;
        
        if (simple_hash(input) == correct_hash) {
            cout << "Access granted!\n";
            return true;
        }
        cerr << "Wrong password!\n";
    }
    
    cerr << "Access denied!\n";
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    if (!is_password_correct()) {
        system("pause");
        return 1;
    }

    while (true) {
        system("cls");
        cout << "1. Atbash\n2. Caesar\n3. Gronsfeld\n0. Exit\n> ";
        
        int choice;
        cin >> choice;
        if (choice == 0) break;
        cin.ignore();

        string text;
        cout << "Input: console(1) or file(2)\n> ";
        getline(cin, type_inp);
        
        if (type_inp == "1") {
            cout << "Enter text:\n> ";
            getline(cin, text);
        } 
        else if (type_inp == "2") {
            cout << "Filename:\n> ";
            string filename;
            getline(cin, filename);
            ifstream file(filename);
            if (file) {
                getline(file, text, '\0');
            } else {
                cerr << "File error!\n";
                continue;
            }
        }

        cout << "Encrypt(1) or Decrypt(2)\n> ";
        cin >> act_cel;
        cin.ignore();

        switch (choice) {
            case 1: atbash(text); break;
            case 2: cezar(text); break;
            case 3: gronsfeld(text); break;
        }

        cout << "\nPress Enter...";
        cin.get();
    }
    return 0;
}
