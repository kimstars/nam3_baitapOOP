#include "Book.h"

class Sach : public Book
{
private:
    string author;
    int sotrang;

public:
    void Nhap()
    {
        cout << "Nhap SACH: ";
        Book::Nhap();
        cout << "Nhap ten tac gia : ";
        fflush(stdin);
        getline(cin, author);
        cout << "Nhap so trang sach '" << name << "' : ";
        cin >> sotrang;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap so trang sach '" << name << "' : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> sotrang;
        }
    }

    void Xuat()
    {
        cout << "SACH : ";
        Book::Xuat();
        cout << "Tac gia : " << left << setw(20) << author << " | ";
        cout << "So trang sach :" << setw(10) << id << endl;
    }

    bool CheckType(int type)
    {
        if (type == 1)
            return 1;
        return 0;
    }
};