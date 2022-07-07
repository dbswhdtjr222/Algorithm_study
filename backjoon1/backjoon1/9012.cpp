#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main(void)
{
	stack<char> s;
	int test_num;
	string result;
	string str;
	string jump = "\n";
	cin >> test_num;
	for (int i = 0; i < test_num; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else {
				if (s.size() != 0) {
					s.pop();
				}
				else {
					result = "NO";
					goto label;
				}
			}
		}
		if (s.size() == 0) {
			result = "YES";
		}
		else {
			result = "NO";
		}
		while (!s.empty())
			s.pop();
	label:
		cout << result;
		cout << jump;
	}
}