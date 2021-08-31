#include<bits/stdc++.h> 
using namespace std; 

void DFSRec(vector<int> adj[], int s, bool visited[], vector<vector<int>> &paths, vector<int> temp) 
{ 	
    visited[s]=true;
    temp.push_back(s);
    
    // if(adj[s].size()==0)
    //     paths.push_back(temp);
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited,paths, temp);
        else
            paths.push_back(temp);
    }
    visited[s] = false;
    temp.pop_back();
}

void DFS(vector<int> adj[], int V, int s, vector<vector<int>> &paths, vector<int> temp){
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    DFSRec(adj,s,visited, paths, temp);
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
ifstream Rf("gold_mine_chapter_1_input.txt");
	ofstream Wf("gold_mine_chapter_2_output.txt");
    int t;
    Rf>>t;
    for(int tt=0; tt<t; tt++)
    {
    
	// Read from the text file
	
	
        int edges;
        Rf>>edges;
        vector<int> adj[edges];
        int V = edges;
        
        vector<vector<int>> paths;
        vector<int> temp;
        vector<long long> cost(edges);
        for(int i=0; i<edges; i++)
        {
            Rf>>cost[i];
            
        }
        
        
        for(int i=0; i<edges-1; i++)
        {
            long long a, b;
            Rf>>a>>b;
            addEdge(adj, a-1, b-1);
        }
    
    // 	cout << "Following is Depth First Traversal: "<< endl; 
    	DFS(adj,V,0, paths, temp); 
        // for(auto x:paths)
        // {
        //     for(int i=0; i<x.size(); i++)
        //         cout<<x[i]+1<<" ";
        //     cout<<endl;
        // }
        long long res = 0;
        if(edges == 1)
            res = cost[0];
        if(paths.size()==1)
        {
            for(int i=0; i<paths[0].size(); i++)
            {
                res += cost[paths[0][i]];
                // cout<<cost[paths[0][i]]<<endl;
            }
            
        }
        else
        {
            for(int i=0; i<paths.size(); i++)
            {
                for(int j=i+1; j<paths.size(); j++)
                {
                    vector<pair<int, int>> mp;
                    long long curr = 0, curr2=0, curr3=0;
                    curr += (long long) cost[paths[i][0]];
                    
                    // cout<<paths[i][0]<<" "<<cost[0]<<endl;;
                    int prevk = 0;
                    for(int k = 1; k<paths[i].size(); k++)
                    {
                        curr += cost[paths[i][k]];
                        // curr1 += cost[paths[i][k]];
                        // cout<<paths[i][k]<<" ";
                        mp.push_back({paths[i][prevk], paths[i][k]});
                        prevk++;
                    }
                    // res = max(curr1, res);
                    // cout<<endl;
                    prevk = 0;
                    // curr2 += cost[paths[j][0]];
                    
                    for(int k=1; k<paths[j].size(); k++)
                    {
                        curr+= cost[paths[j][k]];
                        // curr2+= cost[paths[j][k]];
                        if(find(mp.begin(), mp.end(), make_pair(paths[j][prevk],paths[j][k]))!=mp.end())
                        {
                            curr = 0;
                            break;
                        }
                        else
                        {
                            mp.push_back({paths[j][prevk], paths[j][prevk]});
                            prevk++;
                        }
                    
                    }
                    // cout<<"curr"<<curr<<endl;
                    res = max(curr, res);
                }
            }
            if(res == 0)
            for(int i=0; i<paths.size(); i++)
            {
                long long curr = 0;
                for(int j=0; j<paths[i].size(); j++)
                    curr += cost[paths[i][j]];
                res = max(curr, res);
            }
            
        }
        Wf<<"Case #"<<tt+1<<": "<<res<<endl;
    }
    
	return 0; 
} 

