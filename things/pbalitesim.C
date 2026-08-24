#include "PbaViewer.h"
#include "MyScene.h"
#include "MyBall.h"
#include "Force.h"
#include "SolverManager.h"

float border = 5.0;

int main(int argc, char **argv)
{
   std::vector<std::string> args;
   for (int i = 0; i < argc; i++)
   {
      args.push_back(argv[i]);
   }

   pba::PbaViewer *viewer = pba::CreateViewer();

   // Scene
   pba::PbaThing myscene = pba::CreateMyScene(border);
   viewer->AddThing(myscene);

   // SolverManager
   pba::PbaThing solver_manager = pba::CreateSolverManager();
   auto solver_manager_ptr = std::static_pointer_cast<pba::SolverManager>(solver_manager);
   viewer->AddThing(solver_manager);

   // Force
   pba::PbaThing force = pba::CreateForce();
   auto force_ptr = std::static_pointer_cast<pba::Force>(force);
   solver_manager_ptr->SetForce(force_ptr);
   viewer->AddThing(force);

   // MyBall
   pba::PbaThing myball = pba::CreateMyBall(border);
   auto myball_ptr = std::static_pointer_cast<pba::MyBall>(myball);
   myball_ptr->SetSolver(solver_manager_ptr);
   solver_manager_ptr->SetState(myball_ptr->GetParticles());
   viewer->AddThing(myball);

   viewer->Init(args);
   viewer->MainLoop();
}
