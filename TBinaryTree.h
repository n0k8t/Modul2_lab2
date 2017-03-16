#ifndef MODUL2_LAB2_TBINARYTREE_H
#define MODUL2_LAB2_TBINARYTREE_H

#include <exception>
#include <iostream>

struct TExistElementException
	: public std::exception
{
	TExistElementException(char const* const message) throw()
		: std::exception(message)
	{
	}
};


struct TNotFoundException
	: public std::exception
{
	TNotFoundException(char const* const message) throw()
		: std::exception(message)
	{ }
};

class TBinaryTree
{
public:
	using value_type = int;

	struct TNode
	{
		value_type Data;
		TNode * Right;
		TNode * Left;

	private:
		TNode(const value_type& data, TNode * next = nullptr, TNode * prev = nullptr)
			: Data(data)
			, Right(next)
			, Left(prev)
		{ }
		TNode()
			: Data(value_type())
			, Right(nullptr)
			, Left(nullptr)
		{ }

		~TNode()
		{
			delete Left;
			delete Right;
		}

		friend class TBinaryTree;
	};

private:
	TNode * Root = nullptr;

    static void Print(std::ostream & out, TBinaryTree::TNode * node)
	{
		if (node)
		{
			Print(out, node->Left);
			out << std::endl << node->Data;
			Print(out, node->Right);
		}
	}

public:
	TBinaryTree()
	{ }

	~TBinaryTree()
	{
		delete Root;
	}

	void Insert(const value_type& data)
	{
		if(!TryInsert(data))
			throw TExistElementException("element already exist");
	}

	bool TryInsert(const value_type& data)
	{
		if (Root == nullptr)
		{
			Root = new TNode(data);
			return true;
		}

		TNode * curNode = Root;
		TNode * prevNode = curNode;
		do
		{
			prevNode = curNode;
			if (curNode->Data == data)
				return false;
			if (curNode->Data < data)
				curNode = curNode->Right;
			else
				curNode = curNode->Left;
		} while (curNode);

		TNode * newNode = new TNode(data);
		(prevNode->Data < data) ? prevNode->Right = newNode : prevNode->Left = newNode;
		return true;
	}

	// + Требуется реализовать функцию поиска элемента
	// + Если узел содержит искомый элемент, то функция возвращает указатель на этот узел
	// + Если элемента в дереве не найдено, то функция генерирует исключение TNotFoundException
    // Done
	/*
	TNode * Find(const value_type & value)
    {
        static TNode *currentNode = Root;
        static bool count = false;

        if (count && currentNode != Root)
        {
            count = false;
            currentNode = Root;
        }

        if (currentNode == nullptr)
        {
            throw TNotFoundException("Not found!");
        }


        if (value == currentNode->Data)
        {
            count = true;
            return currentNode;
        }


        if (value < currentNode->Data) {
            currentNode = currentNode->Left;
            return Find(value);
        } else{
            currentNode = currentNode->Right;
            return Find(value);
        }
    }
	*/
	
	TNode * Find(const value_type & value) 
    {
        if (Root == nullptr) 
        {
            throw TNotFoundException("Not found!");
        }

        TNode *currentNode = Root;

        while (currentNode != nullptr) {
            if (value == currentNode->Data) {
                return currentNode;
            } else if (value < currentNode->Data)
            {
                currentNode = currentNode->Left;
            } else 
            {
                currentNode = currentNode->Right;
            }
        }
    }

	friend std::ostream& operator << (std::ostream & out, const TBinaryTree& tree);
};

std::ostream& operator << (std::ostream & out, const TBinaryTree& tree)
{
	TBinaryTree::Print(out, tree.Root);
	return out;
}

#endif //MODUL2_LAB2_TBINARYTREE_H
