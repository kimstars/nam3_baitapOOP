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
    s = split(a," ");

    set<string> setS(s.begin(), s.end());


    map<string, int> data;

    for (set<string>::iterator it = setS.begin(); it != setS.end(); it++)
    {
        data[*it] = 0;
        for(int j = 0 ; j < s.size(); j++){
            if(s[j] == *it) data[*it]++;
        }
        cout << *it << " : " <<data[*it] << endl;
    }

}


    
    