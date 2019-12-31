#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int N, L;
int A[5000010] = { 0 };
int minA[5000010] = { 0 };

int main()
{
	
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= L; i++)
	{
		minA[i] = A[1];
	}
	for (int i = L + 1; i <= N; i++)
	{
		minA[i] = *min_element(A+(i - L + 1), A+(i+1));
		//cout << i << " " << minA[i] << endl;
	}
	
	for (int i = 1; i <= N; i++)
	{
		printf("%d ",minA[i]);
	}
	return 0;
}
