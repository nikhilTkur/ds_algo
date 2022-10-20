#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int findDepthRecursion(char tree[], int n, int & index)
{
    if (tree[index] == 'l' || index >=n) return 0;

    int l = findDepthRecursion(tree, n, ++index);
    int r = findDepthRecursion(tree, n, ++index);

    return max(l,r) + 1;
}

int main()
{
    char tree[] = "nlnnlll";
    int index = 0;
    int n = strlen(tree);
    cout << " height is " << findDepthRecursion(tree, n , index);
    return 0;
}