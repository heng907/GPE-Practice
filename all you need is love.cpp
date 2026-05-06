#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
// change string to int(binary to decimal)
int trans(string s){
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        ans = ans * 2 + (s[i]-'0');
    }
    return ans;
}

int main(){
    int n;
    while(cin>>n){
        string s1;
        string s2;
        for(int i=1; i<=n; i++){
            cin>>s1>>s2;
            int n1 = trans(s1);
            int n2 = trans(s2);
            int result =0;
            result = gcd(n1, n2);
            if(result >1){
                cout<<"Pair #"<<i<<": "<<"All you need is love!"<<endl;

            }
            else{
                cout<<"Pair #"<<i<<": "<<"Love is not all you need!"<<endl;
            }
        }
    }
}