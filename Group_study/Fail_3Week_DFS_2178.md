```c
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int miro[100][100];
//stack <pair<int,int>> S;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int check = 0;

void DFS(int curx,int cury,int N, int M)
{
	if (miro[curx][cury] != 0)
		check++;
	else
	{
		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];
			if( nextx > 0 || nexty > 0 || nextx < N ||nexty < M )
				DFS(nextx,nexty,N,M);
		}
	}

}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &miro[i][j]);
		}
	}

	DFS(0,0,N,M);

	printf("%d", check);

	system("pause");
	return 0;
}
```
