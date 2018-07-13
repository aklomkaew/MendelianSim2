// -----------------------------------------------------------
// File: Chromosome.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "Chromosome.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Chromosome::Chromosome()
{
	strcpy(strand1, "");
	strcpy(strand2, "");
	crossOverFlag = false;
}

Chromosome::~Chromosome()
{
}

void Chromosome::AddGene(Gene *theGene)
{
	v_genes.push_back(theGene);
}

bool Chromosome::GetCrossOverFlag()
{
	return crossOverFlag;
}

char *Chromosome::GetStrand1()
{
	return strand1;
}

char *Chromosome::GetStrand2()
{
	return strand2;
}

void Chromosome::SetStrand1(char *str)
{
	strcpy(strand1, str);
}

void Chromosome::SetStrand2(char *str)
{
	strcpy(strand2, str);
}

int Chromosome::GetRandomStrand(char *strand)
{
	int randNum = rand() % 100 + 1;
	int counter = 0;
	MasterGeneFactory *masterFact = MasterGeneFactory::GetInstance();

	if(randNum < 51)
	{
		// pick first strand
		strcpy(strand, strand1);
	}
	else
	{
		// pick second strand
		strcpy(strand, strand2);
	}

	// Go through each gene in the strand
	for(int i = 0; i < sizeof(strand); i++)
	{
		if(strand[i] == ' ')
		{
			continue;
		}
		if(strand[i] == '\0')
		{
			break;
		}

		MasterGene *master = masterFact->GetElementFromChar(strand[i]);
		randNum = rand() % 100 + 1;
		if(randNum <= master->GetCrossOverChance())
		{
			strand[i] = strand2[i];
			counter++;
		}
	}
	return counter;
}