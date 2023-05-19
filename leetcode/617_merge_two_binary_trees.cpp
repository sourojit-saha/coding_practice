#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

    if (root1==NULL && root2==NULL){
        return root1;
    }

    if (root1==NULL && root2!=NULL){
        return root2;
    }

    if (root1!=NULL && root2==NULL){
        return root1;
    }

    int val1 = root1->val ? root1->val:0;
    int val2 = root2->val ? root2->val:0;

    // int val1 = 0;
    // int val2 = 0;

    // // std::cout<<root1<<" "<<root2<<std::endl;
    // std::cout<<root1<<" "<<root2<<" ";

    // if (root1!=NULL){
    //     // std::cout<<"a"<<std::endl;
    //     val1 = root1->val ? root1->val:0;
    // }

    // if (root2!=NULL){
    //     // std::cout<<"b"<<std::endl;
    //     val2 = root2->val ? root2->val:0;
    // }



    // TreeNode root = TreeNode(val1+val2);
    root1->val = val1+val2;

    std::cout<<"root1 val: "<<root1->val<<std::endl;

    // std::cout<<"----\n"<<std::endl;
    // std::cout<<root1<<std::endl;
    // std::cout<<root2<<std::endl;

    root1->left = mergeTrees(root1 ? root1->left:NULL, root2 ? root2->left:NULL);
    root1->right = mergeTrees(root1 ? root1->right:NULL, root2 ? root2->right:NULL);

    // root1->left = mergeTrees(root1->left, root2->left);
    // root1->right = mergeTrees(root1->right , root2->right);

    return root1;

}

void print_tree(TreeNode* t){
    if (t==NULL){
        return;
    }
    // int val1 = t->val ? t->val:0;
    int val1 = t->val;
    std::cout<<val1<<std::endl;
    print_tree(t->left);
    print_tree(t->right);

    return;

}

int main(){

    TreeNode a5 = TreeNode(5);
    TreeNode a3 = TreeNode(3, &a5, NULL);
    TreeNode a2 = TreeNode(2);
    TreeNode a1 = TreeNode(1, &a3, &a2);

    print_tree(&a1);
    std::cout<<std::endl;

    TreeNode b7 = TreeNode(7);
    TreeNode b3 = TreeNode(3, NULL, &b7);
    TreeNode b4 = TreeNode(4);
    TreeNode b1 = TreeNode(1, NULL, &b4);
    TreeNode b2 = TreeNode(2, &b1, &b3);

    print_tree(&b2);
    std::cout<<std::endl;

    mergeTrees(&a1, &b2);
    // mergeTrees(NULL, &a1);

    print_tree(&a1);
   

    return 0;
}