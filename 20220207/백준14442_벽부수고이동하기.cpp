#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int minDist = 987654321;
int map[1010][1010];
bool checkVisit[1010][1010][11];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct info{
    int x,y,wall,dist;
};

queue<info>Q;

void goEveryPath(){
    info init={0,0,0,1};
    Q.push(init);
    checkVisit[0][0][0]=true;

    while(!Q.empty()){
        int curX = Q.front().x;
        int curY = Q.front().y;
        int brokenWall = Q.front().wall;
        int dist = Q.front().dist;
       // cout<<"X : "<<curX<<" Y : "<<curY<<" wall : "<<brokenWall<<" dist : "<<dist<<"\n";
        Q.pop();

        if(curX == N-1 && curY == M-1){
            if(minDist>dist) minDist = dist;
        }

        for(int i = 0; i<4; i++){
            int nextX = curX+dx[i];
            int nextY = curY+dy[i];
            int nextBrokenWall = brokenWall+1;
            int nextDist = dist+1;

           // cout<<"X : "<<nextX<<" Y : "<<nextY<<" wall : "<<nextBrokenWall<<" dist : "<<nextDist<<"\n";

            if(nextX < 0 || nextY<0||nextX >=N||nextY >=M )continue;
            
            //다음이 벽인데, 벽부술수 있는 경우.
            if(map[nextX][nextY] == 1 && brokenWall < K){
                if(checkVisit[nextX][nextY][nextBrokenWall])continue;
                checkVisit[nextX][nextY][nextBrokenWall] = true;
                info next = {nextX,nextY,nextBrokenWall,nextDist};
                Q.push(next);
            }
            // 다음이 벽이 아닌경우
            else if(map[nextX][nextY]== 0 && !checkVisit[nextX][nextY][brokenWall]){
                checkVisit[nextX][nextY][brokenWall]=true;
                info next = {nextX,nextY,brokenWall,nextDist};
                Q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0x0);
    cin.tie(0);

    cin>>N>>M>>K;
    for(int i = 0; i<N; i++){
        /// C++ 에서 C를 쓰면 채점 엔진에서 오류남!
        // for(int j = 0; j<M; j++){
        //    scanf("%1d",&map[i][j]);
        // }

        string a;
        cin>>a;
        for(int j = 0; j<a.length(); j++){
            map[i][j] = (a[j]-'0');
        }
    }

    goEveryPath();
    
    if(minDist == 987654321) minDist = -1;

    cout<<minDist;

    return 0;
}
