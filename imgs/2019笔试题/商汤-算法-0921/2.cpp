#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int num[1000005];
int visit[1000005];
int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
         cin >> num[i];

     priority_queue <int,vector<int>,greater<int> > que;
     memset(visit, 0x3f, sizeof(visit));
     int l, r, k;
     for(int i=0; i<m; i++)
     {
         cin >> l >> r >> k;

         for(int j=l; j<=r; j++)
         {
             if(visit[j] == INF)
                que.push(num[j]);
         }

         if(que.empty())
            cout << -1 << endl;
         else if(que.size() >= k)
         {

             int x = k;
             int val;
             while(x--)
             {

                 val = que.top();
                 que.pop();

                 for(int t=l; t<=r; t++)
                 {
                     if(num[t] == val && visit[t] == INF)
                     {
                         visit[t] = 0;
                     }
                 }

             }
             cout << val << endl;
         }
         else
         {
             int val;
             while(que.size())
             {
                 val = que.top();
                 que.pop();
             }

             cout << val << endl;

             for(int t=l; t<r; t++)
                visit[t] = 0;
         }

         while(!que.empty())
            que.pop();

     }

    return 0;
}
/*
4 3
1 2 3 4
1 4 2
1 3 2
1 2 1
*/