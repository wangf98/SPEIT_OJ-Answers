#include<stdio.h>
#include<string.h>
#include<math.h>
void add(int a[],int b[]){
  int c[120];
  int i,l;
  memset(c,0,sizeof(c));
  //printf("%d\n",a[a[0]]);
  if (a[0]>b[0]) l=a[0]; else l=b[0];
  for (i=1;i<=l;i++){
    if (a[0]-i+1>0) c[i]=c[i]+a[a[0]-i+1];
    if (b[0]-i+1>0) c[i]=c[i]+b[b[0]-i+1];
   // printf("%d\n",c[i]);
    if (c[i]>=10) {
      c[i+1]++;
      c[i]=c[i] % 10;
    }
  }
  if (c[l+1]>0) l++;
  for (i=l;i>=1;i--) printf("%d",c[i]);
  printf("\n");
}
void getnum(){
  int a[120],b[120];
  char ch;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  scanf("%c",&ch);
  while (ch!=' ') {
    a[0]++;
    a[a[0]]=(int)(ch)-48;
    scanf("%c",&ch);
  };
  scanf("%c",&ch);
  while (ch!='\n'){
    b[0]++;
    b[b[0]]=(int)(ch)-48;
    scanf("%c",&ch);
  }
  add(a,b);
}
int main(){
  int n,i;
  scanf("%d\n",&n);
 // printf("%d\n",n);
  for (i=1;i<=n;i++) getnum();
  printf("END\n");
}
