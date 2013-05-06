/* Find 18th fibonacci number divisible by 7 */

#include<stdio.h>
#include<malloc.h>
#include<string.h>

// Function to add two numbers
void add(char *num1, char *num2, char *sum, char *map) {

 // Declaration
 int i, m, n, carry, a, b, s, l;
 
 // Definition
 m = strlen(num1); // Length of First Number
 n = strlen(num2); // Length of Second Number
 carry = 0;
 
 // Logic to add two numbers
 for(i = 0; i < m; i++) {
  // Find the numerical equivalent
  a = (int)num1[i] - 48;
  b = (int)num2[i] - 48;
  
  s = a + b + carry; // Find the sum
  
  //Condition to check whether there is carry
  if(s > 9) {
   s -= 10;
   carry = 1;
  } else {
   carry = 0;
  }
  
  sum[i] = map[s]; // Put the obtained value in the result
 }
 
 // Condition to check whether extra values are available and are added to the result
 // Considering only the next immediate value to add carry to that value
 if(i < n) {
  a = (int)num2[i] - 48;
  s = a + carry;
  sum[i] = map[s];
  i++;
 } else {
  if(i == n && carry == 1) {
   sum[i] = map[carry];
   i++;
  }
 }
 // Considering the remaining value and copying as they are to the result
 for(; i < n; i++) {
  sum[i] = num2[i];
 }
 
 sum[i] = '\0'; // Assigning null to the end of the result
}

// Main Function
int main() {
 // Declaration
 int count, l, i;
 char *num1, *num2, *sum, *map;
 
 //Allocation
 num1 = (char *)malloc(100); // Stores the First Number
 num2 = (char *)malloc(100); // Stores the Second Number
 sum = (char *)malloc(100); // Stores the Sum
 map = (char *)malloc(10); // Map between integers 0 to 9 and the characters
 
 //Definition
 strcpy(map, "0123456789");
 strcpy(num1, "0");
 strcpy(num2, "1");
 strcpy(sum, "");
 count = 1;
 
 // Logic to find the 18th Fibonacci Number divisible by 7
 // Every 8th number in the Fibonacci Sequence is divisible by 7
 while(count / 8 != 18) {
  add(num1, num2, sum, map); // Adds Numbers 1 and 2 to get the next number in the sequence
  count++;
  strcpy(num1, num2); // Copy num2 to num1
  strcpy(num2, sum); // Copy sum to num2
 }
 
 //Print the Result
 l = strlen(sum);
 for(i = l - 1; i >= 0; i--) {
  printf("%c", sum[i]);
 }
 printf("\n");
 return 0;
}