// -----------------------------------------------------------
// File: MasterGene.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#include "MasterGene.h"
#include <iostream>

using namespace std;

MasterGene::MasterGene()
{
	strcpy(traitName, "");
	strcpy(domAllele, "");
	domSym = '\0';
	strcpy(recAllele, "");
	recSym = '\0';
	strcpy(homoDom, "");
	strcpy(hetero, "");
	strcpy(homoRec, "");
	crossOverChance = 0.0;
}

MasterGene::~MasterGene()
{
}

void MasterGene::PrintData()
{
	cout << "\tTrait Name: " << traitName << endl;
	cout << "\t\tDominant Name: " << domAllele << "(" << domSym << ")\n";
	cout << "\t\tRecessive Name: " << recAllele << "(" << recSym << ")\n\n";
}

void MasterGene::SetTraitName(char* ch)
{
	strcpy(traitName, ch);
}

char* MasterGene::GetTraitName()
{
	return traitName;
}

void MasterGene::SetDomAllele(char *ch)
{
	strcpy(domAllele, ch);
}

char* MasterGene::GetDomAllele()
{
	return domAllele;
}

void MasterGene::SetDomSym(char ch)
{
	domSym = ch;
}

char MasterGene::GetDomSym()
{
	return domSym;
}

void MasterGene::SetRecAllele(char *ch)
{
	strcpy(recAllele, ch);
}

char* MasterGene::GetRecAllele()
{
	return recAllele;
}

void MasterGene::SetRecSym(char ch)
{
	recSym = ch;
}

char MasterGene::GetRecSym()
{
	return recSym;
}

void MasterGene::SetHomoDom(char *ch)
{
	strcpy(homoDom, ch);
}

char* MasterGene::GetHomoDom()
{
	return homoDom;
}

void MasterGene::SetHetero(char *ch)
{
	strcpy(hetero, ch);
}

char* MasterGene::GetHetero()
{
	return hetero;
}

void MasterGene::SetHomoRec(char *ch)
{
	strcpy(homoRec, ch);
}

char* MasterGene::GetHomoRec()
{
	return homoRec;
}

void MasterGene::SetCrossOverChance(double num)
{
	crossOverChance = num;
}

double MasterGene::GetCrossOverChance()
{
	return crossOverChance;
}