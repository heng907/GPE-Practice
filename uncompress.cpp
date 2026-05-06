#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> wordlist;
    char ch;
    string buffer = ""; // 存特定字
    while(cin.get(ch)){
        if(isalpha(ch) || isdigit(ch)){
            buffer += ch;
        }
        else{
            // if buffer is not empty
            if(!buffer.empty()){
                if(isalpha(buffer[0])){
                    // if buffer is word
                    cout<<buffer;
                    wordlist.insert(wordlist.begin(), buffer);
                }
                else{
                    // if buffer is number
                    int index = stoi(buffer); // transfer string into int
                    if(index == 0) return 0;

                    string s = wordlist[index-1];
                    cout<<s;
                    wordlist.erase(wordlist.begin() + index -1);
                    wordlist.insert(wordlist.begin(), s);
                }
                buffer = ""; // clear buffer for next token
            }
            cout << ch; // 其他非字母、數字得標點符號
        }
    }
}