/*
처음에 while문으로 접근해서 풀라고 했으나, 중복되는 값 체크를 안해주고, break해야하는 범위를 알기 어려웠다. 
따라서 런타임에러, 시간초과, 틀렸습니다 등등.. 문제 풀이를 실패했다!
사람들이 queue를 이용해서 많이 풀었길래 생각한 결과, 그냥 while문으로 접근하면 모두 같은수가 나올때까지 무한반복을 해야하지마
queue에 3수가 가질수 있는 모든 경우를 넣고 빼면서 계산을 하면 while문으로 풀때보다 빠를거라고 생각했다.

따라서, queue와 set(중복체크)을 이용하여 풀었다!
*/

#include<iostream>
#include<queue>
#include<set>

using namespace std;

struct info { int a, b, c; };
int A, B, C;
set<pair<pair<int, int>, int>>Visit;
queue<info>Q;

int Go();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;

	if ((A + B + C) % 3 != 0) cout << 0;
	else cout << Go();


	return 0;
}

int Go()
{
	int na,nb,nc = 0;
	Q.push({ A,B,C });
	Visit.insert({ {A,B},C });

	while (!Q.empty())
	{
		int ca = Q.front().a;
		int cb = Q.front().b;
		int cc = Q.front().c;
		Q.pop();

		if (ca == cb && ca == cc && cb == cc) return 1;
		if (ca < cb)
		{
			na = ca + ca;
			nb = cb - ca;
			if (Visit.find({ {na,nb},cc }) == Visit.end())
			{
				Q.push({ na,nb,cc });
				Visit.insert({{ na,nb },cc});
			}
		}
		else if (ca > cb)
		{
			na = ca - cb;
			nb = cb + cb;
			if (Visit.find({ {na,nb},cc }) == Visit.end())
			{
				Q.push({ na,nb,cc });
				Visit.insert({ { na,nb },cc });
			}
		}

		if (ca < cc)
		{
			na = ca + ca;
			nc = cc - ca;
			if (Visit.find({ {na,cb},nc }) == Visit.end())
			{
				Q.push({ na,cb,nc });
				Visit.insert({ {na,cb},nc });
			}
		}
		else if (ca > cc)
		{
			na = ca - cc;
			nc = cc + cc;
			if (Visit.find({ {na,cb},nc }) == Visit.end())
			{
				Q.push({ na,cb,nc });
				Visit.insert({ {na,cb},nc });
			}
		}

		if (cb < cc)
		{
			nb = cb + cb;
			nc = cc - cb;
			if (Visit.find({ {ca,nb},nc }) == Visit.end())
			{
				Q.push({ ca,nb,nc });
				Visit.insert({ {ca,nb},nc });
			}
		}
		else if (cb > cc)
		{
			nb = cb - cc;
			nc = cc + cc;
			if (Visit.find({ {ca,nb},nc }) == Visit.end())
			{
				Q.push({ ca,nb,nc });
				Visit.insert({ {ca,nb},nc });
			}
		}
	}

	return 0;
}
