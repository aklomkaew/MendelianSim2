// -----------------------------------------------------------
// File: Gene.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "Gene.h"
#include <iostream>

using namespace std;

Gene::Gene()
{
	m_MasterGene = NULL;
	allele1 = '\0';
	allele2 = '\0';
}

Gene::Gene(MasterGene *mg, char *ch1, char *ch2)
{
	m_MasterGene = mg;
	allele1 = *ch1;
	allele2 = *ch2;
}

Gene::~Gene()
{
	delete m_MasterGene;
}

void Gene::SetAllele1(char ch)
{
    allele1 = ch;
}

void Gene::SetAllele2(char ch)
{
    allele2 = ch;
}

char Gene::GetAllele1()
{
    return allele1;
}

char Gene::GetAllele2()
{
    return allele2;
}