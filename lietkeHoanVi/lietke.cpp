
#include<iostream>
#define MAX 200
using namespace std;

//ĐỀ BÀI : tính số hoán vị khi xếp N số tự nhiên khác nhau thành vòng trong
 
int n;
int mark[MAX] = { 0 };//Đánh dấu chưa có phần tử nào sử dụng hết
int a[MAX];//Lưu hoán vị vào mảng A
int count;

void init(){
    a[1] = 1;// cố định một phần tử, tránh trùng lặp
    cout << "nhap n = ";
    cin >> n;
    count = 0;
}

void print(){
    cout << a[1] << " ";
    for(int i = 2;i <= n; i++){
        cout << a[i] <<" ";
    }
    count++;
    cout << endl;
}

void Try(int k){
    for(int i = 2; i <= n; i++){
        if(!mark[i]){ //nếu phần tử chưa đc sd thì lưu vào a[i] để in ra và đánh dấu đã dùng
            a[k] = i;
            mark[i] = 1;
            if(k == n) 
                print(); // kiểm tra xem đã đủ một hoán vị chưa
            else Try(k + 1);
            mark[i] = 0; // dùng xong trả lại
        }
    }
}

int main(){
    init();
    cout << "Cac hoan vi vong tron la : \n"
    Try(2);
    cout <<"\n"<< n << " phan tu co " << count << " hoan vi vong tron ~~~ (n-1)!";
}

