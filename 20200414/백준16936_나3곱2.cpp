//10^18승 long long형...

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

struct info { long long num, cnt; };
int N;
long long B[110];
bool check[110];
bool stop;


void BFS(long long cur, long long idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	for (int i = 0; i < N; i++)
	{
		BFS(B[i],i);
		if (stop)break;
	}


	return 0;
}


void BFS(long long cur, long long idx)
{
	
	memset(check, false, sizeof(check));

	queue<info>Q;
	vector<long long>Result;

	check[idx] = true;
	Result.push_back(cur);
	Q.push({ cur,1 });

	while (!Q.empty())
	{
		long long cnum = Q.front().num;
		int ccnt = Q.front().cnt;
		Q.pop();

		if (ccnt == N)
		{
			for (int i = 0; i < Result.size(); i++)
				cout << Result[i] << " ";
			stop = true;
			return;
		}

		if (cnum % 3 == 0)
		{
			long long next = cnum / 3;
			for (int i = 0; i < N; i++)
			{
				if (B[i] == next && check[i]==false)
				{
					check[i] = true;
					Result.push_back(next);
					Q.push({ next,ccnt + 1 });
				}
			}
		}

		long long next = cnum * 2;
		for (int i = 0; i < N; i++)
		{
			if (B[i] == next && check[i]==false)
			{
				check[i] = true;
				Result.push_back(next);
				Q.push({ next,ccnt + 1 });
			}
		}
	}
	
	return;

}
