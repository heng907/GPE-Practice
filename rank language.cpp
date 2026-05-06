#include<bits/stdc++.h>
using namespace std;

char Map[1000][1000]={0};
bool visited[1000][1000] = {0};

void dfs(int x, int y){
    visited[x][y]=1;
    if(Map[x+1][y]==Map[x][y] && visited[x+1][y] == 0){
        dfs(x+1, y);
    }
    if(Map[x-1][y]==Map[x][y] && visited[x-1][y] == 0){
        dfs(x-1, y);
    }
    if(Map[x][y+1]==Map[x][y] && visited[x][y+1] == 0){
        dfs(x, y+1);
    }
    if(Map[x][y-1]==Map[x][y] && visited[x][y-1] == 0){
        dfs(x, y-1);
    }
}

int main(){
    int t;
    cin >> t;
    for(int N = 1; N<=t; N++){
        int m ,n;
        cin >> m >> n;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>Map[i][j];
            }
        }

        map<char, int> area;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]==0){
                    char temp = Map[i][j];
                    area[temp]++;
                    dfs(i, j);
                }
            }
        }

        vector<pair<int, char>> ans;
        for(auto& [lang, cnt]: area){
            ans.push_back({cnt, lang});
        }

        sort(ans.begin(), ans.end(), [](auto& a, auto& b){
            if (a.first != b.first) return a.first > b.first;  // 州數不同 → 大的排前面
            else return a.second < b.second; // 州數相同 → 字母小的排前面
        });

        cout<<"World #"<<N<<endl;
        for(auto& [cnt, lang]:ans){
            cout<<lang<<": "<< cnt <<endl;
        }
    }
}