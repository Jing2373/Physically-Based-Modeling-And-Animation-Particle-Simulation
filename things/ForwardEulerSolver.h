#pragma once
#include "GISolverBase.h"

namespace pba
{
    class ForwardEulerSolver : public GISolverBase
    {
    public:
        ForwardEulerSolver(GISolver pos, GISolver vel) : position(pos), velocity(vel) {}

        void init() override
        {
            position->init();
            velocity->init();
        }

        void solve(const double dt) override
        {
            velocity->solve(dt);
            position->solve(dt);
        }

    private:
        GISolver position;
        GISolver velocity;
    };
}
