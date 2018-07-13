// -----------------------------------------------------------
// File: Gene.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "GeneticsSimDataParser.h"
#include "MasterGene.h"

using namespace std;

class Gene
{
private:
	MasterGene *m_MasterGene;
	char allele1;
	char allele2;
public:
	Gene();
	Gene(MasterGene *mg, char *ch1, char *ch2);
	~Gene();
    void SetAllele1(char ch);
    void SetAllele2(char ch);
    char GetAllele1();
    char GetAllele2();
};
