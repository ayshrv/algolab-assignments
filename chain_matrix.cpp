/*input
5
40 20 30 10 30
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> r;
vector<vector<int> > cost;
vector<vector<int> > factor;

void calculateCost() {
    // int q;
    // for (int L=2; L<n; L++)   
    // {
    //     for (int i=1; i<=n-L+1; i++)
    //     {
    //         int j = i+L-1;
    //         int part=i;
    //         cost[i][j] = INT_MAX;
    //         for (int k=i; k<=j-1; k++)
    //         {
    //             // q = cost/scalar multiplications
    //             q = cost[i][k] + cost[k+1][j] + r[i-1]*r[k]*r[j];
    //             if (q < cost[i][j])
    //             {
    //                 cost[i][j] = q;
    //                 part=k;
    //             }
    //         }
    //         factor[i][j]=part;
    //     }
    // }
    for(int p = 2;p <=n;p++) {
        int i = 1, j = p;
        while(i <= n and j <= n) {

            int part = i;
            int minCost = INT_MAX;

            for(int k = i;k < j;k++) {
                int newCost =    cost[i][k] + cost[k+1][j] + r[i-1]*r[j]*r[k];
                if(newCost < minCost) {
                    minCost = newCost;
                    part = k;
                }

            }

            if(i != j) {
                cost[i][j] = minCost;
                // cout<<i<<" "<<j<<" "<<cost[i][j]<<endl;
                factor[i][j] = part;
            // cout<<minCost<<endl;
            }
            i++;j++;
        }
    }
}

void showBracket(int i, int j) {
    if(i == j) {
        cout<<"M"<<i<<"";
        return;
    }

    int k = factor[i][j];

    cout<<"(";
    showBracket(i,k);
    cout<<"*";
    showBracket(k+1, j);
    cout<<")";
}


int main()
{
    cout << "Enter the number of matrices: ";
    cin>>n;

    cout<<"Enter the dimension of matrices\n";

    r = vector<int>(n+1, 0);
    cost = vector<vector<int> >(n+1, vector<int>(n+1, 0));
    factor = vector<vector<int> >(n+1, vector<int>(n+1, 0));

    for(int i = 0;i < n+1;i++) cin>>r[i];

    calculateCost();
    // cout<<m<<endl;
    showBracket(1, n);

    return 0;
}
