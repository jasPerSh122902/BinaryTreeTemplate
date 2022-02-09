#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;
	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);
	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);
	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);


	void draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	m_root = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	//if m_roots left and right are nullptr which is null...
	if (m_root == nullptr)
		return true;//...return true
	if (m_root->hasLeft() = false)
		return true;
	if (m_root->hasRight() = false)
		return true;
	return false;//...if not false
}


template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	TreeNode<T>* m_insertRoot = new TreeNode<T>(value);
	//just for the start were there is no Nodes
	if (m_root == nullptr)
	{
		//set root to the insertRoot
		m_root = m_insertRoot;
	}
	//made veriables
	bool beginSort = true;
	TreeNode<T>* currentNode = m_root;

	while (beginSort)
	{
		//gets the right side-----------------------------------
		if (m_insertRoot->getData() > currentNode->getData())
		{
			//checks if the current node has right
			if (currentNode->hasRight())
			{
				//makes the currentNode into the right
				currentNode = currentNode->getRight();
			}
			//if the node dos not have a right
			else
			{
				//set the right to the m_insertRoot
				currentNode->setRight(m_insertRoot);
				beginSort = false;//set sorting to false to break out of loop
			}
		}
		//---------------------------------------------------
		//gets the left
		if (m_insertRoot->getData() < currentNode->getData())
		{
			//checks if the current node has left
			if (currentNode->hasLeft())
			{
				//makes the currentNode into the left
				currentNode = currentNode->getLeft();
			}
			//if the node dos not have a left
			else
			{
				//set the right to the m_insertRoot
				currentNode->setLeft(m_insertRoot);
				beginSort = false;//set sorting to false to break out of loop
			}
		}
		//---------------------------------------------------
		if (m_insertRoot->getData() == currentNode->getData())
			beginSort = false;
	}
};

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	bool searching = true;
	TreeNode<T>* currentNode = m_root;


	while (searching)
	{
		//searches the right-----------------------
		if (value > currentNode->getData())
		{
			//if the current has a right
			if (currentNode->hasRight())
				currentNode = currentNode->getRight();//make the current node in to the right
			else
				break;
		}//-------------------------------------------
		//searches the left side-----------------------
		else if (value < currentNode->getData())
		{
			//if the current has a left
			if (currentNode->hasLeft())
				currentNode = currentNode->getLeft();//make the current node in to the left
			else
				break;
		}//-------------------------------------------
		//if the value is the currentNodes data
		else if (value == currentNode->getData())
			return currentNode;//return you dont need to do any thing
	}
	//if a fail happens return NULL.
	return NULL;
}


template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	bool search = true;
	TreeNode<T>* currentNode = nullptr;
	TreeNode<T>* currentParent = nullptr;
	while (search)
	{
		//searches the right side---------------
		if (searchValue > currentNode->getData())
		{
			//check to see if the current has a right
			if (currentNode->hasRight())
			{
				//makes parent into current Node
				currentParent = currentNode;
				currentNode = currentParent->getRight();//and mkakes the current Node into the current parents right.
			}//that is to move the currentNode right because this if loop is meant to move right.
			else
				break;
		}//-------------------------------------

		//searches the left----------------------------------
		if (searchValue < currentNode->getData())
		{
			//if current has a left
			if (currentNode->hasLeft())
			{
				currentParent = currentNode;
				currentNode = currentParent->getLeft();//and mkakes the current Node into the current parents left.
			}//that is to move the currentNode left because this if loop is meant to move left.
			else
				break;
		}//----------------------------------------------

		//This is if the value is the current Node 
		else if (searchValue == currentNode->getData())
		{
			nodeFound = currentNode;//makes found so current node
			if (currentParent->getData() == nodeFound->getData())//makes the current parents data to the found data
			{
				//makes paranent null
				nodeParent = nullptr;
			}
			else//and makes the current parent bakc  to null
				nodeParent = currentParent;
			return true;//then return that it was succsseful
		}
	}
	//if it failes then return false
	return false;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//Decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//Check if the current node is null
	if (currentNode)
	{
		//Draws the left child if this node has one
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between this child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	//pointer to nodes that are NPR
	TreeNode<T>* currentNode = nullptr;
	TreeNode<T>* nodeRemove = nullptr;
	TreeNode<T>* currentParent = nullptr;

	if (!findNode(value, nodeRemove, currentParent))
		return;
	//if then node has a right------------------------------------------------------------------------
	if (nodeRemove->hasRight())
	{
		//make the current node to the nodes removes right
		currentNode = nodeRemove->getRight();
		//if the current node has a left
		if (currentNode->hasLeft())
		{
			//make the parent into teh current
			currentParent = currentNode;

			bool searching = true;
			//while seaching is haveing loop
			while (searching)
			{
				//if the root is not null
				if (m_root != NULL)
				{
					//searches the left if it has a left
					if (currentParent->getLeft()->hasLeft())
					{
						//make the parent to the parents left
						currentParent = currentParent->getLeft();
					}
					//searches the left side
					else
					{
						//make the parent into the parents left
						currentParent = currentParent->getLeft();
						//turen seaching to false
						searching = false;
					}

				}
			}
			//-------------------- end loop from while
			//make the nodes remove data to the current Nodes data
			nodeRemove->setData(currentNode->getData());
			//make the parent left to the current Nodes to the right
			currentParent->setLeft(currentNode->getRight());
			//delete the currentNode
			delete currentNode;
		}
	}//------------------------------------------------------------------------------------------
	//this is the node has a left-------------------------------------------------------
	else
	{
		//if the node to delete has a parent
		if (currentParent)
		{
			//the remove has a left
			if (nodeRemove->hasLeft()) 
			{
				//make the currentNode to the node removes left
				currentNode = nodeRemove->getLeft();

				//make the node to remove to the parents left
				if (currentParent->getLeft() == nodeRemove)
					currentParent->setLeft(currentNode);//set the parents left to currentNode

				//make the node to remove to the parents right
				else if (currentParent->getRight() == nodeRemove)
					currentParent->setRight(currentNode);//set the parents right to currentNode
				//delete node remove
				delete nodeRemove;
				return;
			}
		}
		//if the node dos not have a parent
		else
		{
			//if the node remove has a left
			if (nodeRemove->hasLeft())
			{
				//make currentNode to the noderemoves left
				currentNode = nodeRemove->getLeft();
				//make root equal to current node
				m_root = currentNode;
				//delete noderemove
				delete nodeRemove;
				return;
			}

			else
			{
				//delete the node remove
				delete nodeRemove;
				//make root equal to nullptr
				m_root = nullptr;
			}
		}
		//delete the current node
		delete currentNode;
	}//-------------------------------------------------------------------------
}