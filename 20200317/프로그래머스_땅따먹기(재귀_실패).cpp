//시간초과!!!

#include <iostream>
#include <vector>
using namespace std;

int MMax = -999999;

void Go_eating(int curcol,int currow, int hap, vector<vector<int> > land);

int solution(vector<vector<int> > land)
{
    int answer = 0;
   
    for (int row = 0; row < 4; row++) {
        Go_eating(1, row, land[0][row], land);
    }

    answer = MMax;

    return answer;
}


void Go_eating(int curcol,int currow, int hap, vector<vector<int> > land)
{
    if (curcol == land.size())
    {
        if (MMax < hap)
            MMax = hap;

        return;
    }

    for (int j = 0; j < 4; j++)
    {
        if (j != currow) {
            Go_eating(curcol + 1, j, hap + land[curcol][j], land);
        }
    }
}
