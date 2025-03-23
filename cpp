#include <iostream>
#include <string>
#include <windows.h>  
#include <fstream>    // Для работы с файлами
#include <stdexcept>  // Для обработки исключений

using namespace std;

// Функция для шифрования/дешифрования методом Атбаш
string atbash(const string& text) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {  // Проверяем, является ли символ буквой
            char base = isupper(c) ? 'A' : 'a';  // Определяем базовый символ (A для заглавных, a для строчных)
            result += static_cast<char>(base + 25 - (c - base));  // Преобразуем символ по правилу Атбаша
        } else {
            result += c;  // Если символ не буква, оставляем его без изменений
        }
    }
    return result;
}

// Функция для шифрования/дешифрования методом Цезаря
string caesar(const string& text, int shift) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {  // Проверяем, является ли символ буквой
            char base = isupper(c) ? 'A' : 'a';  // Определяем базовый символ
            // Применяем сдвиг и учитываем зацикливание алфавита
            result += static_cast<char>((c - base + shift + 26) % 26 + base);
        } else {
            result += c;  // Если символ не буква, оставляем его без изменений
        }
    }
    return result;
}

// Функция для шифрования/дешифрования методом Гронсфельда
string gronsfeld(const string& text, const string& key) {
    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (isalpha(c)) {  // Проверяем, является ли символ буквой
            char base = isupper(c) ? 'A' : 'a';  // Определяем базовый символ
            int shift = key[i % key.size()] - '0';  // Получаем сдвиг из ключа (цифра)
            // Применяем сдвиг и учитываем зацикливание алфавита
            result += static_cast<char>((c - base + shift + 26) % 26 + base);
        } else {
            result += c;  // Если символ не буква, оставляем его без изменений
        }
    }
    return result;
}

// Функция для чтения содержимого файла
string read_file(const string& filename) {
    ifstream file(filename);  // Открываем файл для чтения
    if (!file.is_open()) {  // Проверяем, удалось ли открыть файл
        throw runtime_error("File not found or could not be opened.");  // Если нет, выбрасываем исключение
    }
    // Читаем всё содержимое файла в строку
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();  // Закрываем файл
    return content;
}

int main() {
    // Устанавливаем кодировку консоли для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {  // Основной цикл программы
        try {
            int num_method;
            string content, nl;
            system("cls");  // Очищаем консоль
            cout << "Select encryption method:\n"
                 << "1 - Atbash\n"
                 << "2 - Caesar\n"
                 << "3 - Gronsfeld\n"
                 << "Choice: ";
            cin >> num_method;  // Пользователь выбирает метод шифрования
            getline(cin, nl);  // Очищаем буфер ввода

            cout << "Select input type: console(1) or file(2)\nChoice: ";
            string type_inp;
            getline(cin, type_inp);  // Пользователь выбирает тип ввода

            if (type_inp == "1") {  // Ввод текста через консоль
                cout << "Enter text: ";
                getline(cin, content);
            } else if (type_inp == "2") {  // Ввод текста из файла
                string filename;
                cout << "Input file name: ";
                cin >> filename;
                content = read_file(filename);  // Читаем содержимое файла
                if (content.empty()) {
                    cout << "File not found or error reading file. Try again.\n";
                    continue;  // Если файл пуст, возвращаемся в начало цикла
                }
            } else {
                cout << "Invalid choice. Try again.\n";
                continue;  // Если ввод некорректен, возвращаемся в начало цикла
            }

            int var;
            cout << "Select the type of operation: encrypt(1) or decrypt(2)\nChoice: ";
            cin >> var;  // Пользователь выбирает операцию (шифрование или дешифрование)
            cin.ignore();  // Очищаем буфер ввода

            string result;
            switch (num_method) {
                case 1:  // Атбаш
                    result = atbash(content);
                    break;
                case 2:  // Цезарь
                    int shift;
                    cout << "Enter shift value: ";
                    cin >> shift;  // Пользователь вводит сдвиг для шифра Цезаря
                    cin.ignore();
                    result = caesar(content, (var == 1) ? shift : -shift);  // Шифруем или дешифруем
                    break;
                case 3:  // Гронсфельд
                    string key;
                    cout << "Enter key (digits only): ";
                    cin >> key;  // Пользователь вводит ключ для шифра Гронсфельда
                    cin.ignore();
                    result = gronsfeld(content, key);
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    continue;  // Если метод выбран некорректно, возвращаемся в начало цикла
            }

            cout << "Result: " << result << "\n";  // Выводим результат

            char exit;
            while (true) {
                cout << "Do you want to exit? (Y/N): ";
                cin >> exit;
                if (exit == 'Y' || exit == 'N') break;  // Пользователь выбирает, выйти или продолжить
                system("cls");
            }
            if (exit == 'Y') break;  // Выход из программы
        } catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << endl;  // Обработка исключений
        }
    }

    return 0;
}
