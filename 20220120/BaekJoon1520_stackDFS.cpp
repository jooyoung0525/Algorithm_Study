// 스택 DFS
// 시간초과

#include <stdlib.h>
#include <iostream>
#include <stack>


using namespace std;

int N,M;
int map[505][505];
bool visit[505][505];
int allPath = 0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};


struct pathInfo
{
    int x;
    int y;
    int height;
};
stack<pathInfo> st;

void Input(){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin>>map[i][j];
        }
    }
}


void DFS(){
    while(!st.empty()){
       pathInfo cur = st.top();
       st.pop();
       int curx = cur.x;
       int cury = cur.y;
       int curh = cur.height;
       //cout<<"cur"<<curx<<cury<<curh<<"\n";

        if(curx == (M-1) && cury ==(N-1)){
            
            allPath++;
            continue;
        }
       for(int i = 0; i<4; i++){
           int nextx = curx+dx[i];
           int nexty = cury+dy[i];

           if(nextx < 0|| nextx >= M || nexty <0 || nexty >=N )continue;
           if(map[nextx][nexty]<curh){
               pathInfo info;
               info.x = nextx;
               info.y = nexty;
               info.height = map[nextx][nexty];
               //cout<<"push<<< x: "<<nextx<<" y: "<<nexty<<"\n";
               st.push(info);
               //visit[nextx][nexty]=true;
           }
       }
    }

}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>M>>N;

    Input();

   

    visit[0][0]=true;
    pathInfo info;
    info.x = 0;
    info.y = 0;
    info.height = map[0][0];
    st.push(info);
    //cout<<"info"<<"\n";
    DFS();

    cout<<allPath;

    return 0;
}
