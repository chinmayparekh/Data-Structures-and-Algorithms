#include<bits/stdc++.h>

using namespace std;
int has_pal_substr(string s, int len)
{
    long long int forward[s.length()];//to store the hash of all substrings in s of length len
    long long int q =109194853094755497;//taking a very large prime number to reduce collisions
    long long int b=1;
    long long int i;
    long long int p=0;
    for(i=0;i<len;i++)
    {
        p=(p*26+(s[i]-96))%q;
        b=(b*26)%q;
    }
    forward[0]=p;
    int j=1;
    while(i<s.length())//for rolling
    {
        
        p=(p*26+(s[i]-96)-(s[i-len]-96)*b)%q;
        if(p<0)
            p+=q;
        forward[j]=p;
        j++;
        i++;
    }

    string reversed=s;
    reverse(reversed.begin(),reversed.end());//reversing the given string
    p=0;
    b=1;
    for(i=0;i<len;i++)
    {
        p=(p*26+(reversed[i]-96))%q;
        b=(b*26)%q;
    }
    j--;
    while(i<=s.length())
    {
        if(forward[j]==p)//checking if the hash value of the substring is equal to that stored in the array 
            return 1;
        p=(p*26+(reversed[i]-96)-(reversed[i-len]-96)*b)%q;
        if(p<0)
            p+=q;
        i++;
        j--;
    }
    return 0;

}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s ;
    int odd_len[(n+1)/2], even_len[n/2]; // odd_len stores odd nos. till n. even_len stores even nos. till n.
    for(int i=2;i<=n;i+=2){
        even_len[i/2-1] = i;
    }
    for(int i=1;i<=n;i+=2){
        odd_len[i/2] = i;
    }
    // binary search code for odd_len array
    int start = 0, end = (n+1)/2 -1;
    int ans_odd = 0;
    while(start <= end){
        int mid = (start + end)/2; 
        int len = odd_len[mid];
        if(has_pal_substr(s,len)) {
            ans_odd = len;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    // binary search code for even_len array
    start = 0; end = n/2-1;
    int ans_even=0;
    while(start<=end){
        int mid = (start+end)/2;
        int len=even_len[mid];
            if(has_pal_substr(s,len)) {
                ans_even = len;
                start = mid + 1;
        }
        else end = mid - 1;
    }
    
    int ans = max(ans_odd,ans_even);
    cout << ans << endl;
    return 0;
}

