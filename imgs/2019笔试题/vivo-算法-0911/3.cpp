#include <iostream>
#include <stdlib.h>
#include<algorithm>
#include<vector>
#include <string.h>

using namespace std;

/**
* Welcome to vivo !
*/

#define MAX_NUM 100

int solution(int boxs[], int N)
{
 // TODO Write your code here
 int res = 0;
 vector<int> arr(boxs, boxs + N);
 sort(arr.begin(), arr.end());
 for (int i = 0; i < N-1; ++i) {
  int tmp = 1;
  while (i+1<N&&arr[i] == arr[i + 1]) {
   tmp++;
   ++i;
  }
  res += tmp*tmp;
 }
 return res;
}

int main()
{
 string str("");
 getline(cin, str);
 int boxs[MAX_NUM];
 int i = 0;
 char *p;
 int count = 0;

 const char* strs = str.c_str();
 p = strtok((char *)strs, " ");
 while (p)
 {
  boxs[i] = atoi(p);
  count++;
  p = strtok(NULL, " ");
  i++;
  if (i >= MAX_NUM)
   break;
 }

 int num = solution(boxs, count);
 cout << num << endl;
 return 0;
}