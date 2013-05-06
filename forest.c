/*
You are given a tree (a simple connected graph with no cycles). You have to remove as many edges from the tree as possible to obtain a forest with the condition that : Each connected component of the forest should contain an even number of vertices.

Your task is to calculate the number of removed edges in such a forest.

Input Format
The first line of input contains two integers N and M. N is the number of vertices and M is the number of edges.
The next M lines contain two integers ui and vi which specifies an edge of the tree. (1-based index)

Output Format
Print the answer, a single integer.

Constraints
2 <= N <= 100.

Note: The tree in the input will be such that it can always be decomposed into components containing even number of nodes.

Sample Input

10 9
2 1
3 1
4 3
5 2
6 1
7 2
8 6
9 8
10 8

Sample Output

2
*/

#include<stdio.h>
#include<malloc.h>

int getChilds(int **matrix, int n, int node) {
 int i, count = 0;
 for(i = 0; i < n; i++) {
  if(matrix[node][i]) {
    count += getChilds(matrix, n, i);
  }
 }
 count++;
 return count;
}

int main() {
 int n, m, **matrix, *connectedNodes, i, x, y, count = 0;
 scanf("%d %d",&n,&m);
 matrix = (int **) calloc(n, sizeof(int *));
 for(i = 0; i < n; i++) {
  matrix[i] = (int *) calloc(n, sizeof(int));
 }
 connectedNodes = (int *) calloc(n, sizeof(int));
 for(i = 0; i < m; i++) {
  scanf("%d %d", &x, &y);
  matrix[y-1][x-1] = 1;
 }
 for(i = 0; i  < n; i++) {
  connectedNodes[i] = getChilds(matrix, n, i);
 }
 for(i = 1; i < n; i++) {
  if(!(connectedNodes[i] % 2)) {
   count ++;
  }
 }
 printf("%d",count);
 return 1;
}