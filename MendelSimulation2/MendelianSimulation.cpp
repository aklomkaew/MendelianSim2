// -----------------------------------------------------------
// File: MendelianSimulation.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "MendelianSimulation.h"
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>

using namespace std;

MendelianSimulation *MendelianSimulation::GetInstance()
{
	static MendelianSimulation *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new MendelianSimulation();
	}
	return theInstance;
}

MendelianSimulation::~MendelianSimulation()
{
	delete masterFact;
	delete parent1;
	delete parent2;
}

void MendelianSimulation::InitializeSimulation()
{
	srand((unsigned int)(time(NULL)));

	char fileName[64];
	cout << "Please enter file name: " << endl;
	scanf("%s", fileName);

	// Read data file
	GeneticsSimDataParser *parser = GeneticsSimDataParser::getInstance();
	if(!parser->initDataFile(fileName))
	{
		cout << "Invalid file entered. Exiting..." << endl;
		system("pause");
		exit(0);
	}
	geneCount = parser->getGeneCount();
	chromoCount = parser->getChromosomeCount();

	// Create MasterGenes
	masterFact = masterFact->GetInstance();
	for(int i = 0; i < geneCount; i++)
	{
		MasterGene *master = masterFact->CreateMasterGene();
		masterFact->InsertToVector(master);
	}
	//masterFact->PrintAllMasterGene();
	
	// Create Organisms
	OrganismFactory *orgFact = OrganismFactory::GetInstance();
	parent1 = orgFact->CreateOrganism1();
	parent2 = orgFact->CreateOrganism2();
}

void MendelianSimulation::RunSimulation()
{
	cout << "\nEnter number of offspring to generate: ";
	cin >> numOffspring;

	// Start breeding & generating offsprings
	Breed *breeder = new Breed();
	vector<Offspring*> v_Offspring = breeder->GenerateOffspring();

	// Print Results
	OffspringReader *reader = new OffspringReader();
	reader->SetCrossOverCount(breeder->GetCrossOverCounter());
	reader->PrintAllGenes(v_Offspring);

	system("pause");
}

MasterGeneFactory *MendelianSimulation::GetMasterGeneFactory()
{
	return masterFact;
}

int MendelianSimulation::GetGeneCount()
{
	return geneCount;
}

int MendelianSimulation::GetOffspringNum()
{
	return numOffspring;
}

int MendelianSimulation::GetChromoCount()
{
	return chromoCount;
}

Organism *MendelianSimulation::GetParent1()
{
	return parent1;
}

Organism *MendelianSimulation::GetParent2()
{
	return parent2;
}