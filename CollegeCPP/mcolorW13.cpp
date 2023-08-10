#include <iostream>
using namespace std;

#define V 4

bool isValid(int graph[V][V], int v, int color[], int c)
{
    for(int i=0; i<V; i++){
        if(graph[v][i] && c == color[i]){
            return false;
        }
    }
    return true;
}

bool graphColor(int graph[V][V], int m, int color[], int v)
{
    if(v == V){
        return true;
    }
    for(int i=0; i<=m; i++){
        if(isValid(graph, v, color, i)){
            color[v] = i;
            if(graphColor(graph, m, color, v+1)){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool backColor(int graph[V][V], int m)
{
    int color[V] = {0};
    if(!graphColor(graph, m, color, 0)){
        cout << "Solution doesn't exist. " << endl;
        return false;
    }
    cout << "Solution exists. " << endl;
    return true;
}

int main()
{
    int graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m;
    cout << "Enter M: ";    cin >> m;
    backColor(graph, m);
  
    return 0;
}