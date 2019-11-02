#include<cstdio>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iostream>
#define M 21474836487
using namespace std;

int changech(char c){
  switch (c){
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    case 'T':
      return 3;
    default :
      return 0;
  }
}

inline int ha(string str){
  long long int h=0;
  bitset<32> hh;
  int i;
  for (i=0;i<10;i++){
    h=h<<2 | changech(str[i]);
  }
  hh=h;
  return hh.to_ulong();
}

int main(){
  int j,n,i,k,pos;
  int tot,totans;
  long long int hashnum;
  string str,tmpstr;
  cin>>n;
  for (i=1;i<=n;i++){

    int tab[1000]={0};
    long long int val[1000]={0};
    cin>>str;
    tot=0;
    totans=0;
    cout<<'[';
    if (str.length()>10)
    for (j=0;j<str.length()-9;j++){
        tmpstr=str.substr(j,10);
        //cout<<tmpstr<<endl;
        hashnum=ha(tmpstr);
        //cout<<hashnum<<endl;
        pos=-1;
        for (k=1;k<=tot;k++){
          if (hashnum==val[k]){
            pos=k;
            tab[k]++;
            if (tab[k]==2) {
              totans++;
              if (totans==1) for (k=0;k<10;k++) cout<<tmpstr[k];
              else {
                cout<<',';
                for (k=0;k<10;k++) cout<<tmpstr[k];
              }
            }
          }
        }
        if (pos==-1) {
          tot++;
          tab[tot]=1;
          val[tot]=hashnum;
        }
    }
    cout<<"]\n";
  }
  return(0);
}
