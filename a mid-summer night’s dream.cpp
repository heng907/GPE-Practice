#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> num(n);
        for(int i=0; i<n; i++){
            cin>>num[i];
        }
        // 要把數列先由小到大排好
        sort(num.begin(), num.end());
        // mid1: 比較小的中間值
        // mid2: 比較大的中間值
        int mid1 = num[(n-1)/2];
        int mid2 = num[n/2];
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(num[i]==mid1 || num[i]==mid2){
                cnt++;
            }
        }
        cout<<mid1<<" "<<cnt<<" "<<mid2-mid1+1<<endl;
    }
}