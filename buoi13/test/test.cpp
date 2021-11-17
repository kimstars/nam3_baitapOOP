#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
void toString(string &str, char value[30])
{
    str = "";
    for (int i = 0; i < strlen(value); i++)
        str = str + value[i];
}


int main(){
    char name[30] = "chutuankiet";
    string a;
    toString(a,name);
    cout << a.length();

}