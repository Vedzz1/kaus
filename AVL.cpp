#include <iostream>
using namespace std;

struct node {
    int data;
    node* left = NULL;
    node* right = NULL;
};

struct node* newnode(int d1) {
    struct node* n1 = (node *)malloc(sizeof(node));
    n1->data = d1;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}

struct node* insert(node* n1, int d1) {
    if (n1 == NULL) {
        return newnode(d1);
    }

    if (d1 < n1->data) 
	{ 
        n1->left = insert(n1->left, d1);
    }
    
    else if(d1 > n1->data) 
	{
        n1->right = insert(n1->right, d1);
    }

    return n1;
}

void preorder(node *temp)
{
	if(temp != NULL)
	{
		cout<<temp->data<<"\t";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<"\t";
		inorder(temp->right);
	}
}

void postorder(node *temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<"\t";
	}
}

void mirror(node *root)
{
    if(root==NULL)
        return ;
    else
    {
    node *temp;
    mirror(root->left);
    mirror(root->right);
    
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    }
}

int height(node *n1)
{
    if(n1==NULL)
        return 0;
    int lh=height(n1->left);
    int rh=height(n1->right);
    int tot=max(lh,rh)+1;
    return tot;
}

void leafnode(node * n1)
{
	if(n1==NULL)
		return ;
	if(n1->left == NULL && n1->right == NULL)	
	{
		cout<<n1->data<<"\t";
		return ;
	}
	if(n1->left)
		leafnode(n1->left);
	if(n1->right)
		leafnode(n1->right);
}

int countnode(node *n1)
{
	if(n1==NULL)
		return 0;
	int lc=countnode(n1->left);
	int rc=countnode(n1->right);
	return rc+lc+1;
}

int main() 
{
	node * root=NULL;	
	int ch;
	char ch1[5];
    cout << "1. Creation Of New Tree \n2. Tree Traversal \n3. Height Of Tree \n4. Mirror Image Of Tree \n5. Print Leaf Nodes Of Tree\n6. Total Number Of Nodes";
 
    do
	{
    	cout<<"Enter Your Choice: ";
		cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			root=newnode(10);
    			root = insert(root, 20);
    			root = insert(root, 5);
    			root = insert(root, 2);
    			
				cout << "\nTree Is:" << "\n\t\t\t" << root->data;
    			cout << "\n\t\t\t/\\";
    			cout << "\n\t\t      " << root->left->data << "  " << root->right->data;
    			cout << "\n\t\t      /";
    			cout << "\n\t\t     " << root->left->left->data;
    			break;
    	
    		case 2:
    			cout<<"\nPreorder: ";
				preorder(root);
    	
    			cout<<"\nInorder: ";
    			inorder(root);
    		
    			cout<<"\nPostorder: ";
    			postorder(root);
    			break;
    			
    		case 3:
    			mirror(root);
    			cout << "\nMirror Image Of Tree Is:" << "\n\t\t\t" << root->data;
	    		cout << "\n\t\t\t/\\";
	    		cout << "\n\t\t      " << root->left->data << "  " << root->right->data;
	    		cout << "\n\t\t\t   \\";
	    		cout << "\n\t\t\t    " << root->right->right->data;
    			break;
    			
    		case 4:
    			cout<<"\nHeight Of Tree Is: "<<height(root);
    			break;
    		
    		case 5:
    			cout<<"\nLeaf Nodes Of Tree Are: ";
    			leafnode(root);
    			break;
    		
    		case 6:
    			cout<<"\nNumber Of Nodes Are: "<<countnode(root);
    			break;
    		
    		default :
    			cout<<"\nInvalid Choice!";
    			
		}
		cout<<"\n\nDo you want to continue: ";
		cin>>ch1;
	}
while (strcmp(ch1,"Yes")==0||strcmp(ch1,"yes")==0);
	return 0;
}