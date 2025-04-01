#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "functions.h"

using namespace std;

int act_cel = -1;
string type_inp = "";

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

        string text;
        cout << "Input: console(1) or file(2)\n> ";
        cin >> type_inp;
        cin.ignore();
        
        if (type_inp == "1") {
            cout << "Enter text:\n> ";
            getline(cin, text);
        } 
        else if (type_inp == "2") {
            cout << "Filename:\n> ";
            string filename;
            cin >> filename;
            cin.ignore();
            ifstream file(filename);
            getline(file, text, '\0');
        }

        cout << "Encrypt(1) or Decrypt(2)\n> ";
        cin >> act_cel;
        cin.ignore();

        switch (choice) {
            case 1: atbash(text); break;
            case 2: cezar(text); break;
            case 3: gronsfeld(text); break;
        }

        cout << "\nResult:\n" << text << "\n\nPress Enter...";
        cin.get();
    }
    return 0;
}
