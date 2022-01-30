using namespace std;
#include <stack>
#include <string>

enum State {COMPLETE,PARTIAL,BLANK};

stack<Project>* findBuildOrder(vector<string> projects, vector<vector<string>> dependencies){
    Graph graph = buildGraph(projects, dependencies);
    return orderProjects(graph.getNodes());
}

stack<Project>* orderProjects(vector<Project> projects){
    stack<Project> stack;

    // recorro todos los BLANK nodes del grafo y pregunto si se cumple dfs
    for(Project p: projects){
        if(p->state == BLANK){
            if(!doDFS(p, stack)){
                return false;
            }
        }
    }
    return stack;
}

bool doDFS(Project p, stack<Project> stk){
    // detectamos un ciclo
    if(p->state == PARTIAL) return false;

    if(p->state == BLANK){
        vector<Project> children = p.getChildren();
        for(Project son: children){
            if(!doDFS(son, stack)){
                return false;
            }
        }
        p->state = COMPLETE;
        stk.push(p);
    }
    return true;
}

