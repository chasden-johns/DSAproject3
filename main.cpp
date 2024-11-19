#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<chrono>
#include <fstream>
#include <sstream>
#include "medTree.hpp"
using namespace std;


int main() {
    medTree tree;
    string csvFilePath = "medicine_dataset.csv";

    parseInput(csvFilePath, tree);

    string drugName;
    cout << "[[ PHARMACY AID                                   ]] " << endl;
    cout << "| Welcome User!                                    |" << endl;
    cout << "| PHARMACY AID is your key to any question you may |" <<
    endl << "| have on drug specifics!                          |" << endl;
    cout << "| Simply enter the name of your desired medicine   |" <<
    endl << "| below to get a list of all possible side effect  |" <<
    endl << "| and substitutes.                                 |" << endl;

    cout << "[[    Enter Drug Name    ]] :";
    getline(cin, drugName);
    cout << " . . searching for " << drugName << " . . . " << endl;

    // BFS Algorithm
    auto startBFS = chrono::high_resolution_clock::now();
    tree.searchMedBFS(drugName);
    auto endBFS = chrono::high_resolution_clock::now();
    chrono::duration<double> durationBFS = endBFS - startBFS;
    cout << "| Search time for BFS: " << durationBFS.count() << endl;

    // DFS Algorithm
    auto startDFS = chrono::high_resolution_clock::now();
    tree.searchMedDFS(drugName);
    auto endDFS = chrono::high_resolution_clock::now();
    chrono::duration<double> durationDFS = endDFS - startDFS;
    cout << "| Search time for DFS: " << durationDFS.count() << endl;

    // prompt user on whether to end session
    bool endSession = false;
    while (!endSession){
        string answer;
        cout << "| Are you satisfied with your care?                |" << endl;
        cout << "[[  Enter Y to exit or N to search  ]]" << endl <<
                "[[        for another medicine      ]] : ";
        getline(cin, answer);
        if (answer == "N" || answer == "n") {
            string newDrugName;
            cout << "|                                                 |" << endl;
            cout << "[[    Enter Drug Name    ]] :";
            getline(cin, newDrugName);
            cout << " . . searching for " << drugName << " . . . " << endl;

            auto startBFS = chrono::high_resolution_clock::now();
            tree.searchMedBFS(newDrugName);
            auto endBFS = chrono::high_resolution_clock::now();
            chrono::duration<double> durationBFS = endBFS - startBFS;
            cout << "| Search time for BFS: " << durationBFS.count() << endl;

            auto startDFS = chrono::high_resolution_clock::now();
            tree.searchMedDFS(newDrugName);
            auto endDFS = chrono::high_resolution_clock::now();
            chrono::duration<double> durationDFS = endDFS - startDFS;
            cout << "| Search time for DFS: " << durationDFS.count() << endl;
        }
        else if (answer == "Y" || answer == "y"){
            endSession = true;
            cout << "| Thank you for using PHARMACY AID!               |" << endl;
            cout << "|_________________________________________________|" << endl;
        }
        else {
            cout << "| Error. Invalid Input                            |" << endl;
            cin.clear();
        }
    }
    return 0;
}