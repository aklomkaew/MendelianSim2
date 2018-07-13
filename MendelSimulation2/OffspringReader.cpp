// -----------------------------------------------------------
// File: OffspringReader.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "OffspringReader.h"
#include <iostream>
#include <string>

using namespace std;

OffspringReader::OffspringReader()
{
	homoDomCount = 0;
	heteroCount = 0;
	homoRecCount = 0;
	strcpy(homoDom, "");
	strcpy(heteroDom, "");
	strcpy(homoRec, "");
	crossOverCount = 0;
}

OffspringReader::~OffspringReader()
{
}

void OffspringReader::PrintAllGenes(vector<Offspring*> v_Offspring)
{
	MendelianSimulation *sim = MendelianSimulation::GetInstance();
	MasterGeneFactory *masterFact = sim->GetMasterGeneFactory();
	//Node *temp = NULL;
	char offspringGenotype[256];
	char str[3];
	strcpy(offspringGenotype, "");
	strcpy(str, "");

	cout << "\n" << string(60, '*') << "\n" << "| EXPERIMENTAL RESULTS - DEMONSTRATION GENETICS SIMULATION |\n" 
		 << string(60, '*') << endl << endl;
	for(int i = 0; i < sim->GetGeneCount(); i++)
	{
		MasterGene *master;
		homoDomCount = 0;
		heteroCount = 0;
		homoRecCount = 0;

		for(int index = 0; index < v_Offspring.size(); index++)
		{
			Offspring *child = v_Offspring.at(index);
			strcpy(offspringGenotype, child->GetGenotype());

			// for each pair of gene letters in the string
			for(int g = i*2; g < (2*i)+1; g++)
			{
				str[0] = offspringGenotype[g];
				str[1] = offspringGenotype[g+1];
				str[2] = '\0';

				master = masterFact->GetElementFromChar(str[0]);

				if(strcmp(str, master->GetHomoDom()) == 0)
				{
					homoDomCount++;
				}
				else if(strcmp(str, master->GetHetero()) == 0)
				{
					heteroCount++;
				}
				else if(strcmp(str, master->GetHomoRec()) == 0)
				{
					homoRecCount++;
				}
			}
		}

		cout << "Gene: " << master->GetTraitName() << endl;
		cout << "\t" << homoDomCount << " homozygous dominant (" << master->GetDomAllele() 
			 << " " << master->GetHomoDom() << ")" << endl;
		cout << "\t" << heteroCount << " heterozygous dominant (" << master->GetDomAllele() 
			 << " " << master->GetHetero() << ")" << endl;
		cout << "\t" << homoRecCount << " homozygous recessive (" << master->GetRecAllele() 
			 << " " << master->GetHomoRec() << ")" << endl << endl;
	}
	cout << "A total of " << crossOverCount << " offspring had at least one crossover gene." << endl << endl;
}

void OffspringReader::SetCrossOverCount(int num)
{
	crossOverCount = num;
}