#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

void atbash(string& data);
void cezar(string& data);
void gronsfeld(string& data);

extern int act_cel;  // 0 - шифрование, 1 - дешифрование
extern string type_inp;  // "1" - консоль, "2" - файл
extern const int LEN;  // Диапазон символов (126 для печатных ASCII)

#endif
