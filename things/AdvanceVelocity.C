#include "AdvanceVelocity.h"
#include "Force.h"
#include <memory>
#include <iostream>

namespace pba
{

    AdvanceVelocity::AdvanceVelocity(ParticleState pq, PbaThing f) : PQ(pq), force(f) {}

    void AdvanceVelocity::solve(const double dt)
    {

        if (!PQ)
        {
            return;
        }

        auto f_ptr = std::dynamic_pointer_cast<pba::Force>(force);
        if (!f_ptr)
        {
            return;
        }

        const double g = f_ptr->GetGravity();
        const pba::Vector gravity_accel(0.0, g, 0.0);

#pragma omp parallel for
        for (size_t i = 0; i < PQ->nb(); i++)
        {
            PQ->set_accel(i, gravity_accel);
            PQ->set_vel(i, PQ->vel(i) + PQ->accel(i) * dt);
        }
    }

    GISolver make_advance_velocity(ParticleState pq, PbaThing f)
    {
        return std::make_shared<AdvanceVelocity>(pq, f);
    }
}
