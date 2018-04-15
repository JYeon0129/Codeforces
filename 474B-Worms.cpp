#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *pile;
int *num;

int b_search(int n, int start, int end) {
	int r = 0;
	int m = (start + end) / 2;
	if (n > pile[m - 1] && n <= pile[m]) return m;
	else if (n < pile[m]) r = b_search(n, start, m-1);
	else if (n > pile[m]) r = b_search(n, m + 1, end);
	return r;
}

int main() {
	int n,m,tmp;
	cin >> n;
	pile = new int[n+1];
	pile[0] = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> tmp;
		pile[i] = pile[i - 1] + tmp;
	}
	cin >> m;
	num = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}

	int key = (n+1) / 2;
	for (int i = 0; i < m; i++) {
		//for (int j = 1; j < n + 1; j++) {
		//	if (num[i] <= pile[j] && num[i] > pile[j-1]) {
		//		cout << j << endl;
		//		break;
		//	}
		//}
		cout << b_search(num[i], 1, n) <<endl;
	}
	return 0;
}
