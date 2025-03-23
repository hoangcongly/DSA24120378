// ex6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int N = 8;// kích thước bàn cờ là 8*8
int board[N][N] = { 0 };// tạo mảng 2 chiều để lưu trạng thái bàn cờ với 0 là ô trống, 1 là ô đã có quân hậu
bool is_Safe(int row, int col, int N)// hàm bool để kiểm tra quân hậu có thể được đặt tại vị trí [row][col] hay không
{
    for (int i = 0; i < row; i++)// vòng lặp duyệt qua tất cả các hàng nằm phía trên hàng hiện tại(row)
    {
        if (board[i][col]==1)//nếu có quân hậu ở cùng cột thì trả về false
            return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) // kiểm tra đường chéo trái, nếu có quân hậu nằm cùng đường chéo thì trả về false
            return false;
        if (col + (row - i) < N && board[i][col + (row - i)] == 1)// kiểm tra đường chéo phải, nếu có quân hậu nằm cùng trên đường chéo phải thì trả về false
            return false;
    }
    return true;// nếu không có quân hậu nào gây cản trở thì trả về true, vị trí này hợp lệ
}
// hàm in ra bàn cờ
void print_Board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";  // Nếu có hậu, in "Q "
            else
                cout << ". ";  // Nếu không có hậu, in ". "
        }
        cout << endl;
    }
    cout << "*************************************" << endl;
}

void solveNQueens(int row)
{
    if (row == N)// nếu đã đặt hết N quân hậu thì in bàn cờ
    {
        print_Board();// gọi hàm in bàn cờ
        return;
    }
    for (int col = 0; col < N; col++)// duyệt từng cột trên hàng hiện tại
    {
        if (is_Safe(row, col,N))//nếu đặt quân hậu ở vị trí [row][col] hợp lệ
        {
            board[row][col] = 1; // đặt quân hậu vào ô [row][col]
            solveNQueens(row + 1);// sau đó đệ quy để đặt quân hậu vào các hàng tiếp theo
            board[row][col] = 0;// nếu không tìm được cách đặt quân hậu hợp lệ vào các hàng sau thì gỡ hậu khỏi ô [row][col] và thử ô khác trong cùng hàng
        }
    }
}

int main()
{
    solveNQueens(0);
    return 0;
}

