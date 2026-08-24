#include "AdvancePosition.h"
#include <iostream>
#include "Vector.h"

namespace pba
{
    AdvancePosition::AdvancePosition(ParticleState &pq)
        : PQ(pq)
    {
    }

    void AdvancePosition::init() {}

    void AdvancePosition::solve(const double dt)
    {
        if (!PQ)
            return;

        for (size_t i = 0; i < PQ->nb(); i++)
        {
            pba::Vector newPos = PQ->pos(i) + PQ->vel(i) * dt;
            pba::Vector v = PQ->vel(i);

            pba::Vector normals[6] = {
                pba::Vector(1, 0, 0), pba::Vector(-1, 0, 0),
                pba::Vector(0, 1, 0), pba::Vector(0, -1, 0),
                pba::Vector(0, 0, 1), pba::Vector(0, 0, -1)};

            for (int j = 0; j < 6; j++)
            {
                double dist = (newPos * normals[j]) - box_size;

                if (dist > 0)
                {
                    newPos -= dist * normals[j];

                    double vn = v * normals[j];
                    if (vn > 0)
                    {
                        v -= (1.0 + restitution) * vn * normals[j];
                    }
                }
            }

            PQ->set_pos(i, newPos);
            PQ->set_vel(i, v);
        }
    }

    GISolver make_advance_position(ParticleState pq)
    {
        return std::make_shared<AdvancePosition>(pq);
    }
}