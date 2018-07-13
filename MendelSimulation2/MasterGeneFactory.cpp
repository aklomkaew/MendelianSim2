// -----------------------------------------------------------
// File: MasterGeneFactory.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "MasterGeneFactory.h"
#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

MasterGeneFactory *MasterGeneFactory::GetInstance()
{
	static MasterGeneFactory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new MasterGeneFactory();
	}
	return theInstance;
}

MasterGeneFactory::~MasterGeneFactory()
{
}

MasterGene *MasterGeneFactory::CreateMasterGene()
{
	MasterGene *ret = new MasterGene();
	MendelianSimulation *sim = MendelianSimulation::GetInstance();
	char traitName[64];
	char domAllele[64];
	char domSym;
	char recAllele[64];
	char recSym;
	double crossOverChance;
	char temp[3];

	GeneticsSimDataParser::getInstance()->getGeneData(traitName, domAllele, &domSym, recAllele, &recSym, &crossOverChance);
	ret->SetTraitName(traitName);
	ret->SetDomAllele(domAllele);
	ret->SetDomSym(domSym);
	ret->SetRecAllele(recAllele);
	ret->SetRecSym(recSym);
	ret->SetCrossOverChance(crossOverChance);

	// set homoDom
	temp[0] = domSym;
	temp[1] = domSym;
	temp[2] = '\0';
	ret->SetHomoDom(temp);

	// set heteroDom
	temp[0] = domSym;
	temp[1] = recSym;
	temp[2] = '\0';
	ret->SetHetero(temp);

	// set homoRec
	temp[0] = recSym;
	temp[1] = recSym;
	temp[2] = '\0';
	ret->SetHomoRec(temp);

	return ret;
}

void MasterGeneFactory::InsertToVector(MasterGene *mg)
{
	v_masterGene.push_back(mg);
}

MasterGene *MasterGeneFactory::GetVElementAt(int index)
{
	return v_masterGene.at(index);
}

MasterGene *MasterGeneFactory::GetElementFromChar(char ch)
{
	ch = toupper(ch);
	for(int i = 0; i < v_masterGene.size(); i++)
	{
		if(v_masterGene.at(i)->GetDomSym() == ch)
		{
			return v_masterGene.at(i);
		}
	}
	return NULL;
}

void MasterGeneFactory::PrintAllMasterGene()
{
	MendelianSimulation *sim = MendelianSimulation::GetInstance();

	cout << "\nMaster Gene:\n";
	for(int i = 0; i < sim->GetGeneCount(); i++)
	{
		v_masterGene.at(i)->PrintData();
	}
}