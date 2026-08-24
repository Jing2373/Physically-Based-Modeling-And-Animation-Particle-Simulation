#include "MyBall.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;
using namespace pba;

MyBall::MyBall(float size, const std::string nam)
    : PbaThingyDingy(nam), border(size)
{
    Reset();
}

MyBall::~MyBall() {}

void MyBall::Init(const std::vector<std::string> &args)
{
    restitution = 0.866;
}

void MyBall::Display()
{
    glPointSize(5.0);
    glBegin(GL_POINTS);

    for (size_t i = 0; i < particles->nb(); i++)
    {
        const Vector &p = particles->pos(i);
        const Color &c = particles->color(i);

        glColor3f(c.red(), c.green(), c.blue());
        glVertex3f(p.X(), p.Y(), p.Z());
    }

    glEnd();
}

void MyBall::Keyboard(unsigned char key, int x, int y)
{
    if (key == 'c')
    {
        restitution = restitution - 0.05;
    }
    else if (key == 'C')
    {
        restitution = restitution + 0.05;
    }
    else if (key == 'e')
    {
        EmitParticles();
    }
}

void MyBall::solve()
{
    solverManager->setRestitution(restitution);
    solverManager->setBoxSize(border);

    solverManager->Execute(dt);
}

void MyBall::Reset()
{
    if (!particles)
        particles = std::make_shared<ParticleStateData>();

    particles->clear();

    double b = border - 0.1;

    Vector p(
        (drand48() * 2 - 1) * b,
        (drand48() * 2 - 1) * b,
        (drand48() * 2 - 1) * b);

    Vector v(
        drand48() * 2 - 1,
        drand48() * 2 - 1,
        drand48() * 2 - 1);

    particles->add(p, v, Color(1, 0, 0, 0));
}

void MyBall::EmitParticles()
{
    for (int i = 0; i < 100; i++)
    {
        Vector v(
            (drand48() * 2 - 1) * 2,
            (drand48() * 2 - 1) * 2,
            (drand48() * 2 - 1) * 2);

        particles->add(
            particles->init_pos(0),
            v,
            Color(drand48(), drand48(), drand48(), 0));
    }
}

pba::PbaThing pba::CreateMyBall(float size)
{
    return PbaThing(new MyBall(size));
}