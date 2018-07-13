// -----------------------------------------------------------
// File: Offspring.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>

using namespace std;

class Offspring
{
private:
	char genotype[256];
	bool crossOverFlag;
public:
	Offspring();
	~Offspring();
	void SetGenotype(char *str);
	char *GetGenotype();
	void SetCrossOverFlag(bool statement);
	bool GetCrossOverFlag();
};