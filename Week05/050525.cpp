#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <cctype>
#include <fstream>
using namespace std;

struct NODE{
    int num;
    NODE* p_next;
};
struct BigInt{
    NODE*head;
    int sign;
};
BigInt* createBigInt(string str);
void push(BigInt*&Num, int digit);
BigInt* reverse_Number(BigInt* Num);
void display(BigInt*Num);
BigInt* xoaso0(BigInt*& num);
void deleteNum(BigInt*& Num);
BigInt*add_two_bignumber(BigInt*num1, BigInt*num2);
int do_dai(BigInt* num);
BigInt* trim_leading_zeros(BigInt* num);
int so_sanh(BigInt* num1, BigInt* num2);
BigInt* subtract_two_bignumber(BigInt* num1, BigInt* num2);
BigInt* divide_two_bignumber(BigInt* num1, BigInt* num2);
int uu_tien(string c);
void infixToPostfix(const string& str, queue<string>& q);
BigInt* tinh_hau_to(queue<string>& postfixQueue);
void push_back(BigInt* num, int digit) ;
BigInt*copynumber(BigInt*num);
bool isOperator(const string& token);

// hàm tạo số nguyên lớn từ chuỗi string
BigInt* createBigInt(string str)
{
    BigInt* result = new BigInt();
    result->head = nullptr;
    result->sign = 1;
    if (str.empty()) 
    {
        push(result, 0);
        return result;
    }
    if (str[0] == '-')
    {
        result->sign = -1;
        str = str.substr(1);
    } 
    else if (str[0] == '+') 
    {
        str = str.substr(1);
    }
    for (int i = 0; i < str.length(); i++) 
    {
        if (isdigit(str[i])) 
        {
            int num = str[i] - '0';
            push(result, num);
        }
    }
    result = xoaso0(result);
    if (result->head == nullptr) 
    {
        push(result, 0);
        result->sign = 1;
    }
    return result;
}
void push(BigInt*&Num, int digit)
{
    NODE*newNode= new NODE();
    newNode->num=digit;
    newNode->p_next=Num->head;
    Num->head=newNode;
}
BigInt* reverse_Number(BigInt* Num) {
    if (Num == nullptr || Num->head == nullptr) 
    {
        BigInt* result = new BigInt();
        result->head = nullptr;
        result->sign = 1;
        push_back(result, 0);
        return result;
    }
    BigInt* result = new BigInt();
    result->head = nullptr;
    result->sign = Num->sign;
    NODE* cur = Num->head;
    while (cur != nullptr) 
    {
        push(result, cur->num); 
        cur = cur->p_next;
    }
    return result;
}

BigInt*copynumber(BigInt*num)
{
    if(num==nullptr || num->head==nullptr)
    {
        return nullptr;
    }
    BigInt*newnum=new BigInt();
    newnum->sign=num->sign;
    newnum->head=nullptr;
    NODE*cur=num->head;
    NODE*tail=nullptr;
    while(cur!=nullptr)
    {
        NODE*newnode= new NODE();
        newnode->num= cur->num;
        newnode->p_next=nullptr;
        if(newnum->head==nullptr)
        {
            newnum->head=newnode;
            tail=newnode;
        }
        else
        {
            tail->p_next= newnode;
            tail=newnode;
        }
        cur=cur->p_next;
    }
    return newnum;
}
void display(BigInt* Num) 
{
    if (Num == nullptr || Num->head == nullptr) 
    {
        cout << "0" << endl;
        return;
    }
    if (Num->sign == -1) {
        cout << "-";
    }
    Num=reverse_Number(Num);
    NODE* cur = Num->head;
    while (cur != nullptr) {
        cout << cur->num;
        cur = cur->p_next;
    }
    cout << endl;
}
void deleteNum(BigInt*& num)
{
    if (num == nullptr) return;
    NODE* cur = num->head;
    while (cur != nullptr)
    {
        NODE* temp = cur;
        cur = cur->p_next;
        delete temp;
    }
    num->head = nullptr;
    num->sign = 1; // Đặt lại giá trị mặc định
}
bool isValidNumber(const string&str)
{
    if(str.empty()) return false;
    int s=0;
    if(str[0]=='-'|| str[0]=='+')
    {
        s=1;
    }
    if(s>=str.length()) return false;
    for(int i=s; i<str.length(); i++)
    {
        if(!isdigit(str[i])) return false;
    }
    return true;
}
BigInt* add_two_bignumber(BigInt* num1, BigInt* num2) 
{
    if (num1 == nullptr || num1->head == nullptr) 
    {
        return num2;
    }
    if (num2 == nullptr || num2->head == nullptr) 
    {
        return num1;
    }

    if (num1->sign != num2->sign) 
    {
        BigInt* absnum1 = copynumber(num1);
        BigInt* absnum2 = copynumber(num2);
        absnum1->sign = 1;
        absnum2->sign = 1;
        BigInt* result = nullptr;
        if (num1->sign == 1) 
        {
            result = subtract_two_bignumber(absnum1, absnum2);
        } else 
        {
            result = subtract_two_bignumber(absnum2, absnum1);
        }
        deleteNum(absnum1);
        deleteNum(absnum2);
        return result;
    }

    BigInt* result = new BigInt();
    result->head = nullptr;
    result->sign = num1->sign;
    BigInt*absnum1= copynumber(num1);
    BigInt*absnum2= copynumber(num2);
    NODE* cur1 = absnum1->head;
    NODE* cur2 = absnum2->head;
    int carry = 0;

    while (cur1 != nullptr || cur2 != nullptr || carry != 0) {
        int sum = carry;
        if (cur1 != nullptr) {
            sum += cur1->num;
            cur1 = cur1->p_next;
        }
        if (cur2 != nullptr) {
            sum += cur2->num;
            cur2 = cur2->p_next;
        }
        push_back(result, sum % 10);
        carry = sum / 10;
    }
    return result;
}
BigInt* xoaso0(BigInt*& num)
{
    if (num == nullptr || num->head == nullptr) 
    {
        if (num == nullptr) num = new BigInt();
        num->head = nullptr;
        num->sign = 1;
        push_back(num, 0);
        return num;
    }

    // Đảo ngược danh sách để dễ xóa số 0 ở đầu
    BigInt* reversed = reverse_Number(num);
    NODE* cur = reversed->head;
    NODE* prev = nullptr;

    // Xóa các số 0 ở đầu
    while (cur != nullptr && cur->num == 0)
    {
        NODE* temp = cur;
        cur = cur->p_next;
        delete temp;
    }
    reversed->head = cur;

    // Đảo ngược lại để khôi phục thứ tự
    BigInt* result = reverse_Number(reversed);
    deleteNum(reversed);

    // Cập nhật num
    deleteNum(num);
    num = result;
    // Nếu danh sách rỗng, thêm số 0
    if (num->head == nullptr)
    {
        push_back(num, 0);
        num->sign = 1;
    }

    return num;
}


int do_dai(BigInt* num) 
{
    if (num == nullptr|| num->head==nullptr) return 0;
    int len = 0;
    NODE* cur = num->head;
    while (cur != nullptr) 
    {
        len++;
        cur = cur->p_next;
    }
    return len;
} 

int so_sanh(BigInt* num1, BigInt* num2) 
{
    if (num1 == nullptr || num1->head == nullptr) 
    {
        if (num2 == nullptr || num2->head == nullptr) return 0;
        return (num2->sign == -1) ? 1 : -1;
    }
    if (num2 == nullptr || num2->head == nullptr) 
    {
        return (num1->sign == -1) ? -1 : 1;
    }
    if (num1->sign != num2->sign) 
    {
        return (num1->sign > num2->sign) ? 1 : -1;
    }

    BigInt* n1temp = copynumber(num1);
    xoaso0(n1temp);
    BigInt* n2temp = copynumber(num2);
    xoaso0(n2temp);

    int len1 = do_dai(n1temp);
    int len2 = do_dai(n2temp);
    if (len1 > len2) 
    {
        deleteNum(n1temp);
        deleteNum(n2temp);
        return (num1->sign == -1) ? -1 : 1;
    }
    if (len1 < len2) 
    {
        deleteNum(n1temp);
        deleteNum(n2temp);
        return (num1->sign == -1) ? 1 : -1;
    }

    vector<int> digits1, digits2;
    NODE* cur = n1temp->head;
    while (cur != nullptr) 
    {
        digits1.push_back(cur->num);
        cur = cur->p_next;
    }
    cur = n2temp->head;
    while (cur != nullptr) 
    {
        digits2.push_back(cur->num);
        cur = cur->p_next;
    }

    for (int i = len1 - 1; i >= 0; i--) 
    {
        if (digits1[i] > digits2[i]) 
        {
            deleteNum(n1temp);
            deleteNum(n2temp);
            return (num1->sign == -1) ? -1 : 1;
        }
        if (digits1[i] < digits2[i]) 
        {
            deleteNum(n1temp);
            deleteNum(n2temp);
            return (num1->sign == -1) ? 1 : -1;
        }
    }

    deleteNum(n1temp);
    deleteNum(n2temp);
    return 0;
}

BigInt* subtract_two_bignumber(BigInt* num1, BigInt* num2)
{
    if((num1==nullptr|| num1->head==nullptr) && (num2==nullptr|| num2->head==nullptr))
    {
        return createBigInt("0");
    }
    if(num1==nullptr|| num1->head==nullptr)
    {
        BigInt*result= copynumber(num2);
        result->sign=result->sign*-1;
        return result;
    }
    if(num2==nullptr|| num2->head==nullptr)
    {
        BigInt*result= copynumber(num1);
        return result;
    }
    if(num1->sign==-1 && num2->sign==1) // truong hop -a-b
    {
        BigInt*absnum1= copynumber(num1);
        absnum1->sign=1;
        BigInt*result = add_two_bignumber(absnum1, num2);
        result->sign=-1;
        deleteNum(absnum1);
        return result;
    }
    if(num1->sign==1&& num2->sign==-1) // truong hop a+b
    {
        BigInt*absnum2= copynumber(num2);
        absnum2->sign=1;
        BigInt*result= add_two_bignumber(num1,absnum2);
        result->sign=1;
        deleteNum(absnum2);
        return result;
    }
    if(num1->sign==-1&& num2->sign==-1)// truong hop -a+b
    {
        BigInt*absnum1= copynumber(num1);
        BigInt*absnum2= copynumber(num2);
        absnum1->sign=1;
        absnum2->sign=1;
        BigInt*result= subtract_two_bignumber(absnum2, absnum1);
        deleteNum(absnum1);
        deleteNum(absnum2);
        return result;
    }
    // truong hop ca 2 so deu duong
    int cmp = so_sanh(num1, num2);
    int sign = 1;

    BigInt* solon;
    BigInt* sonho;

    if (cmp >= 0)
    {
        solon =(num1); 
        sonho =(num2);
    }
    else
    {
        solon = (num2);
        sonho = (num1);
        sign = -1;
    }

    BigInt* result = new BigInt();
    result->head = nullptr;
    result->sign = sign;
    NODE*cur1= solon->head;
    NODE*cur2= sonho->head;
    int muon=0;
    while(cur1!=nullptr || cur2!= nullptr)
    {
        int digit1=0;
        int digit2=0;
        if(cur1!=nullptr)
        {
            digit1= cur1->num;
        }
        if(cur2!=nullptr)
        {
            digit2= cur2->num;
        }
        int hieu= digit1-digit2-muon;
        if(hieu<0)
        {
            hieu=hieu +10;
            muon=1;
        }
        else muon=0;
        push_back(result,hieu);
        if(cur1!=nullptr) cur1=cur1->p_next;
        if(cur2!=nullptr) cur2=cur2->p_next;
    }
    result->sign= sign;
    result= xoaso0(result);
    return result;
}

BigInt* multipli_two_bignumber(BigInt* num1, BigInt* num2) 
{
    if (num1 == nullptr || num1->head == nullptr || num2 == nullptr || num2->head == nullptr) 
    {
        return createBigInt("0");
    }
    BigInt* result = createBigInt("0");
    BigInt* temp_res = new BigInt();
    temp_res->head = nullptr;
    temp_res->sign = 1;

    NODE* cur2 = num2->head;
    int pos = 0;
    while (cur2 != nullptr) 
    {
        deleteNum(temp_res);
        temp_res = new BigInt();
        temp_res->head = nullptr;
        temp_res->sign = 1;
        for (int i = 0; i < pos; i++) 
        {
            push(temp_res, 0);
        }
        NODE* cur1 = num1->head;
        int carry = 0;
        while (cur1 != nullptr) 
        {
            int nhan = cur1->num * cur2->num + carry;
            push(temp_res, nhan % 10); 
            carry = nhan / 10;
            cur1 = cur1->p_next;
        }
        if (carry > 0) 
        {
            push(temp_res, carry);
        }
        temp_res = reverse_Number(temp_res);
        BigInt* old_result = result;
        result = add_two_bignumber(result, temp_res);
        deleteNum(old_result);

        pos++;
        cur2 = cur2->p_next;
    }
    deleteNum(temp_res);
    result = xoaso0(result);
    result->sign = (num1->sign == num2->sign) ? 1 : -1;
    if(num1->sign==num2->sign) result->sign=1;
    else result->sign=-1;
    if (result->head == nullptr) 
    {
        push_back(result, 0);
        result->sign = 1;
    }
    return result;
}
void push_back(BigInt* num, int digit) 
{
    NODE* newNode = new NODE();
    newNode->num = digit;
    newNode->p_next = nullptr;

    if (num->head == nullptr) 
    {
        num->head = newNode;
    }
    else 
    {
        NODE* temp = num->head;
        while (temp->p_next != nullptr) 
        {
            temp = temp->p_next;
        }
        temp->p_next = newNode;
    }
}
BigInt* divide_two_bignumber(BigInt* num1, BigInt* num2) 
{
    if (num1 == nullptr || num1->head == nullptr) return createBigInt("0");
    if (num2 == nullptr || num2->head == nullptr) return nullptr;

    BigInt* num0 = createBigInt("0");
    if (so_sanh(num2, num0) == 0) 
    {
        deleteNum(num0);
        return nullptr;
    }
    deleteNum(num0);

    BigInt* num1_abs = copynumber(num1);
    num1_abs->sign = 1;
    BigInt* num2_abs = copynumber(num2);
    num2_abs->sign = 1;
    if (so_sanh(num1_abs, num2_abs) < 0) 
    {
        deleteNum(num1_abs);
        deleteNum(num2_abs);
        return createBigInt("0");
    }

    BigInt* result = createBigInt("0");
    BigInt* dutam = createBigInt("0");
    dutam->sign = 1;

    BigInt* n1rev = reverse_Number(num1_abs);
    BigInt* num1_copy = copynumber(n1rev);
    num1_copy->sign = 1;
    BigInt* num2_copy = copynumber(num2_abs);
    num2_copy->sign = 1;

    NODE* cur = num1_copy->head;
    while (cur != nullptr) 
    {
        BigInt* temp_dutam = multipli_two_bignumber(dutam, createBigInt("10"));
        deleteNum(dutam);
        dutam = add_two_bignumber(temp_dutam, createBigInt(std::to_string(cur->num)));
        deleteNum(temp_dutam);
        dutam->sign = 1;

        int thuongtam = 0;
        while (so_sanh(dutam, num2_copy) >= 0) {
            BigInt* temp = copynumber(num2_copy);
            temp->sign = 1;
            BigInt* dutamnew = subtract_two_bignumber(dutam, temp);
            dutamnew->sign = 1;
            deleteNum(dutam);
            deleteNum(temp);
            dutam = dutamnew;
            thuongtam++;
        }
        xoaso0(dutam);

        // Luôn cập nhật result, kể cả khi thuongtam = 0
        BigInt* temp_result = multipli_two_bignumber(result, createBigInt("10"));
        deleteNum(result);
        result = add_two_bignumber(temp_result, createBigInt(std::to_string(thuongtam)));
        deleteNum(temp_result);

        cur = cur->p_next;
    }

    xoaso0(result);
    result->sign = num1->sign * num2->sign;

    deleteNum(n1rev);
    deleteNum(dutam);
    deleteNum(num1_abs);
    deleteNum(num2_abs);
    deleteNum(num1_copy);
    deleteNum(num2_copy);
    return result;
}
int uu_tien(string c) 
{
    if (c == "+" || c == "-") return 1;
    if (c == "*" || c == "/") return 2;
    return 0;
}
void infixToPostfix(const string& str, queue<string>& q) 
{
    stack<string> s;
    string token;
    int i = 0;

    while (i < str.length()) 
    {
        char c = str[i];
        if (c == ' ') 
        {
            i++;
            continue;
        }
        // truong hop c la so, c la dau cong tru hoac dung dau hoac c dung ngay sau dau ( 
        if (isdigit(c) || ((c == '-' || c == '+') && (i == 0 || str[i - 1] == '(' || isOperator(string(1, str[i - 1]))))) 
        {
            token = c;
            i++;
            while (i < str.length() && isdigit(str[i])) 
            {
                token += str[i];
                i++;
            }
            q.push(token); 
            continue;
        }
        token = string(1, c);
        if (token == "(") 
        {
            s.push(token);
        } else if (token == ")") 
        {
            while (!s.empty() && s.top() != "(") 
            {
                q.push(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop(); // Xóa dấu "("
        } 
        else if (isOperator(token)) 
        {
            while (!s.empty() && s.top() != "(" && uu_tien(token) <= uu_tien(s.top())) 
            {
                q.push(s.top());
                s.pop();
            }
            s.push(token);
        }
        i++;
    }
    // Đẩy các toán tử còn lại trong stack vào queue
    while (!s.empty()) 
    {
        if (s.top() != "(") q.push(s.top());
        s.pop();
    }
}
bool isOperator(const string& token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
BigInt* tinh_hau_to(queue<string>& postfixQueue) 
{
    stack<BigInt*> st;
    while (!postfixQueue.empty()) 
    {
        string token = postfixQueue.front();
        postfixQueue.pop();

        if (isValidNumber(token)) 
        {
            BigInt* numbig = createBigInt(token);
            if (numbig == nullptr) {
                while (!st.empty()) {
                    deleteNum(st.top());
                    st.pop();
                }
                return nullptr;
            }
            st.push(numbig);
        } else if (isOperator(token)) {
            if (st.size() < 2) {

                while (!st.empty()) {
                    deleteNum(st.top());
                    st.pop();
                }
                return nullptr;
            }
            BigInt* b = st.top(); st.pop();
            BigInt* a = st.top(); st.pop();
            BigInt* result = nullptr;

            if (token == "+") {
                result = add_two_bignumber(a, b);
            } else if (token == "-") {
                result = subtract_two_bignumber(a, b);
            } else if (token == "*") {
                result = multipli_two_bignumber(a, b); 
            } else if (token == "/") {
                result = divide_two_bignumber(a, b);
            }

            if (result == nullptr) {
                deleteNum(a);
                deleteNum(b);
                while (!st.empty()) {
                    deleteNum(st.top());
                    st.pop();
                }
                return nullptr;
            }

            st.push(result);
            deleteNum(a);
            deleteNum(b);
        } else {
            while (!st.empty()) {
                deleteNum(st.top());
                st.pop();
            }
            return nullptr;
        }
    }

    if (st.size() != 1) {
        while (!st.empty()) {
            deleteNum(st.top());
            st.pop();
        }
        return nullptr;
    }

    BigInt* rs = st.top();
    st.pop();
    return rs;
}
bool isErrorBigInt(BigInt* num)
{
    if (num == nullptr || num->head == nullptr) return true;

    string s;
    NODE* cur = num->head;
    while (cur != nullptr)
    {
        s = char(cur->num + '0') + s;  
        cur = cur->p_next;
    }
    return s == "ERROR";
}
void read_write_Data(const char*inputpath,const char* outputpath)
{
    ifstream fin(inputpath);
    ofstream fout(outputpath);
    if(!fin)
    {
        cerr << "Error don't open input file\n";
        return;
    }
    if(!fout)
    {
        cerr << "Error don't open output file\n";
        return;
    }
    string line;
    while(getline(fin,line))
    {
        queue<string> posfixQueue;
        infixToPostfix(line,posfixQueue);
        BigInt*result= tinh_hau_to(posfixQueue);
        if(result==nullptr|| result->head==nullptr)
        {
            fout<< "ERROR" << endl;
            continue;
        }
        if (isErrorBigInt(result)) 
        {
            fout << "ERROR\n";
            deleteNum(result);
            continue;
        }

            if (result->sign == -1) {
                fout << "-";
            }
            result=reverse_Number(result);
            NODE* cur = result->head;
            while (cur != nullptr) {
                fout << cur->num;
                cur = cur->p_next;
            }
            fout << endl;
    }
    fin.close();
    fout.close();
}
int main() 
{
    const char* inputPath = "tests.txt";
    const char* outputPath = "output_24120378.txt";
    read_write_Data(inputPath, outputPath);
    cout << "Đã xử lý xong. Kết quả đã được ghi vào file: " << outputPath << endl;
    return 0;
}
