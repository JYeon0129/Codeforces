#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;

int main() {
	int n, d, tmp, sum = 0, result = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
	}
	if ((n - 1) * 10 + sum <= d) {
		sum += (n - 1) * 10;
		result = 2 * (n - 1);
		while (1) {
			if (d - sum >= 5) {
				result++;
				sum += 5;
			}
			else break;
		}
		cout << result;
	}
	else {
		cout << -1;
	}
	return 0;
}
