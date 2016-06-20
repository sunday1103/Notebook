/**
 * C++ 语言: 二叉查找树
 *
 * @author skywang
 * @date 2013/11/07
 */

#include "BSTree.h"
#include <iostream>
using namespace std;

static int arr[] = {1, 5, 4, 3, 2, 6};
#define TBL_SIZE(a) ((sizeof(a)) / (sizeof(a[0])))

int main()
{
    int i, ilen;
    BSTree<int> *tree = new BSTree<int>();

    cout << "Insert ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen; i++)
    {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }

    cout << "\nPreOder: ";
    tree->preOrder();

    cout << "\ninOrder: ";
    tree->inOrder();

    cout << "\npostOrder: ";
    tree->postOrder();
    cout << endl;

    cout << "min: " << tree->minimum() << endl;
    cout << "max: " << tree->maximum() << endl;
    cout << "print: " << endl;
    tree->print();

    cout << "\ndelet: " << arr[3];
    tree->remove(arr[3]);

    cout << "\ninOrder: ";
    tree->inOrder();
    cout << endl;

    // 销毁二叉树
    tree->destroy();

    return 0;
}
