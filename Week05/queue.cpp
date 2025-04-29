#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NODE
{
    int key;
    NODE* p_next;
};
struct Queue
{
    NODE* head;
    NODE* tail;
};
NODE*createNode(int data)
{
    NODE*newNode= new NODE();
    newNode->key=data;
    newNode->p_next=NULL;
    return newNode;
}
Queue* initializeQueue(Queue*q)
{
    NODE* cur = q->head;
    while (cur != nullptr)
    {
        NODE* temp = cur;
        cur = cur->p_next;
        delete temp;
    }
    q->head=nullptr;
    q->tail=nullptr;
    return q;
}
void enqueue(Queue *q, int key)
{
    NODE* newNode = createNode(key);
    if (q->head == NULL)
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->p_next = newNode;
        q->tail = newNode;
    }
}
int dequeue(Queue*q)
{
     if(q->head==NULL) return -1;
     NODE*temp= q->head;
     int val=temp->key;
     q->head=q->head->p_next;
     if(q->head==nullptr) q->tail=nullptr;
     delete temp;
     return val;
}
int size(Queue*q)
{
    if(q->head==nullptr) return 0;
    NODE*cur= q->head;
    int size=0;
    while(cur)
    {
        size++;
        cur=cur->p_next;
    }
    return size;
}
bool isEmpty(Queue*q)
{
    return q->head==NULL;
}
void writeData(const char*filepath, Queue*q)
{
    ofstream fOut(filepath,ios::app);
    if (!fOut)
    {
        cerr << "Can't open output file!";
        return;
    }
    if (isEmpty(q)) fOut << "EMPTY" << endl;
    else
    {
        NODE* cur = q->head;
        while (cur)
        {
            fOut << cur->key << " ";
            cur = cur->p_next;
        }
        fOut << endl;
    } 
    fOut.close();
}
void readData(const char*path, Queue*q)
{
    ifstream fin(path);
    if(!fin)
    {
        cerr << "Khong mo duoc file! \n";
        return;
    }
    char line[100];
    while(fin.getline(line,100))
    {
        string command(line);
        if(command=="init")
        {
            initializeQueue(q);
        }
        else if(command.substr(0,7)=="enqueue")
        {
            int val=stoi(command.substr(8).c_str());
            enqueue(q,val);
        }
        else if(command=="dequeue")
        {
            dequeue(q);
        }
        writeData("outputqueue.txt",q);
    }
    fin.close();
}
int main()
{
    Queue*q=new Queue();
    ofstream fOut("outputqueue.txt", ios::trunc);
    fOut.close();
    readData("inputqueue.txt",q);
    NODE* cur = q->head;
    while (cur != NULL)
    {
        NODE* temp = cur;
        cur = cur->p_next;
        delete temp;
    }
    q->head = NULL;    q->tail = NULL;
    delete q;
    return 0;
}
