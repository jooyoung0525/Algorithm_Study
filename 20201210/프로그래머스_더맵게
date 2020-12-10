/*
  큐 사용할때 pop할때 빈 큐인지 확인 ->core dump
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>Q; //오름차순 , 우선순위큐디폴트:내림차순

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //1.벡터에있는 스코빌점수 큐에넣기
    for(int i = 0; i<scoville.size(); i++){
        if(scoville[i]<K){
            Q.push(scoville[i]);
        }
    }
    
    //2.큐에들어간 스코빌지수 검사
    while(!Q.empty()){
                
        int newScoville = 0;
        int first = Q.top(); 
        Q.pop();
                
        if(first >= K)break; //스코빌지수가 K이상이면 반복문 나감
        if(Q.empty())return -1;
        int second = Q.top();
        Q.pop();   
        answer++;
        Q.push(first+(second*2));
    }
   
    return answer;
}
