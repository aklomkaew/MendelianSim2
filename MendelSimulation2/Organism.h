// -----------------------------------------------------------
// File: Organism.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include <vector>
#include "GeneticsSimDataParser.h"
#include "Chromosome.h"
#include "ChromosomeFactory.h"

using namespace std;

class Chromosome;

class Organism
{
private:
	vector<Chromosome*> v_chromosomes;
	char genusName[50];
	char speciesName[50];
	char commonName[50];
	int chromosomeCount;
public:
	Organism();
	~Organism();
	Chromosome *GetRandomChromo();
	void SetGenusName(char *str);
	void SetSpeciesName(char *str);
	void SetCommonName(char *str);
	void SetChromoCount(int num);
	char *GetGenusName();
	char *GetSpeciesName();
	char *GetCommonName();
	int GetChromoCount();
	void AddChromo(Chromosome *chromo);
	Chromosome *GetChromoAt(int index);
};