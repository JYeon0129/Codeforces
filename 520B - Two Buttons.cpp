#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 빨간 버튼은 *2 / 파란버튼은 -1 n -> m으로 가는 최소 횟수
int main() {
	int n, m, result = 0;
	cin >> n >> m;
	if (n >= m) result = n - m;
	else {
		while (n < m) {
			if (m % 2 == 0) {
				m /= 2;
				result++;
			}
			else { // 역으로 가는형태이므로 m이 홀수라면 n*2 -1 이어야 한다. 즉 이동횟수는 2개가 증가되어야한다.
				m = m / 2 + 1;
				result += 2;
			}
		}
		result += (n - m);
	}
	cout << result;
	return 0;
}
