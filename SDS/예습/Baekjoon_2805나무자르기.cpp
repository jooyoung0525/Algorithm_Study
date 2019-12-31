/*

큰수부터 for문돌면 시간초과! -->  나무의 높이가 2,000,000,000이므로
이분탐색을 이용해서 푼다

-->중간값을 구하고 M값이 mid보다 작으면 왼쪽반나눈값에서 구하고, mid보다 크면 오른쪽반나눈값에서 정답을 구하는방식으로 구현!

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int tree[1000010] = { 0 };
long long ans = 0;

void binary(int start,int end)
{
	long long mid;
	if (start <= end)
	{
		mid = (start + end) / 2;
	
		long long hap = 0;

		for (int i = 0; i < N; i++)
		{
			if (tree[i] - mid < 0)continue;
			hap += (tree[i] - mid);
		}

		if (hap >= M)
		{
			ans = mid;
			binary(mid + 1, end);
		}
		else
			binary(start, mid- 1);
	}
}

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

	binary(0,tree[N-1]);
	cout << ans;
	return 0;
}
