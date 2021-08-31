#include <bits/stdc++.h>
using namespace std;


int main()
{
    // Read from the text file
    int t;
	ifstream Rf("consistency_chapter_1_input.txt");
	ofstream Wf("consistency_chapter_1_output.txt");
	Rf>>t;
    for(int tt = 0; tt<t; tt++)
    {
        string s;
        Rf>>s;
        int vowelCount = 0;
        int consCount = 0;
        unordered_map<char, int> mp;
        
        if(s.length()<=1)
        {
            Wf<<"Case #"<<tt+1<<": "<<0<<endl;
            continue;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U')
                vowelCount++;
            else
                consCount++;
            mp[s[i]]++;
        }
        
        // calculating if we convert to vowel
        int maxVowel = 0;
        string vowels = "AEIOU";
        for(int i=0; i<vowels.length(); i++)
        {
            maxVowel = max(maxVowel, mp[vowels[i]]);
        }
        int res1 = (vowelCount - maxVowel)*2 + consCount;
        
        int maxCons = 0;
        string cons = "BCDFGHJKLMNPQRSTWXYZ";
        for(int i=0; i<cons.length(); i++)
        {
            maxCons = max(maxCons, mp[cons[i]]);
        }
        int res2 = (consCount-maxCons)*2 + vowelCount;
        Wf<<"Case #"<<tt+1<<": "<<min(res1, res2)<<endl;
    }
    
}
