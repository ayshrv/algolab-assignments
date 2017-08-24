#include <iostream>
using namespace  std;

int search(int arr[],int x,int n)
{
    for(int i=0;i<n;i++)
      if(arr[i]==x)
         return i;
    return -1;
}
void printPostOrder(int in[],int pre[],int n)
{
   int root=search(in,pre[0],n);
   if(root!=0)
      printPostOrder(in,pre+1,root);
   if(root!=n-1)
      printPostOrder(in+root+1,pre+root+1,n-root-1);
   cout<<pre[0]<<" ";
}

int main()
{
	int in[]={5,3,1,2,7,6,8};
   	int pre[]= {2,3,5,1,6,7,8};
   	int n=sizeof(in)/sizeof(in[0]);
   	printPostOrder(in,pre,n);



}