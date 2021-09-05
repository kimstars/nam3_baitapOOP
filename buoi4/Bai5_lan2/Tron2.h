#include "Hinh1.h"


class Tron: public Hinh{
    private:
        double R;
    public:
        Tron(){};
        Tron(double R):R(R){};

        void Nhap(){
            cout << "Nhap R: ";
            cin >> R; 
            setDienTich();
        }
        double getDienTich(){
            Hinh::getDientich();
        }

        void setDienTich(){
            dientich = 3.14*pow(R,2);
        }
        void Print(){
            cout << "Hinh tron : ban kinh "<< R <<" ";
        }


};

