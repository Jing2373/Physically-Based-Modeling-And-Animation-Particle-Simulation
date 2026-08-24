#include "SolverManager.h"
#include "ForwardEulerSolver.h"

using namespace pba;

SolverManager::SolverManager(const std::string nam)
    : PbaThingyDingy(nam) {}

void SolverManager::Init(const std::vector<std::string> &args)
{
   pos_part = std::make_shared<AdvancePosition>(particles);
   vel_part = std::make_shared<AdvanceVelocity>(particles, gravity_force);

   now_solver = std::make_shared<ForwardEulerSolver>(pos_part, vel_part);
}

void SolverManager::Execute(const double dt)
{
   if (now_solver)
      now_solver->solve(dt);
}

void SolverManager::setRestitution(double r)
{
   pos_part->setRestitution(r);
}

void SolverManager::setBoxSize(double b)
{
   pos_part->setBoxSize(b);
}

pba::PbaThing pba::CreateSolverManager()
{
   return PbaThing(new SolverManager());
}