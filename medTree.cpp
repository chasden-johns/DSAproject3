#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include <sstream>
#include <fstream>

#include "medTree.hpp"
using namespace std;

// split a line by commas
vector<string> splitLine(const string& line, char del) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = line.find(del);

    while (end != string::npos) {
        tokens.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(del, start);
    }

    tokens.push_back(line.substr(start));
    return tokens;
}

// extract the medicine name
string extractMedicineName(const string& name) {
    string medicine;
    for (char ch : name) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            medicine += ch;
        }
        else {
            break;
        }
    }
    return medicine;
}

// read and parse CSV
void parseInput(const string& filePath, medTree& tree) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filePath << endl;
        return;
    }

    string line;
    getline(file, line);
    int lineCount = 0;


    set<string> uniqueMeds;

    while (getline(file, line)) {
        lineCount++;
        vector<string> tokens = splitLine(line, ',');

        if (tokens.empty()) continue;

        string medicine = extractMedicineName(tokens[0]);

        // skip duplicate medicines
        if (uniqueMeds.count(medicine)) {
            continue;
        }
        uniqueMeds.insert(medicine);

        vector<string> subs, sideEffects;

        for (size_t i = 1; i <= 5; ++i) {
            if (i < tokens.size() && !tokens[i].empty()) {
                subs.push_back(tokens[i]);
            }
        }

        for (size_t i = 6; i < tokens.size(); ++i) {
            if (!tokens[i].empty()) {
                sideEffects.push_back(tokens[i]);
            }
        }

        tree.insertMed(medicine, sideEffects, subs);

        // Ppint progress for every 10,000 rows processed
        if (lineCount % 10000 == 0) {
            cout << "Processed " << lineCount << " rows..." << endl;
        }
    }

    file.close();

}



//right right case
treeNode* medTree::rotateLeft(treeNode* node)
{
    if (node == nullptr) return nullptr;
    treeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = height(node);
    return newRoot;
}
// left left case
treeNode* medTree::rotateRight(treeNode* node)
{
    if (node == nullptr) return nullptr;
    treeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = height(node);
    return newRoot;
}
//left right case
treeNode* medTree::rotateLeftRight(treeNode* node)
{
    if (node == nullptr) return nullptr;
    treeNode* leftChild = node->left;
    treeNode* newRoot = leftChild->right;
    leftChild->right = newRoot->left;
    newRoot->left = leftChild;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = height(node);
    return newRoot;
}
//right left case
treeNode* medTree::rotateRightLeft(treeNode* node)
{
    if (node == nullptr) return nullptr;
    treeNode* rightChild = node->right;
    treeNode* newRoot = rightChild->left;
    rightChild->left = newRoot->right;
    newRoot->right = rightChild;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = height(node);
    return newRoot;
}
// returns height
int medTree::height(treeNode* root)
{
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}
// returns balance factor
int medTree::balanceFactor(treeNode* root)
{
    if (root == nullptr) return 0;
    int leftSubHeight = height(root->left);
    int rightSubHeight = height(root->right);
    return leftSubHeight - rightSubHeight;
}
// insert new medicine into tree, takes medicine name, list of effects, and list of subs
treeNode* medTree::insertMedHelper(treeNode* root, string medicine, vector<string>& sideEffects, vector<string>& subs) {
    if (root == nullptr) {
        root = new treeNode(move(medicine), sideEffects, subs);

    }
    else if (medicine == root->med) {

        return root;
    }
    else if (medicine < root->med) {
        root->left = insertMedHelper(root->left, medicine, sideEffects, subs);
    }
    else {
        root->right = insertMedHelper(root->right, medicine, sideEffects, subs);
    }

    // Balancing
    int parentBF = balanceFactor(root);
    int leftSubBF = balanceFactor(root->left);
    int rightSubBF = balanceFactor(root->right);

    if (parentBF >= 2 && leftSubBF >= 1) {
        root = rotateRight(root);
    }
    else if (parentBF >= 2 && leftSubBF <= -1) {
        root = rotateLeftRight(root);
    }
    else if (parentBF <= -2 && rightSubBF <= -1) {
        root = rotateLeft(root);
    }
    else if (parentBF <= -2 && rightSubBF >= 1) {
        root = rotateRightLeft(root);
    }

    root->height = height(root);
    return root;
}

void medTree::insertMed(string medicine, vector<string>& sideEffects, vector<string>& subs)
{
    root = insertMedHelper(root, medicine, sideEffects, subs);
}
// depth first traversal
bool medTree::searchMedHelperDFS(treeNode* root, string medicine)
{
    medFound = false;
    set<string> visited;
    stack<treeNode*> stk;
    visited.insert(root->med);
    stk.push(root);
    while (!stk.empty())
    {
        treeNode* temp = stk.top();
        stk.pop();
        if (temp->med == medicine)
        {
            cout << "medicine found using DFS" << endl;
            medFound = true;
            currMed = medicine;
            effects = temp->sideEffects;
            subs = temp->subs;
            cout << currMed << endl;
            for (auto item : temp->sideEffects)
            {
                cout << item << " ";
            }
            cout << endl;
            for (auto item : temp->subs)
            {
                cout << item << " ";
            }
            cout << endl;
            return true;
        }
        // if not already visited
        if (temp->left != nullptr)
        {
            if (visited.count(temp->left->med) == 0)
            {
                visited.insert(temp->left->med);
                stk.push(temp->left);
            }
        }
        if (temp->right != nullptr)
        {
            if (visited.count(temp->right->med) == 0)
            {
                visited.insert(temp->right->med);
                stk.push(temp->right);
            }
        }
    }
    return false;
}
void medTree::searchMedDFS(string medicine)
{
    if (searchMedHelperDFS(root, medicine))
        return;
    else
        cout << "DFS search failed" << endl;
}
// breadth-first travsersal
bool medTree::searchMedHelperBFS(treeNode* root, string medicine)
{
    medFound = false;
    queue<treeNode*> q;
    set<string> visited;
    q.emplace(root);
    visited.insert(root->med);
    while (!q.empty())
    {
        treeNode* temp = q.front();
        q.pop();
        if (temp->med == medicine)
        {
            cout << "medicine found using BFS" << endl;
            medFound = true;
            currMed = medicine;
            effects = temp->sideEffects;
            subs = temp->subs;
            cout << currMed << endl;
            for (auto item : temp->sideEffects)
            {
                cout << item << " ";
            }
            cout << endl;
            for (auto item : temp->subs)
            {
                cout << item << " ";
            }
            cout << endl;
            return true;
        }
        if (temp->left != nullptr)
        {
            if (visited.count(temp->left->med) == 0)
            {
                visited.insert(temp->left->med);
                q.emplace(temp->left);
            }
        }
        if (temp->right != nullptr)
        {
            if (visited.count(temp->right->med) == 0)
            {
                visited.insert(temp->right->med);
                q.emplace(temp->right);
            }
        }
    }
    return false;
}
void medTree::searchMedBFS(string medicine)
{
    if (searchMedHelperBFS(root, medicine))
        return;
    else
        cout << "BFS search failed" << endl;
}