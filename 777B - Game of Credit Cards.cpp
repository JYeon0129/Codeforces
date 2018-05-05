#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<functional> 
#include<vector>
#include<map>
#include<conio.h>
using namespace std;
//모리어티는 최저점수를 셜록은 최대점수를 얼마나 얻을수 있는지
int *s_arr;
int *m_arr;
int *s_arr2;
int *m_arr2;
int main() {
	int n, m_min = 0, s_max = 0;
	string s, m;
	cin >> n >> s >> m;
	s_arr = new int[n];
	m_arr = new int[n];
	m_arr2 = new int[n];
	for (int i = 0; i < n; i++) {
		s_arr[i] = s.at(i) - '0';
		m_arr[i] = m.at(i) - '0';
		m_arr2[i] = m.at(i) - '0';
	}
	sort(s_arr, s_arr + n);
	sort(m_arr, m_arr + n);
	sort(m_arr2, m_arr2 + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s_arr[i] < m_arr[j]) {				
				m_arr[j] = -1;
				sort(m_arr, m_arr + j);
				s_max++;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m_arr2[i] >= s_arr[j] && s_arr[j] != -1) {
				s_arr[j] = -1;
				sort(s_arr, s_arr + j);
				m_min++;
				break;
			}
		}
	}
	m_min = n - m_min;
	cout << m_min << endl << s_max;
	return 0;
}
