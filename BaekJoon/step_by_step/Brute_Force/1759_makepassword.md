###↓↓↓vector이용방법/코드플러스 인강듣고 품/몇일 뒤에 다시도전/
------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool check(string &password)
{
	int mo = 0;
	int ja = 0;
	for (char x : password) ///password 문자열을 문자x로 끊어서 반복
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo+=1;
		}
		else
			ja+=1;
	}

	if (mo >= 1 && ja >= 2) return true;
	else return false;
}

void go(int L, vector<char> &alpha, string password, int i) {

	if (password.length() == L)
	{
		if (check(password))
		{
			cout << password << "\n";
		}
		return;
	}
	
	if (i >= alpha.size()) return;
	go(L, alpha, password + alpha[i], i + 1);
	go(L, alpha, password, i + 1);
	
	
}

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);

	vector<char> alpha(C);

	for (int i = 0; i < C; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	
	go(L, alpha, "", 0);

	return 0;
}
```
