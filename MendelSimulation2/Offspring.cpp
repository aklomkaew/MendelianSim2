// -----------------------------------------------------------
// File: Offspring.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "Offspring.h"
#include <iostream>

using namespace std;

Offspring::Offspring()
{
	strcpy(genotype, "");
	crossOverFlag = false;
}

Offspring::~Offspring()
{
}

void Offspring::SetGenotype(char *str)
{
	strcpy(genotype, str);
}

char *Offspring::GetGenotype()
{
	return genotype;
}

void Offspring::SetCrossOverFlag(bool statement)
{
	crossOverFlag = statement;
}

bool Offspring::GetCrossOverFlag()
{
	return crossOverFlag;
}