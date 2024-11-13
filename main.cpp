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


vector<vector<string>> parseInput(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return data;
    }
    cout << "File loaded." << endl;
    string line;
    getline(file, line);
    int rowCount = 0;
    while (getline(file, line) && rowCount < 10) {
        stringstream s(line);
        string word;
        vector<string> row;
        rowCount++;
        while (getline(s, word, ',')) {
            // read in each word in column into its own row vector
            row.push_back(word);
        }
        data.push_back(row); // read in each row back into the data
    }
    file.close();
    return data;
}

void printCheck(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Row " << i + 1 << ": ";
        for (const auto& cell : data[i]) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void getMedicine(const vector<vector<string>>& data, int rowIndex) {
    // get medicine based on drugName as parameter
    if (rowIndex >= data.size()) {
        cout << "Index Out of Bounds";
        return;
    }
    auto& row = data[rowIndex]; // access row in readCSV
    string drugName = row[0]; // work to iterate through string name and read up to a space
    // store in string
    vector<string> substitutes;
    vector<string> sideEffects;
    // start from col 1 to get substitutes (cols 1 - 5)
    for (int col = 1; col < row.size(); col++) {
        if (col >= 1 && col <= 6) {
            substitutes.push_back(row[col]);
        }
        else if (col > 6) {
            sideEffects.push_back(row[col]);
        }
    }
    cout << "MedName" << drugName << endl;
    cout << "Substitutes" << endl;
    for (int i = 0; i < substitutes.size(); i++) {
        cout << substitutes[i] << endl;
    }
    cout << "SideEffects" << endl;
    for (int i = 0; i < sideEffects.size(); i++) {
        cout << sideEffects[i] << endl;
    }
}

int main()
{
    string filename = "medicine_dataset.csv";
    int rowIndex = 2; //Example index
    vector<vector<string>> data = parseInput(filename);
    getMedicine(data, rowIndex); // maybe we can change this to take in the name instead

    medTree tester;

    vector<string> sideEffects1 = {"back pain", "headaches", "nausea"};
    vector<string> subs1 = {"ibuprofen", "advil", "acetaminophen"};
    tester.insertMed("tylenol", sideEffects1, subs1);

    vector<string> sideEffects2 = {"drowsiness", "dry mouth", "dizziness"};
    vector<string> subs2 = {"cetirizine", "loratadine", "fexofenadine"};
    tester.insertMed("zyrtec", sideEffects2, subs2);

    vector<string> sideEffects3 = {"upset stomach", "bleeding", "bruising"};
    vector<string> subs3 = {"naproxen", "celecoxib", "diclofenac"};
    tester.insertMed("aspirin", sideEffects3, subs3);

    vector<string> sideEffects4 = {"muscle pain", "weakness", "dark urine"};
    vector<string> subs4 = {"rosuvastatin", "pravastatin", "atorvastatin"};
    tester.insertMed("simvastatin", sideEffects4, subs4);

    vector<string> sideEffects5 = {"fever", "sore throat", "cough"};
    vector<string> subs5 = {"mucinex", "delsym", "robitussin"};
    tester.insertMed("acetaminophen", sideEffects5, subs5);

    vector<string> sideEffects6 = {"loss of appetite", "vomiting", "diarrhea"};
    vector<string> subs6 = {"amoxicillin", "azithromycin", "clarithromycin"};
    tester.insertMed("penicillin", sideEffects6, subs6);

    vector<string> sideEffects7 = {"insomnia", "nervousness", "sweating"};
    vector<string> subs7 = {"prozac", "zoloft", "lexapro"};
    tester.insertMed("fluoxetine", sideEffects7, subs7);

    vector<string> sideEffects8 = {"dry mouth", "blurred vision", "constipation"};
    vector<string> subs8 = {"oxybutynin", "tolterodine", "trospium"};
    tester.insertMed("detrol", sideEffects8, subs8);

    vector<string> sideEffects9 = {"weight gain", "fatigue", "joint pain"};
    vector<string> subs9 = {"metformin", "glipizide", "glimepiride"};
    tester.insertMed("insulin", sideEffects9, subs9);

    vector<string> sideEffects10 = {"sore throat", "hoarseness", "difficulty swallowing"};
    vector<string> subs10 = {"sudafed", "claritin", "allegra"};
    tester.insertMed("benadryl", sideEffects10, subs10);


    auto startBFS = chrono::high_resolution_clock::now();

    tester.searchMedBFS("detrol");

    auto endBFS = chrono::high_resolution_clock::now();

    chrono::duration<double> durationBFS = endBFS - startBFS;

    cout << "search time for BFS: " << durationBFS.count() << endl;




    auto startDFS = chrono::high_resolution_clock::now();

    tester.searchMedDFS("detrol");

    auto endDFS = chrono::high_resolution_clock::now();

    chrono::duration<double> durationDFS = endDFS - startDFS;

    cout << "search time for DFS: " << durationDFS.count() << endl;

    return 0;
    // slight change
}