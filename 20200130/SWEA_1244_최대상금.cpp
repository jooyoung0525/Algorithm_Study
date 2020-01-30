/*

<< 제일 큰 상금 구할 때 >>
set에 조건이 만족하는 상금들을 insert -> 중복제거 및 자동정렬 -> 제일 큰 값 set의 가장아래에 -> 역방향으로 출력 -> 마지막값출력되면 break;

※중복되는 상금이 많을 수도 있으니까 visit[상금][교환횟수] 로 체크해서 중복을 거르고 시간을 줄인다

- string to *char -->  00.c_str(); //string, iostream
- *char to string --> atoi() //stdlib.h

*/


#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<stdlib.h>

using namespace std;


int T,len;
set<string>Result;
string split;
bool visit[1000000][11];

void swap(int a, int b);
void Exchange(int changetime);

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		Result.clear();
		int changetime = 0;
		memset(visit, false, sizeof(visit));
		len = 0;

		//입력
		cin >> split >> changetime;

		len = split.length();
	
		Exchange(changetime);

		for (auto iter = Result.rbegin(); iter != Result.rend(); ++iter) {
			cout <<'#'<<q<<' '<< *iter << "\n";
			break;
		}
	}


	return 0;
}

void swap(int a, int b)
{
	char temp = split[a];
	split[a] = split[b];
	split[b] = temp;
}

void Exchange(int changetime)
{

	if (changetime == 0)
	{
		Result.insert(split);
		return;
	}

	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (i==j ||(split[j] == '0' && i == 0))continue;		
			swap(i,j);
			if (visit[atoi(split.c_str())][changetime] == false) {
				visit[atoi(split.c_str())][changetime] = true;
				Exchange(changetime - 1);
			}
			swap(j,i);	
		}
	}

}
