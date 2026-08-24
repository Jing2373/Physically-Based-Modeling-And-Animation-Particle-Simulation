#pragma once

#include "PbaThing.h"
#include "ParticleState.h"
#include "Force.h"
#include "AdvancePosition.h"
#include "AdvanceVelocity.h"
#include "GISolverBase.h"

namespace pba
{
    using ForcePtr = std::shared_ptr<Force>;

    class SolverManager : public PbaThingyDingy
    {
    public:
        SolverManager(const std::string nam = "SolverManager");

        void Init(const std::vector<std::string> &args);
        void Execute(double dt);

        void SetState(ParticleState s) { particles = s; }
        void SetForce(ForcePtr f) { gravity_force = f; }

        void setRestitution(double r);
        void setBoxSize(double b);

    private:
        GISolver now_solver;

        std::shared_ptr<AdvancePosition> pos_part;
        std::shared_ptr<AdvanceVelocity> vel_part;

        ParticleState particles;
        ForcePtr gravity_force;
    };

    pba::PbaThing CreateSolverManager();
}