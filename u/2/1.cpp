#include<iostream>
#include<omp.h>

using namespace std;
int check(char* text,char* patt,int t,int p,int j){
int s = 0,i;
#pragma omp for
for(i=j;i<j+p;i++)
if(text[i]==patt[i-j])
s++;
if(s==p)
return 1;
return 0;
}

int main(){

int t,p;
cout<<"Length of Text : ";
cin>>t;
char text[t];
cout<<"Enter the Text :";
cin>>text;

cout<<"Length of Pattern : ";
cin>>p;
char patt[p];
cout<<"Enter the Pattern : ";
cin>>patt;

int start = 0,end = t-p,i,ans=0;
#pragma omp for
for(i=start;i<=end;i++)
if(check(&text[0],&patt[0],t,p,i)==1)
ans++;
cout<<ans<<endl;
return 0;
}
