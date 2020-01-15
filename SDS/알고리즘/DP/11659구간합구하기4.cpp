/*
 <<점화식>> 
 
 D[i]= 1~i까지 구간 합
 인덱스 2~6까지의 합 ==> D[6]-D[1] 
 
 
 D[6] = 1~6까지 구간합
 -
 D[1] = 1까지 구간합
 -----------------------------
 = 2~6 구간합
 
 *** 2차원배열로 선언해도 되는데, 수가 커서 1차원으로 해야 시간초과안남!
 ex)D[i][j] = i~j까지 구간합
 
*/


#include<iostream>

using namespace std;

int N, M;
int Num[100010];
int D[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> Num[i];

	D[1] = Num[1];

	for (int i = 2; i <= N; i++)
	{
		D[i] = D[i - 1] + Num[i];
	}

	for(int i = 0; i<M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << D[b] - D[a - 1] << "\n";
	}
	return 0;
}
