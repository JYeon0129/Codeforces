/*
절대로 탈출할 수 없다고 알려진 감옥에서 죄수들이 탈출했다. 이들은 감옥 근처에 세워져 있던 차를 훔쳐서 도주하고 있으며, 총 N대의 차량을 이용하고 있다. 이 차량들에 대한 정보라고는 각각의 차량의 색상 뿐이다. 즉, 빨간 차는 몇 대, 파란 차는 몇 대, … 와 같다.

죄수를 추적하던 경찰은 다음과 같은 가정을 하게 되었다.

죄수들은 차량을 이용하여 수도로 이동할 것이다. 그런데, 감옥에서 수도로 이동하려면 반드시 특정한 톨게이트를 지나야 한다.
이들은 도로 정보를 잘 모르기 때문에, 사이에 다른 차가 끼면 뒤의 차는 앞 차를 놓치고 길을 잃게 된다. 따라서 반드시 이들은 한 줄로 붙어서 이동할 것이다. 죄수들의 차량간 순서는 알 수 없다.
따라서 경찰은 해당 톨게이트를 조사하여, 이 날 이 톨게이트를 통과한 모든 차량에 대한 정보를 얻을 수 있었다. 이 상황에 대한 예를 들어보자. 차량의 색상은 1~9 사이의 숫자로 주어지고, 죄수들이 타고 있는 차량은 1번 색상 2대, 3번 색상 1대, 7번 색상 1대이다. 한 편 이 날 톨게이트를 통과한 차량은 모두 N=10 대이며, 통과한 순서대로 차량의 색상을 보면 다음과 같다.

1 2 8 7 1 3 1 1 2 5

이를 보면, 4번째부터 7번째 차량들의 색상이 각각 7, 1, 3, 1이므로 죄수들이 타고 있는 차량의 색상과 수와 일치한다. 즉 죄수들은 이미 이 톨게이트를 통과했다고 생각할 수 있다.

죄수들이 톨게이트를 통과했는지 여부를 구하는 프로그램을 작성하시오.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int n, m;
		
		int *color; //차량 색상
		
		int *car; //톨게이트를 지난 차량행렬
		int *buf; //임시 버퍼
		vector<int> v; // 범인의 차량 순서

		//input
		cin >> n >> m;
		car = new int[n + 1];
		color = new int[m + 1];
		color[0] = -1;
		car[0] = -1;
		for (int i = 1; i <= m; i++) {
			cin >> color[i];
			if (color[i] > 0) {
				for (int j = 0; j < color[i]; j++)
					v.push_back(i);
			}
		}
		int tmp = v.size(), result = 0, cnt = 0;
		buf = new int[tmp];
		for (int i = 1; i <= n; i++) {
			cin >> car[i];
		}

		//search
		for (int i = 1; i <= n - tmp + 1; i++) {
			for (int j = 0; j < tmp; j++) {
				buf[j] = car[i + j];
				result = i;
			}
			sort(buf, buf + tmp); // v가 순서대로 정렬됨
			for (int k = 0; k < tmp; k++) {
				if (buf[k] != v.at(k)) break;
				else cnt++;
			}
			if (cnt == tmp) break;
			else cnt = 0;
		}

		//output
		if (cnt == tmp) cout << "#" << test_case + 1 << " " << result << endl;
		else cout << "#" << test_case + 1 << " " << 0 << endl;

	}

	return 0;
}
