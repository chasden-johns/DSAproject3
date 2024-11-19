#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "medTree.hpp"
using namespace std;


int main() {
    medTree tree;
    string csvFilePath = "medicine_dataset.csv";

    parseInput(csvFilePath, tree);
    tree.searchMedDFS("allegra");

    return 0;
}