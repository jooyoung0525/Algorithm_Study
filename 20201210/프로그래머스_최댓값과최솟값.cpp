#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int>Number;

string solution(string s) {
    string answer = "";
    string splitstring;
    stringstream ss(s);
    
    while(getline(ss,splitstring,' ')){
      
        int num = stoi(splitstring);
        Number.push_back(num);
    }
    
    int mmin = *min_element(Number.begin(),Number.end());
    int mmax = *max_element(Number.begin(),Number.end());
    
    answer=to_string(mmin)+' '+to_string(mmax);
    return answer;
}
