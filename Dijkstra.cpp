/*input
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[50];

struct Node
{
	int index,dist;
/*	Node(int index, int dist)8
	{
		index=this->index;
		dist=this->dist;
	}*/
};
struct Compare{
    bool operator()(Node &a, Node &b)
    {
        return a.dist > b.dist;
    }
};

void addEdge(int a,int b,int c)
{
	adj[a].push_back(make_pair(b,c));
}

void Dijkstra(int V, int src)
{
	bool visited[V];
	int distances[V],tempDist,index;
	for(int i=0;i<V;i++)
	{
		distances[i] = INT_MAX;
        visited[i] = false;	
	}
	priority_queue<Node,vector<Node>, Compare> q;
	Node first;
	first.index=src;first.dist=0;
	distances[src]=0;
	// cout<<first.index<<endl;
    q.push(first);
	while(!q.empty())
	{
		Node x=q.top();
		q.pop();
		int index=x.index;
		visited[index]=true;
	    // cout<<"hello "<<index<<endl;
		for(int i=0;i<adj[index].size();i++)
		{
			if(!visited[adj[index][i].first])
			{
				// cout<<adj[index][i].first<<" ";
				tempDist = distances[index] + adj[index][i].second;
				// cout<<tempDist<<endl;
				// cout<<distances[adj[index][i].first]<<endl;
				if(distances[adj[index][i].first]>tempDist)
				{
					distances[adj[index][i].first]=tempDist;
					Node newNode;
					newNode.index=adj[index][i].first;
					newNode.dist=tempDist;
					// cout<<newNode.index<<" "<<newNode.dist<<endl;
					q.push(newNode);
				}
			}
		}

	}

	for(int i=0;i<V;i++)
	{
		cout<<"From "<<src<<" To "<<i<<" : "<<distances[i]<<endl;
	}
}

int main()
{
	int nodes,edges,a,b,c;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>a>>b>>c;
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	for(int i=0;i<nodes;i++)
	{
		cout<<i<<": ";
		for(int j=0;j<adj[i].size();j++)
			cout<<"-> "<<adj[i][j].first<<"("<<adj[i][j].second<<") ";
		cout<<endl;
	}
	Dijkstra(nodes,0);


		
}
