#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
};

static int idx=-1;

Node *BuildTree(vector<int> &preorder)
{
    idx++;
    if(preorder[idx]==-1)
    {
        return NULL;
    }
    Node *root=new Node(preorder[idx]);
    root->left=BuildTree(preorder);
    root->right=BuildTree(preorder);
    return root;
}

void Preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

vector<vector<int>> LevelOrder(Node *root)
{
    vector<vector<int>>result;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *safe=q.front();
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            level.push_back(q.front()->data);
            if(q.front()->left)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        result.push_back(level);
    }
    return result;
}

int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int count(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}

int sum(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
        int leftsum=sum(root->left);
        int rightsum=sum(root->right);
        return leftsum+rightsum+root->data;
}

bool search(Node *root,int target)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==target)
    {
        return true;
    }
    return search(root->left,target) || search(root->right,target);
}

// Top View of Binary Tree: In Level Order Traversal, we will keep track of Horizontal Distance of each node from root node.
// Horizontal Distance of root node is 0. Horizontal Distance of left child is Horizontal Distance of parent - 1.
// Horizontal Distance of right child is Horizontal Distance of parent + 1.
// We will use map to store the first node at each horizontal distance.
// Finally, we will return the values of the map in sorted order of keys.
vector<int> TopView(Node *root)
{
    vector<int>result;
    if(root==NULL)
    {
        return result;
    }
    map<int,int>topnode;
    queue<pair<Node *,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node *,int>temp=q.front();
        q.pop();
        Node *frontnode=temp.first;
        int hd=temp.second;
        if(topnode.find(hd)==topnode.end())
        {
            topnode[hd]=frontnode->data;
        }
        if(frontnode->left)
        {
            q.push({frontnode->left,hd-1});
        }
        if(frontnode->right)
        {
            q.push({frontnode->right,hd+1});
        }
    }
    for(auto i:topnode)
    {
        result.push_back(i.second);
    }
    return result;
}

bool RootNodePath(Node *root,int target,vector<int> &path)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==target)
    {
        path.push_back(root->data);
        return true;
    }
    if(RootNodePath(root->left,target,path) || RootNodePath(root->right,target,path))
    {
        path.push_back(root->data);
        return true;
    }
    return false;
}

int main()
{
    vector<int>preorder={6,3,-1,-1,9,7,-1,-1,11,-1,-1};
    Node *root=BuildTree(preorder);
    cout<<"Preorder Traversal of the tree is: ";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal of the tree is: ";
    Inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal of the tree is: ";
    Postorder(root);
    cout<<endl;
    vector<vector<int>>result=LevelOrder(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<"Level "<<i+1<<": ";
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Height of the tree is: "<<height(root)<<endl;
    cout<<"Number of nodes in the tree is: "<<count(root)<<endl;
    cout<<"Sum of all nodes in the tree is: "<<sum(root)<<endl;
    cout<<"Target Node is present in the tree: "<<(search(root,9)?"True":"False")<<endl;
    cout<<"Top View of the tree is: ";
    vector<int>topview=TopView(root);
    for(int i=0;i<topview.size();i++)
    {
        cout<<topview[i]<<" ";
    }
    cout<<endl;
    vector<int>path;  
    if(RootNodePath(root,7,path))
    {
        cout<<"Root to Node Path for target "<<7<<" is: ";
        for(int i=path.size()-2;i>=0;i--)
        {
            cout<<path[i]<<"->";
        }
        cout<<path[path.size()-1];
        cout<<endl;
    }
    else
    {
        cout<<"Target Node is not present in the tree"<<endl;
    }
    return 0;

}