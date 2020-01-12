//
// Created by avital on 12/01/2020.
//

#include <cstring>
#include <vector>
#include "MyClientHandler.h"
#include "Isearchable.h"

MyClientHandler::MyClientHandler(Solver<string, string> *solver1, CacheManager<string> *cache1) {
    solver = solver1;
    cache = cache1;
}

void MyClientHandler::handleClient(int client_socket) {
    string solution;
    char buffer[1024] = {0};
    string row;
    vector<string> matrixVec;
    int valread;
    string strMatrix = "";
    while (true) {
        valread = read(client_socket, buffer, 1024);
        row = strtok(buffer, "\n");
        if (row == "end") {
            break;
        }
        strMatrix += row;
        matrixVec.push_back(row);
    }
    if (cache->isInCache(strMatrix)) {
        solution = cache->get(strMatrix);
    } else {
        Isearchable<T> matrix = new Matrix(strMatrix);
        //solve the problem and save in the cache:
        solution = solver->solve(matrix);
        cache->insert(strMatrix, solution);
    }
    // return solution to client:
    const char *a = solution.c_str();
    int is_sent;
    is_sent = send(client_socket, a, sizeof(solution), 0);
    if (is_sent == -1) {
        cerr << "error sending message" << endl;

    }
}

