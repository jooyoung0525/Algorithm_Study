#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char>S;

int weight = 1; int total = 0;
bool stop= false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string G;
	cin >> G;
	for (int i = 0; i < G.length(); i++)
	{
		char c = G.at(i);
		
		if (c == '(') 
		{
			S.push(c);
			weight *= 2;
		}
		else if (c == '[')
		{
			S.push(c);
			weight *= 3;
		}
		else if (c == ')')
		{
			//cout << S.top() << endl;
			if (S.empty()||S.top() != '(')
			{
				stop = true;
				break;
			}
        
			if (G.at(i-1) != '(' && i>0)
			{
				weight /= 2;
				S.pop();
				continue;
			}
			total += weight;
			weight /= 2;
			S.pop();
		}
		else if (c == ']')
		{
			
			if (S.empty()||S.top() != '[') //OR연산도 순서가있음! 앞에거먼저 작동!! 런타임안나려면 empty먼저 확인해야함
			{
				stop = true;
				break;
			}

			if (G.at(i-1) != '['&& i>0)
			{
				weight /= 3;
				S.pop();
				continue;
			}

			total += weight;
			weight /= 3;
			S.pop();
		}
	}

	if (stop == true || S.size() > 0) {
		cout << 0 << "\n";
	}
	else {
		cout << total << "\n";
	}


	return 0;
}
