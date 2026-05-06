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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >>n;
        vector<pair<int, int>> pts(n);
        for(int i=0; i<n; i++){
            cin>>pts[i].first>>pts[i].second;
        }
        set<tuple<int, int, int>> uq;
        // 枚舉所有點對
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = pts[i].first, y1 = pts[i].second;
                int x2 = pts[j].first, y2 = pts[j].second;
                // ax+by+c=0
                int a=y2-y1; //dy 
                int b=x1-x2; //-dx
                int c=x2*y1 - x1*y2; //截距相關項

                int g=gcd(gcd(abs(a), abs(b)), abs(c));
                // 化簡
                if(g!=0){
                    a /= g;
                    b /= g;
                    c /= g;
                }
                // 規定讓 A 永遠為正；A=0 時讓 B 永遠為正才不會重複
                if(a<0 || (a==0 && b<0)){
                    a = -a;
                    b = -b;
                    c = -c;
                }
                uq.emplace(a, b, c);
            }
        }
        cout<<uq.size()<<endl;
    }
    return 0;
}
