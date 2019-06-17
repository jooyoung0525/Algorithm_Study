
======================================================================================================
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

queue<int> Q;
int point[100020] = {0};
int visit[100020] = {0};
int N, K;

void BFS()
{
	visit[N] = 1;
	Q.push(N);

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		int nx = x - 1;
		if (nx >= 0 && visit[nx] == 0)
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;

		}
		nx = x + 1;
		if (nx <= 100000 && visit[nx] == 0)
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

int main()
{
	scanf("%d %d", &N, &K);

	BFS();

	printf("%d", visit[K] - 1);

	system("pause");
	return 0;
}
```
