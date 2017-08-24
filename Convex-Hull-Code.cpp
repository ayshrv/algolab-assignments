/*input
9
5 0
-5 0
-4 3
2 4
-1 1
4 3
-2 -3
2 -2
4 -5
*/
#include <iostream>
#include <fstream>
using namespace std;

//[(-5, 0), (-4, 3), (-2, -3), (2, 4), (4, -5), (4, 3), (5, 0)]
struct node{
    node* prev;
    node* next;
    int x;
    int y;
}*head;

int area(node* one, node* two, node*three){
    int x1 = one->x;
    int y1 = one->y;
    int x2 = two->x;
    int y2 = two->y;
    int x3 = three->x;
    int y3 = three->y;
    return (x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2));
}

node* makeHull(int points[][2], int start, int end){
    struct node* hullHead = new node;
    if(start==end || start>end)
        return NULL;
    if(end-start==1){
        hullHead->x = points[start][0];
        hullHead->y = points[start][1];
        hullHead->next = NULL;
        hullHead->prev = NULL;
        return hullHead;
    }
    int mid = (start+end)/2;
    struct node* left = makeHull(points, start, mid);
    struct node* right = makeHull(points, mid, end);
    struct node* cur, *leftmax, *rightmin;
    cur = left;
    leftmax = left;
    int xmax = -1000;
    int xmin = 1000;
    int count = 0;
    while(count < mid-start){
        count++;
        if(cur->x > xmax){
            leftmax = cur;
            xmax = cur->x;
            cur = cur->next;
        }
    }
    count = 0;
    cur = right;
    rightmin = right;
    while(count < end-mid){
        count++;
        if(cur->x < xmin){
            xmin = cur->x;
            rightmin = cur;
            cur = cur->next;
        }
    }
    struct node* templeft, *tempright;
    templeft = leftmax;
    tempright = rightmin;
    while(1){
        while(1){
            if(tempright->next== NULL)
                break;
            if(area(templeft, tempright, tempright->next) < 0){
                break;
            }
            else{
                tempright = tempright->next;
            }
        }
        if(templeft->prev== NULL)
            break;
        if(area(templeft->prev, templeft, tempright)<0 ){
            break;
        }
        else{
            templeft = templeft->prev;
        }
    }
    struct node* templ1, *templ2;
    templ1 = templeft;
    templ2 = tempright;

    templeft = leftmax;
    tempright = rightmin;
    while(1){
        while(1){
            if(tempright->prev== NULL)
                break;
            if(area(templeft, tempright, tempright->prev) > 0){
                break;
            }
            else{
                tempright = tempright->prev;
            }
        }
        if(templeft->next==NULL)
            break;
        if(area(templeft->next, templeft, tempright)>0 ){
            break;
        }
        else{
            templeft = templeft->next;
        }
    }
    templ1->next = templ2;
    templ2->prev = templ1;
    templeft->prev= tempright;
    tempright->next = templeft;
    return templ2;
}

int main() {
    int x = -1;
    int y = 0;

    cout<<"Enter n value : "<<endl;
    int n;
    cin>>n;
    int points[n][2];
    cout<<"Enter x and y of elements one by one : \n";
    for(int i=0; i<n; i++){
        cin>>points[i][0]>>points[i][1];
    }

    head = NULL;
    head = makeHull(points, 0, n);
    struct node* mainhead = head;
    cout<<head->x<<" "<<head->y<<endl;
    int t_x=head->x;
    int t_y=head->y;
    head=head->next;

    while (head!=NULL&&t_x!=head->x&&t_y!=head->y) {
        cout<<head->x<<" "<<head->y<<endl;
        head = head->next;
    }
    return 0;
}
