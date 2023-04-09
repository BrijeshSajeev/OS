#include<iostream>

using namespace std;

int main() {
  int n,base_add[20],limit[20],range[20];
  cout<<"Enter no of segments in logical memory >> ";
  cin>>n;
  
  for(int i=0;i<n;i++){
      cout<<"Enter the limit of segment "<<i+1<<" >> ";
      cin>>limit[i];
      cout<<"Enter base address of segment "<<i+1<<" >> ";
      cin>>base_add[i];
      range[i] = base_add[i] + limit[i];
  }
  
  cout<<"\nSEGMNETS\tLIMIT\t\tRANGE";
  for(int i=0;i<n;i++){
      cout<<endl;
      cout<<i+1<<"\t\t\t"<<limit[i]<<"\t\t"<<base_add[i]<<"-"<<range[i];
  }
  
  
}
