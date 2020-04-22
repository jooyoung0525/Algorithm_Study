#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;

struct info { int d1, d2; };
int N;
int Cnt[6];
int Sep[110][110];
int Map[110][110];
vector<info>D;
set<int>Result;

void FindD(int cnt,string D);
void Make_region(int d1,int d2, int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}

	FindD(0,"");

	set<int>::iterator iter;
	for (iter = Result.begin(); iter != Result.end(); iter++)
	{
		cout << *iter;
		break;
	}

	return 0;
}

void FindD(int cnt,string D)
{
	if (cnt == 2)
	{
		int d1 = D[0] - '0';
		int d2 = D[1] - '0';

		for (int i = 1; i <= N - 2; i++) 
		{
			for (int j = 2; j <= N - 1; j++)
			{
				if (1 > i + d1 + d2 || i + d1 + d2 > N || 1 > j - d1 || j + d2 > N)continue;
				Make_region(d1,d2,i,j);
			}
		}
		return;
	}

	for (int i = 1; i <= N - 2; i++)
	{
		FindD(cnt + 1, D + to_string(i));
	}

}

void Make_region(int d1, int d2, int x, int y)
{ 
	memset(Cnt, 0, sizeof(Cnt));
	memset(Sep, 0, sizeof(Sep));

	for (int i = 1; i < x + d1; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			Sep[i][j] = 1;
		}
	}
	for (int i = 1; i <= x + d2; i++)
	{
		for (int j = y + 1; j <= N; j++)
		{
			Sep[i][j] = 2;
		}
	}
	for (int i = x + d1; i <= N; i++)
	{
		for (int j = 1; j < y - d1 + d2; j++)
		{
			Sep[i][j] = 3;
		}
	}
	for (int i = x + d2 + 1; i <= N; i++)
	{
		for (int j = y - d1 + d2; j <= N; j++)
		{
			Sep[i][j] = 4;
		}
	}

	//5번경계
	for (int i = 0; i <= d1; i++)
	{
		Sep[x + i][y - i] = 5;
		Sep[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++)
	{
		Sep[x + i][y + i] = 5;
		Sep[x + d1 + i][y - d1 + i] = 5;
	}

	bool start = false; 
	int C = d1 + d2 + 1;

	for (int a = 1; a <= N; a++)
	{
		int count = 2;
		
		for (int b = 1; b <= N; b++)
		{
			if (Sep[a][b] == 5 && !start)
			{
				C--;
				start = true;
				break;
			}
			else if (start && Sep[a][b] == 5 && count == 2)
			{
				C--;
				count--;
			}
			else if (start && Sep[a][b] == 5 && count == 1)
			{
				count--;
				break;
			}
			else if (start && Sep[a][b] < 5 && count == 1)
			{
				Sep[a][b] = 5;
			}
			if (C == 0)break;
		}
		if (C == 0)break;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Sep[i][j] == 1)
			{
				Cnt[1] += Map[i][j];
			}
			else if (Sep[i][j] == 2)
			{
				Cnt[2] += Map[i][j];
			}
			else if (Sep[i][j] == 3)
			{
				Cnt[3] += Map[i][j];
			}
			else if (Sep[i][j] == 4)
			{
				Cnt[4] += Map[i][j];
			}
			else if (Sep[i][j] == 5)
			{
				Cnt[5] += Map[i][j];
			}
		}
	}

	int mmax = *max_element(Cnt+1, Cnt + 6);
	int mmin = *min_element(Cnt+1, Cnt + 6);

	Result.insert(mmax - mmin);

}
