#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int N, L;
int Map[110][110];
bool visit[110][110];

bool check(int fixidx, int changeidx, string a, int stand);
void V_check(int fixidx, int changeidx, string a);
int Check_col();
int Check_row();

int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}

	int col = Check_col();
	memset(visit, false, sizeof(visit));
	int row = Check_row();

	cout << col + row << endl;

	return 0;
}


int Check_col()
{
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int standard = Map[i][0];

		int row = 1;
		bool can = false;

		while (row < N) {

			int next = Map[i][row];

			if (standard - next == 1)
			{
				if (check(i, row, "CS", next)) 
				{
					V_check(i, row, "CS");
					can = true;
					standard = Map[i][row];
					row += L;
					continue;

				}
				else
				{
					can = false;
					break;
				}
			}

			else if (standard - next == -1)
			{
				if (check(i, row, "CR", standard)) 
				{
					V_check(i, row, "CR");
					can = true;
					standard = Map[i][row];
					row++;
					continue;
				}
				else
				{
					can = false;
					break;
				}
			}

			else if (standard == next)
			{
				can = true;
				row++;
				continue;
			}
			
			else
			{
				can = false;
				break;
			}
		}

		if (can) {
			count++;
			//cout << i << " " << count << endl;
		}
	}

	return count;

}

int Check_row()
{
	int count = 0;

	for (int j = 0; j < N; j++)
	{
		int standard = Map[0][j];
		int col = 1;

		bool can = false;

		while (col < N) {

			int next = Map[col][j];

			if (standard - next == 1)
			{
				if (check(j, col,"RS",next)) {

					V_check(j, col, "RS");
					can = true;
					standard = Map[col][j];
					col += L;
					continue;

				}
				else
				{
					can = false;
					break;
				}
			}

			else if (standard - next == -1)
			{
				if (check(j,col,"RR",standard)) 
				{
					V_check(j, col, "RR");
					can = true;
					standard = Map[col][j];
					col++;
					continue;
				}
				else
				{
					can = false;
					break;
				}
			}

			else if (standard == next)
			{
				can = true;
				col++;
				continue;
			}

			else
			{
				can = false;
				break;
			}
		}

		if (can) {
			count++;
			//cout << j << " " << count << endl;
		}
	}

	return count;


}

bool check(int fixidx, int changeidx, string a, int stand)
{
	if (a == "CS")//Col Straight
	{
		for (int i = changeidx; i < changeidx + L; i++)
		{
			if (i >= N)return false;
			if (Map[fixidx][i] != stand || visit[fixidx][i]==true) return false;
		}

		return true;
	}

	else if (a == "CR")
	{
		for (int i = changeidx - L; i < changeidx ; i++)
		{
			if (i < 0)return false;
			if (Map[fixidx][i] != stand || visit[fixidx][i] == true) return false;
		}
		return true;
	}

	else if (a == "RS")
	{
		for (int i = changeidx; i < changeidx + L; i++)
		{
			if (i >= N)return false;
			if (Map[i][fixidx] != stand || visit[i][fixidx] == true) return false;
		}

		return true;
	}

	else if (a == "RR")
	{
		for (int i = changeidx - L; i < changeidx; i++)
		{
			if (i < 0)return false;
			if (Map[i][fixidx] != stand || visit[i][fixidx] == true) return false;
		}
		return true;
	}

}

void V_check(int fixidx, int changeidx, string a)
{
	if (a == "CS")//Col Straight
	{
		for (int i = changeidx; i < changeidx + L; i++)
		{
			visit[fixidx][i] = true;
		}
	}

	else if (a == "CR")
	{
		for (int i = changeidx - L; i < changeidx; i++)
		{
			visit[fixidx][i] = true;
		}
	}

	else if (a == "RS")
	{
		for (int i = changeidx; i < changeidx + L; i++)
		{
			visit[i][fixidx] = true;
		}
	}

	else if (a == "RR")
	{
		for (int i = changeidx - L; i < changeidx; i++)
		{
			visit[i][fixidx] = true;
		}
		
	}
}
