#include<iostream>
#include<algorithm>

using namespace std;

int A, B, C;

bool visit1[550][550];//AB
bool visit2[550][550];//BC
bool visit3[550][550];//AC

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;
	
	int cnt = 0;
	bool cant = false;
	int  X = 0; int Y = 0;

	if ((A + B + C) % 3 != 0) cout << 0 << endl;

	else {

		while (1)
		{
			cnt++;
			if (A == B && B == C)
			{
				cant = true;
				break;
			}
			if (cnt > 2000000000)break;
			X = 0; Y = 0;
			if (A != B && !visit1[A][B])
			{
				visit1[A][B] = true;
				if (A > B)
				{
					X = B; Y = A;
					B = X + X;
					A = Y - X;
				}
				else if (A < B)
				{
					X = A; Y = B;
					A = X + X;
					B = Y - X;
				}
			}
			else if (B != C && !visit2[B][C])
			{
				visit2[B][C] = true;
				X = 0; Y = 0;
				if (B > C)
				{
					X = C; Y = B;
					C = X + X;
					B = Y - X;
				}
				else if (B < C)
				{
					X = B; Y = C;
					B = X + X;
					C = Y - X;
				}
			}
			else if (A != C && !visit3[A][C])
			{
				visit3[A][C] = true;
				X = 0; Y = 0;
				if (A > C)
				{
					X = C; Y = A;
					C = X + X;
					A = Y - X;
				}
				else if (A < C)
				{
					X = A; Y = C;
					A = X + X;
					C = Y - X;
				}
			}	
		}
		if (!cant) cout << 0;
		else cout << 1;

	}
	return 0;
}

