#include "Force.h"
#include <cstdlib>
#include <GL/gl.h>   // OpenGL itself.
#include <GL/glu.h>  // GLU support library.
#include <GL/glut.h> // GLUT support library.
#include <iostream>

using namespace std;
using namespace pba;

Force::Force(const std::string nam) : PbaThingyDingy(nam)
{

   std::cout << name << " constructed\n";
}

Force::~Force() {}

void Force::Init(const std::vector<std::string> &args)
{
   gravity = -0.2;
}

void Force::Keyboard(unsigned char key, int x, int y)
{
   PbaThingyDingy::Keyboard(key, x, y);
   // Use the keys 'g' and 'G' to decrement/increment the magnitude of the gravity
   if (key == 'g')
   {
      gravity += 0.1;
      std::cout << "Gravity decrement, now is: " << gravity << std::endl;
   }
   else if (key == 'G')
   {
      gravity -= 0.1;
      std::cout << "Gravity increment, now is: " << gravity << std::endl;
   }
}

void Force::solve()
{
}

void Force::Reset()
{
}

float Force::GetGravity()
{
   return gravity;
}

pba::PbaThing pba::CreateForce() { return PbaThing(new Force()); }
