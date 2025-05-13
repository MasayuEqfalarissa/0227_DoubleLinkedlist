#include <iostream>
using namespace std;

//membuat struktur untuk object double linkedlist
struct node 
{
    //deklarasi nomhs dan name untuk menampung data
    int nomhs;
    string name;
    //deklarasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
    node *next;
    node *prev;
};

//deklarasi pointer start dan pemberiaan nilai 
node *start = NULL;

//deklarasi prosedur addnode
void addnode()
{
    //pembuatan node dan pemberian value untuk data nomhs dan name 
    node *newnode = new node(); //step 1 buat node baru 
}
