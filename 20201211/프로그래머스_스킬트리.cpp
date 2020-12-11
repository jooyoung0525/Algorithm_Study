#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;




int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    

    for(int i = 0; i<skill_trees.size(); i++){
        queue<int>Q;
        int skillcheck[27]={0};

       //초기 체크값 설정
       for(int j = 0; j<skill.length(); j++){
            Q.push(skill[j]);
            skillcheck[(skill[j]-'0')-17]++;
        }
        
        bool flag = false;
        for(int j = 0; j<skill_trees[i].length(); j++){
            
             if(Q.empty()){
                 break;
             }
            char now = skill_trees[i][j];
            char checkalpha = Q.front();
            int idx = (now-'0')-17;
          
            
            if(skillcheck[idx]==1 && now == checkalpha){
               
                    Q.pop();
                
                    skillcheck[idx] = -1;
            }
            else if(skillcheck[idx]==0)continue;
            else if(skillcheck[idx]==1 && now != checkalpha){
                flag = true;
                break;
            }            
        }
        if(!flag)answer++;
        
    }
  
    return answer;
}
