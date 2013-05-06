/*
Implement a circular buffer of size N. Allow the caller to append, remove and list the contents of the buffer. Implement the buffer to achieve maximum performance for each of the operations.
The new items are appended to the end and the order is retained i.e elements are placed in increasing order of their insertion time. When the number of elements in the list elements exceeds the defined size, the older elements are overwritten.
 
 
There are four types of commands.
 
"A"  n -  Append the following n lines to the buffer. If the buffer is full they replace the older entries.
"R"  n -  Remove first n elements of the buffer. These n elements are the ones that were added earliest among the current elements.
"L"   - List the elements of buffer in order of their inserting time.
"Q"  - Quit.  
 
Your task is to execute commands on circular buffer.
 
Input format :
 
First line of input contains N ,  the size of the buffer.
A n  - append the following n lines to the buffer.
R n - remove first n elements of the buffer.
L - list the buffer.
Q - Quit.
 
Output format :
 
Whenever  L command appears in the input, print the elements of buffer in order of their inserting time. Element that was added first should appear first. 
 
Sample Input :
 
10
A 3
Fee
Fi
Fo
A 1
Fum
R 2
L
Q
 
Sample Output :
 
Fo
Fum
 
Constraint :
 
0 <= N <= 10000
Number of removing elements will <= number of elements presents in circular buffer.
total number of commands <= 50000.
total number of characters in input <= 20000000.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Buffer {
	private:
	vector<string> vec;
	int size, buffer;
	
	public:
	Buffer() {
		size = 0;
		buffer = 10;
	}
	
	Buffer(int b) {
		size = 0;
		buffer = b;
	}
	
	void append(int n) {
		int i;
		string str;
		for(i = 0; i < n; i++) {
			cin >> str;
			if(size < buffer) {
				vec.push_back(str);
				size++;
			} else {
				vec.erase(vec.begin());
				vec.push_back(str);
			}
		}
	}
	
	void remove(int n) {
		vec.erase(vec.begin(), vec.begin() + n);
		size -= n;
	}
	
	void list() {
		int i;
		for(i = 0; i < size; i++) {
			cout << vec[i] << endl;
		}
	}
};

int main() {
	class Buffer buff;
	int n, val;
	char c;
	bool flag;
	cin >> n;
	buff = Buffer(n);
	flag = true;
	while(flag) {
		cin >> c;
		switch(c) {
			case 'Q':
				flag = false;
				break;
			case 'L':
				buff.list();
				break;
			case 'R':
				cin >> val;
				buff.remove(val);
				break;
			case 'A':
				cin >> val;
				buff.append(val);
				break;
			default:
				break;
		}
	}
	return 0;
}