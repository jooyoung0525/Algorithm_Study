#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

bool S;
int N;
int Init[30][30];
int cpy[30][30];
int dx[] = { -1,0,1,0};
int dy[] = { 0,1,0,-1};
vector<string>P;
vector<int>Result;

void Allpath(int cnt, string p);
void Findmax();
void Move(int x, int y, int dir);
void Print();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Init[i][j];
		}
	}

	Allpath(0,"");

	for (int i = 0; i < P.size(); i++)
	{	
		//cout << P[i] << endl;
		memcpy(cpy, Init, sizeof(Init));

		for (int j = 0; j < P[i].length(); j++)
		{
			//cout << P[i][j] << endl;
			if (P[i][j] == '0')
			{
				Move(i, j, 0);
			}
			else if (P[i][j] == '1')
			{
				Move(i, j, 1);
			}
			else if (P[i][j] == '2')
			{
				Move(i, j, 2);
			}
			else if (P[i][j] == '3')
			{
				Move(i, j, 3);
			}
			//Print();
		}

		Findmax();
		
	}

	cout << *max_element(Result.begin(), Result.end());

	return 0;
}


void Allpath(int cnt, string p)
{
	if (cnt == 5)
	{
		P.push_back(p);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		Allpath(cnt + 1, p + to_string(i));
	}

}

void Findmax()
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result = max(result, cpy[i][j]);
		}
	}
	
	//if (result == 128) S = true;

	Result.push_back(result);
}

void Move(int x, int y, int dir)
{
	int cpy2[30][30] = { 0 };

	if (dir == 0)
	{
		for (int i = 0; i < N; i++) //열
		{
			queue<int>Q;
			int idx = 0;
			
			for (int j = 0; j < N; j++)//행
			{
				if (cpy[j][i] > 0) {
					Q.push(cpy[j][i]);
				}
			}
			while (!Q.empty())
			{
				if (Q.size() > 1)
				{
					int first = Q.front();
					Q.pop();
					int second = Q.front();

					if (first == second)
					{
						cpy2[idx][i] = first + second;
						Q.pop();
					}
					else cpy2[idx][i] = first;
					idx++;
				}

				else if (Q.size() == 1)
				{
					cpy2[idx][i] = Q.front();
					break;
				}
				else
					break;
			}
		}
		memcpy(cpy, cpy2, sizeof(cpy2));
		return;
	}

	else if (dir == 2)
	{
		for (int i = 0; i < N; i++) //열
		{
			queue<int>Q;
			int idx = N-1;
			
			for (int j = N-1; j >=0; j--)//행
			{
				if (cpy[j][i] > 0) {
					Q.push(cpy[j][i]);
				}
			}

			while (!Q.empty())
			{
				if (Q.size() > 1)
				{
					int first = Q.front();
					Q.pop();
					int second = Q.front();

					if (first == second)
					{
						cpy2[idx][i] = first + second;
						Q.pop();
					}
					else cpy2[idx][i] = first;
					idx--;
				}

				else if (Q.size() == 1)
				{
					cpy2[idx][i] = Q.front();
					break;
				}
				else
					break;
			}
		}
		memcpy(cpy, cpy2, sizeof(cpy2));
		return;
	}

	else if (dir == 3)
	{
		for (int i = 0; i < N; i++) //행
		{
			queue<int>Q;
			bool stop = false;
			int idx = 0;

			for (int j = 0; j < N; j++)//열
			{
				if (cpy[i][j] > 0) {
					Q.push(cpy[i][j]);
				}
			}
			
			while (!Q.empty())
			{
				if (Q.size() > 1)
				{
					int first = Q.front();
					Q.pop();
					int second = Q.front();

					if (first == second)
					{
						cpy2[i][idx] = first + second;
						Q.pop();
					}
					else cpy2[i][idx] = first;
					idx++;
				}

				else if (Q.size() == 1)
				{
					cpy2[i][idx] = Q.front();
					break;
				}
				else
					break;
			}
		}
		memcpy(cpy, cpy2, sizeof(cpy2));
		return;
	}
	else if (dir == 1)
	{
		for (int i = 0; i < N; i++) //행
		{
			queue<int>Q;
			int idx =N-1;

			for (int j = N - 1; j >= 0; j--)//열
			{
				if (cpy[i][j] > 0) {
					Q.push(cpy[i][j]);
				}
			}
			
			while (!Q.empty())
			{
				if (Q.size() > 1)
				{
					int first = Q.front();
					Q.pop();
					int second = Q.front();

					if (first == second)
					{
						cpy2[i][idx] = first + second;
						Q.pop();
					}
					else cpy2[i][idx] = first;
					idx--;
				}

				else if (Q.size() == 1)
				{
					cpy2[i][idx] = Q.front();
					break;
				}
				else
					break;
			}
		}
		memcpy(cpy, cpy2, sizeof(cpy2));
		return;
	}
}

void Print()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << cpy[i][j] << " ";
		}
		cout << endl;
	}



}
