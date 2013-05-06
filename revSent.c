/* Reverse sentence with words intact */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
char* reverse(char *s)
{
 char *a;
 int n,i,j,k,start,end;
 n=strlen(s);
 end=0;
 j=n-1;
 a=(char*)malloc(n);
 for(i=0;i<n;i++)
 {
  if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
   start=i;
  else
   continue;
  if(end!=0)
   for(k=0;k<start-end-1;k++,j--)
    a[j]=' ';
  else
   for(k=0;k<start-end;k++,j--)
    a[j]=' ';
  while(s[i]!=' '&&i<n)
  {
   i++;
  }
  end=i-1;
  for(k=end;k>=start;k--,j--)
   a[j]=s[k];
 }
 while(j>=0)
 {
  a[j]=' ';
  j--;
 }
 return a;
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
