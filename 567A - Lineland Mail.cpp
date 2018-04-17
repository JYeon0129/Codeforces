#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *mini;
int *maxi;
int *city;
int main() {
	__int64 n, a, b;
	cin >> n;
	mini = new int[n];
	maxi = new int[n];
	city = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << city[1] - city[i] << " " << city[n - 1] - city[i] << endl;
		}
		else if (i == n - 1) {
			cout << city[i] - city[i-1] << " " << city[i] - city[0] << endl;
		}
		else {
			cout << min(city[i]-city[i-1],city[i+1]-city[i]) << " " << max(city[i]-city[0],city[n-1]-city[i]) << endl;
		}
	}
	return 0;
}
