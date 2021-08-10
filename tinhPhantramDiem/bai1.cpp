#include <iostream>
#include <ctime>
using namespace std;
#include <stdlib.h>

void maxInArray(double a[], int n){
    double max;
    int imax = -1;
    for (int i = 0 ; i < n; i++){
        if(max < a[i]){
            max = a[i];
            imax = i;
        } 
    }
    for (int i = 0 ; i < n; i++){
        if(a[i] == max){
            cout << i << " ";
        }
    }
}

int main(){
    int n; //so hoc vienm
    cout << "nhap so hoc vien : ";
    cin >> n;
    double p[10];
    srand(time(0));
    int arr[n];
    for (int i = 0 ; i < n; i++){
        arr[i] = rand()%10 + 1;
        cout << arr[i] << endl;
    }

    int diem[11] = {0,1,2,3,4,5,6,7,8,9,10};

    cout << "phan tram theo diem \n";
    for(int i = 0; i < 11; i++){
        int d = diem[i];
        // cout << d;
        int count = 0;
        for(int j = 0 ; j < n; j++){
            if(arr[j] == d) count++;
        }
        p[i] = count*100 / n ;
        cout << i << " : " << p[i]  << " %"<< endl;
    }
    cout << "\n Diem co phan tram cao nhat la : " ;
    maxInArray(p,11);
    

}