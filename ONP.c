/*
Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 - 4 + 5" would be written "3 4 - 5 +" first subtract 4 from 3, then add 5 to that.

Transform the algebraic expression with brackets into RPN form.

You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c)
Input

The first line contains t, the number of test cases (less then 100).

Followed by t lines, containing an expression to be translated to RPN form, where the length of the expression is less then 400.
Output

The expressions in RPN form, one per line.

Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

char stack[400];
int tos = 0;

void push(char c) {
 if(tos != 400) {
  stack[tos] = c;
  tos++;
 }
}

char pop() {
 if(tos != 0) {
  tos--;
  return stack[tos];
 }
 return '\0';
}

int main() {
 int t, i, j, k, l;
 char a[410], **output, c;
 scanf("%d",&t);
 output = (char **)malloc(t*sizeof(char *));
 for(i = 0; i < t; i++) {
  output[i] = (char *)malloc(410);
 }
 for(i=0; i<t; i++) {
  scanf("%s",a);
  l = strlen(a);
  k = 0;
  for(j = 0; j < l; j++) {
   if(a[j] >= 'a' && a[j] <= 'z') {
    output[i][k] = a[j];
    k++;
    continue;
   }
   if(a[j] == ')') {
    c = pop();
    while(c != '(') {
     output[i][k] = c;
     k++;
     c = pop();
    }
    continue;
   }
   if(a[j] == '(' || a[j] == '+' || a[j] == '-' || a[j] == '*' || a[j] == '/' || a[j] == '^') {
    push(a[j]);
   }
  }
  output[i][k] = '\0';
 }
 for(i = 0; i < t; i++) {
  printf("%s\n",output[i]);
 }
 return 0;
}
