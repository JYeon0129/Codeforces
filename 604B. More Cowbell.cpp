#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *cowbell;
int main() {
	int n, k, index = 0, result = 0, single = 0;
	cin >> n >> k;
	cowbell = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> cowbell[i];
	}
	result = cowbell[n - 1];
	if (k < n) {
		single = 2 * k - n;
		n -= single;
		while (1) {
			if (result < cowbell[index] + cowbell[n - 1 - index] && (n - 1 - index) >= 0) {
				result = cowbell[index] + cowbell[n - 1 - index];
			}
			index++;
			if (index > n - 1 - index) break;
		}
	}
	cout << result;
	//_getch();
	return 0;
}