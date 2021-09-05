#include "Tron.h"
#include "Tamgiac.h"
#include "HCN.h"
#include "Hinh.h"

class ThucThi{
    private:
        vector<Hinh*> hinhhoc;
        int n1, n2, n3;

    public:
    ThucThi(){
        hinhhoc.resize(0);
        n1= n2= n3 =0;
    }
        void Nhap(vector<Hinh*> &hinhhoc);
        void TimMax(vector<Hinh*> &hinhhoc);
        void thucthi();
};

void ThucThi::Nhap(vector<Hinh*> &hinhhoc){\

    cout << "Nhap so hinh chu nhat : ";
    cin >> n1;
    cout << "Nhap so hinh tam giac : ";
    cin >> n2;
    cout << "Nhap so hinh tron : ";
    cin >> n3;

    cout <<"\nNhap "<< n1 <<" HCN:\n";
    for (int i = 0; i < n1; i++) //array hinh chu nhat
    {
        cout <<"\nNhap HCN "<< i <<" :\n";
        hinhhoc.push_back(new HCN());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }
    cout <<"\nNhap "<< n2 <<" tam giac:\n";
    for (int i = 0; i < n2; i++) //array hinh tam giac
    {
        cout <<"\nNhap tam giac "<< i <<" :\n";

        hinhhoc.push_back(new Tamgiac());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }
    cout <<"\nNhap "<< n3 <<" hinh tron:\n";

    for (int i = 0; i < n3; i++) //array hinh tron
    {
        cout <<"\nNhap hinh tron "<< i <<" :\n";
        hinhhoc.push_back(new Tron());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }

    if(hinhhoc.size()){
        for (int i = 0; i < n1+n2+n3; i++)
        {
            hinhhoc[i]->Print();
        }

    }

}

void ThucThi::TimMax(vector<Hinh*> &hinhhoc){
    double Smax = 0;
    int index = -1;
    for (int i = 0; i < hinhhoc.size() ; i++)
    {
        double temp = hinhhoc[i]->getDienTich();
        if(Smax < temp){
            Smax = temp;
            index = i;
        }
    }
    if(index == -1){
        cout << "Khong tim thay hinh co dien tich lon nhat!!";
    }else{
        cout << "Hinh " << hinhhoc[index]->getName() << " voi Dien tich = " << Smax << endl;
        // cout << hinhhoc[index]->getDienTich() << endl;
    }
    


}


void ThucThi::thucthi(){
    int CatchKey;
    do
    {
        cout << "\n______________________________________________\n";
        cout << "Lua chon tinh nang: \n";
        cout << "\t Press 1. Nhap danh sach cac hinh.\n";
        cout << "\t Press 2. Tim hinh co DIEN TICH lon nhat.\n";
        // cout << "\t Press 3. Danh sach nhan vien.\n";
        // cout << "\t Press 4. Tong luong phai chi tra cho nhan vien.\n";
        // cout << "\t Press 5. Xoa mot nhan vien theo id.\n";
        // cout << "\t Press 6. Khac\n";
        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 0)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            Nhap(hinhhoc);
            break;

        case 2:
            TimMax(hinhhoc);
            break;
        
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}
