// -----------------------------------------------------------
// File: MasterGene.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "GeneticsSimDataParser.h"

using namespace std;

class MasterGene
{
private:
	char traitName[50];
	char domAllele[50];
	char domSym;
	char recAllele[50];
	char recSym;
	char homoDom[3];
	char hetero[3];
	char homoRec[3];
	double crossOverChance;
public:
	MasterGene();
	~MasterGene();
	void PrintData();
	void SetTraitName(char *ch);
	char* GetTraitName();
	void SetDomAllele(char *ch);
	char* GetDomAllele();
	void SetDomSym(char ch);
	char GetDomSym();
	void SetRecAllele(char *ch);
	char* GetRecAllele();
	void SetRecSym(char ch);
	char GetRecSym();
	void SetHomoDom(char *ch);
	char* GetHomoDom();
	void SetHetero(char *ch);
	char* GetHetero();
	void SetHomoRec(char *ch);
	char* GetHomoRec();
	void SetCrossOverChance(double num);
	double GetCrossOverChance();
};