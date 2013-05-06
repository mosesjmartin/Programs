/* Find 18th fibonacci number divisible by 7 */

#include<stdio.h>

// Main Function
int main() {
 // Declaration
 int count, l, i;
 long long double num1, num2, sum;
 count = 1;
 
 // Logic to find the 18th Fibonacci Number divisible by 7
 // Every 8th number in the Fibonacci Sequence is divisible by 7
 while(count / 8 != 18) {
  sum = num1 + num2;
  count++;
  num1 = num2;
  num2 = sum;
 }
 
 printf("%llf\n", sum);
 return 0;
}