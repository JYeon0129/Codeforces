#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *arr_a;
int *arr_p;
int main() {
	int n, result = 0, now_min = 101;
	cin >> n;
	arr_a = new int[n];
	arr_p = new int[n];
	for (int i = 0; i < n; i++) cin >> arr_a[i] >> arr_p[i];
	for (int i = 0; i < n; i++) {
		if (now_min > arr_p[i]) now_min = arr_p[i];
		result += arr_a[i] * now_min;
	}
	cout << result;
	//_getch();
	return 0;
}