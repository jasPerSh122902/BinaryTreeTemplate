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

	
	void draw(TreeNode<T> * currentNode, int x, int y, int horizontalSpacing, TreeNode<T> * selected = nullptr);
		
	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline BinaryTree<T>::BinaryTree()
{}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	//if m_roots left and right are nullptr which is null...
	if (m_root->getLeft() && m_root->getRight() == nullptr)
		return true;//...return true
	return false;//...if not false
}


template<typename T>
inline void BinaryTree<T>::insert(T value)
{		
	TreeNode<T>* m_newRoot = new TreeNode<T>(value);

	if (m_root > m_newRoot){
		while(m_root->hasLeft())
		{
			(TreeNode<T>*)m_root->getLeft()->getData() > (TreeNode<T>*)m_newRoot;
			if (m_root->hasLeft() == NULL)
				m_root->getLeft() == m_newRoot;
			insert(value);}}

	if (m_root > m_newRoot){
		while(m_root->hasRight())
		{
			(TreeNode<T>*)m_root->getRight()->getData() > m_newRoot;
			if (m_root->hasRight() == NULL)
				m_root->getRight() == m_newRoot;
			insert(value);}}

	
}


template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	//iterates through the left
	if (m_root->hasLeft() != true)
	{
		//if you have to go right on the tree
		for (T i = m_root->getLeft()->getData(); i != value; i++)
		{
			//check to see if the value is i
			if (i == value)
			{
				//set i to value if yes
				i = value;
				//delete i;//delete i
			}
		}
	}
	//iterates through the right
	if (m_root->hasRight() != true)
	{
		//if you have to go left
		for (T i = m_root->getRight()->getData(); i != value; i++)
		{
			//check to see if the value is i
			if (i == value)
			{
				//set i to value if yes
				i = value;
				//delete i;//delete i
			}
		}
	}
	//iterats between the left and the right m_root
	if (m_root->hasLeft() && m_root->hasLeft() != true)
	{
		//if you have to go left
		for (T i = m_root->getRight()->getData(); i != value; i++)
		{
			for(T c = m_root->getLeft()->getData(); i != value; c++)
			//check to see if the value is i
			if (i == value)
			{
				//set i to value if yes
				i = value;
				//delete i;//delete i
			}
		}

	}
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	//gets the m_roots data and makes it i then compares i to the value.
	//
	for (T i = m_root->getData(); i != value;)
		if(i == value)//if i is value then... 
			return  (TreeNode<T>*) value;//...return value
}

//this needs to be worked on
template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

//this needs to be worked on
template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	while (searchValue != nodeFound)
	{
		if (searchValue > nodeFound) {
			nodeFound->getLeft;
			nodeParent = nodeFound;
			nodeFound = nodeParent->getLeft;
		}
		if (searchValue < nodeFound) {
			nodeFound->getRight;
			nodeParent = nodeFound;
			nodeFound = nodeParent->getRight;
		}
		else if (searchValue == nodeFound) 
		{
			nodeParent->getLeft = nodeFound;
			searchValue == nodeFound;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//Decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//check if the current node is null
	if (currentNode) 
	{
		//Draws the left child if this node has one
		if (currentNode->hasLeft())
		{
			//Draws a line between th left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the Right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between th left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the Right child
			draw(currentNode->getRight(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		currentNode->draw(x,y, (selected == currentNode));
	}
}
