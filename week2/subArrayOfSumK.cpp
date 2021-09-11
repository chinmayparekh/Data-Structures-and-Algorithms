#include<bits/stdc++.h>
using namespace std;

struct Hashing
{
	unordered_map<int,int> hashmap;
	// Used to insert a value with key.
	void insert(int key, int val)
	{
		hashmap[key]=val;
	}
    // Used ro delete key from hash table.
	void delete_key(int key)
	{
		if(hashmap.count(key))	
			hashmap.erase(key);
	}
    // used to get value using key. Returns 0 if key not present. 
	int get_val(int key)
	{
		return hashmap[key];
	}
};

int solve(int n,int arr[], int k){
int sum=0;
int count=0;
struct Hashing h;
for(int i=0;i<n;i++)
{
	sum+=arr[i];//storing the current sum

	if(sum==k)//checking if the sum is equal to the given sum
		count++;
	if(h.hashmap.find(sum-k)!=h.hashmap.end())//checking if a key equal to (sum-k) exists
		count+=h.hashmap[sum-k];

	h.hashmap[sum]+=1;//increasing the value of the key (equal to sum) by one
	
}
return count;
}

int main()
{
	int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << solve(n,arr,k) << endl;
}