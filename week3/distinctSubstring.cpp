// C++ program to count all distinct substrings in a string
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int length;
    long long int j,i;
    cin >> length;
    string text;
    cin>>text;
    long long int q =109194853094755497;//taking a very large prime number to reduce collisions
    
    int ans=0;
    
    for(i=1;i<=length;i++)//to determine the length of the substring
    {
        unordered_map< long long , int > hash_table;//initializing a new hash table for substrings of different lengths
        long long int p=0;
        long long int b=1;
       //iterating over each substring of length i
        for( j=0;j<i;j++)
        {
            p=(p*26+text[j]-96)%q;
            b=(b*26)%q;
        }
            hash_table[p]++;
        while(j<length)//for rolling
        {
            
            p=(p*26+(text[j]-96)-(text[j-i]-96)*b)%q;

            if(p<0)
                p+=q;
            hash_table[p]++;
            j++;
        }
            ans+=hash_table.size(); //
    }
    cout<< ans <<endl;
    return 0;

}
