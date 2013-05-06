/*
 Given an unordered list of N elements, write a function to find the top four elements of the given list. Make sure your function runs in linear time O(N).
 
Input format :
 
First line of input contains N , number of elements in list.
Next N line , each contains a element.
 
Output format :
 
Print the top four elements of list.
 
Sample input :
 
8
6930886
-1692777
4636915
7747793
-4238335
9885386
9760492
6516649
 
Sample ouput :
 
9885386
9760492
7747793
6930886
 
Constraint :
 
N < 1000000.
all numbers will fit  in 32-bit integer.
*/

#include<iostream>
using namespace std;

void sortedInsert(int *list, int n, int val) {
	int i, j, m;
	for(i = n - 1; i >= 0; i--) {
		if(list[i] > val) {
			break;
		}
		list[i + 1] = list[i];
	}
	list[i + 1] = val;
}

int main() {
    int n, *list, i, *out, m;
	cin>>n;
	list = new int[n];
	if(n < 4) {
		out = new int[n];
		m = n;
	} else {
		out = new int[4];
		m = 4;
	}
    for(i = 0; i < n; i++){
        cin>>list[i];
    }
	for(i = 0; i < m; i++) {
		sortedInsert(out, i, list[i]);
	}
	for(i = m; i < n; i++) {
		if(list[i] > out[3]) {
			sortedInsert(out, m, list[i]);
		}
	}
    for(i = 0; i < m; i++) {
		cout<<out[i]<<endl;
	}
	delete list;
	delete out;
    return 0;
}