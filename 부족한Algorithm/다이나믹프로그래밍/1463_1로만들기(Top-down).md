### DP ==> 메모이제이션 

==> 오늘 이거만 연습!!!!

### [DP푸는법]

### 1.점화식세움(무엇을 풀어야하는 문제인지)

### 2.큰문제를 작은문제로 쪼개봄

### 3. 1,2번을 활용해 식을완성

-------------------------------------------------------------------------------------------------------------------------------------

https://www.acmicpc.net/problem/1463

---------------------------------------------------------------------------------------------------------------------------------------

## 풀이 1 (Top-down(재귀)이용 ==>백준강의 참고)

```c
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int memo[1000001] = {0}; //작은값을 메모해줄 배열만듦

int makeone(int N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout<<makeone(N)<<"\n";

	return 0;
}

int makeone(int N)
{
	if (N == 1) return 0; // N이 1이면 더이상 연산을 안해도되니 0리턴
	else {
		if (memo[N] > 0) return memo[N]; // 만약에 메모에 답이 저장되있다면 그값을 리턴
		memo[N] = makeone(N - 1) + 1; // N번째 답을 N-1인조건을 계산해줌
		if (N % 3 == 0) // N이 3으로 나누어떨어질때 N/3조건을 계산해줌
		{
			int temp = makeone(N / 3) + 1;
			if (memo[N] > temp) memo[N] = temp; // 앞의 조건1번인 N-1조건과 비교했을때 2번조건인 N/3이 더작으면 메모값을 작은값으로 바꿔줌
		}
		if (N % 2 == 0) // N이 2으로 나누어떨어질때 N/2조건을 계산해줌
		{
			int temp = makeone(N / 2) + 1;
			if (memo[N] > temp) memo[N] = temp; // 앞의 조건2번인 N/3조건과 비교했을때 3번조건인 N/2이 더작으면 메모값을 작은값으로 바꿔줌
		}
		return memo[N]; //결국 N번째에 메모되는 값은 조건1,2,3중 가장 작은값 (최솟값을 구해야하기때문)
	}


}
```
