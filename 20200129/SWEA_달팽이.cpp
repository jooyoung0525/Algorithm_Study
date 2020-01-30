//머리식힐겸
 
#include<iostream>
#include<cstring>

using namespace std;

int T;
int N;
int ans[15][15];

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		N = 0;
		memset(ans, 0, sizeof(ans));

		cin >> N;

		int num = 1;
		bool flag = false;

		int first = 0;
		int second = N - 1;
		int third = N - 1;
		int fourth = 0;

		int count = (N / 2) + 1;
		while (count--) {
			for (int j = 0; j < N; j++)
			{
				if (ans[first][j] == 0) {
					ans[first][j] = num;
					if (num == N * N)
					{
						goto here;
					}
					num++;
				}
			}

			first++;

			for (int j = 0; j < N; j++)
			{
				if (ans[j][second] == 0) {
					ans[j][second] = num;
					if (num == N * N)
					{
						goto here;
					}
					num++;
				}
			}
			second--;

			for (int j = N - 1; j >= 0; j--)
			{
				if (ans[third][j] == 0) {
					ans[third][j] = num;
					if (num == N * N)
					{
						goto here;
					}
					num++;
				}
			}
			third--;

			for (int j = N - 1; j >= 0; j--)
			{
				if (ans[j][fourth] == 0) {
					ans[j][fourth] = num;
					if (num == N * N)
					{
						goto here;
					}
					num++;
				}
			}

			fourth++;
		}

	here :

		cout << '#' << q << "\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
