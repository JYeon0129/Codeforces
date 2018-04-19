#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 입력숫자 n에 대하여 1378^n의 마지막 자릿수를 출력하는것
int main() { 
	int n, a =0;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	n %= 4;
	switch (n) {
	case 0:
		a = 6;
		break;
	case 1:
		a = 8;
		break;
	case 2:
		a = 4;
		break;
	case 3:
		a = 2;
		break;
	}
	cout << a;
	return 0;
}
