/*
 Frequency Counting of Words / Top N words in a document.
 
Given N terms, your task is to find the k most frequent terms from given N terms.
 
Input format :
 
First line of input contains N, denoting the number of terms to add.
In each of the next N lines, each contains a term.
Next line contains k, most frequent terms.
 
Output format :
 
Print the k most frequent terms in descending order of their frequency. If two terms have same frequency print them in lexicographical order.
 
Sample input :
 
14
Fee
Fi
Fo
Fum
Fee
Fo
Fee 
Fee
Fo
Fi
Fi
Fo
Fum
Fee
3
 
Sample output :
 
Fee
Fo
Fi
 
Constraint :
0 < N < 300000 
0 < term length < 25.
*/

#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, string> val1, pair<int, string> val2) {
    if(val1.first >= val2.first) {
        if(val1.first > val2.first) {
			return true;
		} else if(val1.second < val2.second) {
            return true;
		}
    }
	return false;
}

int main() {
    int n, k, i;
    string str;
    map<string, int> countMap;
    map<string, int>::iterator iter;
	pair<int, string> value;
	vector< pair<int, string> > vec;
	cin >> n;
    for(i = 0; i < n; i++){
        cin >> str;
        countMap[str]++;
    }
    cin >> k;
    for(iter = countMap.begin(); iter != countMap.end(); iter++){
        value = make_pair(iter->second, iter->first);
        vec.push_back(value);
    }
    sort(vec.begin(), vec.end(), comp);
    for(i = 0; i < k; i++){
        cout << vec[i].second << endl;
    }
    return 0;
}