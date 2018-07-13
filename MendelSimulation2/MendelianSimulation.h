// -----------------------------------------------------------
// File: MendelianSimulation.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include <vector>
#include "GeneticsSimDataParser.h"
#include "MasterGene.h"
#include "MasterGeneFactory.h"
#include "OrganismFactory.h"
#include "OffspringReader.h"
#include "Breed.h"
#include "Offspring.h"

using namespace std;

class Organism;
class MasterGeneFactory;
class BinaryTree;

class MendelianSimulation
{
private:
	MasterGeneFactory *masterFact;
	Organism *parent1;
	Organism *parent2;
	int geneCount;
	int chromoCount;
	int numOffspring;
public:
	static MendelianSimulation *GetInstance();	// Get the singleton instance
	~MendelianSimulation();
	void InitializeSimulation();
	void RunSimulation();
	void SetGeneCount(int num);
	int GetGeneCount();
	MasterGeneFactory *GetMasterGeneFactory();
	int GetOffspringNum();
	int GetChromoCount();
	Organism *GetParent1();
	Organism *GetParent2();
};