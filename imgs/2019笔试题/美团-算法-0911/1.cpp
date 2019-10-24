#include<iostream>
#include<algorithm>
#include"stdio.h"
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<stack>
#include<deque>
#include<string>
#include <sstream>
#include <unordered_map>

using namespace std;

const int MAX_N = 1001;
const int MAX_M = 1001;

int dp[MAX_N][MAX_M];
char str1[MAX_N];
char str2[MAX_M];

int main()
{

    int n, m;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> str1[i];

    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> str2[i];

    memset(dp, 0, sizeof(dp));

    int res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(str1[i] == str2[j])
        {
            dp[i+1][j+1] = dp[i][j] + 1;
            res = max(res, dp[i+1][j+1]);
        }

    }

    cout << res << endl;


    return 0;
}

