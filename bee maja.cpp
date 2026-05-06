#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        if(n==1){
            cout<<"0 0"<<endl;
            continue;
        }
        // 每圈的結束數字：圈 n 到 3n²+ 3n + 1 結束(1, 7, 19, 37...)
        int r = 1; // 算第幾圈
        while(3*r*r+3*r+1 < n){
            r++;
        }
        // 從後面數回來 (7,6,5,4,3,2)
        int end = 3*r*r+3*r+1;
        // 算往回幾步
        int dif = end - n;
        int x = r, y = 0;
        // 對應座標
        // (0, -1)
        for(int i=0; i<r && dif; i++){
            y--;
            dif--;
        }
        // (-1, 0)
        for(int i=0; dif && i < r; i++){
            x--; 
            dif--;
        }
        // (-1, +1)
        for(int i=0; dif && i < r; i++){
            x--; 
            y++; 
            dif--;
        }
        // (0, +1)
        for(int i=0; dif && i < r; i++){
            y++; 
            dif--;
        }
        // (+1, 0)
        for(int i=0; dif && i < r; i++){
            x++; 
            dif--;
        }
        // (+1, -1)
        for(int i=0; dif && i < r; i++){
            x++; 
            y--; 
            dif--;
        }        
        cout<<x<<" "<<y<<endl;
    }
}