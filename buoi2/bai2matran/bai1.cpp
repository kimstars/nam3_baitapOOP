#include <iostream>
#define max 100

using namespace std;

void NhapMaTran(int A[max][max], int m, int n)
{
   for(int i = 0; i<m ; i++)
   for(int j = 0; j<n ; j++)
   {
      printf("[%d][%d] =",i,j);
      scanf("%d", &A[i][j]);
   }
}

void XuatMaTran(int A[max][max], int m, int n)
{
   for(int i = 0; i<m ; i++)
   {
      printf("\n");
      for(int j = 0; j<n ; j++)
         printf("%d\t",A[i][j]);
   }

}
/*Sap xep ma tran tang dan theo dong*/
void BubbleSortA(int A[max][max], int m, int n)
{
   for(int k = 0; k<m ; k++)
      for(int i = 0; i<n-1 ; i++)
      for(int j = n-1; j>i ; j--)
      if(A[k][j]<A[k][j-1])
      {
         int temp = A[k][j];
         A[k][j] = A[k][j-1];
         A[k][j-1] = temp;
      }
}
int main()
{
   int A[max][max], m, n;
   printf("Nhap m, n= ");
   scanf("%d%d",&m,&n);
   NhapMaTran(A,m,n);
   printf("Ma tran A vua nhap\n");
   XuatMaTran(A,m,n);
   printf("\nSap xep tang theo dong\n");
   BubbleSortA(A,m,n);
   XuatMaTran(A,m,n);
}