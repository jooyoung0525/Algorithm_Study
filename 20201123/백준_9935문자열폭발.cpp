#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char>Ans;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char>remain;
	string S;
	string bomb;
	

	cin >> S;
	cin >> bomb;
	
	int bomblast = bomb.length() - 1;
	

	for (int i = 0; i < S.length(); i++) {
		
		remain.push(S[i]);

		if (S[i] == bomb[bomblast]) { //bomb와 같은거있는지 확인
			
			bool flag = true;

			string path;
			for (int j = bomblast; j >= 0; j--) {
				if (remain.empty()) {
					flag = false;
					break;
				}
				char now = remain.top();
				remain.pop();
				path += now;
				
				if (bomb[j] != now) {
					flag = false;
					break;
				}
				//cout << "1" << "\n";
			}
			if (!flag) { //bomb와 다르면 다시 알파벳 넣기
				for(int k = path.length()-1; k>=0; k--)
					remain.push(path[k]);
			}
		}
		
	}
	
	if (remain.empty()) cout << "FRULA";
	else {
	
		while (!remain.empty()) {
			Ans.push(remain.top());
			remain.pop();
		}

		while (!Ans.empty()) {
			cout << Ans.top();
			Ans.pop();
		}
	}
	return 0;
}
