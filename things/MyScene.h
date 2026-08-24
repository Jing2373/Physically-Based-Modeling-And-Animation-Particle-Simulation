#pragma once
#include "Vector.h"
#include "Color.h"
#include "PbaThing.h"

using namespace std;

namespace pba
{
    class MyScene : public PbaThingyDingy
    {
    public:
        MyScene(float size, const std::string nam = "Triangulated Colored Floor");
        ~MyScene();

        void Init(const std::vector<std::string> &args);
        void Display();
        void Reset();

    private:
        float box_size;
    };

    pba::PbaThing CreateMyScene(float box_size);
}
