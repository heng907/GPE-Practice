#include <bits/stdc++.h>
using namespace std;

int sol(int n, int m){
    vector<int> regions;
    // initialized list
    for(int i=1; i<=n; i++){
        regions.push_back(i);
    }
    // eliminate
    int index = 0;
    // always close the first power factory
    regions.erase(regions.begin());
    while(regions.size() > 1){
        // count the index
        index = (index + m - 1) % regions.size();
        regions.erase(regions.begin() + index);
        // 如果idx == size()，要繞回0
        if(index == regions.size()){
            index = 0;
        }
    }
    return regions[0];

}


int main(){
    int n;
    while(cin>>n){
        if(n == 0) break;
        int m = 1;
        while(sol(n, m) != 13){
            m++;
        }
        cout << m << endl;
    }
}