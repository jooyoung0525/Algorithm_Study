![로또](https://user-images.githubusercontent.com/29946480/60888224-9445cb80-a256-11e9-9172-b3297ab2dae8.PNG)

---------------------------------------------------------------------------------------------------------------
### 재귀 어려워어어어어어ㅓㅇㄱ
--------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> lotto;

void pick_num(vector<int>& lotto_num, int i)
{
	if (lotto.size() == 6) //lotto벡터 길이가 6이면
	{
		for (int x : lotto) { //lotto벡터를 int형으로 쪼개서 한개씩 출력
			printf("%d ", x);
		}
		printf("\n");
		
		/*
		for(int i = 0; i < 6; i++)
		{
			printf("%d ",lotto[i]);
		}
		printf("\n);
		*/
		
		return; //return 안해주면 같은 수 반복될 수 있음!
	}
	
	if (i >= lotto_num.size()) return; //인덱스가 초기에 입력받은 lottonum보다 크면 함수 나감(불가능한 상황)

	
	lotto.push_back(lotto_num[i]); //벡터에 숫자 삽입
	pick_num(lotto_num, i + 1); //다음인덱스로 넘어감
	lotto.pop_back(); // 숫자 빼기
	pick_num(lotto_num, i + 1); // 다음인덱스로 넘어감
	
}


int main()
{
	int k;
	

	while (scanf("%d", &k) == 1 && k != 0) {  //입력1개 받았고, 입력받은 k가 0이 아니면 반복

		vector<int> lotto_num(k);
		
		
		for (int i = 0; i < k; i++)
		{
			cin >> lotto_num[i];
			
		}

		sort(lotto_num.begin(), lotto_num.end());

		pick_num(lotto_num,0);
		printf("\n"); //다음 출력전에 빈줄 출력
		lotto_num.clear(); //벡터 초기화시켜서 다음 테스트케이스 준비
	}



	system("pause");
	return 0;
}
```
