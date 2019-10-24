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

typedef pair<int, char> P;
bool cmp(const P p1, const P p2)
{
    if(p1.first > p2.first)
        return true;
    else if(p1.first == p2.first)
    {
        if(p1.second < p2.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

const int MAX_N = 14;
int pass[MAX_N];
int times[MAX_N];
P keyVal[MAX_N];

int n;
string str;
/*
6
ADEGHM
58 42 98 84 84 40 75 97 98 7 8 40 54
*/

int main()
{

    cin >> n;
    cin >> str;

    //priority_queue<P, vector<P>, cmp> que;
    priority_queue<P, vector<P>, less<P>> que;

    for(int i=0; i<n; i++)
        pass[int(str[i] - 'A')] = 1;

    for(int i=0; i<13; i++)
        {
            cin >> times[i];
            keyVal[i] = P(times[i], 'A' + i);
            //que.push(P(times[i], 'A' + i));
        }

    sort(keyVal, keyVal + 13, cmp);
    for(int i=0; i<13; i++)
    {
        P key = keyVal[i];
        if(!pass[int(key.second - 'A')])
        {
            cout << key.second << endl;
            break;
        }

    }
        //cout << keyVal[i].first <<  keyVal[i].second << endl;

    return 0;
}