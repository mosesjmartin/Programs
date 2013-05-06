/* Implementation of magic square */

#include<stdio.h>
main()
{
 int i,j,mat[100][100]={0},row,col,order,number;
 number=1;
 printf("\nEnter the number of rows in the matrix: ");
 scanf("%d",&order);
 row=0;
 col=order/2;
 mat[row][col]=number;
 number++;
 for(;number<=(order*order);number++)
 {
  row=row-1;
  if(row<0)
   row=order-1;
  col=col+1;
  if(col>=order)
   col=0;
  if(mat[row][col]==0)
   mat[row][col]=number;
  else
  {
   row=row+1;
   if(row>=order)
    row=0;
   col=col-1;
   if(col<0)
    col=order-1;
   row=row+1;
   if(row>=order)
    row=0;
   mat[row][col]=number;
  }
 }
 printf("\nThe MAGIC SQUARE:\n");
 for(i=0;i<order;i++)
 {
  for(j=0;j<order;j++)
   printf("%d\t",mat[i][j]);
  printf("\n");
 }
}
