#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
vector<pair<int, int>> vis;
int checkCol(vector<string> grid, int rc)
{
    int count = 0;
    pair<int, int> p;
    for(int i=0; i<grid[rc].length(); i++)
    {
        	if(grid[rc][i] == 'O')
		{
		   return 0;
		}
        	else if(grid[rc][i] == '.')
        	{
            count++;
            if(count==1)
            	p = {rc, i};
     	}
    }
    if(count == 1)
    {
    	if(find(vis.begin(), vis.end(), p)==vis.end())
    	{
    		vis.push_back(p);
//    		cout<<p.first<<" "<<p.second;
    		return count;
    	}
    	else
    		return 0;
    	
    }
    return count;
    	
    
}

int checkRow(vector<string> grid, int rc)
{
    int count = 0;
    bool atleast = false;
    pair<int,int> p;
    for(int i=0; i<grid[rc].length(); i++)
    {
        if(grid[i][rc] == 'O')
        {
        	
	  return 0;}
        else if(grid[i][rc] == '.')
        {
            count++;
            if(count==1)
            	p = {i, rc};
     	}
    }
    if(count == 1)
    {
    	if(find(vis.begin(), vis.end(), p)==vis.end())
    	{
    		vis.push_back(p);
    		return count;
    	}
    	else
    		return 0;
    	
    }
    return count;
}

int main() {
	int t;
	
	
	// Read from the text file
	ifstream MyReadFile("xs_and_os_input.txt");
	ofstream MyFile("xs_and_os_output.txt");
	MyReadFile>>t;
	for(int tt=1; tt<=t; tt++)
	{
	    int n;
	    MyReadFile>>n;
	    vector<string> grid(n);
	    vis.clear();
	    for(int i=0; i<n; i++)
	        MyReadFile>>grid[i];
	    map<int, int> mp;
	    long long r1=0, r2=0;
	    for(int i=0; i<n; i++)
	    {
	        int row  = checkRow(grid, i);
	        int col = checkCol(grid, i);
	        mp[row]++;
	        mp[col]++;
	    }
	   // for(auto x:mp)
	   //     cout<<x.first<<" "<<x.second<<endl;
	   // cout<<"Now answer:"<<endl;
	    mp.erase(0);
	    auto it = mp.begin();
	    if(mp.size())
	     	MyFile<<"Case #"<<tt<<": "<<it->first<<" "<<it->second<<endl;
	    else
	        MyFile<<"Case #"<<tt<<": "<<"Impossible"<<endl;
	}
	MyReadFile.close();
	MyFile.close();
	return 0;
}
