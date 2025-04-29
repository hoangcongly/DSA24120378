#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct NODE
{
    int key;
    NODE* p_next;
};
struct Stack
{
    NODE* top;
};
NODE* createNode(int data)
{
    NODE* newNode = new NODE();
    newNode->key = data;
    newNode->p_next = NULL;
    return newNode;
}

Stack* initializeStack(Stack* s)
{
    if(s!=NULL) 
    {
        NODE* cur = s->top;
        while (cur)
        {
            NODE* temp = cur;
            cur = cur->p_next;
            delete temp;
        }
    }
    s->top = NULL;
    return s;
}

void push(Stack* s, int key)
{   
    NODE* newNode = createNode(key);
    newNode->p_next = s->top;
    s->top = newNode;
}
int pop(Stack* s)
{
    if (s->top == NULL) return -1;
    NODE* temp = s->top;
    s->top = s->top->p_next;
    int val = temp->key;
    delete temp;
    return val;
}
int size(Stack* s)
{
    if (s->top == NULL) return 0;
    NODE* cur = s->top;
    int size = 0;
    while (cur)
    {
        cur = cur->p_next;
        size++;
    }
    return size;
}
bool isEmpty(Stack* s)
{
    return s->top == NULL;
}
void writeRecursive(ofstream& fOut, NODE* cur)
{
    if (cur == NULL) return;
    writeRecursive(fOut, cur->p_next); 
    fOut << cur->key << " ";   
}
void writeData(const char* filepath, Stack* s)
{
    ofstream fOut(filepath, ios::app);
    if (!fOut)
    {
        cerr << "Can't open output file!";
        return;
    }
    if (isEmpty(s)) fOut << "EMPTY" << endl;
    else
    {
        writeRecursive(fOut, s->top);
        fOut << endl;
    } 
    fOut.close();
    return;
}
void readData(const char* path, Stack* s)
{
    ifstream fin(path);
    if (!fin)
    {
        cerr << "Can't open input file! \n";
        return;
    }
    char line[100];
    while (fin.getline(line, 100))
    {
        string command(line);
        if (command == "init")
        {
            initializeStack(s);
        }
        else if (command.substr(0, 4) == "push")
        {
            int val = stoi(command.substr(5).c_str());
            push(s, val);
        }
        else if (command == "pop")
        {
            pop(s);
        }
        writeData("outputstack.txt", s);
    }
    fin.close();
}

int main()
{
    Stack* s = new Stack();
    s->top = NULL;
    ofstream fOut("outputstack.txt", ios::trunc);
    fOut.close();
    readData("inputstack.txt", s);
    NODE* cur = s->top;
        while (cur)
        {
            NODE* temp = cur;
            cur = cur->p_next;
            delete temp;
        }
    s->top = NULL;
    delete s;
    return 0;
}