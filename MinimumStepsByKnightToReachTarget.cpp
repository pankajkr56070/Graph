#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,int n,int m){
  if(x >= 0 && x < n && y >= 0 && y < m)
    return true;
  else
    return false;
}

int dir_col[8]={2,2,1,1,-1,-1,-2,-2};
int dir_row[8]={1,-1,2,-2,2,-2,1,-1};

int move(int curr_row,int curr_col,int des_row,int des_col,int n,int m){

int minCount=INT_MAX;
queue<pair<int,pair<int,int> > >qp;
bool visited[n][m]={false};
qp.push(make_pair(0,make_pair(curr_row,curr_col)));
visited[curr_row][curr_col]=true;
while(!qp.empty()){
    int dis=qp.front().first;
    int x=qp.front().second.first;
    int y=qp.front().second.second;
    cout<<"x: "<<x<<" "<<"y: "<<y<<" "<<"Distance: "<<dis<<endl;
    if(x == des_row && y == des_col){
        //minCount=min(minCount,dis);
        //cout<<"Count: "<<minCount<<endl;
        return dis;
    }
    qp.pop();
    for(int i=0;i < 8;i++){
        if(isSafe(x+dir_row[i],y+dir_col[i],n,m)&& !visited[x+dir_row[i]][y+dir_col[i]]){
            visited[x+dir_row[i]][y+dir_col[i]]=true;
            qp.push(make_pair(dis+1,make_pair(x+dir_row[i],y+dir_col[i])));
    }
    }
}
//return minCount;
}

int main(){
int t;
cin>>t;
while(t--){
  int n,m;
  cin>>n>>m;
    //int minCount=INT_MAX;
  int curr_row,curr_col,des_row,des_col;
  cin>>curr_row>>curr_col>>des_row>>des_col;
  cout<<move(curr_row,curr_col,des_row,des_col,n,m)<<endl;
  //cout<<minCount<<endl;
}
 return 0;
}
