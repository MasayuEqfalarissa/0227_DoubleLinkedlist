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
    cout << "\nenter the roll number of the the student: ";
    cin >> newnode->nomhs; //assign value to the data field of the new node
    cout << "\nenter the name of the student: ";
    cin >> newnode ->name; //assign value to the data field of th

    //insert the new mode in the list
    //kondisi jika start == NULL atau nomhs node baru <= nomhs start
    if (start == NULL || newnode->nomhs <= start ->nomhs)
    {
        
    }
};
