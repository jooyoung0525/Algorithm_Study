# Deque사용 (덱)

- BFS는 가중치가 1인 최단거리를 찾을 때 유용함.
- 아래 문제는 가중치가 1인경우와, 0인경우가 있음
- 따라서 가중치 값이 다른 두 경우를 queue의 앞쪽 뒤쪽으로 나누어서 넣어주던가 (방법1)
- queue를 두개 이용해서 풀어야함. (방법2)
-----------------------------------------------------------------------------------------------------------------------
![Capture](https://user-images.githubusercontent.com/29946480/62456300-67fb6d00-b778-11e9-80ee-80d05b43d3ab.PNG)
-----------------------------------------------------------------------------------------------------------------------
### 방법 1)
-----------------------------------------------------------------------------------------------------------------------
```c
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<deque>

using namespace std;

bool visit[100001] = { 0 };
int N, K;

deque <pair<int, int>>Q;

int main()
{
	scanf("%d %d", &N, &K);

	Q.push_back({ N,0 });
	
	while (!Q.empty())
	{
		int now = Q.front().first;
		int n_dist = Q.front().second;
		Q.pop_front();
		visit[now] = true;

		if (now == K)
			printf("%d", n_dist);

		int nx = now * 2;
		if (nx < 100001 && !visit[nx])
		{
			visit[nx] = true;
			Q.push_front({ nx,n_dist });
		}

		nx = now + 1;
		if (nx < 100001 && !visit[nx])
		{
			visit[nx] = true;
			Q.push_back({ nx,n_dist + 1 });
		}

		nx = now - 1;
		if (nx >= 0 && !visit[nx])
		{
			visit[nx] = true;
			Q.push_back({ nx,n_dist + 1 });
		}
	}
}
```
---------------------------------------------------------------------------------------------------------------------------------
### 방법 2)
-----------------------------------------------------------------------------------------------------------------------
