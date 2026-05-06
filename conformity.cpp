#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n;
    while(cin>>n&&n){
        // 找 course 組合
        map<vector<int>, int> cnt;
        for(int i=0; i<n; i++){
            vector<int> courses(5);
            for(int j=0; j<5; j++){
                
                cin>>courses[j];
            }
            sort(courses.begin(), courses.end());
            cnt[courses]++;
        }
        // 找最多人修的課(可能很多堂一樣人數)
        int maxi=0;
        for(auto& i : cnt){
            maxi = max(maxi, i.second);
        }
        // 把所有人數一樣的popular課人數總和
        int ans =0;
        for(auto& i :cnt){
            if(i.second == maxi){
                ans+=i.second;
            }
        }
        cout << ans<<endl;
        
    }
    return 0;
}