#include<bits/stdc++.h>
using namespace std;

vector<string> tokens;
int idx;
bool illegal;

long long solve(){
    if(idx >= (int)tokens.size()){
        illegal = true;
        return 0;
    }

    string tok = tokens[idx];
    idx++;

    if (tok == "+" || tok == "-" || tok == "*" || tok == "/" || tok == "%") {
        long long left = solve();
        if (illegal) return 0;
        long long right = solve();
        if (illegal) return 0;
        
        if (tok == "+") return left + right;
        if (tok == "-") return left - right;
        if (tok == "*") return left * right;
        if (tok == "/" || tok == "%") {
            if (right == 0) { illegal = true; return 0; }
            if (tok == "/") return left / right;
            if (tok == "%") return left % right;
        }
    }

    return stoll(tok);
}

int main(){
    string line;
    while(getline(cin, line)){
        if(line == ".") break;

        tokens.clear();
        idx=0;
        illegal = false;

        istringstream iss(line);
        string tok;
        while(iss >> tok){
            tokens.push_back(tok);
        }

        long long result = solve();
        if(illegal || idx != (int)tokens.size()){
            cout<<"illegal"<<endl;
        }
        else{
            cout<<result<<endl;
        }
    }
    return 0;
}