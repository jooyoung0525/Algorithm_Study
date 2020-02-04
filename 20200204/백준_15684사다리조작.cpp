#include<iostream>
#include<algorithm>

using namespace std;

int N, M, H;
int ladder[35][10];
int result;
bool stop=false;

bool checkanswer();
void addcol(int col,int cnt,int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}
	
	for (int col = 0; col <= 3; col++)
	{
		addcol(col,0,1);
		if (stop)break;
	}

	if (!stop) cout << -1 << endl;
	else
		cout << result << endl;

	return 0;

}

void addcol(int col, int cnt, int x)
{
	if (stop)return;
	if (col == cnt)
	{
		if (checkanswer())
		{
			result = cnt;
		}
		return;
	}

	for (int i = x; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (col>cnt) {
				if (j - 1 <= 0 && j + 1 > N)continue;
				if (ladder[i][j] == 0 && ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0)
				{
					ladder[i][j] = 1;
					addcol(col,cnt+1,i); //넘기는 파라미터 신경쓰기!!(이거때매 몇번 틀림!)
					ladder[i][j] = 0;
				}
			}
		}
	}

}

bool checkanswer()
{
	
	for (int i = 1; i <= N; i++)
	{
		int start = i;
		for (int j = 1; j <= H; j++)
		{
			
			if (ladder[j][start] == 1)
				start += 1;
			else if (start>1 &&ladder[j][start - 1] == 1)
				start -= 1;

		}
		if (i != start) return false;
	}

	stop = true;
	return true;

}
