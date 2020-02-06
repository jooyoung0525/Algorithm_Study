//인접한 수 지울때 배열복사해서 해야 모든 인접 수에 접근가능
//평균보다 큰수 -1, 평균보다 작은수 1 
//평균은 double로 (소수점까지 비교해야함)


#include<iostream>
#include<queue>

using namespace std;

struct info { int x, y, num; };
int Circle[55][55];
bool check[55][55];
int N, M, T;

void Rotate(int x, int d, int k);
void Findnum();

int main()
{
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Circle[i][j];
		}
	}

	for (int t = 0; t < T; t++)
	{
		int x, d, k = 0;
		cin >> x >> d >> k;
		
		//memset(check, false, sizeof(check));
		for (int i = 1; i <= 50; i++)
		{
			int pannum = x * i;
			if (pannum > N) break;
			//cout << pannum << " " << d << " " << k << endl;
			Rotate(pannum, d, k);
		}
		Findnum();
		/*
		cout << endl;
		cout << "finishfindnum" << endl;
		cout << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << Circle[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	int R = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			//cout << Circle[i][j] << " ";
			R += Circle[i][j];
		}
		//cout << endl;
	}
	//cout << endl;
	cout << R;

	return 0;
}

void Rotate(int x, int d, int k)
{
	
	if (d == 0)
	{
		for (int i = 0; i < k; i++)
		{
			queue<int>temp;
			for (int j = 1; j <= M; j++)
			{
				//cout << endl;
				//cout << "큐" << endl;
				//cout << Circle[x][j] << " ";
				temp.push(Circle[x][j]);
			}

			for (int j = 2; j <= M; j++)
			{
				Circle[x][j] = temp.front();
				temp.pop();
			}

			Circle[x][1] = temp.front();
			temp.pop();
		}
		/*
		cout << endl;
		cout << "rot0" << endl;
		cout << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << Circle[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	else if (d == 1)
	{
		for (int i = 0; i < k; i++)
		{
			queue<int>temp;
			for (int j = 1; j <= M; j++)
				temp.push(Circle[x][j]);


			Circle[x][M] = temp.front();
			temp.pop();

			for (int j = 1; j < M; j++)
			{
				Circle[x][j] = temp.front();
				temp.pop();
			}
		}
		/*
		cout << endl;
		cout << "rot0" << endl;
		cout << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << Circle[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
}

void Findnum()
{
	bool same = false;
	double hap = 0;
	double cnt = 0;
	queue<info>Q;
	int cpy[55][55] = { 0 };

	memcpy(&cpy, &Circle, sizeof(Circle));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			
			//same == false를위해서 미리계산
			if (Circle[i][j] > 0) {
				hap += Circle[i][j];
				Q.push({ i,j,Circle[i][j] });
				cnt++;


				//같은게있는지 확인
				int standard = Circle[i][j];
				//check[i][j] = true;

				if (j + 1 > M)
				{
					if (standard == Circle[i][1])
					{
						same = true;

						cpy[i][j] = 0;
						cpy[i][1] = 0;

					}
				}
				else if (j + 1 <= M && standard == Circle[i][j + 1])
				{
					same = true;

					cpy[i][j] = 0;
					cpy[i][j + 1] = 0;

				}

				if (j - 1 < 0)
				{
					if (standard == Circle[i][M])
					{
						same = true;
						//check[i][M] = true;
						cpy[i][j] = 0;
						cpy[i][M] = 0;

					}
				}
				else if (j - 1 > 0 && standard == Circle[i][j - 1])
				{
					same = true;

					cpy[i][j] = 0;
					cpy[i][j - 1] = 0;

				}


				if (i + 1 <= N && standard == Circle[i + 1][j])
				{
					same = true;

					cpy[i][j] = 0;
					cpy[i + 1][j] = 0;

				}

				if (i - 1 > 0 && standard == Circle[i - 1][j])
				{
					same = true;

					cpy[i][j] = 0;
					cpy[i - 1][j] = 0;

				}
			}

		}
	}
	
	memcpy(&Circle, &cpy, sizeof(cpy));

	if (same == false)
	{
		double standard = hap / cnt;
		//cout << standard << endl;

		while (!Q.empty())
		{
			int cx = Q.front().x;
			int cy = Q.front().y;
			double cn = Q.front().num;
			Q.pop();

			if (standard < cn)
			{
				Circle[cx][cy]--;
			}
			else if(standard > cn)
				Circle[cx][cy]++;
		}
	}

}
