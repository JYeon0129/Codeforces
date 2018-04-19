#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//참가자들을 m개의 팀으로 나눈다 각 팀은 최소 1명 이상의 참가자가 있다.
//같은 팀에 속한 참가자들은 친구가 될수있다. 친구의 최대 최소 숫자를 구하라
__int64 combi(__int64 a) {
	return (a * (a - 1)) / 2;
}

int main() {
	__int64 n, m, tmp = 0, min_result = 0,max_result = 0, tmp2 = 0;
	cin >> n >> m;

	tmp = n - (m - 1);
	max_result = combi(tmp);

	tmp = n / m;
	tmp2 = n % m;
	if (n % m == 0) {
		min_result = combi(tmp)*m;
	}
	else {
		min_result = combi(tmp)*(m-tmp2) + combi(tmp+1)*tmp2;
	}
	cout << min_result << " " << max_result;
	return 0;
}
