#include <bits/stdc++.h>
using namespace  std;

// aabbcddc
int main()
{
	string s;
	cin >> s;
	int last = -1;
	int last_idx_arr[300];
	vector<int> ans;
	for(int i = 0; i < s.size(); i++) {
		last_idx_arr[s[i]] = i;
	}
	int pos = 0, cnt = 0;
	while(pos < s.size()) {
		cnt = 1;
		last = max(last, last_idx_arr[s[pos]]);
		while(pos < last) {
                        ++pos, ++cnt;
			last = max(last, last_idx_arr[s[pos]]);
		}
		ans.push_back(cnt);
                ++pos;
		cnt = 1;
	}
	cout << ans[0];
	for(int i = 1; i < ans.size(); ++i) {
		cout << "," << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}