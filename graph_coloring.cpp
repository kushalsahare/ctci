#include<bits/stdc++.h>

class Graph{

    int V;
    std::list<int> adj;

    public:
    Graph(int v){
	this->V= v;
	adj = new std::list<int>[V];
    }
    ~Graph(){
	delete[] adj;
    }

    void addEdge(int u, int v){

	adj[u].push_back(v);
    }

    void graphColor();

};

void Graph::graphColor(){

    int color[V];
    color[0] = 0;

    for( int u = 1; u < V; ++u){
	color[u] = -1;
    }

    bool available[V];

    for(int cr = 0; cr < V; ++cr){
	available[cr]= false;
    }

    for( int i = 1; i< V; ++i){

	std::list<int>::iterator it;
	for( it = adj[i].begin(); it != adj[i].end(); ++it){
	    if( color[*it] != -1 ){
		available[color[*it]] = true;
	    }
	}

	int cr;

	for( cr = 0; cr < V; ++cr){
	    if( available[cr] == false )
		break;
	}

	color[u]= cr;

	for( i= adj[u].begin(); i != adj[u].end(); ++i){
          if( color[*it] != -1){
             available[color[*it]] =false
	  }
	}
    }

}
