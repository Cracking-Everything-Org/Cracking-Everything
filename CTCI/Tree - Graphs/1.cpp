using namespace std;
#include <string>
#include <queue>

enum State {Unvisited, Visiting, Visited};

bool search(Graph *g, Node *start, Node *end){
    if(start==end) return true;

    queue<Node> q;

    for(Node nd : g) nd.state = Unvisited;

    start.state = Visiting;
    q.push(start);
    Node current;

    while(!q.empty()){
        current = q.front();
        q.pop();
        if(current){
            for(Node adj: current.getAdjacent()){
                if(adj.state == Unvisited){
                    if(adj == end) return true;
                    else{
                        adj.state = Visiting;
                        q.push(adj);
                    }
                }
            }
        current.state = Visited;
        }
    }
    return false;
}