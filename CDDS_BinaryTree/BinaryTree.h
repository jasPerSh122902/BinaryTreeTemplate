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
	TreeNode<T>* m_last;
};

#endif

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	m_root = nullptr;
	m_last = nullptr;
}

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
	/*TreeNode<T>* m_insertRoot = new TreeNode<T>(value);

	if (m_root == nullptr)
	{
		m_root = m_insertRoot;
		m_last = m_root;
	}

	if (m_insertRoot->getData() > m_root->getData())
	{
		if (m_insertRoot->getData() > m_last->getData())
		{
			TreeNode<T>* m_indexRoot = m_last;
			while (m_indexRoot->getRight() != nullptr)
			{
				m_indexRoot = m_indexRoot->getRight();
				if (m_insertRoot->getData() < m_indexRoot->getData())
				{
					m_last = m_indexRoot;
					insert(value);
				}
			}
			m_indexRoot->setRight(m_insertRoot);
			m_last = m_insertRoot;
		}
		if (m_insertRoot->getData() < m_last->getData())
		{
			TreeNode<T>* m_indexRoot = m_last;
			while (m_indexRoot->getLeft() != nullptr)
			{
				m_indexRoot = m_indexRoot->getLeft();
				if (m_insertRoot->getData() > m_indexRoot->getData())
				{
					m_last = m_indexRoot;
					insert(value);
				}
			}
			m_indexRoot->setLeft(m_insertRoot);
			m_last = m_insertRoot;
		}
	}*/


	TreeNode<T>* m_insertRoot = new TreeNode<T>(value);
	if (m_root == nullptr)
	{
		m_root = m_insertRoot;
		m_last = m_root;
	}

	//This is to add things to the right 
	//compared the inserRoots data to the roots data
	//if compared is greater then go in
	if (m_insertRoot->getData() > m_root->getData())
	{
		//compared the insertRoots data to the last data
		//it it is greater go in
		//gos right
		if (m_insertRoot->getData() > m_last->getData())
		{
			//set index to m_root
			TreeNode<T>* m_indexRoot = m_last;
			//loop if index is not nullptr
			if (m_indexRoot->getRight() != nullptr)
			{
				//set index root to index roots right
				//m_indexRoot = m_indexRoot->getRight();
				//if inserts roots data is greater than index roots data
				if (m_insertRoot->getData() > m_indexRoot->getData())
				{
					//m_last = m_indexRoot->getRight();
					m_last = m_indexRoot;
					//m_indexRoot->setRight(m_insertRoot);
					insert(value);
				}

			}
			m_indexRoot->setRight(m_insertRoot);
			m_last = m_insertRoot;
			
		}
		//if get right is null ptr go in
		//else
		//{
		//	//set the right of the m_inserRoot
		//	m_insertRoot->setLeft(m_insertRoot);
		//	//set last to insertRoot
		//	m_last = m_insertRoot;
		//}
	
		//compared the insertRoots data to the last data
		//it it is less go in
		//gos left
		if (m_insertRoot->getData() < m_last->getData())
		{
			//set index to m_root
			TreeNode<T>* m_indexRoot = m_last;
			//loop if index is not nullptr
			if (m_indexRoot->getLeft() != nullptr)
			{
				//set index root to index roots right
				//m_insertRoot = m_insertRoot->getLeft();
				//if inserts roots data is greater than index roots data
				if (m_insertRoot->getData() < m_indexRoot->getData())
				{
					//set last to index
					m_last->setLeft(m_indexRoot);
					//go back to insert
					insert(value);
				}
			}
			m_indexRoot->setRight(m_insertRoot);
			m_last = m_insertRoot;
		
		}
		//else
		//{
		//	//set the let of the m_inserRoot
		//	m_insertRoot->setLeft(m_insertRoot);
		//	//set last to insertRoot
		//	m_last = m_insertRoot;
		//}
	}

	//This is to add things to the left
	//compared the inserRoots data to the roots data
	//if compared is greater then go in
	if (m_insertRoot->getData() < m_last->getData())
	{
		//compared the insertRoots data to the last data
		//it it is greater go in
		//gos right
		if (m_insertRoot->getData() > m_last->getData())
		{
			//set index to m_root
			TreeNode<T>* m_indexRoot = m_last;
			//loop if index is not nullptr
			while (m_indexRoot->getRight() != nullptr)
			{
				//set index root to index roots right
				//m_indexRoot = m_indexRoot->getRight();
				//if inserts roots data is greater than index roots data
				if (m_insertRoot->getData() > m_indexRoot->getData())
				{
					//m_last = m_indexRoot->getRight();
					m_last->setRight(m_indexRoot);
					//m_indexRoot->setRight(m_insertRoot);
					insert(value);
				}
			}
			//if get left is null ptr go in
			if (m_indexRoot->getRight() == nullptr)
			{
				//set the let of the m_inserRoot
				m_indexRoot->setRight(m_insertRoot);
				//set last to insertRoot
				m_last = m_insertRoot;
			}
		}
		//compared the insertRoots data to the last data
		//it it is less go in
		//gos left
		if (m_insertRoot->getData() < m_last->getData())
		{
			//set index to m_root
			TreeNode<T>* m_indexRoot = m_last;
			//loop if index is not nullptr
			while (m_indexRoot->getLeft() != nullptr)
			{
				//set index root to index roots right
				//m_insertRoot = m_insertRoot->getLeft();
				//if inserts roots data is greater than index roots data
				if (m_insertRoot->getData() < m_indexRoot->getData())
				{
					//set last to index
					m_last->setLeft(m_indexRoot);
					//go back to insert
					insert(value);
				}
			}
			//if get left is null ptr go in
			if (m_indexRoot->getLeft() == nullptr)
			{
				//set the let of the m_inserRoot
				m_indexRoot->setLeft(m_insertRoot);
				//set last to insertRoot
				m_last = m_insertRoot;
			}
		}
	}
};


template<typename T>
inline void BinaryTree<T>::remove(T value)
{

}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	//gets the m_roots data and makes it i then compares i to the value.
	if (m_root->getData() > value) 
	{
		for (T i = m_root->getData(); i != value; i--)
		{
			if (i == value)//if i is value then... 
			{
				return  (TreeNode<T>*) value;//...return value
			}
		}
	}

	else if (m_root->getData() < value)
	{
		for (T i = m_root->getData(); i != value; i++)
		{
			if (i == value)//if i is value then... 
			{
				return  (TreeNode<T>*) value;//...return value
			}
		}
	}
	return  (TreeNode<T>*) value;
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
	while (searchValue != nodeFound->getData())
	{
		if (searchValue > nodeFound->getData()) {
			nodeFound->getLeft();
			nodeParent = nodeFound;
			nodeFound = nodeParent->getLeft();
		}
		if (searchValue < nodeFound->getData()) {
			nodeFound->getRight();
			nodeParent = nodeFound;
			nodeFound = nodeParent->getRight();
		}
		else if (searchValue == nodeFound->getData()) 
		{
			nodeParent->getLeft()->getData() = nodeFound->getData();
			searchValue == nodeFound->getData();
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