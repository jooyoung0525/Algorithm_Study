#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int T, N;
bool check[20];
int food_reserve[20][20];
vector<int>Result;

void Cal_taste();
void Select(int cnt, int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		N = 0;
		memset(check, false, sizeof(check));
		memset(food_reserve, 0, sizeof(food_reserve));

		//입력
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> food_reserve[i][j];
			}
		}

		//식재료선택
		Select(0, 1);



		//음식맛의 최솟값 출력
		cout << '#' << q << ' ' << *min_element(Result.begin(), Result.end()) << "\n";
	}
	return 0;
}

void Cal_taste()
{
	vector<int>foodA;
	vector<int>foodB;

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == true)  //선택된거 A음식
			foodA.push_back(i);
		else
			foodB.push_back(i);
	}

	long long tasteA = 0; long long tasteB = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j || i > j)continue;
			tasteA += (food_reserve[foodA[i]][foodA[j]] + food_reserve[foodA[j]][foodA[i]]);
			tasteB += (food_reserve[foodB[i]][foodB[j]] + food_reserve[foodB[j]][foodB[i]]);
		}
	}

	Result.push_back(abs(tasteA - tasteB));
}

void Select(int cnt, int idx)
{
	if (cnt == N / 2)
	{
		Cal_taste();
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		if (check[i] == true)continue;
		check[i] = true;
		Select(cnt + 1, idx + 1); //왜idx야..i지 바보야!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		check[i] = false;
	}
}
