// 문제를 잘읽자!  (k범위 100까지)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int num, cnt; 
bool operator<(const info& a)const
{
	if (cnt == a.cnt)
	{
		return num < a.num;
	}
	return cnt < a.cnt;
}
};
int r, c, k, time;
int Map[1010][1010];
int Cpy_Map[1010][1010];
int Num[150];
int colsize=3, rowsize=3;

char Find_RC();
void Roper();
void Coper();

int main()
{
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	
	while (1)
	{
		if (Map[r-1][c-1] == k)break;
		if (time > 100) break;

		char oper = Find_RC();
	//	cout << "col : " << colsize << " row : " << rowsize << " oper : " << oper << endl;
		if (oper == 'R')
		{
			Roper();
		}
		else if (oper == 'C')
		{
			Coper();
		}
		time++;
		
	}
	
	if (time > 100) cout << -1 << endl;
	else cout << time << endl;
	
	return 0;
}


char Find_RC() // 행, 열 최댓값구하고 R연산,C연산 구분 
{
	if (colsize >= rowsize)return 'R';
	else return 'C';
}



void Roper()
{

	memset(Cpy_Map, 0, sizeof(Cpy_Map));

	int rowmax = 0;

	for (int i = 0; i < colsize; i++)
	{
		memset(Num, 0, sizeof(Num));
		vector<info>Cpy;

		for (int j = 0; j < rowsize; j++)
		{
			if(Map[i][j]>0)
				Num[Map[i][j]]++;
		}

		for (int j = 1; j < 101; j++)
		{
			if (Num[j] > 0)
				Cpy.push_back({ j,Num[j] });
		}

		sort(Cpy.begin(), Cpy.end());

		int rowcnt = Cpy.size() * 2;

		for (int j = 0; j < Cpy.size(); j++)
		{
			Cpy_Map[i][j * 2] = Cpy[j].num;
			Cpy_Map[i][(j * 2) + 1] = Cpy[j].cnt;
		}

		/*
		if (rowcnt > 100) {
			for (int j = 0; j < 50; j++)
			{
				Cpy_Map[i][j * 2] = Cpy[j].num;
				Cpy_Map[i][(j * 2) + 1] = Cpy[j].cnt;
			}
		}

		else
		{
			for (int j = 0; j < Cpy.size(); j++)
			{
				Cpy_Map[i][j * 2] = Cpy[j].num;
				Cpy_Map[i][(j * 2) + 1] = Cpy[j].cnt;
			}
		}*/

		rowmax = max(rowmax, rowcnt);
	}

	rowsize = rowmax;
	memcpy(&Map, &Cpy_Map, sizeof(Cpy_Map));

}


void Coper()
{

	memset(Cpy_Map, 0, sizeof(Cpy_Map));

	int colmax = 0;

	for (int i = 0; i < rowsize; i++)
	{
		memset(Num, 0, sizeof(Num));
		vector<info>Cpy;


		for (int j = 0; j < colsize; j++)
		{
			if (Map[j][i] > 0)
				Num[Map[j][i]]++;
		}

		for (int j = 1; j < 101; j++)
		{
			if (Num[j] > 0)
				Cpy.push_back({ j,Num[j] });
		}

		sort(Cpy.begin(), Cpy.end());

		int colcnt = Cpy.size() * 2;

		for (int j = 0; j < Cpy.size(); j++)
		{
			Cpy_Map[j * 2][i] = Cpy[j].num;
			Cpy_Map[(j * 2) + 1][i] = Cpy[j].cnt;
		}

		/*
		if (colcnt > 100) {
			for (int j = 0; j < 50; j++)
			{
				Cpy_Map[j * 2][i] = Cpy[j].num;
				Cpy_Map[(j * 2) + 1][i] = Cpy[j].cnt;
			}
		}
		else
		{
			for (int j = 0; j < Cpy.size(); j++)
			{
				Cpy_Map[j * 2][i] = Cpy[j].num;
				Cpy_Map[(j * 2) + 1][i] = Cpy[j].cnt;
			}
		}*/

		colmax = max(colmax, colcnt);
	}
	colsize = colmax;

	memcpy(&Map, &Cpy_Map, sizeof(Cpy_Map));
}
