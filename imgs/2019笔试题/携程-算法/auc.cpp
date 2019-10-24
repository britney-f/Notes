#include <bits/stdc++.h>
using namespace  std;


int main()
{
        vector<double> p_score, n_score;
        double x;
        int n, y;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> y >> x;
                if(y) p_score.push_back(x);
                else n_score.push_back(x);
        }
        sort(p_score.begin(), p_score.end());
        sort(n_score.begin(), n_score.end(), greater<double>());
        int cnt = 0, i, j;
        for(i = 0; i < p_score.size(); i++) {
                for(j = 0; j < n_score.size(); j++) {
                        if(p_score[i] > n_score[j]) {
                                break;
                        }
                }
                cnt += n_score.size() - j;
        }
        printf("%.2lf\n", cnt * 1.0 / p_score.size() / n_score.size());
	//system("pause");
	return 0;
}
// 10
// 1 0.90
// 0 0.70
// 1 0.60
// 1 0.55
// 0 0.52
// 1 0.40
// 0 0.38
// 0 0.35
// 1 0.31
// 0 0.10