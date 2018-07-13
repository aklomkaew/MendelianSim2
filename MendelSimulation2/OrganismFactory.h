// -----------------------------------------------------------
// File: OrganismFactory.h
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;
#include <iostream>
#include "GeneticsSimDataParser.h"
#include "ChromosomeFactory.h"
#include "Organism.h"

using namespace std;

class Organism;

class OrganismFactory
{
private:
public:
	static OrganismFactory *GetInstance();	// Get the singleton instance
	~OrganismFactory();
	Organism *CreateOrganism1();
	Organism *CreateOrganism2();
	void PrintParentData();
};