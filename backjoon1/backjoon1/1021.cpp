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
//	int j = 0; // index_list �ε��� ����dd
//	while (index_num--) {
//		for (int i = 0; i < dq.size(); i++) {
//			if (index_list[j] == dq.at(i)) {
//				left = i;
//				right = dq.size() - 1;
//				break;
//			}
//		}
//		if (left <= right) { // �������� ����
//			while (1) {
//				if (dq.front() == index_list[j]) { // �� �̾Ƴ���
//					break;
//				}
//				dq.push_back(dq.front());
//				dq.pop_front();
//				count++;
//			}
//			dq.pop_front();
//		}
//		else { // left > right ���������� ����
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

	int* user_indexs = (int*)malloc(sizeof(int) * user_num); // �����Ҵ� �迭

	for (int i = 0; i < user_num; i++) { // ã������ �ε����� ����
		cin >> user_indexs[i];
		assert(user_indexs[i] >= 1 && user_indexs[i] <= q_size); 
	}
	for (int i = 1; i <= q_size; i++) {
		dq.push_back(i); // ť�� �� �ֱ� ������ �������� �ʾ����Ƿ� 1~ size��ŭ �־��ش�
	}
	for (int i = 0; i < user_num; i++) { // ã�����ϴ� ���� �ε��� ã��
		for (int j = 0; j < q_size; j++) {
			if (user_indexs[i] == dq.at(j)) { 
				index = j; // ã�� ��ġ
				break;
			}
		}
		if (index > (q_size - index)) { // �������̵�
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
		else { // ����
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