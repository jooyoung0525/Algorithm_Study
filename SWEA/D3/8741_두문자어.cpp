#include<iostream>
#include<string>

using namespace std;

int T;

int main()
{
	cin >> T;
	cin.ignore(256, '\n'); //getline은 '\n'을 받으면 종료되는데 앞에 T입력받을때 버퍼에 \n남아있어서 
	                       //cin.ignore안써주면 string s받기도 전에 종료
	for (int i = 1; i <= T; i++)
	{
		string s;
		string change = "";

		getline(cin, s); //string에서 띄어쓰기포함 입력받고 싶을 때
		
		change += toupper(s[0]); //toupper : 소문자를 대문자로 바꿔줌
		for (int j = 1; j < s.length(); j++)
		{
			if (s[j] == ' ')
				change += toupper(s[j + 1]);
		}
	
		cout << '#' << i << ' '<< change << endl;
	}

	return 0;
}
