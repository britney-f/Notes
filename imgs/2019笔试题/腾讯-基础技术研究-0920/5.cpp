#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int In(string s1, string s2)
{
	int flag = 1;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != s2[i])
			flag = 0;
	return flag;
}
int main()
{
	int m, n;
	cin >> n >> m;
	vector<string>a;
	string s, s1;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	vector<vector<string>>b(100000);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> s1;
		b[i].push_back(s);
		b[i].push_back(s1);
	}
	string result;
	for (int i = 0; i < m; i++)
	{
		int flag = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (In(b[i][0], a[j]) && (!In(b[i][1], a[j])))
			{
				cout << a[j] << endl;
				a.erase(a.begin() + j);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "-1" << endl;
	}
}
