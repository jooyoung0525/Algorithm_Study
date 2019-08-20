-----------------------------------------------------------------------------------------------------------------------------
# VECTOR 이용법

### < iterator 사용 안 할 경우 >

- front()  ==> 첫번째 원소 참조
- back() ==> 마지막원소 참조
- empty() ==> 원소의 존재 유무 체크
- size() ==> 원소의 개수 리턴
- max_size() ==> 담을 수 있는 원소의 최대 개수 리턴
- resize() ==> vetor의 크기 변경하고 초기화
- capacity() ==> vector에 할당 된 메모리의 크기 리턴
- clear() ==> vector에 모든 원소 제거
- insert() ==>임의 위치에 임의 값 삽입
- erase() ==> 임의 위치의 원소나 지정 범위의 원소 삭제
- push_back() ==> vector 끝에 원소를 추가
- pop_back() ==> vector 끝에 원소를 제거

-----------------------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>

using namespace std;

int visit[100010] = {0};
int path[100010] = {0};
int N, K;

queue<int>Q;
vector<int>P;

void BFS()
{
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		if (x == K)  // 언니가 동생을 찾았을 경우,
		{
			printf("%d\n", visit[K] - 1);

			P.push_back(x); // 먼저 동생의 위치 vector에 넣기
			int cur = path[x]; //동생의 위치부터 이전에 저장한 이전경로
			P.push_back(cur); //vector에 넣기

			while (cur != -1) // 언니의 초기위치는 -1로설정
			{
				cur = path[cur]; //계속 이전의 경로 찾아서 vector에넣어줌
				P.push_back(cur);	
			}
			
			while (!P.empty()) //vector가 비지않았으면 아래 반복
			{
				int v = P.back(); //마지막원소
				if(v != -1) //마지막원소가 -1이 아니면 출력
					printf("%d ", v);
				P.pop_back(); //vector에서 원소 빼주기
			}

		}

		int nx = x - 1;
		if (nx > -1 && visit[nx] == 0)
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;
			path[nx] = x;
		}

		nx = x + 1;
		if (nx < 100010 && visit[nx] == 0)
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;
			path[nx] = x;
		}

		nx = x*2;
		if (nx < 100010 && visit[nx] == 0)
		{
			Q.push(nx);
			visit[nx] = visit[x] + 1;
			path[nx] = x;
		}
	}
}

int main()
{

	scanf("%d %d", &N, &K);

	visit[N] = 1;
	path[N] = -1;
	Q.push(N);
	BFS();

	system("pause");
	return 0;
}
```
