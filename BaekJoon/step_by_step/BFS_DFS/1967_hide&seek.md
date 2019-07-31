![Capture](https://user-images.githubusercontent.com/29946480/59597367-f0a34880-90f9-11e9-9fca-269dfa104df9.PNG)
------------------------------------------------------------------------------------------------------------------
### BFS이용한 문제!

### 이해하니까 쉬웠지만 처음에는 왜 BFS이용하는지 이해가 안가서 힌트보고 품..
---------------------------------------------------------------------------------------------------------------------
```c

// 언니가 1초에 갈 수 있는 경우의수
// 1. N-1
// 2. N+1
// 3. N*2
// 각각 경우의 수를 방문할 수 있을 경우 방문체크

#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

queue<int> Q;
int visit[100020] = {0};
int N, K;

void BFS()
{
	visit[N] = 1; // 언니위치 방문체크
	Q.push(N);

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		int nx = x - 1; 
		if (nx >= 0 && visit[nx] == 0) //배열은 0부터이므로 nx가 음수이면 안됨.
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;

		}
		nx = x + 1;
		if (nx <= 100000 && visit[nx] == 0) //배열이 100000까지 이므로 nx 가 100000를 넘어가서는 안됨.
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;
		}
		nx = 2 * x;
		if (nx <= 100000 && visit[nx] == 0)
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;
		}
	}	

}

// ↓↓ BFS실행할 경우 배열의 상태 ↓↓
// point[100000] = 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
// visit[100000] = 6 5 4 3 2 1 2 3 3 3 2 3 3 4 4 5 4 5 5 4 3

int main()
{
	scanf("%d %d", &N, &K);

	BFS();

	printf("%d", visit[K] - 1);

	system("pause");
	return 0;
}
```
-----------------------------------------------------------------------------------------------------------------------
### ↓↓↓또 다른 풀이↓↓↓

- queue에 언니의 위치, 걸린시간 두 정보를 넣어준다
- 위의 코드처럼 한개씩 언니의 위치가 바뀔 때(queue에 새로운 정보를 집어넣을때)마다 걸린시간을 바꾸는 것이 아니라, queue에서 정보를 한번씩 빼낼때마다 세 조건 한꺼번에 걸린시간이 바뀜

---------------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int visit[100000] = { 0 };
queue<pair<int,int>> Q;

int main() {

	int N, k;
	scanf("%d %d", &N, &k);

	int sec = 0;
	Q.push({N,0});

	while (!Q.empty()) {

		int x = Q.front().first;
		int s = Q.front().second;

		visit[x] = 1;
		Q.pop();
		
		if (x == k)
		{
			sec = s;
			break;
		}

		int nx = 2 * x;
		if (nx <= 100000 && visit[nx] == 0) {
			Q.push({ nx,s + 1 });
		}
		
	    nx = x + 1;
		if (nx <= 100000 && visit[nx] == 0) {
			Q.push({ nx,s + 1 });
		}
		
		nx = x - 1;
		if (nx >= 0 && visit[nx] == 0) {
			Q.push({ nx,s + 1 });
		}

		
	}

	printf("%d\n", sec);

	//system("pause");
	return 0;
}
```
