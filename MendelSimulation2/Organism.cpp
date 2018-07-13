// -----------------------------------------------------------
// File: Organism.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "Organism.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

Organism::Organism()
{
	strcpy(genusName, "");
	strcpy(speciesName, "");
	strcpy(commonName, "");
	chromosomeCount = 0;
}

Organism::~Organism()
{
}

Chromosome *Organism::GetRandomChromo()
{
	int randNum = 0;
	Chromosome *ret = NULL;

	randNum = rand() % 100 + 1;
	if(randNum < 51)
	{
		// pick first strand
		ret = v_chromosomes.at(0);
	}
	else
	{
		// pick second strand
		ret = v_chromosomes.at(1);
	}

	return ret;
}

void Organism::SetGenusName(char *str)
{
	strcpy(genusName, str);
}

void Organism::SetSpeciesName(char *str)
{
	strcpy(speciesName, str);
}

void Organism::SetCommonName(char *str)
{
	strcpy(commonName, str);
}

void Organism::SetChromoCount(int num)
{
	chromosomeCount = num;
}

char *Organism::GetGenusName()
{
	return genusName;
}

char *Organism::GetSpeciesName()
{
	return speciesName;
}

char *Organism::GetCommonName()
{
	return commonName;
}

int Organism::GetChromoCount()
{
	return chromosomeCount;
}

void Organism::AddChromo(Chromosome *chromo)
{
	v_chromosomes.push_back(chromo);
}

Chromosome *Organism::GetChromoAt(int index)
{
	return v_chromosomes.at(index);
}