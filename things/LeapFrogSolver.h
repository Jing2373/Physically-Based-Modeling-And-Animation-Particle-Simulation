#pragma once
#include "GISolverBase.h"

namespace pba
{
    class LeapFrogSolver : public GISolverBase
    {
    public:
        LeapFrogSolver(GISolver pos, GISolver vel) : position(pos), velocity(vel) {}

        void init() override
        {
            position->init();
            velocity->init();
        }

        void solve(const double dt) override
        {
            const double dtd2 = 0.5 * dt;
            position->solve(dtd2);
            velocity->solve(dt);
            position->solve(dtd2);
        }

    private:
        GISolver position;
        GISolver velocity;
    };
}
