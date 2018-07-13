// -----------------------------------------------------------
// File: OrganismFactory.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "OrganismFactory.h"
#include <iostream>

using namespace std;

OrganismFactory *OrganismFactory::GetInstance()
{
	static OrganismFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new OrganismFactory();
	}
	return theInstance;
}

OrganismFactory::~OrganismFactory()
{
}

Organism *OrganismFactory::CreateOrganism1()
{
	Organism *ret = new Organism();

	GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();
	ChromosomeFactory *chromoFact = ChromosomeFactory::GetInstance();
	char strand1[32];
	char strand2[32];

	strcpy(strand1, "");
	strcpy(strand2, "");

	ret->SetGenusName(parser->getGenus());
	ret->SetSpeciesName(parser->getSpecies());
	ret->SetCommonName(parser->getCommonName());
	ret->SetChromoCount(parser->getChromosomeCount());

	for(int i = 0; i < ret->GetChromoCount(); i++)
	{
		parser->getP1Chromosome(strand1, strand2);
		Chromosome *chromo = chromoFact->CreateChromosome(strand1, strand2);
		ret->AddChromo(chromo);
	}

	return ret;
}

Organism *OrganismFactory::CreateOrganism2()
{
	Organism *ret = new Organism();

	GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();
	ChromosomeFactory *chromoFact = ChromosomeFactory::GetInstance();
	char strand1[32];
	char strand2[32];

	strcpy(strand1, "");
	strcpy(strand2, "");

	ret->SetGenusName(parser->getGenus());
	ret->SetSpeciesName(parser->getSpecies());
	ret->SetCommonName(parser->getCommonName());
	ret->SetChromoCount(parser->getChromosomeCount());

	for(int i = 0; i < ret->GetChromoCount(); i++)
	{
		parser->getP2Chromosome(strand1, strand2);
		Chromosome *chromo = chromoFact->CreateChromosome(strand1, strand2);
		ret->AddChromo(chromo);
	}
	return ret;
}

void OrganismFactory::PrintParentData()
{

}