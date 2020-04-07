/*
  사각형 안을 채우는거에서 시간을 너무 많이 끌었다!!!
  간단하게 생각해서 경계선을 구하고 탐색하면서 while문으로 사각형안을 색칠해주면 쉽게풀렸다
  그래도 마를모꼴 구하는거 다른사람코드보고 공부하자!
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int Map[25][25];
int Seperate[25][25];

int N;
int Region_num[5];
int MMin = 10e9;

void Seperate_region();
void make_d(int x, int y);
void make_line(int x, int y, int d1, int d2);

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
	
	Seperate_region();

	cout << MMin << endl;

	return 0;
}

void Seperate_region()
{
	for (int i = 1; i <N-1; i++)
	{
		for (int j = 2; j <N; j++)
		{
			make_d(i, j);
		}
	}
}


void make_d(int x, int y)
{
	int value = N - x;
	for (int i = 1; i < y; i++)
	{
		for (int j = 1; j <= N - y; j++)
		{
			if (value < i + j)continue;
			make_line(x, y, i, j);
		}
	}
}

void make_line(int x, int y, int d1, int d2)
{
	memset(Seperate, 0, sizeof(Seperate));
	memset(Region_num, 0, sizeof(Region_num));

	for (int i = 0; i <= d1; i++)
	{
		Seperate[x + i][y - i] = 5;
		Seperate[x + d2 + i][y + d2 - i] = 5;
	}


	for (int i = 0; i <= d2; i++)
	{
		Seperate[x + i][y + i] = 5;
		Seperate[x + d1 + i][y - d1 + i] = 5;
	}

	bool start = false; bool end = false;
	int cnt = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Seperate[i][j] == 5 && start == false)
			{
				cnt++;
				start = true;
				break;
			}
			else if (Seperate[i][j] == 5 && start == true && cnt < d1 + d2 + 1)
			{
				cnt++;
				int ny = j + 1;
				while (Seperate[i][ny] == 0)
				{
					Seperate[i][ny] = 5;
					ny++;
				}
				break;
			}
			else if (Seperate[i][j] == 5 && start == true && end == false && d1+d2+1 == cnt)
			{
				end = true;
				break;
			}
		}
		if (end)break;
	}

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (Seperate[r][c] == 5)
			{
				Region_num[4] += Map[r][c];
				continue;
			}
			if (1 <= r && r < x + d1 && 1 <= c && c <= y)
			{
				Seperate[r][c] = 1;
				Region_num[0] += Map[r][c];
				continue;
			}
			else if (1 <= r && r <= x + d2 && y < c && c <= N)
			{
				Seperate[r][c] = 2;
				Region_num[1] += Map[r][c];
				continue;
			}
			else if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2)
			{
				Seperate[r][c] = 3;
				Region_num[2] += Map[r][c];
				continue;
			}
			else if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N)
			{
				Region_num[3] += Map[r][c];
				Seperate[r][c] = 4;
			}
		}
	}

	
	int max_num = *max_element(Region_num, Region_num + 5);
	int min_num = *min_element(Region_num, Region_num + 5);
	
	int result = max_num - min_num;

	if (result < MMin)
		MMin = result;
}
