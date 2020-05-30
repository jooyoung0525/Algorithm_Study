#include <string>
#include<iostream>
#include <vector>
#include<map>

using namespace std;

int answer;
map<string,int>M;
vector<int>IDX;
int num[40];
bool check[40];

void DFS(int count, int now, int idx);

int solution(vector<vector<string>> clothes) {
    
    answer = clothes.size();
    
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
    
    if(M.size()>=2)
    {
        for(int cnt = 2; cnt<=M.size(); cnt++)
        {
            DFS(cnt,0,0);
        }
    }
    
    return answer;
}

void DFS(int count, int now, int idx)
{
    if(count == now)
    {
        int ans = 1;
        for(int i = 0; i<M.size(); i++)
        {
            if(check[i])
            {
                ans*=IDX[i];
            }
        }
        answer+=ans;
        return;
    }
    
    for(int i =idx; i<M.size(); i++)
    {
        if(check[i])continue;
        check[i]=true;
        DFS(count,now+1,i+1);
        check[i]=false;
    }
}

