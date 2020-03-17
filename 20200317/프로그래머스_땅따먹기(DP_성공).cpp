/*
<<시간초과때문에 DP로 접근>>

1. memo배열의 초기값은 맨앞줄로 설정
2. i행k열관점으로 memo의 i행k열 배열값이 되려면 (i-1행k열 land배열값 + i행k열의memo값)과 (memo의i행k열의 값)중 최댓값을 구해야함!
3. 메모를 다했으면 마지막행(land.size()-1)의 최댓값을 구해주면됨

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int memo[100010][5];

void Go_eating(vector<vector<int> > land);

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int col = land.size()-1;
   
    for(int i = 0; i<4; i++)
    {
        memo[0][i]=land[0][i];
    }
    
    Go_eating(land);
    
    answer = *max_element(memo[col],memo[col]+4);
    
    return answer;
}


void Go_eating(vector<vector<int> > land)
{
  
    for(int i = 1; i<land.size(); i++)
    {
        for(int j = 0; j<4; j++) //열의 기준값
        {
            int now = j;
            for(int k = 0; k<4; k++)
            {
                if(now==k)continue;
                memo[i][now] = max(memo[i-1][k]+land[i][now],memo[i][now]);
            }
        } 
       
    }
    
}
