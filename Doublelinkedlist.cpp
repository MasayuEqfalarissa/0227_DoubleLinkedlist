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
        //step 2: insert the new mode at new beginning
        //kondisi jika start tidak kosong dan nomhs node baru sama dengan nomhs
        if (start != NULL && newnode -> nomhs == start -> nomhs)
        {
            cout << "\033[31mduplicate roll numbers not allowed\033[0m" << endl;
        }
        //if the list is empty, make the new node the start
        //jika list kosong, maka node next nya adalah start
        newnode->next = start; //step 3 make the new node point the frst node
        //kondisi jika start tidak memiliki nilai atau tidak kosong
        if (start != NULL)
        {
            start -> prev = newnode;
        }
        //memberi nilai prev = NULL dan start = node baru
        newnode -> prev = NULL; //step 5 make the new node point to null
        start = newnode; //step 6  make the new node the first node   
    }
    //kondisi jika semua kondisi if tidak terpenuhi
    else
    {
        //insert the new node in the middle or at the end
        //set nilai current = start dan nilai previous = null
        node *current = start; //step 1.a: start from the first node
        node *previous = NULL; //step 1.b: previous node is null initlally

        //looping selama current != null dan nomhs dari current lebih kecil dari
        while (current != NULL && current -> nomhs < newnode->nomhs)
        {
            previous = current;
            current = current -> next;
        }

        //set nilai next node baru = current dan prev node baru = previous
        newnode->next = current;
        newnode->prev = previous;

        //kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current -> prev =newnode;
        }
    }
};
