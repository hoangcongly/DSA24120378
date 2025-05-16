#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

const int TABLE_SIZE=2000;
const int p=31;
struct Company{
    string name;
    string profit_tax;
    string address;
};
struct NODE{
    Company* company;
    NODE* p_next;
};
struct HashTable{
    NODE*table[2000];
};
NODE* createNode(Company*company)
{
    NODE*newNode= new NODE();
    newNode->company= company;
    newNode->p_next=nullptr;
    return newNode;
}
long long hashString(string company_name)
{
    long long power=1;
    long long hash=0;
    string s;
    // nếu tên công ty dưới 20 kí tự thì lấy hết
    if(company_name.length()<=20)
    {
        s=company_name;
    }
    else// lấy 20 kí tự cuối của tên công ty
    {
        s = company_name.substr(company_name.length()-20);
    }
    for(int i=0; i<s.length();i++)
    {
        hash=(hash+s[i]*power)%TABLE_SIZE;
        power=(power*p)%TABLE_SIZE;
    }
    return hash;
}
vector<Company> readCompanyList(string filepath)
{
    ifstream file(filepath);
    vector<Company> list;
    string line;
    
    getline(file,line);
    while(getline(file,line))
    {
        Company company;
        size_t pos1= line.find('|');
        size_t pos2= line.find('|', pos1+1);
        company.name= line.substr(0,pos1);
        company.profit_tax= line.substr(pos1+1,pos2-pos1-1);
        company.address= line.substr(pos2+1);
        list.push_back(company);
    }
    return list;
}
HashTable* createHashTable(vector<Company> list_company)
{
    HashTable*hashtb= new HashTable();
    for(int i=0; i<TABLE_SIZE; i++)
    {
        hashtb->table[i]=nullptr;
    }
    for(Company&company: list_company)
    {
        Company*cmp= new Company(company);
        NODE*node= createNode(cmp);
        long long ind= hashString(company.name);
        node->p_next = hashtb->table[ind];
        hashtb->table[ind] = node;
    }
    return hashtb;
}

void insert(HashTable*hash_table, Company com)
{
    Company* cmpny= new Company(com);
    NODE*node= createNode(cmpny);
    long long index= hashString(com.name);
    node->p_next= hash_table->table[index];
    hash_table->table[index]=node;
}

Company* search(HashTable*hash_table, string company_name)
{
    long long index = hashString(company_name);
    NODE* current = hash_table->table[index];

    while (current != nullptr) {
        if (current->company->name == company_name)
            return current->company;
            current = current->p_next;
    }
    return nullptr;
}
void deletehashtable(HashTable*tb)
{
    for(int i=0; i<TABLE_SIZE; i++)
    {
        NODE*cur= tb->table[i];
        while(cur!=nullptr)
        {
            NODE*temp=cur;
            cur=cur->p_next;
            delete temp->company;
            delete temp;
        }
    }
    delete tb;
}
int main(int argc, char* argv[])
{
    if (argc < 4) 
    {
        cerr << "./main MST.txt input.txt output.txt" << endl;
        return 1;
    }
    string mst_file = argv[1];
    string input_file = argv[2];
    string output_file = argv[3];

    vector<Company> list = readCompanyList(mst_file);
    HashTable* table = createHashTable(list);

    ifstream infile(input_file);
    ofstream outfile(output_file);
    string line;
    while (getline(infile, line)) 
    {
        Company* result = search(table, line);
        if (result != nullptr)
        { 
            outfile << result->name << "|" << result->profit_tax << "|" << result->address << endl;
            cout << result->name << "|" << result->profit_tax << "|" << result->address <<  endl;
        }
    }
    delete table;
    return 0;
}