#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main()
{
    long long t;
    ifstream Rf("weak_typing_chapter_2_input.txt");
	ofstream Wf("weak_typing_chapter_2_output.txt");
	Rf>>t;
    for(long long tt=0; tt<t; tt++)
    {
        long long n;
        Rf>>n;
        string s;
        Rf>>s;
        
        long long res = 0LL;
        char prevChar;
        long long prevIdx = 0;
        long long i;
        for( i=0; i<n; i++)
        {
            if(s[i]=='O' || s[i] == 'X')
            {
                prevIdx = i;
                prevChar = s[i];
                break;
            }
        }
        // cout<<prevIdx<<endl;
        for(long long j=i; j<n; j++)
        {
            if(s[j]!='F' && s[j] != prevChar)
            {
                res = (res + ((long long)(prevIdx+1)%mod)*((long long)(n-j)%mod))%mod;
                prevIdx = j;
                prevChar = s[j];
            }
            if(s[j]!='F' && s[j] == prevChar)
            {
                prevIdx = j;
            }
        }
        Wf<<"Case #"<<tt+1<<": "<<res<<endl;
    }
    
    Rf.close();
    Wf.close();
    
    return 0;
}
