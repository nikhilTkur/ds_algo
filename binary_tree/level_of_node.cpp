#include <iostream>
#include <list>


using namespace std;

int main()
{
    list<int> li {1,2,3,4};
    cout << li.size() << endl;
    //li.erase(li.begin());

    for (auto it = li.begin(); it != li.end();)
    {
        cout << *it << endl;
        it = li.erase(it);
        cout << "size is" << li.size() << endl;
    }
    int l = li.size();
    bool c = l == 0 ? true : false;
    cout << "C is " << c << endl;
    // cout << li.empty();
    cout<<"Hello World";

    return 0;
}
