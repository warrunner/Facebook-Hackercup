#include <bits/stdc++.h>
using namespace std;



int main()
{
	int t;
	ifstream Rf("weak_typing_chapter_1_input.txt");
	ofstream Wf("weak_typing_chapter_1_output.txt");
	Rf>>t;
	
	for(int tt=0; tt<t; tt++)
    {
        long long n;
        Rf>>n;
        string s;
        Rf>>s;
        // cout<<s<<endl;
        long long res = -1;
        char prev;
        int i;
        for(i=0; i<n; i++)
        {
            if(s[i] == 'O' || s[i] == 'X')
            {
                prev = s[i];
                res = 0;
                break;
            }
        }
        if(i==n)
            res = 0;
        else{
            for(int j = i+1; j<n; j++)
            {
                // cout<<"here"<<endl;
                if(s[j] != 'F' && prev != s[j])
                {
                    // cout<<"herehere"<<endl;
                    res++;
                    prev = s[j];
                }
            }
        }
        
        Wf<<"Case #"<<tt+1<<": "<<res<<endl;
    }
    
    Rf.close();
    Wf.close();
    return 0;
}
