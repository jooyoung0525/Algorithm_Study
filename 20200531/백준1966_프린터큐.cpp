#include<iostream>
#include<queue>

using namespace std;

struct info { int name, important;};

int T;

priority_queue<int>Standard;
queue<info>Q;

void Init_all();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		Init_all();
		int Count = 0;
		int N, M; //N:문서의수 M:궁금한문서
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			Standard.push(a);
			Q.push({i,a});
		}

		while (!Q.empty())
		{
			int Standnum = Standard.top();
			int nowM = Q.front().name;
			int nowImport = Q.front().important;
			//cout << Standnum << " " << nowM << " " << nowImport << "\n";
			Q.pop();

			if (Standnum != nowImport)
			{
				Q.push({ nowM,nowImport });
			}
			else if (Standnum == nowImport)
			{
				Count++;
				Standard.pop();
				if (nowM == M)
				{
					break;
				}
			}
		}
		cout << Count << "\n";
	}

	return 0;
}

void Init_all()
{
	while (!Standard.empty())
		Standard.pop();
	while (!Q.empty())
		Q.pop();
}
