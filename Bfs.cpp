#include "Bfs.h"

// search a path to solve the given problem
string Bfs::search(Isearchable<Point *> *problem) {
    searchBfs(problem->getInitialState(), problem->getGoalState(), problem);
    if (problem->getGoalState()->getCameFrom() == nullptr) {
        return "No path";
    }
    return backTrace(problem);
}

// use BFS
void Bfs::searchBfs(state<Point *> *start, state<Point *> *end, Isearchable<Point *> *problem) {
    int evaluateNum=0;
    set<state<Point*>*> MySet;
    state<Point *> *s;
    addToOpenQ(start);
    MySet.insert(start);
    while (openQsize() != 0) {
        state<Point *> *n = popOpenQ();
        evaluateNum++;
        if (n->equals(*end)) {
            return;
        }
        queue<state<Point *> *> succ = problem->getAllPossibleStates(n);
        while (!succ.empty()) {
            s = succ.front();
            succ.pop();
            set<state<Point *> *>::iterator it = MySet.find(s);
            if (it == MySet.end()) {
                s->setCameFrom(n);
                s->trailCost = n->trailCost + 1;
                MySet.insert(s);
                addToOpenQ(s);
            }
        }
    }
}