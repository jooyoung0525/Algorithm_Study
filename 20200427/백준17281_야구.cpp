#include<iostream>
#include<string>
#include<vector>
#include<cstring>


using namespace std;

int N;
int mmax = -1;
int Score[55][10];
bool num[10];
vector<string>Allnum;
vector<int>Result;

void Play(string tasun);
void Make_num(int cnt, string n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> Score[i][j];
		}
	}

	Make_num(0,"");

	//Play("567123489");
	
	for (int i = 0; i < Allnum.size(); i++)
	{
		Play(Allnum[i]);
	}

	cout << mmax;

	return 0;
}

void Make_num(int cnt, string n)
{
	if (cnt == 8)
	{
		string Neww;

		for (int i = 0; i < 3; i++)
		{
			Neww += n[i];
		}
		Neww += '1';
		for (int i = 3; i < n.length(); i++)
		{
			Neww += n[i];
		}
		//cout << Neww << endl;
		Allnum.push_back(Neww);
		return;
	}

	for (int i = 2; i <= 9; i++)
	{
		if (num[i])continue;
		num[i] = true;
		Make_num(cnt + 1, n + to_string(i));
		num[i] = false;
	}

}

void Play(string tasun)
{
	int next = 0;//시작할인덱스
	int allscore = 0;
	//cout << tasun << endl;

	for (int i = 1; i <= N; i++) 
	{
		bool Tasuk[4] = { 0 };//idx0 1루, idx1 2루, idx2 3루
		int out = 0;

		while (1)
		{
			if (Score[i][tasun[next] - '0'] == 0)
			{
				out++;
				next++;
				if (next > tasun.length()-1) next = 0;
				if (out == 3)break;
				continue;
			}

			else if (Score[i][tasun[next] - '0'] == 1)
			{
				bool check[4] = { false };
				for (int k = 0; k < 3; k++)
				{
					
					if (Tasuk[k])
					{
						if (k + 1 >= 3)
						{
							allscore++;
							continue;
						}
						check[k + 1] = true;
					}
				}

				memcpy(Tasuk, check, sizeof(check));
				Tasuk[0] = true;
				
				next++;
				if (next > tasun.length()-1) next = 0;
				continue;
			}

			else if (Score[i][tasun[next] - '0'] == 2)
			{
				bool check[4] = { false };

				for (int k = 0; k < 3; k++)
				{
					if (Tasuk[k])
					{
						if (k + 2 >= 3)
						{
							allscore++;
							continue;
						}
						check[k + 2] = true;
					}
				}
				memcpy(Tasuk, check, sizeof(check));
				Tasuk[1] = true;

				
				next++;
				if (next > tasun.length()-1) next = 0;
				continue;
			}

			else if (Score[i][tasun[next] - '0'] == 3)
			{
				bool check[4] = { false };

				for (int k = 0; k < 3; k++)
				{
					if (Tasuk[k])
					{
						if (k + 3 >= 3)
						{
							allscore++;
							continue;
						}
						check[k + 3] = true;
					}
				}
				memcpy(Tasuk, check, sizeof(check));
				Tasuk[2] = true;

				next++;
				if (next > tasun.length()-1) next = 0;
				continue;
			}

			else if (Score[i][tasun[next] - '0'] == 4)
			{
				allscore++;
				for (int k = 0; k < 3; k++)
				{
					if (Tasuk[k])
					{
						allscore++;
						Tasuk[k] = false;
					}
				}

				next++;
				if (next > tasun.length()-1) next = 0;
				continue;
			}

		}
	}

	if (mmax < allscore)mmax = allscore;
	return;
}
