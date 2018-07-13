// -----------------------------------------------------------
// File: OffspringReader.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "Offspring.h"
#include "MasterGeneFactory.h"
#include "MasterGene.h"
#include "MendelianSimulation.h"

using namespace std;

class OffspringReader
{
private:
	int homoDomCount;
	int heteroCount;
	int homoRecCount;
	char homoDom[3];
	char heteroDom[3];
	char homoRec[3];
	int crossOverCount;
public:
	OffspringReader();
	~OffspringReader();
	void PrintAllGenes(vector<Offspring*> v_Offspring);
	void SetCrossOverCount(int num);
};