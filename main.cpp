#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<chrono>
#include "medTree.hpp"
using namespace std;


int main()
{
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