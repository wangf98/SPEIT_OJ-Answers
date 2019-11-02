#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
  int sta[100],out[100];
  int n,m;
  int now,i,j,ans,flag,heada,tailsta;
  flag=0;
  while (1){
    scanf("%d",&n);
    if (n!=0){
      //flag=1;
      heada=1;
      tailsta=0;
      memset(out,0,sizeof(out));
      memset(sta,0,sizeof(sta));
      if (flag==0){
        flag=1;
        m=n;
        for (i=1;i<=m;i++) {
          scanf("%d",&out[i]);
        }
      } else {
        out[1]=n;
        for (i=2;i<=m;i++) scanf("%d",&out[i]);}
      ans=1;
      for (i=1;i<=m;i++){
        now=out[i];
        if (now==sta[tailsta]){
          sta[tailsta]=0;
          tailsta=tailsta-1;
        }
        else if (now>=heada){
          for (j=heada;j<=now;j++){
            tailsta++;
            sta[tailsta]=j;
            heada++;
          }
          if (now==sta[tailsta]){
            sta[tailsta]=0;
            tailsta=tailsta-1;
          }
        }
        else{
          ans=0;
          break;
        }
      }
    }
    else {
      if (flag!=0)printf("---\n");
      if (flag==0) break; else flag=0;
    }
    if (n!=0)
    if (ans==0) printf("No\n"); else printf("Yes\n");
  }

}
