#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	stack<char> s;
	int result= 0;
	string str;
	
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { // push
			s.push(str[i]);
		}
		else if (str[i] == ')') { //�������϶�, ������϶�
			s.pop();
			if (str[i - 1] == ')') {
				result++;
			}
			else {
				result += s.size();
			}
		}
	}
	cout << result;
}