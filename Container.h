#pragma once

#include "ostream"

template<typename T>
class DPArray
{
public:
	DPArray()
		: MaxSize(2)
		, ArrayCount(0)
	{
		Arr = new T[MaxSize];
	}

	~DPArray()
	{
		delete[] Arr;
	}

	T& operator[] (int Index) const
	{
		if (!IsValidIndex(Index))
		{
			std::cout << "DPArray: Out of Range" << std::endl;
			exit(1);
		}

		return Arr[Index];
	}

	inline void Add(const T& InData)
	{
		if (ArrayCount >= MaxSize)
		{
			// 배열 크기가 부족하면, 더 크게 생성하고 메모리 이동
			MaxSize = 2 * MaxSize;
			T* Temp = new T[MaxSize];
			for (unsigned int Index = 0; Index < ArrayCount; Index++)
			{
				Temp[Index] = Arr[Index];
			}
			delete[] Arr;
			Arr = Temp;
		}

		Arr[ArrayCount++] = InData;
	}

	int Find(const T& InData) const
	{
		for (unsigned int Index = 0; Index < ArrayCount; Index++)
		{
			if (InData == Arr[Index])
				return Index;
		}

		return -1;
	}

	bool Contains(const T& InData) const
	{
		if (-1 != Find(InData))
			return true;

		return false;
	}

	void Insert(const T& InData, unsigned int InIndex)
	{
		if (!IsValidIndex(InIndex))
		{
			std::cout << "DPArray: Insert index is larger than array size" << std::endl;
			exit(1);
		}

		unsigned int Index = ArrayCount++;
		while (InIndex != Index)
		{
			Arr[Index] = Arr[Index-1];
			Index--;
		}

		Arr[Index] = InData;
	}

	void Empty()
	{
		delete[] Arr;
		Arr = new T[MaxSize];
		ArrayCount = 0;
	}

	inline bool IsEmpty() const { return 0 == ArrayCount; }
	inline bool IsValidIndex(unsigned int InIndex) const { return 0 <= InIndex && InIndex < ArrayCount; }

private:
	T* Arr;
	int MaxSize;
	unsigned int ArrayCount;
};

template<typename KeyT, typename ValueT>
class DPMap
{
	struct Node
	{
		KeyT Key;
		ValueT Value;
		struct Node* Left;
		struct Node* Right;

		Node(KeyT InKey, ValueT InValue)
			: Left(nullptr)
			, Right(nullptr)
			, Key(InKey)
			, Value(InValue)
		{ }

		~Node()
		{
			if (nullptr != Left)
			{
				delete Left;
				Left = nullptr;
			}

			if (nullptr != Right)
			{
				delete Right;
				Right = nullptr;
			}
		}
	};

public:
	DPMap()
		: ArrayCount(0)
		, Root(nullptr)
	{ }

	~DPMap()
	{
		if (nullptr != Root)
		{
			delete Root;
			Root = nullptr;
		}
	}

	void Insert(KeyT InKey, ValueT InValue)
	{
		Node* TempNode = new Node(InKey, InValue);
		InsertNode(Root, TempNode);
	}

	void InsertNode(Node* CompNode, Node* InNode)
	{
		if (InNode.Key == CompNode.Key)
		{
			std::cout << "DPMap: Same key is used twice" << std::endl;
			exit(1);
		}

		
		if (CompNode.Key > InNode.Key)
		{
			if (nullptr == CompNode.Left)
			{
				CompNode.Left = InNode;
				return;
			}
			else
			{
				InsertNode(CompNode.Left, InNode);
			}
		}
		else
		{
			if (nullptr == CompNode.Right)
			{
				CompNode.Right = InNode;
				return;
			}
			else
			{
				InsertNode(CompNode.Right, InNode);
			}
		}
	}

private:
	Node* Root;
	unsigned int ArrayCount;
};