#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include "Solver.h"
#include <string>

class StringReverser : public Solver<string, string> {
    string solve(string problem);
};

#endif //EX4_STRINGREVERSER_H
