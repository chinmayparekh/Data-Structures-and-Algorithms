#include<bits/stdc++.h>

using namespace std;

int arr[10000000];

/* swaps arr[i] with arr[j] (considering 0 based indexing)*/
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* function which puts the element in arr[end] in arr[i]
while ensuring that elements from arr[start] to arr[i-1] are lesser than or equal to arr[i],
and that elements from arr[i+1] to arr[end] are greater than arr[i].
This function returns the value of i. Here, 0 based indexing is used.
Eg) given arr = [4,1,0,6,2,3], partition(arr,1,4) will change arr to
[4,1,0,2,6,3] and will return the position of 2 which is 3 */ 
int partition (int arr[], int start, int end){
    int pivot =arr[start];
    int i=start+1;
    int j=end;
    while(i<=j)
    {
        while(arr[i]<=pivot && i<=j)
        i++;
        while(arr[j]>pivot && i<=j)
        j--;
        if(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }
    i--;
    arr[start]=arr[i];
    arr[i]=pivot;
    return i;

}


/* function which returns the k+1 smallest element in arr (the element in arr[k] after sorting arr) using partition.
Note: arr need not be sorted completely to return the k+1 smallest element*/
int findRank(int arr[], int start, int end, int rank){
    if(start<end)
    {
        int p=rand()%(end-start+1)+start;
        swap(arr[start],arr[p]);
        int k=partition(arr,start,end);
        if(rank==end-k+1)
            return k;
        else if(rank<end-k+1)
            return findRank(arr,k+1,end,rank);
        else
            return findRank(arr,start,k-1,rank-end+k-1);

    }
    return end;

}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) 
    cin >> arr[i];
    int index=findRank(arr,0,n-1,k);
    long long ans = 0;
    for(int i=index;i<n;i++)
    {
	   ans+=arr[i];
    }  
    cout << ans << endl;
    return 0;
}