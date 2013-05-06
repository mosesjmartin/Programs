/* Next Palindrome for n values */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

 int isPal(long int num)
 {
   long int old=num,newnum=0;

   while(num)
   {
     newnum*=10;
     newnum+=num%10;
     num/=10;
   }
   return newnum==old;
 }

int main()
 {
   long int t,i,n,num;

   cin >> t;
   n=t;
   long int arr1[10240];
   long int *arr=arr1;
   while(t--)
   {
     cin >> num;
     for(i=num+1; !isPal(i); i++);
     *arr=i;
     arr++;
   }
   arr=arr1;
   for(i=0; i<n; i++)
   {
     cout << arr1[i] << endl;
   }
  return 0;
 }
