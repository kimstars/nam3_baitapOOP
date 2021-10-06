#include <bits/stdc++.h>

using namespace std;

class Book
{
private:
    string name;
    string author;
    string nxb;
    string type;
    long price;

public:
    Book(string name, string author, string nxb, string type, long price) : name(name), author(author), nxb(nxb), type(type), price(price){};

    Book()
    {
        name = author = nxb = type = "";
        price = 0;
    };
    friend istream &operator>>(istream &in, Book &a);

    void Nhap()
    {
        cout << "Nhap ten sach : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Nhap tac gia sach " << name << " : ";
        fflush(stdin);
        getline(cin, author);
        cout << "Nha xuat ban sach " << name << " : ";
        fflush(stdin);
        getline(cin, nxb);
        // cout << "Nhap the loai sach " << name << " : ";
        // fflush(stdin);
        // getline(cin, type);
        cout << "Nhap gia ca sach  " << name << " : ";
        cin >> price;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap gia ca sach  " << name << " : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> price;
        }
    }
    friend ostream &operator<<(ostream &out, Book &);
    
    void setType(string type)
    {
        this->type = type;
    }

    void Xuat()
    {
        cout << "Sach  " <<setw(15)<< name << " | ";
        cout << "Tac gia :" <<setw(10)<< author << " | ";
        cout << "Nha xuat ban :" <<setw(10)<< nxb << " | ";
        cout << "The loai :" <<setw(10)<< type << " | ";
        cout << "Gia :" <<setw(10)<< price << endl;
    }
};

istream &operator>>(istream &in, Book &a)
{
    cout << "Nhap ten sach : ";
    fflush(stdin);
    getline(in, a.name);
    cout << "Nhap tac gia sach  " << a.name << " : ";
    fflush(stdin);
    getline(in, a.author);
    cout << "Nha xuat ban sach : " << a.name << " : ";
    fflush(stdin);
    getline(in, a.nxb);
    cout << "Nhap the loai sach " << a.name << " : ";
    fflush(stdin);
    getline(in, a.type);
    cout << "Nhap gia ca sach  " << a.name << " : ";
    in >> a.price;
    return in;
}

ostream &operator<<(ostream &out, Book &a)
{
    out << "Sach  " << a.name << " | ";
    out << "Tac gia :" << a.author << " | ";
    out << "Nha xuat ban :" << a.nxb << " | ";
    out << "Gia :" << a.price << endl;
    return out;
}
