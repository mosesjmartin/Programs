/* 
You and your K-1 friends want to buy N flowers. Flower number i has cost ci. Unfortunately the seller does not like a customer to buy a lot of flowers, so he tries to change the price of flowers for customer who had bought flowers before. More precisely if a customer has already bought x flowers, he should pay (x+1)*ci dollars to buy flower number i.
You and your K-1 firends want to buy all N flowers in such a way that you spend as less money as possible.

Input:

The first line of input contains two integers N and K (K <= N) next line contains N positive integers c1,c2,…,cN respectively.

Output:

Print the minimum amount of money you (and your friends) have to pay in order to buy all N flowers.

Sample input :

3 3
2 5 6

Sample output :

13

Explanation :
In the example each of you and your friends should buy one flower. in this case you have to pay 13 dollars.

Constraint :

1 <= N, K  <= 100
Each ci is not more than 1000,000
*/

#include<stdio.h>
int main() {
    int i, N, K, result, t, j, l;
    int C[102];
    scanf("%d %d", &N, &K);
    for(i=0; i<N; i++){
        scanf("%d", &t);
        for(j = i - 1; j >= 0; j--) {
            if(C[j] < t) {
                C[j+1] = C[j];
            } else {
                break;
            }
        }
        C[j+1] = t;
    }
    result = 0;
    l = 1;
    for(i = 0; i < N; ) {
        j = 0;
        while (j < K && i < N) {
            result += (l * C[i]);
            j++;
            i++;
        }
        l++;
     } 
    printf("%d\n", result);
    return 0;
}