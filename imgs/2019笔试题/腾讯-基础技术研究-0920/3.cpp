#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
#define maxn 310000

struct node{
    long long x,y;
}a[maxn];


bool cmp(node t1, node t2){
    return t1.y>t2.y;
}

priority_queue <int,vector<int>,greater<int> >q;

int n,k;
long long sum[maxn];
int main(){
    int n,m;
	while (scanf("%d %d", &n, &k) != EOF) {
        for(int i=0;i<n;i++){
            scanf("%lld %lld",&a[i].x, &a[i].y);
        }
        sort(a,a+n, cmp);

        long long sum = 0;
        long long ans = 0;
        for(int i=0;i<k;i++){
            q.push(a[i].x);
            sum += a[i].x;
            ans = max(ans,  sum*a[i].y);
        }
        
        for(int i=k;i<n;i++){
            sum+=a[i].x;
            q.push(a[i].x);

            sum-=q.top();
            q.pop();

            ans = max(ans, sum*a[i].y);
        }

        printf("%lld\n", ans);
    }

	return 0;
}
/*
3 2
3 3
1 2
2 2


1 1
2 3

 */
