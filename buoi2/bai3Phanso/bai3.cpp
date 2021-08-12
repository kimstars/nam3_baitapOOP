#include <iostream>
#include <stdlib.h>
using namespace std;

class phanso
{
public:
   double a, b;
   void nhap()
   {
      cout << "nhap tu so : ";
      cin >> a;
      do{
         cout << "nhap mau so : ";
         cin >> b;
         if(b == 0){
            cout << "b khac 0 !!! pls\n";
         }
      }while(b == 0);
   }
   void in()
   {
      if(b == 1){
         cout << a;
      }else{
         cout << a << "/" << b;

      }
   }
};
int gcd(int a, int b)
{
   if (a == 0)
      return b;
   return gcd(b % a, a);
}

phanso toigian(phanso p1)
{
   phanso p;
   int u = gcd(p1.a, p1.b);
   p.a = p1.a / u;
   p.b = p1.b / u;
   return p;
}

phanso cong(phanso p1, phanso p2)
{
   phanso p;
   p.a = p1.a * p2.b + p1.b * p2.a;
   p.b = p1.b * p2.b;
   return toigian(p);
}

phanso tru(phanso p1, phanso p2)
{
   phanso p;
   p.a = p1.a * p2.b - p1.b * p2.a;
   p.b = p1.b * p2.b;
   return toigian(p);
}

phanso nhan(phanso p1, phanso p2)
{
   phanso p;
   p.a = p1.a * p2.a;
   p.b = p1.b * p2.b;
   return toigian(p);
}

phanso p1, p2;

void nhaphai()
{
   cout << "nhap phan so thu nhat : \n";
   p1.nhap();
   cout << "nhap phan so thu hai : \n";
   p2.nhap();
}

void nhapmot()
{
   cout << "nhap phan so thu nhat : \n";
   p1.nhap();
}

void pressAnyKey()
{
   cout << endl;
   system("pause");
   system("cls");
}

using namespace std;
int main()
{
   int op;
   phanso res;
   while (1)
   {
      cout << "\nBan muon lam gi: " << endl;
      cout << "1. Cong hai phan so\n";
      cout << "2. Tru hai phan so\n";
      cout << "3. Nhan hai phan so\n";
      cout << "4. Toi gian phan so\n";
      cout << "0. Thoat\n";
      cout << ">> ";
      cin >> op;
      switch (op)
      {
      case 1:
         nhaphai();
         res = cong(p1, p2);
         res.in();
         pressAnyKey();
         break;

      case 2:
         nhaphai();
         res = tru(p1, p2);
         res.in();
         break;
         pressAnyKey();
      case 3:
         nhaphai();
         res = nhan(p1, p2);
         res.in();
         pressAnyKey();
         break;
      case 4:
         nhapmot();
         res = toigian(p1);
         res.in();
         pressAnyKey();
         break;
      case 0: //thoat
            printf("\nBan da chon THOAT chuong trinh!! Hen gap lai \n");
            return 0;
      default:
         cout << "khong co chuc nang nay";
         break;
      }
   }
}