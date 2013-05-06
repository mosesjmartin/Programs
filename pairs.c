/*
Given N numbers [N<=10^5], count the total pairs of numbers that have a difference of K. [K>0 and K<1e9]. Each of the N numbers will be greater than 0 and be at least K away from 2^31-1 (Everything can be done with 32 bit integers).

Input Format:

1st line contains N & K (integers).
2nd line contains N numbers of the set. All the N numbers are assured to be distinct.

Output Format:

One integer saying the no of pairs of numbers that have a diff K.

Sample Input #00:

5 2
1 5 3 4 2

Sample Output #00:

3

Sample Input #01:

10 1
363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793 

Sample Output #01:

0
*/

#include<stdio.h>
#include<malloc.h>

int main() {
    int i, n, k, *values, count, x, y, j;
    scanf("%d %d",&n,&k);
    values = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d",&values[i]);
    }
    count = 0;
    for(i = 0; i < n; i++) {
        x = values[i] + k;
        y = values[i] - k;
        for(j = i + 1; j < n; j++) {
            if(values[j] == x || values [j] == y) {
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}