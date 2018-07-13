// -----------------------------------------------------------
// File: MasterGeneFactory.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include <vector>
#include "GeneticsSimDataParser.h"
#include "MasterGene.h"
#include "MendelianSimulation.h"

using namespace std;

class MasterGene;

class MasterGeneFactory
{
private:
	vector<MasterGene*> v_masterGene;
public:
	static MasterGeneFactory *GetInstance();	// Get the singleton instance
	~MasterGeneFactory();
	MasterGene *CreateMasterGene();
	void InsertToVector(MasterGene *mg);
	MasterGene *GetVElementAt(int index);
	MasterGene *GetElementFromChar(char ch);
	void PrintAllMasterGene();
};