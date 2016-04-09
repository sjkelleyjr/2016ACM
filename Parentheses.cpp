#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//return strings of yes and no, rather than true false
string isValid(string cand){
	stack<char> lefts;
	stack<char> rights;
	for(int i = 0;i<cand.length();i++){
		if (cand[i] == '(') {
			lefts.push('(');
		}else{
			rights.push(')');
			//if the left stack is smaller than the right
			//unbalanced
			if(lefts.size()<rights.size()){
				return "no";
			}
			//otherwise we can take off a pair of parenthesis.
			lefts.pop();
			rights.pop();
		}
	}
	if(lefts.empty() && rights.empty()){
		return "yes";
	}else{
		return "no";
	}
}

int main(){
	int k;
	cin >> k;
	string statement;
	vector<string> candidates;
	for(int i = 0;i<k;i++){
		cin >> statement;
		candidates.push_back(statement);
	}
	for(int i = 0;i<k;i++){
		cout << isValid(candidates[i]) << endl;
	}

}
