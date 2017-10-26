#include<iostream>
#include<omp.h>
using namespace std;

int main(int argc, char const *argv[]) {

  int i,l,j,k;
  cin>>l;
  int array[l];
  for(i=0;i<l;i++)
    cin>>array[i];

  #pragma omp for
  for (i = 0; i < l; i++)
    for (j = i; j < l; j++)
      if(array[i]<array[j]){
        k = array[i];
        array[i] = array[j];
        array[j] = k;
      }

  for(i=0;i<l;i++)
    cout<<array[i]<<" ";
    cout<<endl;
  cout<<"Second Largest Number is "<<array[1]<<endl;

  return 0;
}
