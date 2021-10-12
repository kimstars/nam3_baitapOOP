#include <iostream>

using namespace std;

class PhuongTrinhBacHai{
    private:
        double a,b,c;
        
    public:
        PhuongTrinhBacHai(){
            a= b = c =0;
        }
        PhuongTrinhBacHai(double a, double b, double c):a(a),b(b),c(c){};
        void Nhap(){
            cout <<"Ax^2 + Bx + C = 0 \n";
            cout << "Nhap he so a : "; cin >> a;
            cout << "Nhap he so b : "; cin >> b;
            cout << "Nhap he so c : "; cin >> c;

        }
        void TimNghiem(){
            double delta = 0, x1,x2;

            if(a == 0 ){
                if(b){
                    cout << "Phuong trinh co nghiem duy nhat : x = "<< b/c << endl;
                }else{
                    if (c == 0){
                        cout <<"Phuong trinh vo so nghiem \n";
                    }else{
                        cout << "Phuong trinh vo nghiem.\n";
                    }
                }
            }else{
                delta = b*b +4*a*c;
                if(delta > 0){
                    x1 = (-b + sqrt(delta))/(2*a);
                    x2 = (-b - sqrt(delta))/(2*a);
                    cout <<"Nghiem thu nhat : x1 = " << x1 << endl;
                    cout <<"Nghiem thu hai : x2 = " << x2 << endl;
                }else if(delta == 0){
                    cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b/(2*a)<< endl;
                }else{
                    cout <<"Phuong trinh vo nghiem\n";
                }
            }

        }
};