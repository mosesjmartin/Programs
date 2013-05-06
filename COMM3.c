/*
 The Chef likes to stay in touch with his staff. So, the Chef, the head server, and the sous-chef all carry two-way transceivers so they can stay in constant contact. Of course, these transceivers have a limited range so if two are too far apart, they cannot communicate directly.

The Chef invested in top-of-the-line transceivers which have a few advanced features. One is that even if two people cannot talk directly because they are out of range, if there is another transceiver that is close enough to both, then the two transceivers can still communicate with each other using the third transceiver as an intermediate device.

There has been a minor emergency in the Chef's restaurant and he needs to communicate with both the head server and the sous-chef right away. Help the Chef determine if it is possible for all three people to communicate with each other, even if two must communicate through the third because they are too far apart.
Input

The first line contains a single positive integer T = 100 indicating the number of test cases to follow. The first line of each test case contains a positive integer R = 1,000 indicating that two transceivers can communicate directly without an intermediate transceiver if they are at most R meters away from each other. The remaining three lines of the test case describe the current locations of the Chef, the head server, and the sous-chef, respectively. Each such line contains two integers X,Y (at most 10,000 in absolute value) indicating that the respective person is located at position X,Y.
Output

For each test case you are to output a single line containing a single string. If it is possible for all three to communicate then you should output "yes". Otherwise, you should output "no".

To be clear, we say that two transceivers are close enough to communicate directly if the length of the straight line connecting their X,Y coordinates is at most R.
Example

Input:
3
1
0 1
0 0
1 0
2
0 1
0 0
1 0
2
0 0
0 2
2 1


Output:
yes
yes
no

*/

#include<stdio.h>
#include<math.h>

float distance(int x1, int y1, int x2, int y2) {
 return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}
int main() {
 int t, r, x1, x2, x3, y1, y2, y3, c;
 float d1, d2, d3;
 scanf("%d", &t);
 while(t--) {
  scanf("%d", &r);
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &x3, &y3);
  d1 = distance(x1, y1, x2, y2);
  d2 = distance(x1, y1, x3, y3);
  d3 = distance(x3, y3, x2, y2);
  c = 0;
  if(d1 - r > 0) {
   c++;
  }
  if(d2 - r > 0) {
   c++;
  }
  if(d3 - r > 0) {
   c++;
  }
  if(c >= 2) {
   printf("no\n");
  } else {
   printf("yes\n");
  }
 }
 return 0;
}