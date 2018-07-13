// -----------------------------------------------------------
// File: Breed.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "Breed.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

Breed::Breed()
{
	allele1 = '\0';
	allele2 = '\0';
	strcpy(allelePair, "");
	crossOverCounter = 0;
}

Breed::~Breed()
{
}

vector<Offspring*> Breed::GenerateOffspring()
{
	MendelianSimulation *sim = MendelianSimulation::GetInstance();
	Organism *parent1 = sim->GetParent1();
	Organism *parent2 = sim->GetParent2();
	bool crossOver1 = false;
	bool crossOver2 = false;
	bool done = false;
	char strand1[32];
	char strand2[32];
	char offspringGenotype[256];
	int tempCounter = 0;

	strcpy(strand1, "");
	strcpy(strand2, "");

	for(int i = 0; i < sim->GetOffspringNum(); i++)
	{
		strcpy(offspringGenotype, "");
		for(int c = 0; c < sim->GetChromoCount(); c++)
		{
			Chromosome *chromo1 = parent1->GetChromoAt(c);
			Chromosome *chromo2 = parent2->GetChromoAt(c);

			// get random strand and cross over flag from each parent
			tempCounter = chromo1->GetRandomStrand(strand1);
			if(tempCounter >= 1)
			{
				crossOver1 = true;
				crossOverCounter = crossOverCounter + tempCounter;
			}
			tempCounter = chromo2->GetRandomStrand(strand2);
			if(tempCounter >= 1)
			{
				crossOver2 = true;
				crossOverCounter = crossOverCounter + tempCounter;
			}

			// for each letter in strand strings
			for(int index = 0; index < sizeof(strand1) - 1; index++)
			{
				// get a letter from each strand to create a gene pair
				if(strand1[index] == ' ')
				{
					continue;
				}
				if(strand1[index] == '\0')
				{
					break;
				}
				allele1 = strand1[index];
				allele2 = strand2[index];
				GetCorrectFormGene();
				strcat(offspringGenotype, allelePair);
			}
		}
		// create offspring instance
		Offspring *child = new Offspring();

		// set offspring genotype string to that just built
		child->SetGenotype(offspringGenotype);

		// if cross over flag of either parent is true set offspring crossover flag to true
		child->SetCrossOverFlag(crossOver1 || crossOver2);

		// add offspring to collection of offspring
		v_Offspring.push_back(child);
	}
	return v_Offspring;
}

void Breed::GetCorrectFormGene()
{
	if(allele1 < allele2)
	{
		allelePair[0] = allele1;
		allelePair[1] = allele2;
		allelePair[2] = '\0';
	}
	else
	{
		allelePair[0] = allele2;
		allelePair[1] = allele1;
		allelePair[2] = '\0';
	}
}

int Breed::GetCrossOverCounter()
{
	return crossOverCounter;
}