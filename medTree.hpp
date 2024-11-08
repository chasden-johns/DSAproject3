#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


struct treeNode{
        string med;
        vector<string> sideEffects;
        vector<string> subs;
        int height;
        treeNode* left;
        treeNode* right;
        treeNode(string medicine, vector<string>& sideEffects, vector<string>& subs)
        {
                this->med = medicine;
                this->sideEffects = sideEffects;
                this->subs = subs;
                this->height = 0;
                this->left = nullptr;
                this->right = nullptr;
        }
};

class medTree
{
private:
        bool medFound;
        treeNode* root = nullptr;
        string currMed;
        vector<string> effects;
        vector<string> subs;
        treeNode* insertMedHelper(treeNode* root, string medicine, vector<string>& sideEffects, vector<string>& subs);
        bool searchMedHelperDFS(treeNode* root, string medicine);
        bool searchMedHelperBFS(treeNode* root, string medicine);


        // rotations
        treeNode* rotateLeft(treeNode* node);
        treeNode* rotateRight(treeNode* node);
        treeNode* rotateLeftRight(treeNode* node);
        treeNode* rotateRightLeft(treeNode* node);
public:

        // insert new medicine
        void insertMed(string medicine, vector<string>& sideEffects, vector<string>& subs);

        // find given medicine in depth first traversal
        void searchMedDFS(string medicine);

        // find given medicine in breadth first traversal
        void searchMedBFS(string medicine);

        // list of side effects
        vector<string> getSideEffects(string medicine);

        // list of substitute medicine
        vector<string> getSubs(string medicine);

        // return BF
        int balanceFactor(treeNode* root);

        // return height
        int height(treeNode* root);

};
