/* Print the square matrix in spiral order */

#include<stdio.h>
void print(int a[10][10],int n)
{
 int i,j;
 for(i=0;i<n/2;i++)
 {
  for(j=i;j<n-i;j++)
   printf("%d ",a[i][j]);
  for(j=i+1;j<n-i-1;j++)
   printf("%d ",a[j][n-i-1]);
  for(j=n-i-1;j>=i;j--)
   printf("%d ",a[n-i-1][j]);
  for(j=n-i-2;j>i;j--)
   printf("%d ",a[j][i]);
 }
 if(n%2)
  printf("%d\n",a[i][i]);
 else
  printf("\b\n");
}
int main()
{
 int a[10][10],n,i,j;
 printf("Enter the order of the matrix: ");
 scanf("%d",&n);
 printf("Enter the matrix:\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
 printf("The matrix in spiral order:\n");
 print(a,n);
 return 0;
}
