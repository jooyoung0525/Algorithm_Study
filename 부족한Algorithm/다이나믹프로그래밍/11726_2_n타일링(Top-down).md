
## [내가 세운 점화식]

### 1. 점화식 정의 :D[n]은  2*n에 타일을 채우는 방법의 수

### 2. 큰문제 -> 작은문제 (Top-down방식을 이용함으로 큰값에서 접근)

===> 2*n타일을 2*1타일로 채우던가, 1*2타일로 채우던가

==> 1*2로 채우면 n-2(n*2의 전체 세로값)가 되는데 타일이 2개가 채워짐 -->기저조건

==> 2*1로 채우면 n-1(n*2의 전체 세로값)이 되고 타일이 1개 채워짐 -->기저조건

==>이를 토대로 세운식 ::::: D[n] = D[n-2]+D[n-1]

-------------------------------------------------------------------------------------------------------------------------------

https://www.acmicpc.net/problem/11726

----------------------------------------------------------------------------------------------------------------------------------

### 풀이1. top-down

```c
#include<iostream>

using namespace std;

int n;
int memo[1100] = { 0 };


int filltile(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout<<filltile(n);

	return 0;
}

int filltile(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (memo[n] > 0) return memo[n];

	memo[n] =( filltile(n - 1) + filltile(n - 2)) % 10007;  //처음에 여기서 memo[n] = memo[n-1]+memo[n-2]로 생각함 그리고 %10007을 안해줌!

        // 위에 줄에서 바로 return memo[n] = (filltile(n-1)+filltile(n-2))%10007해줘도 상관없음!!!!                                        
	return memo[n];

}
```
