
------------------------------------------------------------------------------------------------------

### 뭐지.. na,nb까지 만들고 안풀려서 풀이를 봤는데 깔끔한 풀이였다! 풀이대로 풀고싶었는데 맨날 답지보는거 같아서 
### 내가 풀던대로 풀어보려고 안고치고 계속 생각했는데 맞았다!!!!코드는 지저분하지만..ㅎ 
-------------------------------------------------------------------------------------------------------

###풀이 1. (맞음)
```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int num[100] = {0};
int operate[4] = { 0 };

vector<int>V;

void calculate(int a, int b,int sum)
{
	
	int na = a + 1;
	int nb = b + 1;

	if (operate[0] == 0 && operate[1] == 0 &&operate[2] == 0 &&operate[3] == 0)
	{
		//cout << sum<<endl;
		V.push_back(sum);
	}
	
	if (operate[0] > 0)
	{
		operate[0]--;
		sum += num[b];
		//cout << "+" << sum << endl;
		calculate(na, nb, sum);
		operate[0]++;
		sum -= num[b];
	}
	if (operate[1] > 0)
	{
		operate[1]--;
		sum -= num[b];
		//cout << "-" << sum << endl;
		calculate(na, nb, sum);
		operate[1]++;
		sum += num[b];
	}
	if (operate[2] > 0)
	{
		operate[2]--;
		sum *= num[b];
		//cout << "*" << sum << endl;
		calculate(na, nb, sum);
		operate[2]++;
		sum /= num[b];
	}
	if (operate[3] > 0)
	{
		operate[3]--;
		sum /= num[b];
		//cout << "/" << sum << endl;
		calculate(na, nb, sum);
		operate[3]++;
		sum *= num[b];
	}
	
		
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> operate[i];
		//cout << operate[i];
	}

	calculate(0,1,num[0]);

	int MAX = *max_element(V.begin(), V.end());
	int MIN = *min_element(V.begin(), V.end());

	cout << MAX << endl;
	cout << MIN << endl;


	system("pause");
	return 0;
}
```
