#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
using namespace std;
class SoPhuc {
public: int Phanthuc,Phanao;
 
	public: SoPhuc()
	{
		Phanthuc=0;
		Phanao=0;
	}
	// 1
	public: SoPhuc(int thuc)
	{
		Phanthuc=thuc;
		Phanao=0;
	}
	// 2
	public: SoPhuc(int thuc,int ao)
	{
		Phanthuc=thuc;
		Phanao=ao;
	}
	// 3 +
	SoPhuc operator +(SoPhuc sp)
	{
		Phanthuc=Phanthuc+sp.Phanthuc;
		Phanao=Phanao+sp.Phanao;
		return (*this);
	}
	// 3 - 2 SoPhuc
	SoPhuc operator -(SoPhuc sp)
	{
		Phanthuc=Phanthuc-sp.Phanthuc;
		Phanao=Phanao-sp.Phanao;
		return (*this);
	}
	// 3 * 2 SoPhuc
	SoPhuc operator *(SoPhuc sp)
	{
		Phanthuc=Phanthuc*sp.Phanthuc-Phanao*sp.Phanao;
		Phanao=Phanthuc*sp.Phanao+Phanao*sp.Phanthuc;
		return (*this);
	}
 
	// 4 == so sanh 2 so phuc tra ve dau = khi 2 so bang nhau va dau <> khi 2 so khong bang nhau
	char* operator ==(SoPhuc sp)
	{
		if(Phanthuc==sp.Phanthuc&&Phanao==sp.Phanao) return "=";
		else return "<>";
	}
 
	// 5 tim vi tri so phuc trong mang
 
	// 6 xuat <<xuat SoPhuc
	friend ostream& operator <<(ostream& xuat,SoPhuc& sp)
	{
		if(sp.Phanthuc!=0) xuat<<sp.Phanthuc;
		if(sp.Phanao>0) {cout<<"+";xuat<<sp.Phanao;cout<<"i";}
		if(sp.Phanao<0) {xuat<<sp.Phanao; cout<<"i";}
		return xuat;
	}
	// 6 nhap >> sophuc
	friend istream& operator>>(istream& nhap,SoPhuc& sp)
	{
		cout<<"a= ";
		cin.ignore(1);
		nhap>>sp.Phanthuc;
		cout<<"b= ";
		cin.ignore(1);
		nhap>>sp.Phanao;
		return nhap;
	}
	// Gan sophuc=sophuc sp
	SoPhuc operator =(SoPhuc sp)
	{
		Phanthuc=sp.Phanthuc;
		Phanao=sp.Phanao;
	}
};
 
class MangSoPhuc: public SoPhuc {
	public: SoPhuc Mangsophuc[100];
	// 1
	void TaoMangTuMang(MangSoPhuc msp)
	{
		for(int vitri=0;vitri<=msp.ViTriPhanTuCuoi();vitri++)
		{
			Mangsophuc[vitri]=(msp.Mangsophuc[vitri]);
		}
	}
	int ViTriPhanTuCuoi()
	{
		int vitricuoi=-1;
		while(Mangsophuc[vitricuoi+1].Phanthuc!=NULL&&Mangsophuc[vitricuoi+1].Phanao!=0)
		{
			vitricuoi++;
		}
		return vitricuoi;
	}
	// 2
	void Them(SoPhuc sp, int vitrik)
	{
		//doi cac phan tu tu vi tri k ra phai sau
		for(int vitritam=ViTriPhanTuCuoi();vitritam>=vitrik;vitritam--)
		{
			Mangsophuc[vitritam+1]=Mangsophuc[vitritam];
		}
		// chen so vao vitri k
		Mangsophuc[vitrik]=(sp);
	}
	// 3 []
	void operator [](int k)
	{
		cout<<(Mangsophuc[k]);
	}
	// 4
	void Xoa(int k)
	{
		for(int vitri=k;vitri<ViTriPhanTuCuoi();vitri++)
		{
			Mangsophuc[vitri]=(Mangsophuc[vitri+1]);
		}
		Mangsophuc[ViTriPhanTuCuoi()]=NULL;
	}
	// 5 nhap >>
	friend istream& operator >>(istream& nhapmang, MangSoPhuc& msp)
	{
		int vitri=-1;
		SoPhuc sophuctam(1);
		cout<<"Viec nhap so phuc vao mang ngung khi ban nhap a=0 va b=0\n";
		while (sophuctam.Phanthuc!=0||sophuctam.Phanao!=0)
		{
			cin>>(sophuctam);
			if(sophuctam.Phanthuc!=0||sophuctam.Phanao!=0)
			{
				cout<<"So vua nhap: "<<(sophuctam)<<"\n";
				vitri=vitri+1;
				msp.Mangsophuc[vitri]=(sophuctam);
				cout<<"Nhap thanh cong\n";
			}
		};
		return nhapmang;
	}
	// 5 xuat <<
	friend ostream& operator <<(ostream& xuatmang,MangSoPhuc& msp)
	{
		if(msp.ViTriPhanTuCuoi()<0) cout<<"Khong co phan tu nao trong mang";
		for(int vitri=0;vitri<=msp.ViTriPhanTuCuoi();vitri++)
		{
			cout<<(msp.Mangsophuc[vitri])<<"\t";
		}
		return xuatmang;
	}
};
void main()
{
	system("clear");
	SoPhuc sp1(0),sp2(0),sp3(0,0),spthem(0,0);
	MangSoPhuc mangnhan,mangsophucdacho,mangsp;
	int chon=1;
	while(chon>0&&chon<=9)
	{
	system("clear");
	gotoxy(20,3);
	cout<<"DO AN MON PHUONG PHAP LAP TRINH HUONG DOI TUONG";
	gotoxy(20,4);
	cout<<" NHOM 23 - LOP DH10TH - DE TAI 10";
	gotoxy(20,5);
	cout<<" NGUOI HUONG DAN: NGUYEN THAI DU";
	gotoxy(10,7);
	cout<<"1/ Thanh Vien";
	gotoxy(10,8);
	cout<<"2/ De Tai";
	gotoxy(10,9);
	cout<<"3/ Thao Tac Tren 2 So Phuc";
	gotoxy(10,10);
	cout<<"4/ Tao Mang So Phuc Tu Dong";
	gotoxy(10,11);
	cout<<"5/ Gan Mang So Phuc Bang Mang So Phuc Cho Truoc";
	gotoxy(10,12);
	cout<<"6/ Tu Nhap Mang So Phuc";
	gotoxy(10,13);
	cout<<"7/ Them So Phuc Vao Mang";
	gotoxy(10,14);
	cout<<"8/ Xoa So Phuc Ra Khoi Mang So Phuc";
	gotoxy(10,15);
	cout<<"9/ So Phuc Tai Vi Tri K Trong Mang";
	gotoxy(10,16);
	cout<<"0/ THOAT";
	gotoxy(10,17);
	cout<<"============================================================";
	gotoxy(10,18);
	cout<<" Chon= ";
	cin>>chon;
	switch(chon)
	{
		case 1: 
		{
			system("clear");
			gotoxy(19,9);
			cout<<"------------------THANH VIEN--------------------";
			gotoxy(19,10);
			cout<<"| 1. LE NGUYEN DUC DTH092032 (NHOM TRUONG) |";
			gotoxy(19,11);
			cout<<"| 2. LE THI THUY LINH DTH092055 |";
			gotoxy(19,12);
			cout<<"| 3. LE MINH TAM DTH092077 |";
			gotoxy(19,13);
			cout<<"------------------------------------------------";
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 2: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<----------------------------------DE TAI 10------------------------------>>>";
			gotoxy(2,6);
			cout<<"a. Xay dung lop so phuc co dang a+bi,trong do phan thuc phan ao la so nguyen.";
			gotoxy(2,7);
			cout<<" Yeu Cau:";
			gotoxy(2,8);
			cout<<" 1.Viet phuong thuc tao doi duong so phuc tu so nguyen.";
			gotoxy(2,9);
			cout<<" 2.Viet phuong thuc tao doi tuong so phuc tu 2 phan thuc va ao cho truoc.";
			gotoxy(2,10);
			cout<<" 3.Viet cac toan tu cong, tru, nhan 2 doi tuong so phuc voi nhau.";
			gotoxy(2,11);
			cout<<" 4.Viet cac toan tu so sanh: >,<,=== hai doi tuong so phuc voi nhau.";
			gotoxy(2,12);
			cout<<" 5.Viet ham tim kiem 1 so phuc trong mot mang cac so phuc cho truoc.";
			gotoxy(2,13);
			cout<<" 6.Viet cac toan tu nhap>> va xuat<< cho cac so phuc.";
			gotoxy(2,14);
			cout<<"b. Xay dung lop mang cac so phuc.";
			gotoxy(2,15);
			cout<<" 1.Tao doi tuong mang cac so phuc tu mot mang cac so phuc cho truoc.";
			gotoxy(2,16);
			cout<<" 2.Viet phuong thuc them mot so phuc vao trong mang tai vi tri k.";
			gotoxy(2,17);
			cout<<" 3.Viet toan tu [] cho phep truy xuat phan tu trong mang tai vi tri k.";
			gotoxy(2,18);
			cout<<" 4.Viet phuong thuc loai bo so phuc tai vi tri k ra khoi mang.";
			gotoxy(2,19);
			cout<<" 5. viet cac toan tu nhap >> va xuat << cho doi tuong mang cac so phuc.";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 3: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<-----------------------THAO TAC TREN 2 SO PHUC--------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(10,6);
			cout<<"Moi Ban Nhap 2 So Phuc";
			gotoxy(10,7);
			cout<<"So phuc thu nhat:";
			gotoxy(10,8);
			cin>>(sp1);
			gotoxy(10,9);
			cout<<"So phuc thu 2:";
			gotoxy(10,10);
			cin>>(sp2);
			sp3=(sp1);
			gotoxy(10,11);
			cout<<"Thuc Hien Cac Phep Tinh Tren 2 So Phuc Da Nhap";
			gotoxy(10,12);
			cout<<"So phuc thu nhat : "<<(sp1);
			gotoxy(10,13);
			cout<<"So phuc thu hai : "<<(sp2);
			gotoxy(10,14);
			cout<<"Tong 2 so phuc : "<<(sp1+(sp2));
			sp1=(sp3);
			gotoxy(10,15);
			cout<<"Hieu 2 so phuc : "<<(sp1-(sp2));
			sp1=(sp3);
			gotoxy(10,16);
			cout<<"Tich 2 so phuc : "<<(sp1*(sp2));
			sp1=(sp3);
			gotoxy(10,17);
			cout<<"So sanh 2 so phuc: "<<sp1<<" "<<(sp1==(sp2))<<" "<<sp2;
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 4: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<----------------------------TAO MANG TU DONG----------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(20,12);
			cout<<"Mang So Phuc Dang Duoc Tao Xin Doi!!";
			int max=random(100);
			// cho mang tu dong
			for(int vt=0;vt<=max;vt++)
			{
			mangsophucdacho.Mangsophuc[vt].Phanthuc=vt+1;
			mangsophucdacho.Mangsophuc[vt].Phanao=vt+1;
			};
			delay(5000);
			gotoxy(20,14);
			cout<<" Mang da tao xong!";
			gotoxy(10,16);
			cout<<(mangsophucdacho);
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 5: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<---------------TAO MANG SO PHUC TU MANG SO PHUC CHO TRUOC---------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(10,12);
			cout<<"Dang tao mang so phuc tu mang so phuc cho truoc (lay mang tao tu dong)";
			mangnhan.TaoMangTuMang(mangsophucdacho);
			delay(3000);
			gotoxy(10,14);
			cout<<" Mang da nhan duoc";
			gotoxy(10,16);
			cout<<(mangnhan);
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 6: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<----------------------------NHAP MANG SO PHUC---------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(1,6);
			cin>>(mangsp);
			system("clear");
			gotoxy(1,5);
			cout<<"<<<----------------------------NHAP MANG SO PHUC---------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(20,7);
			cout<<"So so phuc trong mang: "<<mangsp.ViTriPhanTuCuoi()+1;
			gotoxy(20,9);
			cout<<" Mang Da duoc tao la";
			gotoxy(2,12);
			cout<<(mangsp);
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 7: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<-------------------------THEM SO PHUC VAO MANG--------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(12,7);
			cout<<"Moi ban nhap so phuc muon them";
			gotoxy(12,8);
			cin>>(spthem);
			gotoxy(12,9);
			cout<<"So phuc ban muon them la: "<<(spthem);
			int vtthem;
			gotoxy(12,10);
			cout<<"Vi tri ban muon them: ";
			cin>>vtthem;
			mangsp.Them(spthem,vtthem);
			gotoxy(12,11);
			cout<<"Mang sau khi them "<<(spthem)<<" la: "<<(mangsp);
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 8: 
		{
			system("clear");
			int vtxoa;
			gotoxy(1,5);
			cout<<"<<<-------------------------XOA SO PHUC TRONG MANG-------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(1,6);
			cout<<"Moi ban nhap vi tri xoa: ";
			cin>>vtxoa;
			mangsp.Xoa(vtxoa);
			gotoxy(1,7);
			cout<<"Mang sau khi xoa la : "<<(mangsp);
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 9: 
		{
			system("clear");
			gotoxy(1,5);
			cout<<"<<<--------------------------SO PHUC TAI VI TRI K--------------------------->>>";
			gotoxy(1,20);
			cout<<"<<<------------------------------------------------------------------------->>>";
			gotoxy(1,6);
			cout<<"Moi ban nhap vi tri cua so phuc trong mang : ";
			int vttruyxuat;
			cin>>vttruyxuat;
			gotoxy(1,7);
			cout<<"Mang so phuc tai vi tri "<<vttruyxuat<<" la : ";
			mangsp[vttruyxuat];
			gotoxy(25,24);
			cout<<"AN PHIM BAT KI DE TRO VE MENU CHON";
			getch();
			break;
		}
		case 0: 
		{
			break;
		}
	}
	};
}