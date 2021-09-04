#include <bits/stdc++.h>

using namespace std;

typedef  vector<int> vi;
typedef long long int64;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    vector<int> a;
    for (size_t i = 0; i < 7; i++)
    {
        a.push_back(i);
    }
    sort(a.begin(),a.end(), cmp);
    for (size_t i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    

}