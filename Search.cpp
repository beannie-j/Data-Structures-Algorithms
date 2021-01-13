#include <string>
#include <queue>
#include <stack>
#include <iostream>

// BFS DFS
// Breadth-First Search
// Depth-First Search

struct Node
{
	std::string Data;
	std::vector<Node*> Children;

	Node(std::string data)
		: Data(data) {}
};

void PrintSpaces(int count)
{
	for (int i = 0; i < count; i++)
		std::cout << " ";
}

void PrintTreeBFS(Node* root)
{
	std::queue<Node*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		Node* node = nodeQueue.front();
		nodeQueue.pop();

		std::cout << node->Data << std::endl;
		for (Node* child : node->Children)
			nodeQueue.push(child);
	}
}

Node* FindNodeBFS(Node* root, const std::string& search)
{
	std::queue<Node*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		Node* node = nodeQueue.front();
		if (node->Data == search)
			return node;

		nodeQueue.pop();

		for (Node* child : node->Children)
			nodeQueue.push(child);
	}

	return nullptr;
}

void PrintTreeDFS(Node* root)
{
	std::stack<Node*> nodeStack;
	nodeStack.push(root);

	while (!nodeStack.empty())
	{
		Node* node = nodeStack.top();
		std::cout << node->Data << std::endl;
		nodeStack.pop();

		for (int i = node->Children.size() - 1; i >= 0; i--)
			nodeStack.push(node->Children[i]);

	}
}

void VisitNode(Node* root, int depth = 0)
{
	PrintSpaces(depth);
	std::cout << root->Data << std::endl;

	for (Node* child : root->Children)
	{
		VisitNode(child, depth + 1);
	}
}

int main()
{
	Node* root = new Node("Root");
	Node* a = new Node("A");
	Node* b = new Node("B");
	root->Children.emplace_back(a);
	root->Children.emplace_back(b);

	Node* c = new Node("C");
	Node* d = new Node("D");
	a->Children.emplace_back(c);
	a->Children.emplace_back(d);
	Node* e = new Node("E");
	d->Children.emplace_back(e);

	Node* search = FindNodeBFS(root, "2");
	if (search)
		std::cout << "Found! Data = " << search->Data << std::endl;
	else
		std::cout << "Could not find node!" << std::endl;

	VisitNode(root);

	system("PAUSE");
}