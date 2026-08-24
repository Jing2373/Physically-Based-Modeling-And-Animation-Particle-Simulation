#pragma once
#include "GISolverBase.h"
#include "ParticleState.h"
#include "PbaThing.h"

namespace pba
{
    class AdvanceVelocity : public GISolverBase
    {
    public:
        AdvanceVelocity(ParticleState pq, PbaThing f);
        ~AdvanceVelocity() {}

        void init() override {}
        void solve(const double dt);

    private:
        ParticleState PQ;
        PbaThing force;
    };

    GISolver make_advance_velocity(ParticleState pq, PbaThing f);

}
