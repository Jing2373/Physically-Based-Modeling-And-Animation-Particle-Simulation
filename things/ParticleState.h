#pragma once
#include <memory>

#include "Vector.h"
#include "Color.h"

#include <cstddef>
#include <vector>

namespace pba
{

    class ParticleStateData
    {
    public:
        std::size_t nb() const { return positions.size(); }

        const Vector &pos(std::size_t i) const { return positions[i]; }
        void set_pos(std::size_t i, const Vector &p) { positions[i] = p; }

        const Vector &init_pos(std::size_t i) const { return positions_init[i]; }

        const Vector &vel(std::size_t i) const { return velocities[i]; }
        void set_vel(std::size_t i, const Vector &v) { velocities[i] = v; }

        const Vector &accel(std::size_t i) const { return accelerations[i]; }
        void set_accel(std::size_t i, const Vector &a) { accelerations[i] = a; }

        const Color &color(std::size_t i) const { return colors[i]; }

        void add(const Vector &p, const Vector &v, const Color &c)
        {
            positions.push_back(p);
            positions_init.push_back(p);
            velocities.push_back(v);
            accelerations.push_back(Vector(0.0, 0.0, 0.0));
            colors.push_back(c);
        }

        void clear()
        {
            positions.clear();
            positions_init.clear();
            velocities.clear();
            accelerations.clear();
            colors.clear();
        }

    private:
        std::vector<Vector> positions_init;
        std::vector<Vector> positions;

        std::vector<Vector> velocities;
        std::vector<Vector> accelerations;
        std::vector<Color> colors;
    };

    using ParticleState = std::shared_ptr<ParticleStateData>;

}
