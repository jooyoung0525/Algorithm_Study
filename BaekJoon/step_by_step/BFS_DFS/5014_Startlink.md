![캡처](https://user-images.githubusercontent.com/29946480/65026041-b0f73180-d972-11e9-99b5-c735317632d9.JPG)
---------------------------------------------------------------------------------------------------------------
### 걸린시간 16:40~17:40
### 쓰던대로 쓰자!!! 배열크기도 int,bool일때 몇개까지 가능한지 알아보기!
---------------------------------------------------------------------------------------------------------------
# 풀이 1. (맞음)
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
-------------------------------------------------------------------------------------------------------------------
# 풀이 2. (틀림 // 고치고 맞은코드 2-(1))

## 틀린이유 ==> 배열 선언할때 너무 큰 크기의 배열을 지역변수(스택메모리)로 할당해서 오류가 남
## 관련 설명 블로그 : https://dsnight.tistory.com/50

--------------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;


queue<pair<int,int>>Q;

int main()
{
	
	int F, S, G, U, D;
	int visit[1000000];

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	
	for (int i = 1; i <= F; i++)
	{
		visit[i] = 0;
	}

	visit[S] = 1;
	Q.push({S,0});

	while (!Q.empty())
	{
		int curx = Q.front().first;
		int c = Q.front().second;
		Q.pop();
				
		if (curx == G)
		{
			printf("%d", c);
		}

		int nx = curx + U;
		if (nx <= F && visit[nx] == 0)
		{
			visit[nx] =  1;
			Q.push({nx,c+1});
		}
		int nd = curx - D;
		if (nd > 0 && visit[nd] == 0)
		{
			visit[nd] = 1;
			Q.push({ nd,c + 1 });
		}
	}

	printf("use the stairs");
	
	//system("pause");
	return 0;
}
```
--------------------------------------------------------------------------------------------------------------------
# 풀이 2-(1).  (틀린코드 수정해서 맞음)

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;
int visit[1000000];   //많이 큰 크기의 배열은 전역변수로 선언!!!!!

queue<pair<int, int>>Q;

int main()
{

	int F, S, G, U, D;
	int result = -10;

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	for (int i = 1; i <= F; i++)
	{
		visit[i] = 0;
	}

	visit[S] = 1;
	Q.push({ S,0 });


	while (!Q.empty())
	{
		int curx = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (curx == G)
		{
			result = c;
			printf("%d", result);
			break;
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

	if(result == -10)
		printf("use the stairs");

	//system("pause");
	return 0;
}
```
