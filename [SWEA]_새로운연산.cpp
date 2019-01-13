/*
2차원 평면 제 1사분면 위의 격자점 (x,y)에 위 그림과 같이 대각선 순서로 점에 수를 붙인다.

점 (x,y)에 할당된 수는 #(x,y)로 나타낸다.

예를 들어 #(1,1) = 1, #(2,1)=3, #(2,2) = 5, #(4,4) = 25이다.

반대로 수 p가 할당된 점을 &(p)로 나타낸다.

예를 들어 &(1) = (1,1), &(3) = (2,1), &(5) = (2,2), &(25) = (4,4)이다.

두 점에 대해서 덧셈을 정의한다. 점 (x,y)와 점 (z,w)를 더하면 점 (x+z, y+w)가 된다.

즉, (x,y) + (z,w) = (x+z, y+w)로 정의한다.

우리가 해야 할 일은 수와 수에 대한 새로운 연산 ★를 구현하는 것으로, p★q는 #(&(p)+&(q))으로 나타난다.

예를 들어, &(1)=(1,1), &(5) = (2,2)이므로, 1★5 = #(&(1)+&(5)) = #((1,1)+(2,2)) = #(3,3) = 13이 된다.
     |    |    |    |   |
   7 |    |    |    |   |
   4 |  8 |    |    |   |
   2 |  5 |  9 |    |   |
   1 |  3 |  6 | 10 |   |
    좌표의 순서는 이런식
*/

#include<iostream>
using namespace std;
int* checklevel(int x) {
	int a = 1, b = 0 ,level = 0, index = 1;
	int result[2] = { 0 };
	while (1) {
		if (b < x && x <= a) {
			level = a - b;
			result[0] = level; //level
			result[1] = b; // 직전 level의 최대값
			break;
		}
		b = a;
		index++;
		a += index;		
	}
	return result;
}
int computing(int x, int y) {
	int result = 0;
	for (int i = 1; i <= x; i++) {
		result += i;
	}
	for (int i = 0; i < y-1; i++) {
		result += (x + i);
	}
	return result;
}
int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int result = 0;
		int p, q;
		cin >> p >> q;
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0, nx = 0, ny = 0;
		int* a;
		int* b;
		
		a = checklevel(p);
		x1 = p - a[1];
		y1 = a[0] + 1 - x1;

		b = checklevel(q);
		x2 = q - b[1];
		y2 = b[0] + 1 - x2;
		nx = x1 + x2;
		ny = y1 + y2;
		result = computing(nx, ny);
		
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
