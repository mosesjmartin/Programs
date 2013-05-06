/*
Let's consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, three in the third line, etc. Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that:

    on each path the next number is located on the row below, more precisely either directly below or below and one place to the right;
    the number of rows is strictly positive, but less than 100
    all numbers are positive integers between O and 99.

Input

In the first line integer n - the number of test cases (equal to about 1000).
Then n test cases follow. Each test case starts with the number of lines which is followed by their content.
Output

For each test case write the determined value in a separate line.
Example

Input:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

Output:
5
9
*/

#include<stdio.h>
#include<malloc.h>

int main() {
 int n, t, **a, *b, i, j, k, sum, max;
 scanf("%d", &t);
 for(i = 0; i < t; i++) {
  scanf("%d", &n);
  a = (int **)calloc(n, sizeof(int *));
  b = (int *)calloc(n, sizeof(int));
  for(j = 0; j < n; j++) {
   a[j] = (int *)calloc(n, sizeof(int));
  }
  for(j = 0; j < n; j++) {
   for(k = 0; k <= j; k++) {
    scanf("%d", &a[j][k]);
   }
  }
  b[0] = a[0][0];
  for(j = 0; j < n - 1; j++) {
   for(k = j; k >= 0; k--) {
    sum = b[k] + a[j + 1][k + 1];
	if(sum > b[k + 1]) {
	 b[k + 1] = sum;
	}
	sum = b[k] + a[j + 1][k];
	if(sum > b[k]) {
	 b[k] = sum;
	}
   }
  }
  max = 0;
  for(j = 0; j < n; j++) {
   if(max < b[j]) {
    max = b[j];
   }
  }
  free(a);
  free(b);
  printf("%d\n", max);
 }
 return 0;
}