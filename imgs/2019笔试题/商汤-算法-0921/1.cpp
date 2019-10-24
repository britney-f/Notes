#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;


int f(int n)
{
    if(n == 1)
        return 0;
    else if( n <= 3)
        return 1;

    int val1 = n, val2 = n;
    if(n % 2 == 0)
        val1 = min(val1, f(n/2) + 1);
    else
        val1 = min(val1, f((n+1)/2) + 2);

    if(n % 3 == 0)
        val2 = min(val2, f(n/3) + 1);
    else if(n % 3 == 2)
        val2 = min(val2, f((n+1)/3) + 2);
    else
        val2 = min(val2, f((n+2)/3) + 3);

    return min(val1, val2);
}

int main()
{

    int n;
    cin >> n;

    cout << f(n) << endl;
}

/*
int main()
{

    int n;
    cin >> n;

    if(n == 1)
        cout << 0 << endl;
    else if( n <= 3)
        cout << 1 << endl;
    else
    {
        int count = 0;
        while(n > 3)
        {
            if(n % 3 == 0)
                n /= 3;
            else if (n % 2 == 0)
                n /= 2;
            else
                n += 1;
            //cout << n << endl;
            count++;
        }
		
		if(n == 1)
			cout << count << endl;
		else if( n <= 3)
			cout << count + 1 << endl;

    }

    return 0;
}
*/