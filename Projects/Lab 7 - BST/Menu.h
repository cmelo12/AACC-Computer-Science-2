#pragma once
#include "BinarySearchTree.h"

void mainMenu(BinarySearchTree<City>* myTree);
void searchMenu(BinarySearchTree<City>* myTree);
void reportsMenu(BinarySearchTree<City>* myTree);
void maxminMenu(BinarySearchTree<City>* myTree);
void editMenu(BinarySearchTree<City>* myTree);

void searchZip(BinarySearchTree<City>* myTree);
void searchId(BinarySearchTree<City>* myTree);
void searchArea(BinarySearchTree<City>* myTree);

void listCities(BinarySearchTree<City>* myTree);
void searchDensity(BinarySearchTree<City>* myTree);
void listTimeZones(BinarySearchTree<City>* myTree);
void postOrder(BinarySearchTree<City>* myTree);

void maxLandArea(BinarySearchTree<City>* myTree);
void maxPopulation(BinarySearchTree<City>* myTree);
void minLandArea(BinarySearchTree<City>* myTree);
void minPopulation(BinarySearchTree<City>* myTree);
void maxDensity(BinarySearchTree<City>* myTree);
void minDensity(BinarySearchTree<City>* myTree);

void editPopulation(BinarySearchTree<City>* myTree);
void editArea(BinarySearchTree<City>* myTree);

