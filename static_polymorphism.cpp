#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
};

template <typename T>
class GenericParser {
public:
    void parsePreOrder(TreeNode *node) {
        if (node) {
            processNode(node);
            parsePreOrder(node->left);
            parsePreOrder(node->right);
        }
    }

    void processNode(TreeNode* node) {
        static_cast<T*>(this)->processNode(node);
    }

};

class EmployeeParser : public GenericParser<EmployeeParser> {
public:
    void processNode(TreeNode *node) {
        cout << "Employee processNode" << endl;
    }
};

int main()
{
    TreeNode *root = nullptr;
    unique_ptr<EmployeeParser> empParser (new EmployeeParser());

    empParser->processNode(root);

    return 0;
}
