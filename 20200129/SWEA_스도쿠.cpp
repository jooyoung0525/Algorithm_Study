#include<iostream>
#include<cstring>
#include<set>

using namespace std;

int T;
int sdoku[9][9];
bool check[10];

bool square();
bool col();
bool row();

int main()
{
	cin >> T;
	
	for (int q = 1; q <= T; q++)
	{
		memset(sdoku, 0, sizeof(sdoku));

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> sdoku[i][j];
			}
		}


		if (!square() && !col() && !row())
		{
			cout << '#' << q << ' ' << 1 << "\n";
		}
		else
			cout << '#' << q << ' ' << 0 << "\n";
	}
	return 0;
}

bool square() 
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}


	memset(check, false, sizeof(check));
	for (int i = 6; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	memset(check, false, sizeof(check));
	for (int i = 6; i < 9; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == false) return true;
	}

	return false;
}

bool col()
{
	
	for (int i = 0; i < 9; i++)
	{
		memset(check, false, sizeof(check));
		for (int j = 0; j < 9; j++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
		for (int j = 1; j <= 9; j++)
		{
			if (check[j] == false) return true;
		}
	}
	

	return false;
}

bool row()
{
	
	for (int j = 0; j < 9; j++)
	{
		memset(check, false, sizeof(check));
		for (int i = 0; i < 9; i++)
		{
			if (check[sdoku[i][j]] == true)
			{
				return true;
			}
			check[sdoku[i][j]] = true;
		}
		for (int i = 1; i <= 9; i++)
		{
			if (check[i] == false) return true;
		}
	}


	return false;
}
