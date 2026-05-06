#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int pos = 0;
        vector<int> a(m+1);
        for(int i=1; i<=m; i++){
            int move;
            string s;
            cin>>s;
            if(s=="LEFT"){
                a[i] = -1;
                move= -1;
            }
            else if(s=="RIGHT"){
                a[i]=1;
                move =1;
            }
            else{
                string temp; // temp string to store the AS
                int x; // x is the number of the X
                cin>>temp>>x;
                a[i] = a[x];
                move = a[x];
            }
            pos = pos+move;
            
        }
        cout<<pos<<endl;
    }
}