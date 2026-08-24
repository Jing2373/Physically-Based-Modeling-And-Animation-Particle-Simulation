#pragma once

#include "Vector.h"
#include "Color.h"
#include "PbaThing.h"
#include "ParticleState.h"
#include "SolverManager.h"

namespace pba
{
    using SolverPtr = std::shared_ptr<SolverManager>;

    class MyBall : public PbaThingyDingy
    {
    public:
        MyBall(float border, const std::string nam = "Ball");
        ~MyBall();

        void SetSolver(SolverPtr in_solver) { solverManager = in_solver; }

        void Init(const std::vector<std::string> &args);
        void Display();
        void Keyboard(unsigned char key, int x, int y);
        void solve();
        void Reset();

        std::shared_ptr<ParticleStateData> GetParticles() { return particles; }

    private:
        void EmitParticles();

        std::shared_ptr<ParticleStateData> particles;
        std::shared_ptr<SolverManager> solverManager;

        double restitution;
        double border;
    };

    pba::PbaThing CreateMyBall(float border);
}