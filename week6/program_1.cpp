#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};


// function to get a new node
Node* getNode(int data)
{
    // Allocate memory
    Node *newNode =
        (Node*)malloc(sizeof(Node));
      
    // put in the data    
    newNode->data = data;
    newNode->left = newNode->right = NULL;    
    return newNode;
}
  
Node* constructBst(int arr[], int start, int end)
{
    if(start > end) return NULL;
    int mid = (start+end)/2;
    Node* root = getNode(arr[mid]);
    root-> left = constructBst(arr,start,mid-1);
    root->right = constructBst(arr,mid+1,end);      
    return root;
}

void inorderTraversal(Node* root)
{
    /* TO DO */  
    if(root !=NULL)
    {
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

Node* solve(Node* root,int* sum) {
    if(root==NULL)
        return 0;
    solve(root->right,sum);
    *sum=*sum+root->data;
    root->data=*sum;
    solve(root->left,sum);
    return root;
}


int main(){
    int n;int sum=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    Node *root = constructBst(arr,0,n-1);
    inorderTraversal(solve(root,&sum));
    cout << endl;
    return 0;
}
