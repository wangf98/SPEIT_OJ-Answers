#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int result=0;
int nxt[27][27]={0};

int dfs(int n, int num, int totnum, int* tra,int* route){
  if (result!=0) return(0);
  if (tra[n]==1) {
    result=3;
    return(0);
  }
  tra[n]=1;
  route[num]=n;
  if (num == totnum){
    result=1;

    return(0);
  }
  int i;
  for (i=1;i<=nxt[n][0];i++) {
    dfs(nxt[n][i],num+1,totnum,tra,route);
    tra[nxt[n][i]]=0;
  }
}

int main(){
  int n,m,i,j;
  char c1,c2,c3;
  int num1,num2;
  int road[27][27]={0};
  int tra[27]={0};
  int route[27]={0};
  while (true) {
    cin>>n>>m;
    memset(nxt,0,sizeof(nxt));
    memset(road,0,sizeof(road));
    int printed=0;
    result=0;
    if (n==0 && m==0) break;
    for (i=1;i<=m;i++){
      cin>>c1>>c2>>c3;
      num1=(int)c1-64;
      num2=(int)c3-64;
      if (road[num1][num2]==0){
        road[num1][num2]=1;
        nxt[num1][0]++;
        nxt[num1][nxt[num1][0]]=num2;
      }
      if (result==0 && road[num2][num1]==1) {
        result=3;
      }
      if (result==0) for (j=1;j<=n;j++){
        int num=1;
        if (result!=0) break;
        for (int k=1;k<=n;k++) route[k]=0;
        for (int k=1;k<=n;k++) tra[k]=0;
        dfs(j,num,n,tra,route);
      }
      if (printed==0 && result!=0){
        if (result==3) cout<<"Inconsistency found after "<<i<<" relations."<<endl;
        if (result==1) {
          cout<<"Sorted sequence determined after "<<i<<" relations: ";
          for (j=1;j<=n;j++) cout<<(char)(route[j]+64);
          cout<<'.'<<endl;
        }
        printed=1;
      }
    }
    if (printed==0) cout<<"Sorted sequence cannot be determined."<<endl;
  }
}
