#include <iostream>
#include <string>
#include <windows.h>
#include <functional>
#include "functions.h"
#include <iomanip>
#include <fstream>
#include <stdexcept>

using namespace std;

// Прототипы функций
unsigned int simple_hash(const string &str);
bool is_password_correct();
string read_file(const string& filename);
void atbash(string &text);
void cezar(string &text);
void gronsfeld(string &text);

int act_cel = -1;
string type_inp = "";
const int LEN = 255;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    if(!is_password_correct()) return 0;
    
    while (true) {
        try {
            int num_method;
            string content, nl;
            bool error = true;
            
            system("cls");
            cout << "Select encryption method:\n"
                 << "1 - Atbash\n"
                 << "2 - Cezar\n"
                 << "3 - Gronsfeld\n"
                 << "Choice: ";
            cin >> num_method;
            getline(cin, nl);
            
            cout << "Select input type: console(1) or file(2)" << endl 
                 << "Choice: ";
            getline(cin, type_inp);
            
            if (type_inp == "1") {
                cout << "Enter text: ";
                getline(cin, content);
            } 
            else if (type_inp == "2") {
                string filename;
                cout << "Input file name: ";
                cin >> filename;
                content = read_file(filename);

                if (content.empty()) {
                    cout << "File not found or error reading file. Try again." << endl;
                    continue;
                }
            } 
            else {
                error = false;
                cout << "You must make correct choice" << endl;
            }

            if (error) {
                int var;
                cout << "Select the type of operation: encrypt(1) or decrypt(2)" << endl 
                     << "Choice: ";
                cin >> var;
                cout << endl;
                
                act_cel = (var == 1) ? 0 : 1;
                cout << "Method: ";
                
                switch (num_method) {
                    case 1: 
                        atbash(content); 
                        break;
                    case 2: 
                        cezar(content); 
                        break;
                    case 3: 
                        gronsfeld(content); 
                        break;
                    default:
                        cout << "Invalid choice. Try again." << endl;
                        continue;
                }
            }
            
            char exit = ' ';
            while (true) {
                cout << "Do you want to exit? (Y/N): ";
                cin >> exit;
                if (exit == 'Y' || exit == 'N') break;
                system("cls");
            }
            if (exit == 'Y') break;
        }
        catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << endl;
        }
    }
    return 0;
}

// Функция проверки пароля
bool is_password_correct() {
    const unsigned int stored_hash = 1216985755;
    int attempts = 0;
    const int max_attempts = 3;

    try {
        while (attempts < max_attempts) {
            string input_password;
            cout << "Enter your password: ";
            cin >> input_password;

            if (cin.fail()) {
                throw invalid_argument("Invalid input. Please enter a valid password.");
            }

            unsigned int input_hash = simple_hash(input_password);
            if (stored_hash == input_hash) {
                cout << "Access granted!" << endl;
                return true;
            } 
            else {
                attempts++;
                cout << "Wrong password! Attempts left: " << (max_attempts - attempts) << endl;
            }
        }
        cout << "Maximum attempts exceeded. Access denied!" << endl;
        return false;
    } 
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
        return false;
    }
}

// Хэш-функция для пароля
unsigned int simple_hash(const string &str) {
    unsigned int hash = 0;
    for (char c : str) {
        hash = hash * 31 + c;
    }
    return hash;
}

// Чтение из файла
string read_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File not found or could not be opened.");
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();

    return content;
}

// Реализация шифров (заглушки - нужно заменить на реальные реализации)
void atbash(string &text) {
    cout << "Atbash cipher applied to: " << text << endl;
    // Реальная реализация шифра Атбаш
}

void cezar(string &text) {
    cout << "Caesar cipher applied to: " << text << endl;
    // Реальная реализация шифра Цезаря
}

void gronsfeld(string &text) {
    cout << "Gronsfeld cipher applied to: " << text << endl;
    // Реальная реализация шифра Гронсфельда
}
