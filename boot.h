//
// Created by avital on 09/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Solver.h"
#include "CacheManager.h"
#include "server_side.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SerachSolver.h"
#include "check.cpp"
#include "MyClientHandler.h"

namespace boot {
    class Main {
    public:
        void main(int port) {
            ISearcher<Point*> *i = new check<Point*>();
            Solver<Isearchable<Point*>*, string>* sol = new SerachSolver<Point*>(i);
            CacheManager<string>* c = new FileCacheManager(5);
            server_side::Server* ser = new MySerialServer();
            ClientHandler* cli = new MyClientHandler(sol, c);
            ser->open(port, cli);
        }
    };
}

#endif //EX4_BOOT_H
