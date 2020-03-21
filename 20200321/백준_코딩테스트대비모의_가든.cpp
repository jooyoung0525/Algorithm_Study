#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

struct dist { int x, y; };
struct info { char color; int time; };
struct all { dist d; info i; };

int N, M, G, R;
int hap;
int result = -10e9;
int map[55][55];
info visit[55][55];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool check[300];
bool check2[300];

vector<dist>Yello;
queue<all>Q;

void Select(int cnt, int idx);
void Green(vector<int>can,int cnt, int idx);
void Spread();


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;
	hap = G + R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				Yello.push_back({ i,j });
		}
	}

  //조합으로 G+R개수 선택하고
	Select(0,0);


	cout << result << endl;

	return 0;
}

void Select(int cnt, int idx)
{
	if (cnt == hap)
	{
  
		vector<int>can; //지역으로 선언해서 Green함수 매개로 넘겨줌 ( 초기화안해도됨)

		
		for (int i = 0; i < Yello.size(); i++)
		{
			if (check[i]) {
				can.push_back(i);
			}
		}
		
		Green(can,0, 0); //선택한 인덱스들 중에서 녹색고르는 조합

		return;
	}

	for (int i = idx; i < Yello.size(); i++)
	{
		if (check[i]==true)continue;
		check[i] = true;
		Select(cnt + 1, i + 1);
		check[i] = false;
	}
}

void Green(vector<int>can,int cnt, int idx) //녹색조합고르는 함수
{
	if (cnt == G)
	{
    //큐 초기화
		while (!Q.empty())
		{
			Q.pop();
		}
    
    //visit배열 초기화
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visit[i][j] = { '\0',0 };
			}
		}

	
		for(int i = 0; i<can.size(); i++)
		{
			if (check2[i]) { //초록색 조합
				int idxg = can[i];
				Q.push({ Yello[idxg].x,Yello[idxg].y,'G',0 }); //큐에넣고
				visit[Yello[idxg].x][Yello[idxg].y] = {'G',0 }; //방문체크
			}
			else //빨간색 조합
			{
				int idxr = can[i]; 
				Q.push({ Yello[idxr].x,Yello[idxr].y,'R',0 }); //큐에넣고
				visit[Yello[idxr].x][Yello[idxr].y] = { 'R',0 }; //방문체크
			}
		}
    
		Spread(); //초록과 빨강퍼트리기

		return;
	}

	for (int i = idx; i < can.size(); i++)
	{
		if (check2[i])continue;
		check2[i] = true;
		Green(can,cnt + 1, i + 1);
		check2[i] = false;
	}

}

void Spread()
{
	int flower = 0;

	while (!Q.empty())
	{
		int cx = Q.front().d.x;
		int cy = Q.front().d.y;
		char col = Q.front().i.color;
		int ct = Q.front().i.time;
		Q.pop();
    
		if (visit[cx][cy].color == 'F') continue; //만약 현재위치가 꽃이면 넘겨야한다( 꽃은 더이상 퍼지지 않음 )

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nt = ct + 1;

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;

			if (map[nx][ny] > 0) { //다음위치가 호수가아니면 (퍼질수있음)

				if (visit[nx][ny].color == '\0' && visit[nx][ny].time == 0) //다음위치에 아무것도 없었으면
				{
					Q.push({ nx,ny,col,nt }); //퍼트린다
					visit[nx][ny].color = col;
					visit[nx][ny].time = nt;
				}

				else if (visit[nx][ny].color != '\0' && visit[nx][ny].time == nt) //다음위치에 이미 퍼진 배양액이있고, 퍼진배양액의시간이 현재퍼질시간과 같을경우 
				{
					if (col == 'G' && visit[nx][ny].color == 'R') //만약 서로 다른배양액이 같은자리에 만나면
						visit[nx][ny].color = 'F'; //꽃이핀다
					else if (col == 'R' && visit[nx][ny].color == 'G')
						visit[nx][ny].color = 'F';
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j].color == 'F') flower++; //꽃이피면 꽃의갯수++
		}
	}


	result = max(flower, result); //꽃의 최대개수 구하기
}
