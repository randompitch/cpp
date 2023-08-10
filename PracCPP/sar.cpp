#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

//Functions used
void menu(vector<pair<int,int> > adj[], int V);
void printGraph(vector<pair<int,int> > adj[], int V);
void prims(vector<pair<int,int> > adj[],int V);
void kruskals(vector<pair<int,int> > adj[],int V);

//Different functions to add edges depending upon the type of graph
void addEdgeUW(vector <pair<int, int> > adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void addEdgeUU(vector <pair<int, int> > adj[], int u, int v, int wt=1){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void addEdgeDW(vector <pair<int, int> > adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v, wt));
}
void addEdgeDU(vector <pair<int, int> > adj[], int u, int v, int wt=1){
    adj[u].push_back(make_pair(v, wt));
}

//Menu Program to provide different operations to perform
//on a graph created
void menu(vector<pair<int,int> > adj[], int V){
    int n;
    cout<<endl<<"Congrats! Your graph has been created, what operation would you like to perform on it: "<<endl;
    cout<<endl<<"(1)Print Graph";
    cout<<endl<<"(2)Prim's MST";
    cout<<endl<<"(3)Kruskal's MST";
    cout<<endl<<"(4)Dijkstra's Shortest Path";
    cout<<endl<<"(5)Network Flow(Max) in the graph(Only for Directed Graph)";
    cout<<endl<<"(6)Remove Edge";
    cout<<endl<<"(7)Exit"<<endl;
    cout<<endl<<"Enter your choice :";
    cin>>n;
    if(n==1){
        printGraph(adj,V);
    }
    else if(n==2){
        prims(adj,V);
    }
    else if(n==3){
        kruskals(adj,V);
    }
    else if(n==4){
        //Dijkstra
    }
    else if(n==5){
        //max flow
    }
    else if(n==6){
        //remove edge
    }
    else{
        exit(0);
    }
}

//Function to print all the edges present in a graph with their weights
//Undirected graphs gives each edge present a pre-defined weight of 1
void printGraph(vector<pair<int,int> > adj[], int V){
    int v, w;
    cout<<endl<<"Note : No written weight represents edge weight=1 "<<endl;
    for (int u = 0; u < V; u++){

        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++){
            v = it->first;
            w = it->second;
            if(w==1){
                cout<< "\tNode "<< v << "\n";
            }
            else{
                cout << "\tNode " << v << " with edge weight ="<< w << "\n";
            }

        }
        cout <<endl;
    }

    menu(adj,V);
}

//Prim's Algorithm to find Minimum spanning tree
void prims(vector<pair<int,int> > adj[],int V){

    vector <bool> visited(V,false);

    vector<int> connection(V,-1);

    vector<int> value(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

    que.push(make_pair(0, 1));
    value[1]=0;
    while (!que.empty()) {
        int node = que.top().second;
        visited[node] = true;
        que.pop();
        for (auto it : adj[node]) {
            int w = it.second;
            int v = it.first;
            if (!visited[v] && value[v] > w) {
                value[v] = w;
                connection[v] = node;
                que.push(make_pair(value[v], v));
            }
        }
    }
    for(int i=2;i<V;i++){
        cout<<connection[i]<<"-"<<i<<endl;
    }
    menu(adj,V);
}

//Kruskals algorithm to find MST
void kruskals(vector<pair<int,int> > adj[],int V){
    int a,b;
    vector <bool> visited(V,false);
    vector <pair<int,int> > adj1[V];

    for(int i=0;i<V;i++){

        for(auto it=adj[i].begin();it!=adj[i].end();it++){
                a=it->first;
                b=it->second;
                addEdgeUW(adj1,i,a,b);
            }
    }

    int edgecount=0;
    int u,v,w,x,y;
    int add;

    while(edgecount<V-1){
        add=INT_MAX;
        for(int i=0;i<V;i++){

            for(auto it=adj1[i].begin();it!=adj1[i].end();it++){
                w=it->second;
                x=it->first;

                if(w<add){
                    add=w;
                    u=i;
                    v=x;
                }
            }

            if(!visited[u] || !visited[v]){
                edgecount++;
                cout<<u<<"---"<<w<<"---"<<v<<endl;
                visited[u]=true;
                visited[v]=true;
                for (auto it = adj[u].begin(); it!=adj[u].end(); it++){
                    y=it->first;
                    if(y==v){
                        adj[u].erase(it);
                    }
                }
                for (auto it = adj[v].begin(); it!=adj[v].end(); it++){
                    y=it->first;
                    if(y==u){
                        adj[v].erase(it);
                    }
                }
            }
        }
    }
    
    menu(adj,V);
}

//Function to perform removal of an edge
void delEdge(vector<pair<int,int> > adj[], int V){
    int y,z,u,v;
    cout<<endl<<"Enter the two vertices :"<<endl;
    cout<<endl;
    cout<<"Vertex A: ";
    cin>>u;
    cout<<"Vertex B: ";
    cin>>v;
    for (auto it = adj[u].begin(); it!=adj[u].end(); it++) {
        y=it->first;
        if (y == v) {
            adj[u].erase(it);
            break;
        }
    }

    for (auto it = adj[v].begin(); it!=adj[v].end(); it++) {
        z=it->first;
        if (z == u) {
            adj[v].erase(it);
            break;
        }
    }
    menu(adj,V);
}

void crDirectW(int v){
    int n,a,b,w;
    vector<pair<int,int> > graphD[v];
    int x=v*(v-1);
    cout<<endl<<"Enter the number of edges you would like to add in the graph (Maximum of "<<x<<" can be added) :";
    cin>>n;
    cout<<endl<<"Enter edge from vertex A to vertex B with desired weight: "<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<"Vertex A: ";
        cin>>a;
        cout<<"Vertex B: ";
        cin>>b;
        cout<<"Weight: ";
        cin>>w;
        addEdgeDW( graphD, a, b, w);
    }
    menu(graphD,v);
}

void crDirectU(int v){
    vector<pair<int,int> > graphD[v];
    int a,b,n;
    int x=v*(v-1);
    cout<<endl<<"Enter the number of edges you would like to add in the graph (Maximum of "<<x<<" can be added) :";
    cin>>n;
    cout<<endl<<"Enter edge from vertex A to vertex B :"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<"Vertex A: ";
        cin>>a;
        cout<<"Vertex B: ";
        cin>>b;
        addEdgeDU( graphD, a, b);
    }
    menu(graphD,v);
}

void crUndirectW(int v){
    vector<pair<int,int> > graphU[v];
    int a,b,w,n;
    int x=v*(v-1)/2;
    cout<<endl<<"Enter the number of edges you would like to add in the graph (Maximum of "<<x<<" can be added) :";
    cin>>n;
    cout<<endl<<"Enter the vertices A and B with the desired weight to get an edge in between :"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<"Vertex A: ";
        cin>>a;
        cout<<"Vertex B: ";
        cin>>b;
        cout<<"Weight: ";
        cin>>w;
        addEdgeUW( graphU, a, b, w);
    }
    menu(graphU,v);
}

void crUndirectU(int v){
    int a,b,n;
    vector<pair<int,int> > graphU[v];
    int x=v*(v-1)/2;
    cout<<endl<<"Enter the number of edges you would like to add in the graph (Maximum of "<<x<<" can be added) :";
    cin>>n;
    cout<<endl<<"Enter the vertices A and B to form an edge between the both"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<"Vertex A: ";
        cin>>a;
        cout<<"Vertex B: ";
        cin>>b;
        addEdgeUU( graphU, a, b);
    }
    menu(graphU,v);
}

void createGraph(){
    int a,b,V;
    cout<<"Welcome! How would you like to create your graph?"<<endl;
    cout<<endl<<"(1)Directed Graph"<<endl;
    cout<<"(2)Undirected Graph"<<endl;
    cout<<endl<<"Enter your choice :";
    cin>>a;
    cout<<endl<<"Would you like your graph to be weighted(1) or unweighted(2)?"<<endl;
    cout<<endl<<"Enter your choice :";
    cin>>b;
    cout<<endl<<"Enter the number of vertices you would like on your graph :";
    cin>>V;
    if(a==1){
        if(b==1){
            crDirectW(V);
        }
        else{
            crDirectU(V);
        }
    }
    else{
        if(b==1){
            crUndirectW(V);
        }
        else{
            crUndirectU(V);
        }
    }
}

int main(){
    createGraph();
}