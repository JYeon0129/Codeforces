/* 369 게임을 한다
  3,6,9가 들어가면 "-"을 출력하며
  33과 같이 2개이상포함시 "--"로 이어서 출력한다
  각 출력마다 띄어쓰기를 포함한다
  */

#include<iostream>
#include<vector>
using namespace std;
int game(int x) {
	vector<int> v;
	int temp = 0;
	while (x > 0) {
		temp = x % 10;
		if(temp % 3 == 0 && temp != 0) v.push_back(temp);
		x /= 10;
	}
	
	return v.size();
}
int main() {
	int N;
	cin >> N;
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		temp = game(i);
		if (temp > 0) {
			for (int j = 0; j < temp; j++) cout << "-";
			cout << " ";
		}
		else
			cout << i << " ";
	}

	return 0;
}
