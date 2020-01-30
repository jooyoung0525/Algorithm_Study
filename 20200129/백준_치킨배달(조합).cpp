//Select함수 순열로 구현해서 처음에 시간초과남 
//이 문제는 조합!

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int map[55][55];
bool check[15];
struct info { int x, y; };

vector<info>chickenHouse;
vector<info>House;
vector<int>CCd; //citychickendist

void Cal_dist();
void Select(int cnt, int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				House.push_back({ i,j });
			else if (map[i][j] == 2)
				chickenHouse.push_back({ i,j });
		}
	}

	//치킨집중 M개 고르기
	Select(0,0);
	
	cout << *min_element(CCd.begin(), CCd.end());

	return 0;
}

void Cal_dist()
{
	int citychickendist = 0;

	for (int i = 0; i < House.size(); i++) //모든집과
	{
		int chickendist = 10e9;
		for (int j = 0; j < chickenHouse.size(); j++) //선택된 치킨가게의
		{
			if (check[j] == false)continue;
			int dist = abs(House[i].x - chickenHouse[j].x) + abs(House[i].y - chickenHouse[j].y); //치킨거리를구하고
			chickendist = min(chickendist, dist); //치킨거리중 최솟값을 구함
		}

		citychickendist += chickendist; //치킨거리의 최솟값만을 더하면 도시의 치킨거리의 최솟값이 나옴
	}

	CCd.push_back(citychickendist); //벡터에 저장

}

void Select(int cnt, int idx)
{
	if (cnt == M)
	{
		//모든집을 기준으로 치킨집과의 거리의 최솟값을 구함
		Cal_dist();

		return;
	}

	for (int i = idx; i < chickenHouse.size(); i++) 
	{
		if (check[i] == true) continue;
		check[i] = true;
		Select(cnt + 1,i+1);
		check[i] = false;

	}

}
