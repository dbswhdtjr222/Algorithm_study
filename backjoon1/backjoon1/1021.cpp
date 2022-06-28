#include <iostream>
#include <deque>

#define MAX 50
using namespace std;
int main(void)
{
	int size, index_num, p, left, right;
	int count = 0;
	cin >> size >> index_num;
	int index_list[MAX];

	deque<int> dq;
	for (int i = 0; i < index_num; i++) {
		cin >> index_list[i];
	}
	for (int i = 1; i <= size; i++)
	{
		dq.push_back(i);
	}
	int j = 0; // index_list �ε��� ����
	while (index_num--) {
		for (int i = 0; i < dq.size(); i++) {
			if (index_list[j] == dq.at(i)) {
				left = i;
				right = dq.size() - 1;
				break;
			}
		}
		if (left <= right) { // �������� ����
			while (1) {
				if (dq.front() == index_list[j]) { // �� �̾Ƴ���
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}
		else { // left > right ���������� ����
			while (1) {
				if (dq.front() == index_list[j]) {
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
		j++;
	}
	printf("%d\n", count);
}