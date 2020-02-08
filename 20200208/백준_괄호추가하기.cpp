#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define small -10e9
using namespace std;

struct info { int s, e; };
int N;
int MMax = small;
bool check[30];
deque<int>Q;
string sik;

void Select(int gulho, int cnt, int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> sik;

	if (N == 1) {
		cout << sik << endl;
		return 0;
	}
	else
	{
		int maxgulho = 0;
		if (N == 3 || N == 5)maxgulho = 1;
		else if (N == 7 || N == 9)maxgulho = 2;
		else if (N == 11 || N == 13)maxgulho = 3;
		else if (N == 15 || N == 17)maxgulho = 4;
		else if (N == 19)maxgulho = 5;

		for (int i = 1; i <= maxgulho; i++)
		{
			Select(i, 0, 0);
		}

		cout << MMax << endl;
		return 0;
	}
}

void Select(int gulho, int cnt, int idx)
{
	if (gulho == cnt)
	{
		deque<int>cpy;
		cpy = Q;

		int hap = 0; int start = 0;
		if (check[0] == 0)
		{
			hap = sik[0] - '0';
			start = 1;
		}
		else {
			hap = cpy.front();
			cpy.pop_front();
			start = 3;
		}

		//cout << "start" << start << " " << "s_hap" << hap << endl;

		for (int i = start; i < N; i += 2)
		{
			if (check[i] == 1)continue;
			if (check[i + 1] == 0) {
				if (sik[i] == '+')
				{
					hap += (sik[i + 1] - '0');
				}
				else if (sik[i] == '-')
				{
					hap -= (sik[i + 1] - '0');
				}
				else if (sik[i] == '*')
				{
					hap *= (sik[i + 1] - '0');
				}
				//cout << "oper" << sik[i] << " " << "num" << sik[i + 1] << " " << hap << endl;
				continue;
			}
			else if (check[i + 1] == 1)
			{
				int num = cpy.front();
				cpy.pop_front();

				if (sik[i] == '+')
				{
					hap += (num);
				}
				else if (sik[i] == '-')
				{
					hap -= (num);
				}
				else if (sik[i] == '*')
				{
					hap *= (num);
				}
				continue;
			}
		}

		MMax = max(MMax, hap);

		return;
	}

	for (int i = idx; i <= N - 3; i += 2)
	{
		int a = sik[i] - '0';
		int b = sik[i + 2] - '0';

		if (sik[i + 1] == '+')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a + b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}
		else if (sik[i + 1] == '-')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a - b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}
		else if (sik[i + 1] == '*')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a * b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}


	}
}
