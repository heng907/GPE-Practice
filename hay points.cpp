#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin>>m>>n;

    // dictionary
    map<string, int> dic;
    for(int i=0; i<m; i++){
        string word;
        int value;
        cin>>word>>value;
        dic[word] = value;
    }
    // jobs
    for(int i=0; i<n; i++){
        string word;
        int salary = 0;
        while(cin>>word){
            if(word == "."){
                break;
            }
            salary = salary + dic[word];
        }
        cout<<salary<<endl;
    }
}