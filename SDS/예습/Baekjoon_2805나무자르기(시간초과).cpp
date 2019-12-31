#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int tree[1000010] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	sort(tree, tree + N);
	int result = 0;

	for (int i = tree[N-1]; i >= 0; i--) //나무의 높이가 2,000,000,000이 최대이므로 저 값들을 다 for문돌리면 너무오래걸림!!!
	{
		int hap = 0;
		for (int j = 0; j < N; j++)
		{
			if(tree[j] > i)
				hap += (tree[j] - i);
		}
		if (hap >= M)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
