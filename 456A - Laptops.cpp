#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *arr;
int *arr2;
// 두 정수의 합이 만약 같은것이 2개 이상나온다면 3+7 -> 4+6 처럼 퀄리티는 높아지고 가격은 낮아지는 현상이 발생한것
//하지만 항상 그런것은아님
int main() {
	int n, a, b;
	string str = "Poor Alex";
	cin >> n;
	arr = new int[n + 1];
	arr2 = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = 0;
		arr2[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[a] = b;
		arr2[a] = b;
	}
	sort(arr+1, arr + n+1);
	for (int i = 1; i < n+1; i++) {
		if (arr[i] != arr2[i]) {
			str = "Happy Alex";
			break;
		}
	}
	cout << str;
	return 0;
}
