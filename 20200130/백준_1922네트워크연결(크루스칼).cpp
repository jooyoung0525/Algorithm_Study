/*  << MST구하는 알고리즘 --> 크루스칼(유니온파인드이용) >>

1. 벡터에 간선정보, 가중치를 저장
2. 가중치를 기준으로 오름차순으로 벡터를 sort

3. union-find함수 생성
   --> 1) 부모정보저장할 배열 초기화 (자기 인덱스값으로)
       2) 높이정보저장할 배열만들기
       3) find함수 만들기 --> dp이용해서 리턴하기(간선의 부모정보 찾으면 배열에 바로바로저장해서 중복줄임)
       4) union함수 만들기 --> 높이 고려해서 작은트리에 큰트리가 합쳐지게...?(내가 외운방법)
                           --> 높이같을경우 ++해줌
                           
4. 벡터 처음부터 size만큼 for문 돌면서 정점a와 정점b의 부모노드가 같은지 확인(같으면 사이클생김으로 고려해주면안됨)
5. a와 b의 부모가 같으면 continue, 다르면 가중치를 결과값에 더해주고 a,b를 결합해줌 ( 최소가중치를 가진 a와b 연결한다는 의미 )

*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct info { int start, end, weight; 

bool operator<(const info& a)const
{
	return weight < a.weight;
};

};

int N, M;
int Parent[1100];
int height[1100];
vector<info>V;

int findparent(int a)
{
	if (Parent[a] == a)return a;
	return Parent[a] = findparent(Parent[a]);
}

void merge(int a, int b)
{
	int roota = findparent(a);
	int rootb = findparent(b);

	if (roota == rootb)return;

	if (height[roota] > height[rootb]) 
		swap(roota, rootb);

	Parent[roota] = rootb;

	if (height[roota] == height[rootb])
	{
		height[rootb]++;
	}
}

int main()
{
	int result = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a=0, b=0, c=0;
		cin >> a >> b >> c;
		V.push_back({ a,b,c });
	}

	sort(V.begin(), V.end());

	for (int i = 1; i <= N; i++)
		Parent[i] = i;

	for (int i = 0; i < V.size(); i++)
	{
		if(findparent(V[i].start) == findparent(V[i].end)) continue;

		result += V[i].weight;

		merge(V[i].start, V[i].end);
	}

	cout << result << "\n";

	return 0;
}
