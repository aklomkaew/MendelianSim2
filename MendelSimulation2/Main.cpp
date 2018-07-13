// -----------------------------------------------------------
// File: Gene.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "MendelianSimulation.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	MendelianSimulation *sim = MendelianSimulation::GetInstance();
	sim->InitializeSimulation();
	sim->RunSimulation();

	delete sim;
	return 0;
}