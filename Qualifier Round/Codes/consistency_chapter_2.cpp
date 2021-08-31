#include <bits/stdc++.h>
using namespace std;

#define V 26


#define INF INT_MAX


vector<vector<int>> floydWarshall(vector<vector<int>> graph)
{
	
	int  i, j, k;
	vector<vector<int>> dist(V, vector<int> (V));

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	
	for (k = 0; k < V; k++) {
		
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

    return dist;
}

int main()
{
    
    int t;
	
	
	// Read from the text file
	ifstream Rf("consistency_chapter_2_input.txt");
	ofstream Wf("consistency_chapter_2_output.txt");
	Rf>>t;
	for(int tt=0; tt<t; tt++)
	{
	    string s;
	    Rf>>s;
	    
	    vector<vector<int>> graph(26, vector<int>(26));
	    
	    int v;
	    Rf>>v;
	    for(int i=0; i<26; i++)
	    {
	        for(int j=0; j<26; j++)
	        {
	            graph[i][j] = INF;
	            if(i==j)
	                graph[i][j] = 0;
	        }
	            
	    }
	    
	    vector<char> ends;
	    for(int i=0; i<v; i++)
	    {
	        string in;
	        Rf>>in;
	        graph[in[0]-'A'][in[1]-'A'] = 1;
	        ends.push_back(in[1]);
	    }
	    
		
		vector<vector<int>> dist = floydWarshall(graph);
		long long res = INT_MAX;
		for(int i=0; i<ends.size(); i++)
		{
		    long long curr = 0;
		    for(int j=0; j<s.size(); j++)
		    {
		        if(dist[s[j]-'A'][ends[i]-'A']==INF)
		        {
		            curr = -1;
		            break;
		        }
		        curr += dist[s[j]-'A'][ends[i]-'A'];
		    }
		    if(curr!=-1)
		        res = min(res, curr);
		}
		if(v==0 || s.length()==1)
			res = 0;
		Wf<<"Case #"<<tt+1<<": ";
		if(res==INT_MAX)
			Wf<<-1<<endl;
		else
			Wf<<res<<endl;
	}
	Rf.close();
	Wf.close();
	return 0;
}




