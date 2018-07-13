// -----------------------------------------------------------
// File: ChromosomeFactory.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "ChromosomeFactory.h"
#include <iostream>

using namespace std;

ChromosomeFactory *ChromosomeFactory::GetInstance()
{
	static ChromosomeFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new ChromosomeFactory();
	}
	return theInstance;
}

ChromosomeFactory::~ChromosomeFactory()
{
}

Chromosome *ChromosomeFactory::CreateChromosome(char *strand1, char *strand2)
{
	Chromosome *ret = NULL;
	char *ch1 = NULL;
	char *ch2 = NULL;
	bool done = false;
    bool crossOverFlag = false;
	MendelianSimulation *sim = MendelianSimulation::GetInstance();
	MasterGeneFactory *master = sim->GetMasterGeneFactory();
	MasterGene *mg;

	ch1 = strand1;
	ch2 = strand2;

	ret = new Chromosome();
	ret->SetStrand1(strand1);
	ret->SetStrand2(strand2);

	while(!done)
	{
		mg = master->GetElementFromChar(ch1[0]);
		if(mg == NULL) return NULL;
		Gene *theGene = new Gene(mg, ch1, ch2);
		ret->AddGene(theGene);
		ch1++;
		if(*ch1 == '\0') done = true;
		ch2++;
		ch1++;
		ch2++;
	}

	return ret;
}
