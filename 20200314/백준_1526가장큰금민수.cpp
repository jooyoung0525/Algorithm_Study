#include<iostream>
#include<string>

using namespace std;

bool check(int cur);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = N; i >= 4; i--)
	{
		if (check(i) == true) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}


bool check(int cur)
{
	string now = to_string(cur);

	for (int i = 0; i < now.length(); i++)
	{
		if (now[i] == '4')continue;
		else if (now[i] == '7')continue;
		else return false;
			
	}

	return true;
}
