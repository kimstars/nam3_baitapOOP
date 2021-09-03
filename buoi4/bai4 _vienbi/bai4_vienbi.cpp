#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void doivitri(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int n;
    cin >> n;
    srand(time(0));
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 3 + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }

    cout << endl;

    int i = 0, j = n-1; // i ->>>> 1123213131323123213  <<<<- j
    int left = 0, right = n-1;

    for(int i = 0; i < n; i++){
        if(a[i] == 1) doivitri(a[i] , a[left++]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 3 ) doivitri(a[i] , a[right--]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}