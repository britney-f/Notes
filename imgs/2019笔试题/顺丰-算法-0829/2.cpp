#include<iostream>
#include<algorithm>
#include"stdio.h"

using namespace std;


const int MAX_N = 210000;
int f[MAX_N];
int vis[MAX_N];

int fa(int a)
{
    if(a == f[a])
        return a;
    else
        return f[a]=fa(f[a]);

}

int n, m, k;
/*
3 3 2
2 3
3 1
*/

int main()
{

    cin >> n >> m >> k;

    for(int i=1; i<=m+n; i++)
    {
        f[i]=i;
        vis[i]=-1;
    }

    for(int i=1; i<=k; i++)
    {
        int u, v;
        cin >> u >> v;
        v += n;
        f[fa(u)] = fa(v);
    }

    int ans=0;
    for(int i=0; i<=n; i++)
        if(vis[fa(i)] == -1)
    {
        vis[fa(i)] = 1;
        ans++;
    }
    if(k==0)
        cout << ans << endl;
	
    else
        cout << ans - 1 << endl;

    return 0;
}