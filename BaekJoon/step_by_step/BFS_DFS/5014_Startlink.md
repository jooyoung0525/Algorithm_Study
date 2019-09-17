![캡처](https://user-images.githubusercontent.com/29946480/65026041-b0f73180-d972-11e9-99b5-c735317632d9.JPG)
---------------------------------------------------------------------------------------------------------------
### 걸린시간 16:40~17:40
### 쓰던대로 쓰자!!! 배열크기도 int,bool일때 몇개까지 가능한지 알아보기!
---------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int F, S, G, U, D;
int visit[1000001];

queue<pair<int, int>>Q;

int BFS()
{
	while (!Q.empty())
	{
		int curx = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (curx == G)
		{
			return c;
		}
		
			

		int nx = curx + U;
		if (nx <= F && visit[nx] == 0)
		{
			visit[nx] = 1;
			Q.push({ nx,c + 1 });
		}
		int nd = curx - D;
		if (nd > 0 && visit[nd] == 0)
		{
			visit[nd] = 1;
			Q.push({ nd,c + 1 });
		}
	}

	return -5;
}

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	for (int i = 1; i <= F; i++)
	{
		visit[i] = 0;
	}

	visit[S] = 1;
	Q.push({ S,0 });

	int result = BFS();

	if(result == -5)
		printf("use the stairs");
	else
		printf("%d",result);

	//system("pause");
	return 0;
}
```
