/* 입력숫자 중에서 가장 차이가 많이 나는 숫자쌍의 가능한 개수를 구하라 */

#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int *flower;
int main() {
	__int64 n, min_count = 0, max_count = 0;
	cin >> n;
	flower = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> flower[i];
	}
	sort(flower, flower + n);
	if (flower[0] != flower[n - 1]) {
		for (int i = 0; i < n; i++) {
			if (flower[0] == flower[i]) {
				min_count++;
			}
			if (flower[n - 1] == flower[n - 1 - i]) {
				max_count++;
			}
		}
		cout << flower[n - 1] - flower[0] << " " << min_count * max_count;
	}
	else {
		cout << flower[n - 1] - flower[0] <<" " << n * (n - 1) / 2;
	}
	
	return 0;
}
