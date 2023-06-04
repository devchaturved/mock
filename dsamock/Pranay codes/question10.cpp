#include<bits/stdc++.h>
using namespace std;
#define mod 1e9
int main(){
    cout<<"enter no. of node"<<endl;
    int n; cin>>n;
    cout<<"enter np of edges"<<endl;
    int m; cin>>m;
    cout<<"enter edges and respective weight"<<endl;
    vector<pair<int,int>> adj[n];
    for(int i=0; i<m; i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int vis[n]={0};
    int sum=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            if(vis[it.first]==0)
            pq.push({it.second,it.first});
        }
    }
    cout<<sum<<endl;



}