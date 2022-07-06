#include <iostream>
#include <assert.h>
#include <deque>
using namespace std;

int main(void)
{
	int q_size =  0 , user_num = 0, index = 0, count = 0;
	deque<int> dq;
	
	cin >> q_size >> user_num;

	int* user_indexs = (int*)malloc(sizeof(int) * user_num); // 동적할당 배열

	for (int i = 0; i < user_num; i++) { // 찾으려는 인덱스를 저장
		cin >> user_indexs[i];
		assert(user_indexs[i] >= 1 && user_indexs[i] <= q_size); 
	}
	for (int i = 1; i <= q_size; i++) {
		dq.push_back(i); // 큐에 값 넣기 값들이 정해지지 않았으므로 1~ size만큼 넣어준다
	}
	for (int i = 0; i < user_num; i++) { // 찾고자하는 값의 인덱스 찾기
		for (int j = 0; j < dq.size(); j++) {
			if (user_indexs[i] == dq.at(j)) { 
				index = j; // 찾은 위치
				break;
			}
		}
		if (index >= (dq.size() - index)) { // 오른쪽이동
			while (1) {
				if (dq.front() == user_indexs[i]) {
					dq.pop_front();
					break;
				}
				else {
					int b;
					b = dq.back();
					dq.pop_back();
					dq.push_front(b);
					count++;
				}
			}
		}
		else { // 왼쪽
			while (1) {
				if (dq.front() == user_indexs[i]) {
					dq.pop_front();
					break;
				}
				else {
					int a;
					a = dq.front();
					dq.pop_front();
					dq.push_back(a);
					count++;
				}
			}
		}
	}
	cout << count;
}