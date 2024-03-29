/*
The chef has just finished baking several pies, and it's time to place them on cooling racks. The chef has exactly as many cooling racks as pies. Each cooling rack can only hold one pie, and each pie may only be held by one cooling rack, but the chef isn't confident that the cooling racks can support the weight of the pies. The chef knows the weight of each pie, and has assigned each cooling rack a maximum weight limit. What is the maximum number of pies the chef can cool on the racks?
Input:

Input begins with an integer T=30, the number of test cases. Each test case consists of 3 lines. The first line of each test case contains a positive integer N=30, the number of pies (and also the number of racks). The second and third lines each contain exactly positive N integers not exceeding 100. The integers on the second line are the weights of the pies, and the integers on the third line are the weight limits of the cooling racks.
Output:

For each test case, output on a line the maximum number of pies the chef can place on the racks.
Sample input:

2
3
10 30 20
30 10 20
5
9 7 16 4 8
8 3 14 10 10
 

Sample output:

3
4
*/

#include<stdio.h>
#include<malloc.h>
int main()
{
 int t,*p,*w,n,i,j,x;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  p=(int *)malloc(n*sizeof(int));
  w=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
   scanf("%d",&p[i]);
   x=p[i];
   for(j=i-1;j>=0;j--)
   {
    if(p[j]>x)
     p[j+1]=p[j];
    else
     break;
   }
   p[j+1]=x;
  }
  for(i=0;i<n;i++)
  {
   scanf("%d",&w[i]);
   x=w[i];
   for(j=i-1;j>=0;j--)
   {
    if(w[j]>x)
     w[j+1]=w[j];
    else
     break;
   }
   w[j+1]=x;
  }
  for(i=0,j=0;j<n;)
  {
   if(p[i]<=w[j])
    i++;
   j++;
  }
  printf("%d\n",i);
  free(p);
  free(w);
 }
 return 0;
}