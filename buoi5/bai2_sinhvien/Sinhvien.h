#include "chuanhoa.h"

class Sinhvien
{
private:
    int maSV;
    string name;
    double diemtb;

public:
    string lastName;
    Sinhvien()
    {
        maSV = 0;
        lastName = name = "";
        diemtb = 0;
    }

    Sinhvien(int maSV, string name, double diemtb) : maSV(maSV), name(name), diemtb(diemtb){};
    void Nhap();
    void Show();
    string Tachten();
    double getDiem()
    {
        return diemtb;
    }
};

void Sinhvien::Nhap()
{
    int num;
    cout << "Nhap ma sv : ";
    while (!(cin >> num))
    {
        cout << "ERROR: a number must be entered: ";
        cin.clear();
        cin.ignore(132, '\n');
    }
    maSV = num;
    cout << "Nhap ten SV : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    name = chuanhoa(name);
    lastName = Tachten();
    cout << "Nhap diem trung binh : ";
    cin >> diemtb;
}

void Sinhvien::Show()
{
    cout << "ma sv : " << maSV << ", ";
    cout << "Ten SV : " << name << ", ";
    cout << "Diem trung binh : " << diemtb << "\n";
}

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

string Sinhvien::Tachten()
{
    vector<string> a = split(name, " ");
    // string res = "";
    // std::reverse(a.begin(),a.end());
    // res += a[0];
    return a[a.size() - 1];
}
