#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
int n, tmp;
vector<__int64> v;
vector<__int64> diff;
__int64 *result;
int main(){
	cin >> n;
	result = new __int64[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		if (i > 0) {
			diff.push_back(abs(v.at(i) - v.at(i - 1)));
		}
	}
	if (n == 2) {
		cout << diff.at(0);
		return 0;
	}
	result[0] = diff.at(0);
	result[1] = diff.at(1);
	__int64 maxi = max(result[0], result[1]);
	for (int i = 2; i < n-1; i++) {
		//result[i-2]를 i-2번째 노드까지의 최적해이므로 초항으로 볼수있음
		result[i] = max(diff.at(i), result[i - 2] - diff.at(i - 1) + diff.at(i));
		if (maxi < result[i]) maxi = result[i];
	}
	cout << maxi << endl;
	return 0;
}
