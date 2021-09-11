 #include<bits/stdc++.h>
// #include <stdio.h>
// #include<unordered_map>

using namespace std;

struct Hashing
{
	unordered_map<int,int> hashmap;
	void init()
	{
		hashmap.clear();
	}
	void update(int key, int newval)
	{
		hashmap[key]=newval;
	}
	void delete_key(int key)
	{
		if(hashmap.count(key))	
			hashmap.erase(key);
	}
	int get_val(int key)
	{
		return hashmap[key];
	}

};
/*
 * use Hashing struct provided above as blackbox in case you don't know C++ STL.
 * 
 * init() -> clears the hashmap.
 * update(key,newval) -> updates the value mapped by key to the new value.
 * delete_key(int key) -> deletes the key if present in hashmap.
 * get_val(int key) -> retrieves the value mapped by key.
 * 
 * Time complexity of all the operations mentioned above are O(1)
 * 
 * 
*/

/*
 * The code required to be written does not need any knowledge of C++.
 * So, C code using the Hashing struct as blackbox will work fine.
 * 
*/


int main()
{
	struct Hashing h;
	long long int n;
	long long int count=0;
	scanf("%lli",&n);
	for(long long int i=0;i<n;i++)
	{
		long long int x,y;
		scanf("%lli %lli",&x,&y);
		int key=x-y;//assigning x-y as the key for mapping

			count+=h.get_val(key);//incrementing the value of count by the value stored by its key 
			h.update(key,h.get_val(key)+1);//incrementing the value stored by the key 
			/*if a particular key comes across again then we will have to add its value to count,to take into account all the combinations formed and then increase 
			the value stored by the key by one */
			
	}

	printf("%lli\n",count);
	return 0;
}