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
int ans = 0;

void binary(int start,int end) //시작값, 끝값
{
	if (start <= end) //시작값이랑 끝값이 같거나, 시작값이 끝값보다 작을경우
	{ 
		int mid = (start + end) / 2;
	
		long long hap = 0;

		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid) //mid보다 나무의 길이가 크면
			    hap += (tree[i] - mid); //hap+자른나무의길이
		}

		if (hap >= M) //만약 원하는 나무의길이와 자른나무의 길이가 같거나, 원하는길이보다 더 많이 잘랐을경우 
		{
			ans = mid;
			binary(mid + 1, end); //최적값을 찾기위해 다시 이분탐색해봄
		}
		else
			binary(start, mid- 1); //자른나무의길이가 원하는 길이보다 작을경우 다시 이분탐색
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

	sort(tree, tree + N); //이분탐색전 오름차순으로 sort해줘야함

	binary(0,tree[N-1]); //이분탐색
	
	cout << ans;
	return 0;
}
