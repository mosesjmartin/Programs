/* N Queen problem */

#include<stdio.h>
#include<malloc.h>

int checkPlacement(int *columnForRow, int row, int position) {
 int i, j;
 for(i = 0; i < row; i++) {
  j = position - columnForRow[i];
  if(j < 0) {
   j = columnForRow[i] - position;
  }
  if(j == 0 || j == row - i) {
   return 0;
  }
 }
 columnForRow[row] = position;
 return 1;
}
int placeQueen(int *columnForRow, int row, int maxRow, int flag) {
 int i, j;
 if(row == maxRow) {
  for(i = 0; i < row; i++) {
   printf("%d ",columnForRow[i] + 1);
  }
  printf("\n");
  return 1;
 }
 for(i = 0; i < maxRow; i++) {
  if(checkPlacement(columnForRow, row, i)) {
   if(!flag) {
    flag = placeQueen(columnForRow, row + 1, maxRow, 0);
   } else {
    return 1;
   }
  }
 }
 return 0;
}

int main() {
 int n, *columnForRow;
 scanf("%d",&n);
 columnForRow = (int *)calloc(n,sizeof(int));
 return placeQueen(columnForRow, 0, n, 0);
}