// -----------------------------------------------------------
// File: Breed.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "Organism.h"
#include "Offspring.h"
#include "MendelianSimulation.h"
#include <vector>

using namespace std;

class Breed
{
private:
	char allele1;
	char allele2;
	char allelePair[3];
	vector<Offspring*> v_Offspring;
	int crossOverCounter;
public:
	Breed();
	~Breed();
	vector<Offspring*> GenerateOffspring();
	void GetCorrectFormGene();
	int GetCrossOverCounter();
};