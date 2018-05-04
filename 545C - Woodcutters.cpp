#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 입력값은 나무의 위치 x ,  나무의 길이 h
//각 좌표에는 나무가 심어져있고 그 나무를 쓰러뜨리면 x-h 또는 x+h 만큼 공간을 차지한다
//두 구간 내에 이미 쓰러진 나무나 서있는 나무가 존재하지않으면 쓰러뜨릴 수 있을 때 쓰러뜨릴수 있는 최대 나무의 갯수
vector<__int64> point;
vector<__int64> bound;
int main() {
	__int64 n, a, b, tmp = 0;
	__int64 *dp;
	cin >> n;
	dp = new __int64[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		dp[i] = 0;
		point.push_back(a);
		bound.push_back(b);
	}
	if (n == 1) {
		cout << 1;
	}
	else {
		dp[0] = 1;
		for (int i = 1; i < n - 1; i++) {
			if (point.at(i) - bound.at(i) > point.at(i - 1)) {
				dp[i] = dp[i - 1] + 1;
			}
			else if (point.at(i) + bound.at(i) < point.at(i + 1)) {
				point.at(i) = point.at(i) + bound.at(i);
				dp[i] = dp[i - 1] + 1;
			}
			else dp[i] = dp[i - 1];
		}
		dp[n - 1] = dp[n - 2] + 1;
		cout << dp[n - 1];
	}
	return 0;
}
