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
		for (int j = 0; j < dq.size(); j++) {
			if (user_indexs[i] == dq.at(j)) { 
				index = j; // ã�� ��ġ
				break;
			}
		}
		if (index >= (dq.size() - index)) { // �������̵�
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