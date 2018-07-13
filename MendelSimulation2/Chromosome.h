// -----------------------------------------------------------
// File: Chromosome.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include <vector>
#include "GeneticsSimDataParser.h"
#include "Gene.h"
#include "MasterGeneFactory.h"
#include "MasterGene.h"

using namespace std;

class Gene;

class Chromosome
{
private:
	char strand1[32];
	char strand2[32];
	bool crossOverFlag;
	vector<Gene*> v_genes;
public:
	Chromosome();
	~Chromosome();
	void AddGene(Gene *theGene);
	bool GetCrossOverFlag();
	char *GetStrand1();
	char *GetStrand2();
	void SetStrand1(char *str);
	void SetStrand2(char *str);
	int GetRandomStrand(char *strand);
};