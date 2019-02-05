
# C/C++ 입력 꿀팁

### 1. cin이 편할 떄

   ***※ 주의) cin 은 using namespace std; 써 줘야함***

- 1 0 1 0 1 1 이렇게 숫자 사이에 공백있을때! --> 알아서 공백 인식해서 입력받음

- Cin 으로 입력받으면 입력받은 변수타입으로 알아서 맞춰 

    ***ex) scanf(" %d",&a); scanf처럼 공백을 입력해서 안받아도됨***

- cin으로 101011통으로 입력받으면 하나의 변수에 101011이 통으로 들어가기 때문에 루프돌면서 한개씩 잘라줘야함.



### 2. scanf가 편할 때

- 101011를 한개씩 입력 받아야 할 떄!     -->     ***scanf("%1d",&a);***

------------------------------------------------------------------------------------------------------------------

# system("pause"); 안써도 되는법!

1. 메뉴의 프로젝트 -> '프로젝트이름'속성

2. 구성속성 -> 링커 -> 시스템 -> 하위시스템 -> 콘솔선택

------------------------------------------------------------------------------------------------------------------

# 두번째 시도 - 예외처리 빼고 성공! 

**(토마토가 모두 익지 못하면 -1, 모두 익어있는 상태면 0 출력)**

```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include <iostream>
#include<algorithm>

using namespace std;

int tomato[1100][1100] = { 0 , };
int visited[1100][1100] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };



queue<pair<int,int>> Q;

void BFS (int curx, int cury, int M, int N )
{
	
	//Q.push(make_pair(curx, cury));
	//visited[curx][cury] = 1;

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx <= -1 || nx > M || ny <= -1 || ny > N) continue;

			if (visited[nx][ny] == 0 && tomato[nx][ny] == 0)
			{
					Q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;
					visited[nx][ny] = visited[X][Y] + 1;

			}

			
		}


	}

	
}

int main()
{
	int M, N;
	int MAX[1000];
	//scanf("%d %d", &M, &N);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//scanf("%d ", &tomato[i][j]);
			cin >> tomato[i][j];
		}
	}

	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 1)
			{
				Q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			
		}
	}

	BFS(0, 0, M, N);
	
	
	
	for (int i = 0; i < M; i++) {
		
		MAX[i] = *max_element(visited[i], visited[i]+N);
		
	}

	int MAX2 = *max_element(MAX, MAX + N);

	printf("%d\n", MAX2-1);
	
	

	//system("pause");
	return 0;
}
```

----------- ----------------------------------------------------------------------------------------------------
**테스트 케이스**

https://www.acmicpc.net/board/view/13878
-------------------------------------------------------------------------------------------------------------------
# ㅋㅋㅋㅋㅋㅋㅋ어이없게 세시간날렸다~~~~

```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include <iostream>
#include<algorithm>

# define MAX1 5000
using namespace std;

int tomato[MAX1][MAX1] = { 0 , };
int visited[MAX1][MAX1] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;


queue<pair<int, int>> Q;

int check_ans(int M, int N)          
{
	int check=0;                       //초기에 토마토가 모두 익어있는지 판별하기 위해 만든 변수
	int MAX[MAX1];
	
	for (int i = 0; i < M; i++) {
		MAX[i] = *max_element(visited[i], visited[i] + N);   //각 행의 최대값구하기 --> MAX배열에 저장
	}
	int MAX2 = *max_element(MAX, MAX + M);                       //행의 최댓값 중 최댓값 구하기
	                                                            //여기서 어이없게 틀림!! ※ N이아니라M

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)      //BFS를 돌렸지만 방문하지 않은 곳이 나오면 익지않은 토마토가 있다는 소리!
				return -1;           //토마토가 모두 익지 못하는 상황이기때문에 -1리턴.
				                     //여기서 리턴을 써야 함수를끝내고 바로 -1값을 리턴할 수 있음.
						     
			else if (tomato[i][j] == 0)  //안익은 토마토가 있다면
				check++;             //check변수++
		}
	}

	if (check <= 0)           //초기에 안익은토마토가 없다면 check가 0일테니까 
		return 0;         //모든토마토가 익어있는 상황이니까 0값을 리턴
	else
		return MAX2 - 1;  //그렇지 않으면 최댓값-1을 리턴!(BFS에서 익은토마토때문에 1부터 체크되기때문에 -1해줘야함)
}

void BFS(int M, int N)
{

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];
			
			if (nx <= -1 || nx >= M || ny <= -1 || ny >= N) continue; //범위에 벗어나면(※여기도 주의!)
			                                                         
			if (visited[nx][ny] == 0)                 //방문을 하지 않았고
			{
				if (tomato[nx][ny] == 0) {        //토마토가 익어있지 않으면
					Q.push(make_pair(nx, ny));  //큐에 좌표넣고
					visited[nx][ny] = 1;        //방문처리
					visited[nx][ny] = visited[X][Y] + 1;   
				}	
			}
		}
	}
}

int main()
{
	int M, N;
	
	//scanf("%d %d", &M, &N);
	cin >> N >> M; //행 열 순

	for (int i = 0; i < M; i++) { //행
		for (int j = 0; j < N; j++) { //열
			//scanf(" %d", &tomato[i][j]);    //한개씩 끊어서 입력은 scanf가 편하고,
			cin >> tomato[i][j];              //공백과 같이 입력받는건 cin이 편함!
		}
	}


	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 1 && visited[i][j] == 0)   //토마토가 익어있고, 방문을 안했을 때
			{
				Q.push(make_pair(i, j));               //익은토마토 좌표를 큐에 넣는다.
				visited[i][j] = 1;                     //익은토마토 좌표 방문처리
			}
			else if (tomato[i][j] == -1 && visited[i][j] == 0)  // 토마토가 없고, 방문을 안했을 때
				visited[i][j] = -1;                         // 토마토가 없는 좌표 -1처리!
				                                     //(예외처리를 쉽게 하기 위해서 1이나0보다 다른수가 편함)
				
		}
	}

	BFS(M, N);   //BFS돌리기


	printf("%d",check_ans(M, N));  //BFS돌리고 check_ans에서 예외처리를 함.
	
	
	return 0;
}
```
-----------------------------------------------------------------------------------------------------------------

# 다른사람이 짠코드 나랑제일비슷한거!! 뭐가다르냐???,,,,똑같은거같은데


```c
//BJ7576 토마토

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int Max();

int box[1001][1001] = {0, };
int check[1001][1001] = {0, };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;

int main(){
    
    queue<pair<int, int>> q;
    scanf("%d %d", &M, &N);
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            scanf("%d", &box[i][j]);
        }
    }//입력 끝
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(box[i][j] == 1&&check[i][j]==0){
                
                q.push(make_pair(i,j));
                check[i][j] = 1;
            }
        }
    }
    int x, y;
    while(!q.empty()){//BFS탐색 시작
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(box[nx][ny]==0 & check[nx][ny]==0){ //토마토가 익지 않았으면 익힌다
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx,ny));
                    box[nx][ny] = 1;
                }
                
                else if(box[nx][ny] == -1 && check[nx][ny]==0){
                    check[nx][ny] = -1;
                }
            }
        }
        
    }//BFS 탐색 끝
    printf("%d", Max());
}

int Max(){
    int maxnum = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(box[i][j] == 0)
                return -1;
            else if(check[i][j]>maxnum)
                maxnum = check[i][j];
        }
    }
    
    return maxnum-1;//처음시작 0인데 check값 1이라고 해둠
}
```
