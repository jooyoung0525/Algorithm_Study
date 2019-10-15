### 기저값은 n==1일때 2*1타일1개로 이루어진거 = 1가지, n==2일때 1*2타일 2개로이루어진거+ 2*1타일2개로이루어진거+2*2타일1개로이루어진거 = 3가지

-----------------------------------------------------------------------------------------------------------------------------------

https://www.acmicpc.net/problem/11727

------------------------------------------------------------------------------------------------------------------------------------

### 풀이1.

```c
#include<iostream>

using namespace std;

int n;
int memo[1010] = { 0 };

int filltile(int n)
{
	if (n == 1) return 1;
	if (n == 2)return 3;
	if (memo[n] > 0)return memo[n];

	return memo[n] = ((filltile(n - 1) + (2 * filltile(n - 2))) % 10007); //괄호조심!!! 연산에 우선순위 잘생각해서 풀기를(이거때매 틀렸었음)
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << filltile(n);

	return 0;
}
```
