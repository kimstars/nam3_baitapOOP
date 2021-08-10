#include <stdio.h>
#include <conio.h>
int x[1000], t[1000], n,m;
long long d = 0;

void khoitao()
{
    printf("\nNhap n = ");
    scanf("%d", &n);
    printf("\nNhap m = ");
    scanf("%d", &m);
    x[0] = 1;// mảng x lưu nghiệm
    t[0] = 0;// t[i] lưu tổng nghiệm các phần tử mảng x từ x[1] -> x[i]
}
void xuat(int k)
{
    printf("\n%d = ", n);
    int i = 0;
    for (i = 1; i < k; i++){
        printf(" %d + ", x[i]);
        // d++;
    }
    d++;
    if(k < m){
        printf(" %d + ", x[k]);
        for(i = 0; i < m-k-1; i++){
            printf(" 0 + ");
        }
        printf(" 0 ");
    }else{
        printf(" %d", x[k]);
    }
}
void phantich(int i)
{
    int j = 0;
    for (j = x[i - 1]; j <= ((n - t[i - 1]) / 2); j++)
    {
        x[i] = j;
        t[i] = t[i - 1] + j;
        phantich(i + 1);
    }
    x[i] = n - t[i - 1];
    if(i <= m){
        xuat(i);
    }
}
int main()
{
    khoitao();
    phantich(1);
    printf("\ncount = %d", d);
    return 0;
}



//cho x1 + x2 + ... xM = N 
// tìm số nghiệm 