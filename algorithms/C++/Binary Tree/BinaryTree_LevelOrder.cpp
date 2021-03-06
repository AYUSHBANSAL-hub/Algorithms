/* Binary Tree Level Order Traversal Input and Output
 * @author : Ravi Anand
 * @date : 2 October 2020
 */

#include<iostream>
#include<queue>
using namespace std;

template<class T>
class BinaryTreeNode{               // template class for Binary Tree Node
public:
	T data;                         // data of T type according to the argument of template
	BinaryTreeNode<T> *left;        // left pointer to point to the left children of node
	BinaryTreeNode<T> *right;       // right pointer to point to the right children of node

	explicit BinaryTreeNode(T val){          // constructor to intialize value of data members
		this->data = val;
		left = nullptr;
		right = nullptr;
	}
};


template<class T>
BinaryTreeNode<T>* takeInputLevelOrder(){          // template function to take input of tree in level order until entered '-1'

	T data;
	cout<<"Enter the root data"<<endl;             // data of root node is entered
	cin>>data;
	
	if(data == -1)return nullptr;                  // if data is -1 then return there is no children of the node
	
	BinaryTreeNode<T> *root = new BinaryTreeNode<T>(data);
	queue<BinaryTreeNode<T>*> *totakeInput = new queue<BinaryTreeNode<T>*>();    // A queue is created of BinaryTreeNode pointer type to store Binary Tree Node to take input level wise by using FIFO technique of Queue
	totakeInput->push(root);

	while(!totakeInput->empty()){
		BinaryTreeNode<T> *temp = totakeInput->front();             // front element of queue is stored in temp variable 
		totakeInput->pop();                                         // front element is popped from the queue

		cout<<"Enter the left node of "<<temp->data<<endl;          // data of left node is entered
		cin>>data;
		
		if(data != -1){
		BinaryTreeNode<T> *leftnode = new BinaryTreeNode<T>(data);   // left node is created 
		temp->left = leftnode;                                       // leftnode is linked to the temp node popped from queue by pointing left pointer to it
		totakeInput->push(leftnode);                                 // left node is pushed in the queue to take input of it when it is at front position in the queue
		}

		cout<<"Enter the right node of "<<temp->data<<endl;          // same as left node
		cin>>data;
		if(data != -1){
		BinaryTreeNode<T> *rightnode = new BinaryTreeNode<T>(data);
		temp->right = rightnode;
		totakeInput->push(rightnode);
		}
	}
	return root;
}

template<typename T>
void printLevelOrder(BinaryTreeNode<T> *root){                      // template function to print Binary Tree level wise
	
	if(root == nullptr)return;                                       // if root is null then return as the tree is empty
	
  queue<BinaryTreeNode<T>*> *qu = new queue<BinaryTreeNode<T>*>();    // queue is created to store BinaryTreeNode pointers to print level wise using FIFO technique
  qu->push(root);

  while(!qu->empty()){
	  
    BinaryTreeNode<T> *node = qu->front();                           // front node is stored in node variable
    qu->pop();                                                       // front element is popped
    
    if(node != nullptr)cout<<node->data<<" ";                       // node is printed
    
    if(node->left != nullptr)qu->push(node->left);
    
    if(node->right != nullptr)qu->push(node->right);
    }
  }

}

template<class T>
void PreOrder_Traversal(BinaryTreeNode<T> *root){         // template PreOrder traversal function using recursion
	  if(root == nullptr)return;
	  
	  cout<<root->data<<" ";
	  PreOrder_Traversal(root->left);
	  PreOrder_Traversal(root->right);
	}

template<class T>
void PostOrder_Traversal(BinaryTreeNode<T> *root){       // template PostOrder traversal function using recursion 
	if(root == nullptr)return;
	
	PostOrder_Traversal(root->left);
	PostOrder_Traversal(root->right);
	cout<<root->data<<" ";
	}
	
template<class T>
void InOrder_Traversal(BinaryTreeNode<T> *root){         //  template InOrder traversal function using recursion 
	if(root == nullptr)return;
	
	InOrder_Traversal(root->left);
	cout<<root->data<<" ";
	InOrder_Traversal(root->right);
	}
	
int main(){
	 BinaryTreeNode<int> *root = takeInputLevelOrder<int>();
	 
	 cout<<"Level Order : "; printLevelOrder(root); cout<<endl;	  
	 cout<<" PreOrder : "; PreOrder_Traversal(root); cout<<endl;
	 cout<<" PostOrder : "; PostOrder_Traversal(root); cout<<endl;
	 cout<<" InOrder : "; InOrder_Traversal(root);
	}

/*
Enter the root data
1
Enter the left node of 1
2
Enter the right node of 1
3
Enter the left node of 2
4
Enter the right node of 2
-1
Enter the left node of 3
-1
Enter the right node of 3
-1
Enter the left node of 4
-1
Enter the right node of 4
5
Enter the left node of 5
-1
Enter the right node of 5
-1
* Level Order : 1 2 3 4 5  
* PreOrder : 1 2 4 5 3 
  PostOrder : 5 4 2 3 1 
  InOrder : 4 5 2 1 3 


           1
          / \
         2   3
        /
       4
        \
         5
         
         
   */
