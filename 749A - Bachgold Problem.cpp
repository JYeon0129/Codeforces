#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//입력 n에 대해 가능한 많은 소수의 합으로 표현하려한다.
//표현하려는 소수의 개수와 소수들을 출력하라
int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2 << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << 2 << " ";
		}
	}
	else {
		cout << n / 2 << endl;
		for (int i = 0; i < (n / 2)-1; i++) {
			cout << 2 << " ";
		}
		cout << 3;
	}
	return 0;
}
