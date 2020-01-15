//이차원배열의 구간합 구하기

#include<iostream>


using namespace std;

int N, M;
int Num[1100][1100];
int D[1100][1100];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Num[i][j];
		}
	}
	
	D[1][1] = Num[1][1];//초기값
  
	for (int i = 2; i <= N; i++)
	{
		D[1][i] = D[1][i - 1] + Num[1][i]; //1행 구간합 초기값으로 구해줌
		D[i][1] = D[i - 1][1] + Num[i][1]; //1열 구간합 초기값으로 구해줌
	}
  

  // 1  2  3  4
  // 5  6  7  8
  // 9  10 11 12
  
  // 1~11 구간합 --> (1,2,3,5,6,7의 합) + (1,2,5,6,9,10의 합) -(1,2,5,6의 합(중복)) + 11의합
  
	for (int i = 2; i <= N; i++)
	{
		for(int j = 2; j<=N; j++)
		{
			D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + Num[i][j]; 
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1,x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1];
		cout << result << "\n";

	}

	return 0;
}
