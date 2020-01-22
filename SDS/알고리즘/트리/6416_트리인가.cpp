/* 
< Set의 특징 >

- 중복Key값 허용안함  --> set에 삽입된 모든원소는 단일원소! (중복허용원하면 multiset이용)
- 삽입되는 원소 자동정렬

-----------------------------------------------------------------------------------------------------------

< 트리의 특징 >

- 정점개수 == 간선개수 + 1
- 그냥 정점만 있어도 트리!


---------------------------------------------------------------------------------------------------------------

< 아래문제 접근법 >

 1. set에 u,v의 값을 넣어서 정점의 개수를 구함
 2. u,v입력받으면서 line개수를 세줌 ( u,v입력받는게 간선개수 )
 3. 위의 트리의 특징을 모두 만족하면 출력하고 line개수와 set자료형 초기화
*/



#include<iostream>
#include<set>

using namespace std;

set<int>node;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u = 1, v = 1;
	int k = 0, line = 0;

	while (1)
	{
		cin >> u >> v;

		if (u == -1 && v == -1) break;
		if (u == 0 && v == 0)
		{
			if (node.size() - 1 == line || line == 0)
			{
				cout << "Case " << ++k << " is a tree." << "\n";
				line = 0;
				node.clear();
			}
			else
			{
				cout << "Case " << ++k << " is not a tree." << "\n";
				line = 0;
				node.clear();
			}
			continue;
		}
		node.insert(u); 
		node.insert(v);
		line++;
	}
	return 0;
}
