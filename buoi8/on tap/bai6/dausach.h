#include "book.h"


class dausach:public Book {
private:
    string name;
    int n;
    vector<Book *> listBook;

public :
    void Nhap(){
        cout << "Nhap ten dau sach : ";
        fflush(stdin);
        getline(cin, name);
    }

    void addBook(){
        cout << "nhap so luong sach them vao " << name << " : "; 
        cin >> n;
        for (int i = 0; i < n; i++)
        {      
            cout << "Nhap sach thu " << i+1 << endl;
            listBook.push_back(new dausach());
            listBook[listBook.size()-1]->Nhap();
            listBook[listBook.size()-1]->setType(name);
        }  
    }
    string getName(){
        return name;
    }
    int getSizeList(){
        return listBook.size();
    }

    void Xuat(){
        cout << "Dau sach : " << name << endl;

        for (int i = 0; i < n; i++)
        {      
            cout <<setw(2) << i+1 << " ";
            listBook[i]->Xuat();
        }  
    }
    
    

};