// 참고 : https://www.crocus.co.kr/683 

//Union-find 알고리즘 (최적화 코드로 짜봄)


#include<iostream>
#include<cstring>

using namespace std;

int n, m;
long long Parent[1000010];
long long height[1000010];

int findparent(int num)
{
	if (Parent[num] == num) return num;
	return Parent[num] = findparent(Parent[num]); //dp이용해서 계산했던 부모노드 다시 계산안하게
}

void UUnion(int a, int b)
{
	int roota = findparent(a);
	int rootb = findparent(b);

	if (roota == rootb) return;

//union-by-rank최적화
	if (height[roota] > height[rootb]) //roota의 트리크기가 rootb트리크기보다클때 --> roota:큰트리 rootb:작은트리
		swap(roota, rootb); //순서바꿈 --> swap후, roota:작은트리 rootb:큰트리

	Parent[roota] = rootb; // 작은 트리의 부모에 큰 트리부모 붙여줌

	if (height[roota] == height[rootb]) // 두개의 트리의 크기가 같으면 둘중 아무거나 부모의 크기 플러스
		height[rootb]++; 

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	//입력
	cin >> n >> m;

	//초기화
	memset(height, 1, sizeof(height));
	for (int i = 1; i <= n; i++)
	{
		Parent[i] = i;
	}
	
	//m개만큼 명령진행
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		
		if (a == 0)
		{
			UUnion(b, c);
		}

		else if (a == 1)
		{
			if (findparent(b) == findparent(c)) cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}
