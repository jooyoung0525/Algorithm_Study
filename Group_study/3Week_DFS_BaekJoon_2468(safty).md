
![safty](https://user-images.githubusercontent.com/29946480/52328275-512ac680-2a32-11e9-95b7-cc5fc8d379fe.JPG)

--------------------------------------------------------------------------------------------------------------------

# 헤헤헤 한시간 반만에 풀었다!!! 기분짱좋~~~~

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define N_MAX 100

int rain[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
int ans[N_MAX];  
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;

void DFS(int curx, int cury, int i, int N)
{
	visited[curx][cury] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx <= -1 || nx >= N || ny <= -1 || ny >= N) continue;   //범위를 벗어나면 continue
		
		if (visited[nx][ny] == 0 && rain[nx][ny] >= 0) {   //방문하지 않았고, 물에 잠기지 않은구역에서
			DFS(nx, ny, i, N);                         //DFS돌려줌
		}
	}
}


int main()
{
	int N;
	int rain_MAX[N_MAX];  //맵의 최댓값 구하기위한 배열
	

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> rain[i][j];
		}
	}


	for (int i = 0; i < N; i++)
		rain_MAX[i] = *max_element(rain[i], rain[i] + N); //각 행의 최댓값구해서 배열에저장

	int rain_MAX2 = *max_element(rain_MAX, rain_MAX + N); //최댓값만 저장된 배열에서 최댓값 구해서 변수에 저장

	//printf("%d\n", rain_MAX2);

	

	for (int i = 0; i < rain_MAX2; i++)  //0부터 배열의 최댓값까지 반복 (0부터 시작하는이유 ==>비가 안올경우)
	{
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (rain[j][k] == i)   //만약 비가 2내렸다면 맵의값이 2일경우
				{
					rain[j][k] = -1;  //맵의 값를 -1로지정 (DFS하기위한 조건설정하기위해) 
					                  // --> 맵이 물에 잠겼다는걸 -1로표현
				}
				visited[j][k] = 0; //0~최댓값만큼 반복하기때문에 visited를 초기화해줘야함
				                  //여기서 rain[][]은 초기화하지않아도됨 어차피 강수량 이하는 다 잠겨있으니까!
			}
			
		}
		cnt = 0;                     //초기화
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				
				if (visited[j][k] == 0 && rain[j][k] >= 0) { //방문하지 않았고, 맵이 물에 잠기지 않았을때
					DFS(j, k, i, N);   //해당위치보터 DFS를 돌려준다.
					cnt++;              //카운트를해서 구역의 수를 세준다.
					ans[i] = cnt;       //센 구역의 값을 정답배열에 저장한다.(최댓값 찾기위해)
				}
			}
		}
	}


	
	/*
	for (int i = rain_MIN2; i < rain_MAX2; i++)
	{
		printf("%d %d\n",i, ans[i]);
	}*/

	int ans_MAX = *max_element(ans, ans + rain_MAX2);  //정답의 최댓값을 찾아서 변수에 저장

	printf("%d\n", ans_MAX);   //정답출력

	//system("pause");
	return 0;
}
```
------------------------------------------------------------------------------------------------------------

# 3개월뒤에 다시풀었다!! 문제 잘읽고풀자 ...

```c
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int region[200][200];
int visit[200][200][200] = { 0 }; //visit초기화 대신 3차원배열로 만들어서 풀음.
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int safe_region;
int save_result[1000];

int find_max(int N) //region영역의 최댓값 찾기
{
	int col_max[1000];
	int max;

	for (int i = 0; i < N; i++)
	{
		col_max[i] = *max_element(region[i], region[i] + N);
	}

	max = *max_element(col_max, col_max + N);

	return max;
}

void DFS(int curx, int cury, int N, int k)
{
	int i;
	visit[k][curx][cury] = 1;

	for (i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx < 0 || ny < 0 || nx > N || ny > N)continue;
		if (region[nx][ny] > 0 && visit[k][nx][ny] == 0)
			DFS(nx, ny, N,k);
	}
}

int main() {

	int N, i, j, k;
	int max, result_max;
	

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &region[i][j]);
		}
	}

	max = find_max(N);


	for (k = 0; k < max; k++) //0부터 최댓값까지 높이 1씩 증가하며 같은 연산 반복
	{
		
		safe_region = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (region[i][j] == k)
					region[i][j] = -1; //해당 높이일때 -1값으로 변환
			}
		}

		for (i = 0; i < N; i++)   // 주의!! 위의 for문과 따로 돌려줘야함. 위의 for문에서 해당높이의 값을 -1로 
					  // 변환해준 다음 DFS를 돌려줘야 된다!! (-1의값으로 변환과 동시에 DFS돌리면 정확한 답이 나올 수 없다)
		{
			for (j = 0; j < N; j++)
			{
				if (region[i][j] > 0 && visit[k][i][j] == 0) {

					DFS(i, j, N,k);
					safe_region++;
				}
			}
		}

		save_result[k] = safe_region;
	
	}

	result_max = *max_element(save_result, save_result + max);

	printf("%d", result_max);

	system("pause");
	return 0;
}
```
