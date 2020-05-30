// 원래 클래스 별로 숫자 + 1 의 모들 클래스를 모두 곱하고 -1 하면 정답
#include <string>
#include<iostream>
#include <vector>
#include<map>

using namespace std;

int answer = 1;
map<string,int>M;
vector<int>IDX;
int num[40];
bool check[40];

void DFS(int count, int now, int idx);

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    
    for(int i = 0; i<clothes.size(); i++)
    {
        if(M.find(clothes[i][1]) == M.end())
        {
           M.insert(make_pair(clothes[i][1],1));
        }
        else
        {
            map<string,int>::iterator iter = M.find(clothes[i][1]);
            iter->second++;
        }
    }
 
    for(auto iter = M.begin(); iter!=M.end(); iter++)
    {
        //cout<<iter->first<<" "<<iter ->second<<"\n";
        IDX.push_back(iter->second);
    }
    
    for(int i = 0; i<IDX.size(); i++){
        answer *= (IDX[i]+1);
    }
    return answer-1;
}
