![숨2](https://user-images.githubusercontent.com/29946480/62212470-15e5d080-b3a1-11e9-9d00-e5612a64240f.PNG)
--------------------------------------------------------------------------------------------------------------------
### 내 생각으로 BFS두번돌려서 푼 코드(쓸데없이 길다..// 짧게 바꿔보기!)

- 단점: BFS(visit배열 100010번까지)두번돌려 느림!
-------------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

queue<pair<int, int>>Q;
queue<pair<int, int>>Q2;

int N, k;
int visit[100010] = { 0 };
int visit2[100010] = { 0 };

int BFS() //수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지
{
	while (!Q.empty())
	{
		int x = Q.front().first; // 현재 위치
		int s = Q.front().second; // 걸린 시간

		visit[x] = 1;
		Q.pop();

		if (x == k) //만약 현재위치가 동생의 위치가 같다면
			return s; //걸린시간 리턴!

		int nx = x + 1;
		if (nx <= 100000 && visit[nx] == 0)
			Q.push({ nx,s + 1 });

		nx = x - 1;
		if (nx >= 0 && visit[nx] == 0)
			Q.push({ nx, s + 1 });

		nx = 2 * x;
		if (nx <= 100000 && visit[nx] == 0)
			Q.push({ nx, s + 1 });
		
	}
}


void BFS2(int min)     //가장 빠른 시간으로 찾는 방법이 몇 가지 인지
{
	int cnt = 0;
	while (!Q2.empty())
	{
		int x = Q2.front().first; //현재위치
		int s = Q2.front().second; //걸린시간

		visit2[x] = 1;
		Q2.pop();

		if (x == k && s == min) //현재의 위치가 k(동생의 위치)와 같고, 현재 걸린시간이 가장빠른시간일 때 카운트
			cnt++;
			

		int nx = x + 1;
		if (nx <= 100000 && visit2[nx] == 0)
			Q2.push({ nx,s + 1 });

		nx = x - 1;
		if (nx >= 0 && visit2[nx] == 0)
			Q2.push({ nx, s + 1 });

		nx = 2 * x;
		if (nx <= 100000 && visit2[nx] == 0)
			Q2.push({ nx, s + 1 });
  }
	printf("%d", cnt); //queue가 비었을 때, 가장 빠른시간으로 찾는방법의 수를 출력
}


int main()
{
	
	scanf("%d %d", &N, &k);
	
	Q.push({ N, 0 });
	Q2.push({ N, 0 }); //BFS두번돌리기 때문에 초기 값 각각의 queue에 두번 넣기
	
  int min = BFS(); //언니가 동생찾는데 걸린 최단시간(첫 BFS돌렸을 때의 값) 저장 
                   // ==> 두번째 BFS돌릴때 (몇번 최단시간동안 찾았는지)최단시간 비교하기 위해
	printf("%d\n",min);

	BFS2(min); //몇 번 최단시간동안 동생을 찾았는지

	//system("pause");
	return 0;
  
}
```
