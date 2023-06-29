#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class Solution {
    public:
        void find(int i,int j,vector<string>&grid,string &s, vector<vector<unordered_set<string>>>&vis, queue< pair <  pair<int,int>, string  > >&qmt,int m,int n){
            if(i>=m||i<0||j>=n||j<0)return;
            if(grid[i][j]=='#')return;



            if(grid[i][j]>='a'&&grid[i][j]<='z')
            {
                string tmp=s;

                int flg=0;
                for(auto&p:tmp)if(p==grid[i][j])flg=1;
                if(flg==0)
                    tmp.push_back(grid[i][j]);
                sort(tmp.begin(),tmp.end());
                if(vis[i][j].find(tmp)!=vis[i][j].end())return;
                vis[i][j].insert(tmp);
                qmt.push({ {i,j},tmp});
                return;
            }
            if(grid[i][j]=='.'||grid[i][j]=='@')
            {
                string tmp=s;
                if(vis[i][j].find(tmp)!=vis[i][j].end())return;
                vis[i][j].insert(tmp);
                qmt.push({ {i,j},tmp});
                return;
            }
            if(grid[i][j]>='A'&&grid[i][j]<='Z')
            {
                string tmp=s;
                char t=grid[i][j]+32;
                int flg=0;
                for(auto&p:tmp)if(p==t)flg=1;
                if(flg==0)return;

                if(vis[i][j].find(tmp)!=vis[i][j].end())return;
                vis[i][j].insert(tmp);
                qmt.push({ {i,j},tmp});
            }
        }

        int shortestPathAllKeys(vector<string>& grid) 
        {
            int m=grid.size(),n=grid[0].size(),cntk=0,strti,strtj;
            vector<vector<unordered_set<string>>>mp
                (m,vector<unordered_set<string>> (n, unordered_set<string> {}));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]=='@')
                    {
                        strti=i;strtj=j;
                    }
                    if(grid[i][j]>='a'&&grid[i][j]<='z')cntk++;
                }
            }
            int ans=-1;
            queue< pair <  pair<int,int>, string > >qmt;
            qmt.push({{strti,strtj},""});
            while(qmt.size()>0)
            {
                ans++;
                int sz=qmt.size();

                for(int k=0;k<sz;k++)
                {
                    pair< pair<int,int>,string >p=qmt.front();
                    qmt.pop();
                    int i=p.first.first,j=p.first.second;
                    string s=p.second;

                    if(s.size()==cntk)return ans;
                    find(i+1,j,grid,s,mp,qmt,m,n);
                    find(i-1,j,grid,s,mp,qmt,m,n);
                    find(i,j+1,grid,s,mp,qmt,m,n);
                    find(i,j-1,grid,s,mp,qmt,m,n);
                }
            }
            return -1;
        }
};


int main (int argc, char *argv[]) {
    cout<< " Hello world"<<endl;
    return 0;
}
