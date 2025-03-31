// Exercise4_Tower_of_HaNoi_puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void tower_of_HaNoi(int n, char from, char to, char aux)
{
    if (n == 1)// nếu chỉ có 1 đĩa thì đưa nó từ cột from sang cột to
    {
        cout << "move disk 1 from " << from << " to " << to << endl;
        return;
    }
    tower_of_HaNoi(n - 1, from, aux, to);// di chuyển n-1 đĩa từ cột from sang cột aux qua cột trung gian là to
    cout << "Move disk " << n << " from " << from << " to " << to << endl;// di chuyển đĩa nằm dưới cùng từ cột from sang to
    tower_of_HaNoi(n - 1, aux, to, from);// di chuyển n-1 đĩa từ cột aux sang cột to qua cột trung gian là from
}
int main()
{
    int n;
    cin >> n;
    tower_of_HaNoi(n, 'A', 'B', 'C');
    return 0;
}

