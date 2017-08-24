/*input
4
0 12 5 7
11 0 13 6
4 9 0 18
10 3 2 0
*/
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define ss(x) scanf("%s",x);
#define sc(x) scanf("%c",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define pc1(x) cout<<x<<" "<<endl;
#define pc2(x,y) cout<<x<<" "<<y<<" "<<endl;
#define pc3(x,y,z) cout<<x<<" "<<y<<" "<<z<<" "<<endl;
#define pc4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl;
#define pce(x) cout<<x<<endl;
#define ps0() cout<<endl;
#define ps1(x) cout<<#x<<" ";
#define ps2(x,y) cout<<#x<<" "<<y<<" "<<endl;
#define ps3(x,y,z) cout<<#x<<" "<<y<<" "<<z<<" "<<endl;
#define ps4(w,x,y,z) cout<<#w<<" "<<x<<" "#y<<" "<<z<<" "<<endl;
#define pse(x) cout<<#x<<endl;
#define GET_MACRO(_0, _1, _2, _3, _4, NAME, ...) NAME
#define GET_MACRO1(_1, _2, _3, _4, NAME, ...) NAME
#define ps(...) \
		do{if (DEBUG) GET_MACRO(_0, ##__VA_ARGS__, ps4, ps3, ps2, ps1, ps0)(__VA_ARGS__)} while(0);
#define pc(...) \
 		do{if (DEBUG) GET_MACRO1(__VA_ARGS__, pc4, pc3, pc2, pc1)(__VA_ARGS__)} while(0);
#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI; 

#define DEBUG 0
struct node
{
	int cost,index,flag;
	VI left,done;
};
struct Compare{
    bool operator()(node a, node b)
    {
        return a.cost > b.cost;
    }
};

int main()
{
	int n,z;
	sd(n)
	int cost_matrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sd(cost_matrix[i][j])
		}
	}	
		ps(helasaslo)
	node x,k;
	x.cost=0;
	x.index=0;
	x.flag=0;
	for(int i=1;i<n;i++)
	{
		x.left.PB(i);
	}
	x.done.PB(0);
    priority_queue<node,vector<node>, Compare> q;
    q.push(x);
	while(1)
	{
		k=q.top();
		q.pop();
		ps(index,k.index)
		ps(cost,k.cost)
		if(k.left.size()==0&&k.flag==1)
		{

			// ps(yoyo)
			break;
		}
		if(k.left.size()==0)
		{
			// ps(ypoyoyoyoyoyo)
			// pc(k.cost)
			k.cost+=cost_matrix[k.index][0];
			k.index=0;
			k.done.PB(0);
			k.flag=1;
			q.push(k);
		}
		else
		{
			for(int i=0;i<k.left.size();i++)
			{
				node a;
				a.flag=0;
				a.index=k.left[i];
				a.cost=k.cost+cost_matrix[k.index][k.left[i]];
				for(int j=0;j<k.left.size();j++)
				{
					z=k.left[j];
					if(z!=k.left[i])
						a.left.PB(z);
				}
				for(int j=0;j<k.done.size();j++)
				{
					a.done.PB(k.done[j]);
				}
				a.done.PB(a.index);
				q.push(a);
			}
		}
	}
	pc(k.cost)
	cout<<"Cost "<<k.cost<<endl;
	cout<<"Path: ";
	for(int i=0;i<k.done.size();i++)
	{
		cout<<k.done[i]+1<<" ";
	}

}
