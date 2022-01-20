// dfs 재귀 + 이동가능한 경로를 미리 저장
// 시간초과 => 메모이제이션 

#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;

int N,M;
int map[505][505];
bool visit[505][505];
vector<int> path[505][505];

int allPath = 0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};



void Input(){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin>>map[i][j];
        }
    }
}

void availablePath(){

    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){

           int now = map[i][j];

           for(int k = 0; k<4; k++){
               int nx = i+dx[k];
               int ny = j+dy[k];
               if(nx<0||ny<0||nx>=M||ny>=N||now<=map[nx][ny])continue;
               
               path[i][j].push_back(k);
           }

        }
    }
}

void DFS(int x, int y){
    if(x == M-1 && y==N-1){
        allPath++;
       // cout<<"allPath: "<<allPath<<"\n";
        return;
    }

    for(int i = 0; i<path[x][y].size(); i++){
        int nowIndex = path[x][y][i];
        //cout<<nowIndex<<"\n";
   
        int nX = x+dx[nowIndex];
        int nY = y+dy[nowIndex];
        if(nX<0||nY<0||nX>=M||nY>=N || visit[nX][nY]) continue;
        //cout<<nX<<" "<<nY<<"\n";
         visit[nX][nY]=true;
         DFS(nX,nY);
         visit[nX][nY]=false;
         //cout<<"&&BACK : "<<nX<<" "<<nY<<"\n";
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>M>>N;

    Input();
    availablePath();
    visit[0][0]=true;
    DFS(0,0);

    cout<<allPath;

    return 0;
}
