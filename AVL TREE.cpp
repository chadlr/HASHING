//---------------AVL TREE DATA STRUCTURE---------------
#include<iostream>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<ctime>
#include<conio.h>

using namespace std;

//----------------------------------------------------
//Node representation
//The node store char value;info
//Pointer to left subtree; left
//Pointer to right subtree; right
//----------------------------------------------------

struct TreeNode
{
    string info;
    struct TreeNode *left;
    struct TreeNode *right;
}*root;

class AVL_TREE
{
    public:
        int height(TreeNode *);
        int diff(TreeNode *);
        void inorder(TreeNode *);
        TreeNode *right_right(TreeNode *);
        TreeNode *left_left(TreeNode *);
        TreeNode *left_right(TreeNode *);
        TreeNode *right_left(TreeNode *);
        TreeNode* balance(TreeNode *);
        TreeNode* insert(TreeNode *, string );
        TreeNode* search(TreeNode *, string);
		TreeNode* remove(TreeNode *, string);
		
        AVL_TREE()
        {
            root = NULL;
        }
};


//---------------------TREE HEIGHT---------------------//
int AVL_TREE::height(TreeNode *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

//--------------------HEIGHT DELTA:--------------------//
int AVL_TREE::diff(TreeNode *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
//------------------ROTATE RIGHT-RIGHT-----------------//
TreeNode *AVL_TREE::right_right(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
//------------------ROTATE LEFT-LEFT:------------------//
TreeNode *AVL_TREE::left_left(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
//------------------ROTATE LEFT-RIGHT------------------//
TreeNode *AVL_TREE::left_right(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->left;
    parent->left = right_right (temp);
    return left_left (parent);
}
//------------------ROTATE RIGHT-LEFT------------------//
TreeNode *AVL_TREE::right_left(TreeNode *parent)
{
    TreeNode *temp;
    temp = parent->right;
    parent->right = left_left (temp);
    return right_right (parent);
}
//--------------------BALANCE TREES--------------------//
TreeNode *AVL_TREE::balance(TreeNode *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = left_left (temp);
        else
            temp = left_right (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = right_left (temp);
        else
            temp = right_right (temp);
    }
    return temp;
}
string LargestRight (TreeNode*& root)
{
       string info;
       info = root->info;
       if (root->right !=NULL)
       {
            return LargestRight(root->right);
       }
       else 
       {
            root=NULL;
            return info;
       }
}
//-------------SEARCH LOWEST TREE ELEMENT:-------------//
string Lowest (TreeNode*& root)
{
    if (root->left !=NULL)
    {
         return LargestRight(root->left);
         //return Lowest(root->left);
    }
    else
    {
        string info;
        info=root->info;
        if(root->right !=NULL)
        {
             root = root->right;
        }
        else
        {
            root=NULL;
        }
        return info;
    }
}

//--------------INSERT ELEMENT INTO TREE:--------------//
TreeNode *AVL_TREE::insert(TreeNode *root, string value)
{
    if (root == NULL)
    {
        root = new TreeNode;
        root->info = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value.compare(root->info)<0)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value.compare(root->info) >=0)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

//--------------SEARCH ELEMENT FROM TREE:--------------//
 TreeNode *AVL_TREE::search(TreeNode *root, string value)
 {
    if (root == NULL)
    {
         cout<<"Element found"<<endl;
    }
    else if (value.compare(root->info)<0)
    {
         root->left = search(root->left, value);
         //root = balance (root);
    }
    else if (value.compare(root->info) >0)
    {
         root->right = search(root->right, value);
         //root = balance (root);
    }
    else //if (value.compare(root->info) = 0)
    {
         cout<<"found"<<endl;
    }
    return root;
 }

//--------------REMOVE ELEMENT FROM TREE:--------------//
  TreeNode *AVL_TREE::remove(TreeNode *root, string value)
 {
    if (root == NULL)
    {
         cout<<"not found"<<endl;
    }
    else if (value.compare(root->info)<0)
    {
         root->left = remove(root->left, value);
    }
    else if (value.compare(root->info) >0)
    {
         root->right = remove(root->right, value);
    }
    else //if (value.compare(root->info) = 0)
    {
        if (root->right !=NULL)
        {
             root->info = Lowest(root->right);
        }
        else if (root->left !=NULL)
        {
             root = root->left;
        }
        else
        {
            root = NULL;
            root = balance(root);
        }
            cout<<"Element deleted"<<endl;
    }
    return root;
 }
 
//----------------PRINT TREE (INORDER):----------------//
void AVL_TREE::inorder(TreeNode *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->info<<"  ";
    inorder (tree->right);
}

int main()
{
    char choice;
    string item;
    AVL_TREE avl;
    string line;
    clock_t start;
    double duration;
    ifstream file("InputFile.txt");    
    while (1)
    {
        system("CLS");
        cout<<"-----------------AVL TREE OPERATIONS-----------------"<<endl;
        cout<<"1.Insert element"<<endl;
        cout<<"2.Upload info from file"<<endl;
        cout<<"3.Search element from tree"<<endl;
		cout<<"4.Remove element from tree"<<endl;
        cout<<"5.Print tree (inorder)"<<endl;
        cout<<"6.Exit"<<endl<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case '1':
            cout<<"Enter value to be inserted: ";
            cin>>item;
            start = std::clock();
            root = avl.insert(root, item);
            cout<<"Element added"<<endl;
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            cout<<endl<<"Time Elapsed: "<<duration<<endl;
            start = 0;
            duration = 0;
            getch();
            break;
        case '2':{
             string value;
             cout<<endl<<endl<<"Enter file path: ";
			 getline(cin, value);
			 cout<<endl<<endl;
			 
			 //ifstream file(value,ios::in);
			 string out;
             
			 start = std::clock();
			 while(getline (file,line)){
				 root = avl.insert(root,line);
			 }
            cout<<"Inputs from file inserted"<<endl;
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            cout<<endl<<"Time Elapsed: "<<duration<<endl;
            start = 0;
            duration = 0;
            //line = NULL;
            //avl.display(root, 1);
            getch();
            break;
            }
		case '3':
            cout<<"Enter value to be searched:";
            cin>>item;
            start = std::clock();
            root = avl.search(root, item);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            cout<<endl<<"Time Elapsed: "<<duration<<endl;
            start = 0;
            duration = 0;
            getch();
            break;
        case '4':
		    cout<<"Enter value to be deleted: ";
            cin>>item;
            start = std::clock();
            root = avl.remove(root, item);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            cout<<endl<<"Time Elapsed: "<<duration<<endl;
            start = 0;
            duration = 0;
            getch();
            break;
		case '5':
            cout<<"Print tree (inorder):"<<endl;
            start = std::clock();
            avl.inorder(root);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
            cout<<endl<<endl<<"Time Elapsed: "<<duration<<endl;
            start = 0;
            duration = 0;
            getch();
            break;
        case '6':
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
            getch();
            break;
        }
    }
    return 0;
}
