
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, string sep)
{
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    vector<string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL)
    {
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

int main(){
    string name ;
    getline(cin, name);
    vector<string> a = split(name, " ");
    string res = "";
    std::reverse(a.begin(),a.end());
    res += a[0];
    for (int i = 1; i < a.size(); i++)
    {
        res += " " + a[i];
    }
    cout << endl;
    cout << res[0];
    

}