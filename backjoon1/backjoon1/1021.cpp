//#include <iostream>
//#include <deque>
//
//#define MAX 50
//using namespace std;
//int main(void)
//{
//	int size, index_num, p, left, right;
//	int count = 0;
//	cin >> size >> index_num;
//	int index_list[MAX];
//
//	deque<int> dq;
//	for (int i = 0; i < index_num; i++) {
//		cin >> index_list[i];
//	}
//	for (int i = 1; i <= size; i++)
//	{
//		dq.push_back(i);
//	} 
//	int j = 0; // index_list 인덱스 고정dd
//	while (index_num--) {
//		for (int i = 0; i < dq.size(); i++) {
//			if (index_list[j] == dq.at(i)) {
//				left = i;
//				right = dq.size() - 1;
//				break;
//			}
//		}
//		if (left <= right) { // 왼쪽으로 가기
//			while (1) {
//				if (dq.front() == index_list[j]) { // 값 뽑아내기
//					break;
//				}
//				dq.push_back(dq.front());
//				dq.pop_front();
//				count++;
//			}
//			dq.pop_front();
//		}
//		else { // left > right 오른쪽으로 가기
//			while (1) {
//				if (dq.front() == index_list[j]) {
//					break;
//				}
//				dq.push_front(dq.back());
//				dq.pop_back();
//				count++;
//			}
//			dq.pop_front();
//		}
//		j++;
//	}
//	printf("%d\n", count);
//}

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
		for (int j = 0; j < q_size; j++) {
			if (user_indexs[i] == dq.at(j)) { 
				index = j; // 찾은 위치
				break;
			}
		}
		if (index > (q_size - index)) { // 오른쪽이동
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