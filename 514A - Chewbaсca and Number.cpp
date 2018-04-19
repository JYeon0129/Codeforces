#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
// 입력 숫자의 각 자릿수에 대해 inverse 한 수가 더 작으면 inverse하여 출력한다. 단 맨 앞자리가 0일수는 없다
// inverse는 숫자 t에 대하여 9-t한 것.
int main() { 
	string result;
	__int64 x, tmp = 0;
	cin >> x;

	while (x > 0) {
		tmp = x % 10;
		if (x == 9) {
			result += to_string(tmp);
			break;
		}
		if (tmp >= 5) {
			result += to_string(9 - tmp);
		}
		else {
			result += to_string(tmp);
		}
		x /= 10;
	}
	for (int i = 0; i < result.length(); i++) cout << result.at(result.length() - 1 - i);
	return 0;
}
