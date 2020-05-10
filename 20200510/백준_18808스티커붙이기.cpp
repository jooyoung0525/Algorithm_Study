#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int Map[50][50];
int sticker[10][10];
int stickerx, stickery;
int N, M, K;

void Rotate();
bool Find();
void Patch(int x,int y);
bool Can(int x, int y);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++)
	{
		memset(sticker, 0, sizeof(sticker));
		stickerx = 0; stickery = 0;

		cin >> stickerx >> stickery;

		for (int a = 0; a < stickerx; a++)
		{
			for (int b = 0; b < stickery; b++)
			{
				cin >> sticker[a][b];
			}
		}

		for (int i = 1; i < 5; i++)
		{
			if (!Find())
			{
				Rotate();
			}
			else
				break;
		}
	}

	int Count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)Count++;
		}
	}
	
	cout << Count;

	return 0;
}


void Rotate()
{
	queue<int>Q;
	int cpy[10][10] = { 0 };

	for (int i = 0; i < stickerx; i++)
	{
		for (int j = 0; j < stickery; j++)
		{
			Q.push(sticker[i][j]);
		}
	}

	for (int j = stickerx-1; j >=0; j--)
	{
		for (int i = 0; i < stickery; i++)
		{
			if (!Q.empty())
			{
				cpy[i][j] = Q.front();
				Q.pop();
			}
		}
	}
	int x = stickerx;
	int y = stickery;

	stickerx = y;
	stickery = x;

	memcpy(sticker, cpy, sizeof(cpy));

	/*cout << endl;

	for (int i = 0; i < stickerx; i++)
	{
		for (int j = 0; j < stickery; j++)
		{
			cout << sticker[i][j];
		}
		cout << endl;
	}*/
}



bool Find()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << "i " << i << " j " << j << "\n";
			//cout << Can(i, j) << "\n";
			if (Can(i, j))
			{
				Patch(i, j);
				return true;
			}
		}
	}

	return false;
}


void Patch(int x, int y)
{
	for (int i = x; i < x + stickerx; i++)
	{
		for (int j = y; j < y + stickery; j++)
		{
			if (sticker[i - x][j - y] == 0)continue;
			Map[i][j] = sticker[i - x][j - y];
		}
	}
}


bool Can(int x, int y)
{
	for (int i = x; i < x + stickerx; i++)
	{
		for (int j = y; j < y + stickery; j++)
		{
			if (i >= N || j >= M)return false;
			if (sticker[i - x][j - y] == 1 && Map[i][j] == 1)
			{
				//cout << "sticker idx" << i - x << " " << j - y << "\n";
				//cout << sticker[i - x][j - y] << " " << Map[i][j] << "\n";
				return false;
			}
		}
	}

	return true;
}
