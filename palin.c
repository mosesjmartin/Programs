/* Palindrome */

#include<stdio.h>
#include<string.h>
int main()
{
 char s[250];
 int i,l,flag=0;
 scanf("%s",&s);
 l=strlen(s);
 for(i=0;i<l/2;i++)
  if(s[i]!=s[l-i-1])
  {
   flag=1;
   break;
  }
 if(flag==1)
  printf("NO\n");
 else
  printf("YES\n");
 return 0;
}
