#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int D[550][550];
int Arr[550][550];
int n;

int main()
{
	cin >> n;

	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cnt; j++) //삼각형모양으로 입력 (j<i로해도됨)
		{
			int a;
			cin >> Arr[i][j];

		}
		cnt++;
	}
	
	D[0][0] = Arr[0][0]; //D초기값
	
	cnt = 2;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			D[i][j] = *max_element(D[i - 1] + (j - 1), D[i - 1] + (j + 1)) + Arr[i][j];
		}
		cnt++;
	}

	int result = *max_element(D[n - 1], D[n - 1] + n);
	cout << result;
	return 0;
}
