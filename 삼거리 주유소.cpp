#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
using namespace std;
vector<int> h_cost;
vector<int> h_length;
vector<int> v_cost;
vector<int> v_length;
int arr[5000];
int h, v, n, pre_mini = 0;

int horizontal_only() { // case1
	int result = 0, min_cost = 1001;
	for (int i = 0; i < h - 1; i++) {
		if (h_cost.at(i) < min_cost) min_cost = h_cost.at(i);
		result += min_cost * h_length.at(i);
	}
	return result;
}

int horizontal_mini() { //v 지점까지 탐색
	int result = 0, min_cost = 1001;
	for (int i = 0; i < v - 1; i++) {
		if (h_cost.at(i) < min_cost) min_cost = h_cost.at(i);
		result += min_cost * h_length.at(i);
	}
	pre_mini = min_cost;
	return result;
}

int horizontal_mini2(int mini) {
	int result = 0, min_cost = mini;
	for (int i = v - 1; i < h - 1; i++) {
		if (h_cost.at(i) < min_cost) min_cost = h_cost.at(i);
		result += min_cost * h_length.at(i);
	}
	return result;
}

int vertical_mini(int mini) {
	int result = 0, min_cost = mini, now_total = 0;
	
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			result += min_cost * v_length.at(i);
			now_total += v_length.at(i);
			if (v_cost.at(i) < min_cost) {
				min_cost = v_cost.at(i);
				pre_mini = min_cost;
			}
		}
		else if (i > 0) { 
			result += min_cost * v_length.at(i);
			now_total += v_length.at(i);
			if (v_cost.at(i) < min_cost) {
				min_cost = v_cost.at(i);
				pre_mini = min_cost;
			}
		}
		arr[i] = result + min_cost * (now_total) + horizontal_mini2(min_cost);
	}
	
	sort(arr, arr + n);
	return arr[0];
}

int main() {
	int tmp1, tmp2, result = 0;
	cin >> h;
	for (int i = 1; i < h; i++) {
		cin >> tmp1 >> tmp2;
		h_cost.push_back(tmp1);
		h_length.push_back(tmp2);
	}
	cin >> v >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		v_cost.push_back(tmp2);
		v_length.push_back(tmp1);
	}
	int c0 = horizontal_only();
	int c1 = horizontal_mini();
	if (pre_mini > h_cost.at(v - 1)) pre_mini = h_cost.at(v - 1);
	int c2 = vertical_mini(pre_mini);
	int c3 = horizontal_mini2(pre_mini);

	result = min(c0, c1 + c2);
	cout << result <<endl;

	return 0;
}
