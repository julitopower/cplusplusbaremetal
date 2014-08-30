#include <iostream>
#include <vector>

#include <Map.hpp>
#include <Simulation.hpp>
#include <Mouse.hpp>

using namespace std;

namespace {
  char m[] = {10,11,11,11,3,1,8,
	      12,12,12,12,2,3,13,
	      12,12,6,7,3,1,12,
	      12,14,3,3,3,3,13,
	      12,12,10,11,3,1,12,
	      12,6,7,15,3,3,13,
	      6,3,2,12,2,3,5};
  vector<char> map(m, m + 49);

  char m2[] = {1,10,0,0,
	       0,5,11,8,
	       2,0,6,0,
	       5,9,13,10,
	       0,0,0,4};
  vector<char> map2(m2, m2 + 20);
}



int main(int argc, char** argv)
{
  cout << "Starting simulation" << endl;
  Map m(map2, 4, 5);
  Simulation s(m);

  Mouse m1(s);
  //  Mouse m2(s);
  //Mouse m3(s);
  s.addMouse(m1);
  //s.addMouse(m2);
  //s.addMouse(m3);
  //s.runOneStep();
  s.runSteps(40);
}
