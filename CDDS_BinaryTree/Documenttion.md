#BinaryTree

This program is meant to be a test to make and work with the idea of a binary tree


$File$ : _BinaryTree.h_

$Type$ : Tempate T

The Nodes hold information that can be pointers or eny viables

$Name$ :  BinaryTree()
+ Description : Is a baic contructor for the BinaryTree class.
* Visualibility : public

$Name$ :  ~BinaryTree()
+ Description : Is a baic decontructor for the BinaryTree class.
* Visualibility : public

$Name$ :  isEmpty() const
+ Description : searches to see is the m_root is nullptr
* Visualibility : public
* Type : bool

$Name$ :  insert(T value)
+ Description : creats a node with the value that is given
* Visualibility : public
* Type : void

$Name$ :  remvoe(T vlaue)
+ Description : remove the node at the given value
* Visualibility : public
* Type : void

$Name$ :  find(T value)
+ Description : finds the node at the given value
* Visualibility : public
* Type : TreeNode<T>*

$Name$ :  draw(TreeNode<T>* selected = nullptr)
+ Description : draws the treeNode that is given
* Visualibility : public
* Type : void

$Name$ :  findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
+ Description : finds the node that is the value and finds the node and keeps a parent.
* Visualibility : private
* Type : bool

$Name$ :  m_root
+ Description : is the start of the tree
* Visualibility : private
* Type : ReeNode<T>* 

$File$ : _TreeNode.h_

$Type$ : Tempate T

The Nodes hold information that can be pointers or eny viables

$Name$ :  TreeNode()
+ Description : Is a baic contructor for the TreeNode class.
* Visualibility : public

$Name$ :  TreeNode(T value)
+ Description : Is a baic contructor for the TreeNode class and takes in a value
* Visualibility : public

$Name$ :  ~TreeNode()
+ Description : Is a baic decontructor for the TreeNode class.
* Visualibility : public

$Name$  hasLeft()
+ Description : checks the varible of m_left if it is null
* Visualibility : public
* Type : bool

$Name$  hasRight()
+ Description : checks the varible of m_right if it is null
* Visualibility : public
* Type : bool

$Name$  getData()
+ Description : gets the value of the node
* Visualibility : public
* Type : T

$Name$  getLeft()
+ Description : checks the varible of m_left and gives a value
* Visualibility : public
* Type : TreeNode<T>*

$Name$  getRight()
+ Description : checks the varible of m_right and gives a value
* Visualibility : public
* Type : TreeNode<T>*

$Name$  setData(T vlaue)
+ Description : set the value of a node
* Visualibility : public
* Type : void

$Name$  setLeft()
+ Description : set the varible of m_left 
* Visualibility : public
* Type : void

$Name$  setRight()
+ Description : sets the varible of m_right
* Visualibility : public
* Type : void

$Name$  draw(int x, int y, bool selected = null)
+ Description : daws the tree
* Visualibility : public
* Type : void

$Name$ m_value
+ Description : is a value varible
* Visualibility : private
* Type : T

$Name$ m_left
+ Description : is a  varible that holds the value of m_left 
* Visualibility : private
* Type : TreeNode<T>*

$Name$ m_right
+ Description : is a  varible that holds the value of m_right
* Visualibility : private
* Type : TreeNode<T>*