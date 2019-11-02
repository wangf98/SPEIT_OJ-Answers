#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

class bigInteger
{
private:
    int data[502];
public:
    bigInteger()
    {
        //length = 1;
        memset(data, 0, sizeof(data));
    }
    bigInteger(const char* l);
    int compare(bigInteger n2);
    bigInteger& operator=(const bigInteger &);
    bigInteger operator+(const bigInteger &);
    bigInteger operator-(const bigInteger &);
    bigInteger operator*(const bigInteger &);
    void show();
};

bigInteger::bigInteger(const char* l){
  int i;
  memset(data, 0, sizeof(data));
  data[0]=strlen(l);
  for (i=1;i<=data[0];i++) {
    data[data[0]-i+1]=(int)(l[i-1])-48;
    }
};

bigInteger bigInteger::operator+(const bigInteger &n2){
   int tmp[502];
   memset(tmp, 0, sizeof(tmp));
   int i,maxl;
   if (this->data[0]<n2.data[0]) maxl=n2.data[0]; else maxl=this->data[0];
   for (i=1;i<=maxl;i++){
      tmp[i]=tmp[i]+data[i]+n2.data[i];
      if (tmp[i]>=10) {
        tmp[i+1]=tmp[i+1]+tmp[i]/10;
        tmp[i]=tmp[i]%10;
      }
   }
   if (tmp[maxl+1]>0) tmp[0]=maxl+1; else tmp[0]=maxl;
   for (i=0;i<=maxl+1;i++) data[i]=tmp[i];
   return(*this);
};

int bigInteger::compare(bigInteger n2){
  if (data[0]>n2.data[0]) return(1);
  if (data[0]<n2.data[0]) return(0);
  int i;
  for (i=data[0];i>=1;i--){
    if (data[i]<n2.data[i]) return(0);
    if (data[i]>n2.data[i]) return(1);
  }
  return(2);
}

bigInteger bigInteger::operator-(const bigInteger &n2){
  int i;
  int tmp[502];
  memset(tmp,0,sizeof(tmp));
  for (i=1;i<=data[0];i++){
    if (data[i]+tmp[i]<n2.data[i]){
      tmp[i+1]=tmp[i+1]-1;
      tmp[i]=10+tmp[i];
    }
  tmp[i]=tmp[i]+data[i]-n2.data[i];
  }
  tmp[0]=data[0];
  for (i=0;i<=tmp[0];i++) data[i]=tmp[i];
  for (i=tmp[0];i>=1;i--) if (data[i]==0) tmp[0]--; else break;
  return(*this);
}

bigInteger bigInteger::operator*(const bigInteger &n2){
  int tmp[502];
  memset(tmp, 0, sizeof(tmp));
  int i,j,now,flag;
  for (i=1;i<=data[0];i++)
    for (j=1;j<=n2.data[0];j++){
      now=i+j-1;
      tmp[now]=tmp[now]+data[i]*n2.data[j];
      if (tmp[now]>=10) {
        tmp[now+1]=tmp[now+1]+tmp[now]/10;
        tmp[now]=tmp[now]%10;
      }
    }
  if (tmp[now+1]>0) data[0]=now+1; else data[0]=now;
  flag=0;
  for (i=1;i<=now+1;i++){
    data[i]=tmp[i];
    if ((data[i]>0)&(flag==0)) flag=1;
  }
  if (flag==0) data[0]=1;
  return(*this);
}

bigInteger &bigInteger::operator=(const bigInteger &bi){
  int i;
  memset(data, 0, sizeof(data));
  for (i=0;i<=bi.data[0];i++){
    data[i]=bi.data[i];
    }
  return(*this);
};

void bigInteger::show(){
  int i;
  for (i=data[0];i>=1;i--) printf("%d",data[i]);
  printf("\n");
}

int main(void)
{
    int i, n;
    char op;
    char num1[501] = {0};
    char num2[501] = {0};
    while (cin >> num1 >> op >> num2)
    {
        bigInteger a(num1), b(num2), c;
    //    a.show();
    //    b.show();
        int flag=0;
        switch (op)
        {

            case '+':
                c=a + b;
                break;
            case '-':
                  flag=a.compare(b);
                //  cout<<flag<<endl;
                  if (flag==0){
                    cout<<'-';
                    c=b-a;
                  }
                  else if (flag==1)c = a - b;
                break;
            case '*':
                c = a * b;
                break;
        }
        if (flag==2) cout<<'0'<<endl; else c.show();
        flag=0;
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
    }
}
