#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define defaultsize 200
using namespace std;

template <class elem> class List {
  public:
    virtual void clear() = 0;
    virtual bool insert(const elem&) = 0;
    virtual bool append(const elem&) = 0;
    //virtual bool remove(elem&) = 0;
    virtual void setStart() = 0;
    virtual void setEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    //virtual int leftlength() const= 0;
    //virtual int rightlength() const= 0;
    //virtual bool setPos(int pos) = 0;
    //virtual bool getValue(elem&) const= 0;
    virtual void print() const= 0;
    virtual ~List(){};
};

template <class elem> class Alist:public List<elem> {
  private:
    long int maxSize;
    long int listSize;
    long int fence;
    elem* listArray;
  public:
   // Alist();
    Alist(long int size){
      maxSize = size;
      listSize = fence = 0;
      listArray = new elem[maxSize];
    }
    ~Alist(){
      delete [] listArray;
    }
    void clear(){
      delete [] listArray;
      listSize=fence=0;
      listArray=new elem[maxSize];
    }
    void setStart(){
      fence=0;
    }
    void setEnd(){
      fence = listSize;
    }
    void prev(){
      if (fence != 0) fence--;
    }
    void next(){
      if (fence <= listSize) fence++;
    }
    bool insert(const elem& item);
    bool append(const elem& item);
    void print()const;
    void joint(Alist<elem>& b);
};

template<class elem>
bool Alist<elem>::insert(const elem& item) {
  if(listSize==maxSize) return false;
  for(int i=listSize; i>fence; i--)
    listArray[i]=listArray[i-1];
  listArray[fence]=item;
  listSize++;
  return true;
}

template <class elem>
bool Alist<elem>::append(const elem& item) {
  if (listSize == maxSize) return false;
  listArray[listSize++] = item;
  return true;
}

template <class elem>
void Alist<elem>::print() const {
  long int i;
  for (i=0;i<listSize;i++) cout<<listArray[i];
  cout<<endl;
}

template <class elem>
void Alist<elem>::joint(Alist<elem>& b){
  Alist<elem> c(400);
  long int i,m;
  for (i=b.listSize-1;i>=0;i--) c.insert((elem) b.listArray[i]);
  for (i=listSize-1;i>=0;i--) m=c.insert((elem) listArray[i]);
  c.print();
}

int main(){
  long int n,i,j,l1,l2;
  char aa[200],bb[200];
  char ch;
  cin>>n;
  for (j=1;j<=n;j++){
    Alist<char> a(200);
    Alist<char> b(200);
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    cin>>aa;
    cin>>bb;
    l1=strlen(aa);
    //cout<<l1<<endl;
    l2=strlen(bb);
    for (i=l1;i>=1;i--) a.insert((char) aa[i-1]);
    for (i=l2;i>=1;i--) b.insert((char) bb[i-1]);
    a.joint(b);
    a.clear();
    b.clear();
  }
}
