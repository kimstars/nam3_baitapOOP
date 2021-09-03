#include <bits/stdc++.h>
#include <cmath>

using namespace std;
vector<string> res;
int a[100][100] = {0};
bool ok[100][100] = {0};
bool check = false;
int m, n;

void genArray()
{
    cout << "Nhap kich thuoc ma tran : (m,n) ";
    cin >> m >> n;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            a[i][j] = rand() % 2;
        }
    }
}

void PrintArr(int m, int n)
{
    cout << "______________________" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "______________________" << endl;
    cout << endl;
}

void Try(int i, int j, string s)
{
    if (a[i][j])
    {
        cout << "co min! you die\n";
        return;
    }
    else
    {
        if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
        {
            check = true;
            res.push_back(s);
            return;
        }

        if (i < n - 1 && !a[i + 1][j] && !ok[i + 1][j])
        {
            ok[i][j] = 1;
            Try(i + 1, j, s + "D"); //down
            ok[i][j] = 0;
        }

        if (j < n - 1 && !a[i][j + 1] && !ok[i][j + 1])
        {
            ok[i][j] = 1;
            Try(i, j + 1, s + "R"); // right
            ok[i][j] = 0;
        }

        if (j > 0 && !a[i][j - 1] && !ok[i][j - 1])
        {
            ok[i][j] = 1;
            Try(i, j - 1, s + "L"); //left
            ok[i][j] = 0;
        }

        if (i > 0 && !a[i - 1][j] && !ok[i - 1][j])
        {
            ok[i][j] = 1;
            Try(i - 1, j, s + "T"); // top
            ok[i][j] = 0;
        }
    }
}

int main()
{
    srand(time(0));
    int i, j;
    res.clear();

    genArray();

    PrintArr(m, n);
    cout << "nhap vi tri hien tai (i : so hang, j : so cot):";
    cin >> i >> j;
    cout << "(Diem hien tai se la diem bat dau ban di)\n(D: Down, T: Top, L: Left, R: Right)\n";

    Try(i, j, "");

    if (!res.size())
    {
        cout << "-1";
    }
    else
    {
        cout << "So phuong an tim duoc la : " << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }
}