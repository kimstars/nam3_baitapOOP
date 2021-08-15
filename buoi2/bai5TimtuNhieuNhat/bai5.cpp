#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<string> split(string str, string sep)
{
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL)
    {
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

int main()
{
    vector<string> s;
    string a;

    getline(cin, a);
    s = split(a," "); //tách câu theo dấu cách

    set<string> setS(s.begin(), s.end());


    map<string, int> data;
    int max = 0;
    string res = "";
    for (set<string>::iterator it = setS.begin(); it != setS.end(); it++)
    {
        data[*it] = 0;
        for(int j = 0 ; j < s.size(); j++){
            if(s[j] == *it) data[*it]++;
        }
        if(data[*it] > max){
            max = data[*it];
            res = *it;
        }
        cout << *it << " : " << data[*it] << endl;
    }

    cout << endl << "Tu xuat hien nhieu nhat la: " << res << " xuat hien " << max  << " lan";

}


    
    