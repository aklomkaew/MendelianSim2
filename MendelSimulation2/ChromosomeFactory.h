// -----------------------------------------------------------
// File: ChromosomeFactory.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "Chromosome.h"
#include "MendelianSimulation.h"
#include "MasterGeneFactory.h"

using namespace std;

class Chromosome;

class ChromosomeFactory
{
private:
public:
	static ChromosomeFactory *GetInstance();	// Get the singleton instance
	~ChromosomeFactory();
	Chromosome *CreateChromosome(char *strand1, char *strand2);
};