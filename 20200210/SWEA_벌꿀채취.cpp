//세상복잡ㅎ

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;


struct info{ int x, y, honey; };
int T;
int N, M, C;
int map[15][15];
int check[15][15];
vector<info>work1;
vector<info>work2;
vector<int>RE;
vector<int>ANS;


void cal(int cnt, int count, int idx, vector<info>work1, int hap, vector<int>result);
void Select(int cnt);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		N = 0, M = 0, C = 0;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		ANS.clear();
		work1.clear();
		work2.clear();

		//입력
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		//일꾼1 고르고 Select들어가서 일꾼2고름
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N - M; j++) //시작범위가 N-M초과하면 범위가 넘어가서 안됨
			{
				
        //허용된 길이만큼 체크해주고, 일꾼1의 범위를 벡터에넣어주기
        int cur = 0;
				for (int k = j; k < j + M; k++)
				{
					check[i][k] = 1;
					work1.push_back({ i,k,map[i][k] });
					cur = k;
				}
        
				Select(0);
        
        //초기화
				memset(check, 0, sizeof(check));
				work1.clear();
			}
		}

		cout <<'#'<<q<<' '<<*max_element(ANS.begin(), ANS.end())<<"\n";

	}


	return 0;
}

void Select(int cnt)
{

	if (cnt == 1) //일꾼2도 골랐을 때, 
	{
		int result = 0;
		int mmax1 = 0;
		
    //<<일꾼1>>
    
    //일꾼 1의 선택한 범위의 값을 계산
		for (int i = 0; i < work1.size(); i++)
		{
			mmax1 += work1[i].honey;
		}
    
		if (mmax1 <= C) { //선택한 모든범위의 값이 C보다 작거나 같으면 

			for (int i = 0; i < work1.size(); i++)
			{
				result += (work1[i].honey * work1[i].honey); //계산
			}
		}
		else //선택한 모든범위의 값이 C보다 크면
		{
			// 선택한 모든 범위 중에서 1~M-1개 선택후 계산
			RE.clear(); //전역이기때문에 초기화 필요!
			vector<int>R; //선택한 범위의 값이 C보다 작거나같을경우, 해당 값들을 넣어주는 벡터
      
			for (int i = 1; i < M; i++)
			{
				cal(i, 0, 0, work1, 0,R); //1~M-1까지
			}
      
			result += *max_element(RE.begin(), RE.end());
		}

    //<<일꾼2>>
		int mmax2 = 0;
		for (int i = 0; i < work2.size(); i++)
		{
			mmax2 += work2[i].honey;
		}
    
		if (mmax2 <= C) {
			for (int i = 0; i < work2.size(); i++)
			{
				result += (work2[i].honey * work2[i].honey);
			}
		}
		else
		{
			RE.clear();
			vector<int>R;
		
      //1~M-1선택
			for (int i = 1; i < M; i++)
			{
				cal(i, 0, 0, work2, 0, R);
			}
			
			result += *max_element(RE.begin(), RE.end());
		}

		ANS.push_back(result);
		
		return;
	}

  //일꾼1의 범위 피해서 일꾼2의 범위 고르기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			bool flag = false;
			for (int k = j; k < j + M; k++)
			{
				if (check[i][k] == 1) flag = true; //일꾼1의 범위와 겹치면 안되기 때문에 아래코드 계산안하고 넘어감
			}
      
			if (!flag) { //일꾼2의 범위가 1의 범위와 안겹칠경우
				int cur = 0;
				for (int k = j; k < j + M; k++)
				{
					check[i][k] = 2;
					work2.push_back({ i,k,map[i][k]}); //일꾼2의 벡터에 고른 범위 넣어줌
					cur = k;
				}
        
				Select(cnt + 1);
        
        //일꾼2의 범위 Select재귀이전으로 되돌림
				for (int k = cur; k >= j; k--)
				{
					check[i][k] = 0;
				}
				work2.clear();
			}
		}
	}
}

void cal(int cnt, int count, int idx, vector<info>work1, int hap,vector<int>R)
{
	if (cnt == count)
	{
		if (hap <= C)
		{
			//cout <<"cnt "<< cnt << " hap " << hap << endl;
			int ans = 0;
			for (int i = 0; i < R.size(); i++)
			{
				//cout << "R " << R[i] << endl;
				ans += (R[i] * R[i]);
			}
			//cout << endl;
			RE.push_back(ans);
		}
		return;
	}

	for (int i = idx; i < work1.size(); i++)
	{
		R.push_back(work1[i].honey);
		cal(cnt, count + 1, i + 1, work1, hap + work1[i].honey,R);
		R.pop_back();
	}

}
