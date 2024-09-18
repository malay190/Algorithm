#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional>

// Node structure for Huffman Tree
struct Node
{
    char character;
    int frequency;
    Node *left, *right;
    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparator to order nodes in the priority queue
struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->frequency > r->frequency;
    }
};

// Function to generate Huffman Codes
void generateCodes(Node *root, std::string str, std::unordered_map<char, std::string> &huffmanCodes)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        huffmanCodes[root->character] = str;
    }
    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

// Function to perform Huffman Coding
void huffmanCoding(const std::string &data)
{
    // Calculate frequency of each character
    std::unordered_map<char, int> frequency;
    for (char ch : data)
    {
        frequency[ch]++;
    }

    // Create a priority queue to store nodes of the Huffman Tree
    std::priority_queue<Node *, std::vector<Node *>, Compare> minHeap;

    // Create a node for each character and insert into the priority queue
    for (auto pair : frequency)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        Node *top = new Node('\0', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // Root of the Huffman Tree
    Node *root = minHeap.top();

    // Generate Huffman Codes
    std::unordered_map<char, std::string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print Huffman Codes
    std::cout << "Huffman Codes:\n";
    for (auto pair : huffmanCodes)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main()
{
    std::string data = "ABRACADABRA";
    huffmanCoding(data);
    return 0;
}
