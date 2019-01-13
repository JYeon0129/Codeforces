/*
  N명의 손님이 각각 x초에 도착할 때
  붕어빵 장수는 M초에 K개의 붕어빵을 생산한다.
  이때 모든 손님에게 정상적으로 판매가능하면 Possible 아니면 Impossible을 출력한다
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		//int result = 0;
		string result = "Possible";
		int N, M, K; // N명의 손님 , M초에 K의 붕어빵 생산
		int bread[11112] = { 0 };
		int stock = 0;
		cin >> N >> M >> K;

		int temp, max_num = 0;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			bread[temp]++;
			if (max_num < temp) max_num = temp;
		}

		for (int i = 0; i <= max_num; i++) {
			if (i != 0 && i % M == 0) stock += K;
			if (bread[i] > 0) {
				if (bread[i] <= stock) stock -= bread[i];
				else {
					result = "Impossible";
					break;
				}
			}
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
