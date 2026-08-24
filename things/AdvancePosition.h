#pragma once
#include "GISolverBase.h"
#include "ParticleState.h"

namespace pba
{
    class AdvancePosition : public GISolverBase
    {
    public:
        AdvancePosition(ParticleState &pq);
        void init() override;
        void solve(const double dt);

        void setRestitution(float r) { restitution = r; }
        void setBoxSize(float b) { box_size = b; }

    private:
        ParticleState PQ;

        float restitution;
        float box_size;
    };
    GISolver make_advance_position(ParticleState pq);
}
