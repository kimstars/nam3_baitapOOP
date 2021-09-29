#include "nguoi.h"


class SV : public Nguoi
{
private:
    double diemtb;
public:
    SV(){};
    SV(string name, int birth, bool gender, double diemtb):Nguoi(name, birth, gender){
        diemtb = diemtb;
    }
    ~SV();
    void Nhap()
    {
        Nguoi::Nhap();
        cout << "nhap diem cua sv : ";
        cin >> diemtb;
    }
    void Xuat(){
        cout << "Thong tin sinh vien : " << endl;
        Nguoi::Xuat();
        cout << "- Diem trung binh : " << diemtb << endl;
        Xeploai();
    }

    void Xeploai(){
        cout << "Xep loai sinh vien : ";
        if(diemtb >= 8){
            cout << "Gioi\n";
        }else if(diemtb >= 6 && diemtb < 8){
            cout << "Kha\n";
        }else{
            cout << "Trung binh\n";
        }
    }


};
