/* Merge Sort */

#include<stdio.h>
#include<malloc.h>

int * msort(int *a,int s1,int e1,int s2,int e2)
{
 int i,j,*r,s,e;
 r=(int *)malloc((e2-s1+1)*sizeof(int));
 i=0;
 s=s1;
 e=e2;
 while(s1<=e1&&s2<=e2)
 {
  if(a[s1]<a[s2])
  {
   r[i]=a[s1];
   s1++;
  }
  else
  {
   r[i]=a[s2];
   s2++;
  }
  i++;
 }
 if(s1<=e1)
 {
  while(s1<=e1)
  {
   r[i]=a[s1];
   s1++;
   i++;
  }
 }
 else
 {
  while(s2<=e2)
  {
   r[i]=a[s2];
   s2++;
   i++;
  }
 }
 j=0;
 for(;j<i;j++)
 {
  a[s]=r[j];
  s++;
 }
 return a;
}
int * merge(int *a,int s,int e)
{
 int m,i;
 if(s<e)
 {
  m=(s+e)/2;
  a=merge(a,s,m);
  a=merge(a,m+1,e);
  a=msort(a,s,m,m+1,e);
 }
 return a;
}
int main()
{
 int i, n, *a;
 scanf("%d",&n);
 a = (int *)malloc(n * sizeof(int));
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 merge(a,0,n);
 for(i=0;i<n;i++) {
  printf("%d",a[i]);
  if(i != n - 1) {
   printf("\n");
  }
 }
 return 0;
}
