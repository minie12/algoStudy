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
			if (Arr[Index] == InData)
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

template<typename T>
class DPList
{
	struct Node
	{
		T Data;
		Node* Prev;
		Node* Next;

		Node(const T& InData)
			: Data(InData)
			, Prev(nullptr)
			, Next(nullptr)
		{ }
	};

public:
	DPList()
		: Root(nullptr)
		, Tail(nullptr)
		, ListCount(0)
	{}

	~DPList()
	{
		Node* Temp = Root;
		
		while (nullptr != Temp)
		{
			Node* NextTemp = Temp->Next;
			
			delete Temp;
			Temp = NextTemp;
		}
	}

	class iterator 
	{
	public:
		iterator() : CurrentNode(nullptr) { }
		iterator(Node* InCurrent)
			: CurrentNode(InCurrent)
		{ }

		T operator*() const
		{
			return CurrentNode->Data;
		}

		iterator& operator++()
		{
			CurrentNode = CurrentNode->Next;
			return *this;
		}
		iterator& operator--()
		{
			CurrentNode = CurrentNode->Prev;
			return *this;
		}
		T& operator->() const
		{
			return CurrentNode->Data;
		}
		bool operator!=(const iterator& Other) const
		{
			return Other.CurrentNode != CurrentNode;
		}
		bool operator==(const iterator& Other) const
		{
			return Other.CurrentNode == CurrentNode;
		}

	private:
		Node* CurrentNode;
	};

	void PushBack(const T& InData)
	{
		Node* Temp = new Node(InData);

		if (nullptr == Root)
		{
			Root = Tail = Temp;
		}
		else
		{
			Tail->Next = Temp;
			Temp->Prev = Tail;

			Tail = Temp;
		}
		
		ListCount++;
	}

	void Clear()
	{
		Node* Temp = Root;
		while (nullptr != Temp)
		{
			Node* Del = Temp;
			Temp = Temp->Next;

			delete Del;
		}
	}

	iterator begin()
	{
		iterator Temp(Root);
		return Temp;
	}
	iterator end()
	{
		iterator Temp;
		return Temp;
	}
	inline T& Front() const { return Root->Data; }
	inline T& Back() const { return Tail->Data; }
	inline unsigned int Size() const { return ListCount; }
	inline bool IsEmpty() const { return ListCount <= 0; }

private:
	Node* Root;
	Node* Tail;
	unsigned int ListCount;
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
