#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
using namespace std;
int *check;
int *arr;

int main() {
	int m, a, b, n = 0, result = 0;
	string str;
	cin >> str >> m;
	n = str.length();
	check = new int[n];
	arr = new int[m];
	check[0] = 0;
	for (int i = 1; i < n; i++) {
		check[i] = check[i-1];
		if (str.at(i) == str.at(i - 1)) {
			check[i] = check[i-1] + 1;
		}
	}
	for (int i = 0; i < m; i++) {
		arr[i] = 0;
		cin >> a >> b;
		arr[i] = check[b - 1] - check[a - 1];
	}
	for (int i = 0; i < m; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
