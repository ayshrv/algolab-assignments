/*input
1
1
*/
#include <bits/stdc++.h>
using namespace std;

void max_heapify(int Arr[],int i,int N)
{
	int largest;
    int left=2*i;
    int right=2*i+1;
    if(left<=N&&Arr[left]>Arr[i])
          largest=left;
    else
         largest=i;
    if(right<=N&&Arr[right]>Arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(Arr[i],Arr[largest]);
        max_heapify(Arr,largest,N); 
    } 
 }

void build_maxheap(int Arr[],int N)
{
    for(int i=N/2;i>=1;i--)
    {
        max_heapify(Arr,i,N);
    }
}

void heap_sort(int Arr[],int N)
{
    int heap_size=N;
    build_maxheap(Arr,N);
    for(int i = N; i>=2 ; i-- )
    {
        swap(Arr[1],Arr[i]);
        heap_size=heap_size-1;
        max_heapify(Arr,1,heap_size);
    }
}

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	heap_sort(a,n);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);	
	}


