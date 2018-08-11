#include<iostream>
#include<string>
using namespace std;
int main(){
   int a,b,c=0,d,z=0,max=0;
   string maxn,name,bgb,xb;
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
        cin>>name>>a>>b>>bgb>>xb>>d;
        if(a>80&&d>=1) c+=8000;
        if(a>85&&b>80) c+=4000;
        if(a>90) c+=2000;
        if(a>85&&xb=="Y") c+=1000;
        if(b>80&&bgb=="Y") c+=850;
        z=z+c;
        if(c>max||(c==0&&c==max)){
            max=c;
            maxn=name;
        }
        c=0;
    }
   cout<<maxn<<endl<<max<<endl<<z;
   return 0;
}
