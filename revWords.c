/* Reverse words in a sentence */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
char* reverse(char *s)
{
 char a;
 int n,i,x,y;
 n=strlen(s);
 for(i=0;i<n;i++)
 {
  if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
   x=i;
  else
   continue;
  while(s[i]!=' '&&i<n)
  {
   i++;
  }
  y=i-1;
  while(x<y)
  {
   a=s[x];
   s[x]=s[y];
   s[y]=a;
   x++;
   y--;
  }
 }
 return s;
}
int main()
{
 char s[1000];
 printf("Enter a string: ");
 scanf("%[^\n]s", s);
 printf("%s\n",s);
 printf("%s",reverse(s));
 return 0;
}
