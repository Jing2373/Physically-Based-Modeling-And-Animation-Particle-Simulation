#pragma once
#include "Vector.h"
#include "Color.h"
#include "PbaThing.h"

using namespace std;

namespace pba
{
    class Force : public PbaThingyDingy
    {
    public:
        Force(const std::string nam = "Force");
        ~Force();

        void Init(const std::vector<std::string> &args);
        void Keyboard(unsigned char key, int x, int y);
        void solve();
        void Reset();

        float GetGravity();

    private:
        float gravity = -1;
        float dt = 0.0;
    };

    pba::PbaThing CreateForce();

}
