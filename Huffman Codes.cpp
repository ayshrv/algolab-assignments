/*input
5
a 15
b 10
c 180
d 65
e 20
*/
#include <bits/stdc++.h>
using namespace  std;

struct Node
{
    int freq;
    char data;
    Node *Left,*Right;

    Node(char data, int freq)
    {
        this->freq=freq;
        this->data=data;
        Left=NULL;
        Right=NULL;
    }
    Node(Node* Left, Node* Right)
    {
        this->freq=Left->freq+Right->freq;
        this->Left=Left;
        this->Right=Right;
    }
};

struct Compare{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

int isLeaf(Node* a)
{
    return !(a->Left) && !(a->Right);
}

void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
    printf("\n");
}
void printCodes(Node* ptr, int arr[], int x)
{
    if(ptr->Left)
    {
        arr[x]=0;
        printCodes(ptr->Left,arr, x+1);
    }
    if(ptr->Right)
    {
        arr[x]=1;
        printCodes(ptr->Right,arr, x+1);
    }
    if(isLeaf(ptr))
    {
        printf("%c: ",ptr->data);
        printArr(arr,x);
    }
}

int main()
{
    int n;
    cin>>n;
    char arr[n+1];
    int freq[n];
    for(int i=0;i<n;i++)
    {
        scanf(" %c %d",&arr[i],&freq[i]);   
    }
    int codes[1000000];
    priority_queue<Node*,vector<Node*>, Compare> q;
    for(int i=0;i<n;i++)
    {
        Node* temp=new Node(arr[i],freq[i]);   
        q.push(temp);
    }
    while(q.size()>1)
    {
        Node* l=q.top();
        q.pop();
        Node* r=q.top();
        q.pop();
        Node* newNode=new Node(l,r);
        q.push(newNode);
    }
    Node* z=q.top();
    printCodes(z,codes,0);
}