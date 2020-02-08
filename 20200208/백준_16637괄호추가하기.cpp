#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define small -10e9
using namespace std;

struct info { int s, e; };
int N;
int MMax = small;
bool check[30];
deque<int>Q;
string sik;

void Select(int gulho, int cnt, int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> sik;

	if (N == 1) { //길이가 1이면 그냥출력 (괄호를 만들 필요가 없음)
		cout << sik << endl;
		return 0;
	}
	else
	{
		int maxgulho = 0; //만들수 있는 최대 괄호수를 미리 구함
		if (N == 3 || N == 5)maxgulho = 1;
		else if (N == 7 || N == 9)maxgulho = 2;
		else if (N == 11 || N == 13)maxgulho = 3;
		else if (N == 15 || N == 17)maxgulho = 4;
		else if (N == 19)maxgulho = 5;

		for (int i = 1; i <= maxgulho; i++)
		{
			Select(i, 0, 0); //1~최대괄호수까지 자리별로 괄호추가
		}

		cout << MMax << endl;
		return 0;
	}
}

void Select(int gulho, int cnt, int idx)
{
	if (gulho == cnt) //선택한괄호수랑, 기존에 설치하려고했던 괄호수랑 같으면 
	{
		deque<int>cpy; //Q복사(check배열에 따라서 Q를빼야하니까)
		cpy = Q;

		int hap = 0; int start = 0;
		if (check[0] == 0) //처음에 괄호설치 안했으면
		{
			hap = sik[0] - '0'; //초기값은 string[0]의 수
			start = 1; //초기 연산자의 위치
		}
		else { //처음에 괄호설치 했으면 미리계산된 괄호안의 결과값을 초기값으로 설정
			hap = cpy.front(); 
			cpy.pop_front();
			start = 3;//괄호 다음이 초기 연산자의 위치
		}

		//cout << "start" << start << " " << "s_hap" << hap << endl;

		for (int i = start; i < N; i += 2) //초기연산자 위치~ 끝까지 idx가 홀수일때 검사(연산자)
		{
			if (check[i] == 1)continue;//만약 연산자가 괄호를 설치한 연산자면 넘김(이미 계산완료)
			if (check[i + 1] == 0) { //연산자 다음의 수에 괄호설치 안했을 때, 
				if (sik[i] == '+')
				{
					hap += (sik[i + 1] - '0');
				}
				else if (sik[i] == '-')
				{
					hap -= (sik[i + 1] - '0');
				}
				else if (sik[i] == '*')
				{
					hap *= (sik[i + 1] - '0');
				}
				//cout << "oper" << sik[i] << " " << "num" << sik[i + 1] << " " << hap << endl;
				continue;
			}
			else if (check[i + 1] == 1) //연산자 다음 괄호설치 했을때
			{
				int num = cpy.front(); //hap과 연산을 해야하는 숫자를 큐에서 뽑음
				cpy.pop_front();

				if (sik[i] == '+')
				{
					hap += (num);
				}
				else if (sik[i] == '-')
				{
					hap -= (num);
				}
				else if (sik[i] == '*')
				{
					hap *= (num);
				}
				continue;
			}
		}

		MMax = max(MMax, hap);

		return;
	}

	for (int i = idx; i <= N - 3; i += 2) //
	{
		int a = sik[i] - '0';
		int b = sik[i + 2] - '0';

		if (sik[i + 1] == '+')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a + b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}
		else if (sik[i + 1] == '-')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a - b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}
		else if (sik[i + 1] == '*')
		{
			if (check[i] == true)continue;
			check[i] = true;
			check[i + 1] = true;
			check[i + 2] = true;
			Q.push_back(a * b);
			Select(gulho, cnt + 1, i + 2);
			Q.pop_back();
			check[i] = false;
			check[i + 1] = false;
			check[i + 2] = false;
		}


	}
}
