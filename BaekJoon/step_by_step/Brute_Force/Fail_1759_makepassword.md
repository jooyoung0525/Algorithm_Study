![암호](https://user-images.githubusercontent.com/29946480/60815534-24710b80-a198-11e9-9a5e-79dcdf1a7f28.PNG)

-----------------------------------------------------------------------------------------------------
## return, break, continue의 사용법


- return : 함수에서 탈출을 의미 

- break : 루프문 탈출을 의미. 

- continue : (continue 아래코드) 일부 코드를 실행하지 않고 건너뜀
-----------------------------------------------------------------------------------------------
###↓↓↓vector이용방법/코드플러스 인강듣고 품/몇일 뒤에 다시도전/
------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int L, C;

bool mo_ja(string &password)
{
	int mo = 0;
	int ja = 0;
	for (char x : password) // password문자열은 char문자 하나씩 끊어서 봄.
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') mo++;
		else ja++;
	}
	if (mo >= 1 && ja >= 2) return true;
	else return false;
}

void make_password(vector<char> &gived_alpha, string password, int i)
{
	if (password.length() == L) // string password의 길이가 만들려던 패스워드 길이와 같을경우
	{
		if (mo_ja(password)) { // 모음과 자음의 수의 조건이 충족됬을 때
			cout << password << '\n'; //패스워드 출력
		}
		return;  // ** 리턴안해주면 같은 값 두개씩 출력
		         // 모음과 자음의 수가 충족 안 됬을 경우는 리턴.
	}

	if (i < gived_alpha.size()) { //인덱스 번호가 주어진 알파벳 개수보다 클 경우 ==> 불가능한 상황

		make_password(gived_alpha, password + gived_alpha[i], i + 1); //해당 인덱스 알파벳을 password로 선택한 경우.
		make_password(gived_alpha, password, i + 1);  //해당 인덱스 알파벳을 password로 선택하지 않은 경우.
	}
}

int main() {

	
	scanf("%d %d", &L, &C);

	vector<char> gived_alpha(C); //벡터에 크기 C만큼의 배열생성

	for(int i = 0; i < C; i++)
	{
		cin >> gived_alpha[i]; //입력 ==> cin 은 iostream
	}

	sort(gived_alpha.begin(), gived_alpha.end()); // 알파벳은 증가하는 순서로 배열되있기 때문에 미리 sort함.

	make_password(gived_alpha,"",0); //주어진 알파벳 벡터배열과, 빈string, 초기 인덱스 0

	//system("pause");
	return 0;
}
```
