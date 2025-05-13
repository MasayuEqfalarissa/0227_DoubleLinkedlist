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

        //kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous ->next = newnode;
        }
        //kondisi jika if previous sama dengan null
        else
        {
            start = newnode;
        }
    }
};

//pembuatan function search untuk mencari data
bool search(int rollno, node **previous, node **current)
{
    *previous = NULL;
    *current = start;
    while (*current != NULL && (*current)->nomhs != rollno)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

//pembuatan prosedur delete untuk menghapus data 
void deletenode()
{
    node *previous, *current;
    int rollno;

    cout << "\nenter the roll number of the student whose record is to be delete: ";
    cin >> rollno;

    if (start == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    current = start;
    previous = NULL;

    //locate the node to be deleted
    while (current != NULL && current -> nomhs != rollno)
    {
        previous = current;
       current = current-> next;
    }

    if (current == NULL)
    {
        cout << "\033[31nthe record with roll number " << rollno << "not found\033[om" << endl;
        return;
    }

    // node to be deleted in the first node 
    if (current = start)
    {
        start = start -> next;
        if (start != NULL)
        {
            start -> prev = NULL;
        }
    }
    else 
    {
        previous -> next = current -> next;
        if (current -> next != NULL)
        {
            current -> next -> prev = previous ;
        }
    }
    //release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mrecord with roll number " << rollno << "deleted\x1b[0m" <<endl;
}

//methad untuk mengecek apakah list kosong 
bool listempty()
{
    return (start == NULL);
}

void traverse()
{
    if (listempty())
    {
        cout << "\nList is empty\n";
    }
    else
    {
        cout << "\n\nRecord in ascending order of roll number are:\n";
        node *currentnode = start;
        while (currentnode != NULL)
        {
            cout << currentnode->nomhs << endl;
            currentnode = currentnode->next;
        }
        cout << endl;
    }
}

void revtraverse()
{
    if (listempty())
        cout << "\nlist is empty" << endl;
    else
    {
        cout << "\nrecord in ascending order of roll number are: " << endl;
        node *currentnode = start;
        while (currentnode->next != NULL)
            currentnode = currentnode->next;

        while (currentnode != NULL)
        {
            cout << currentnode->nomhs << " " << currentnode->name << endl;
            currentnode = currentnode->prev;
        }
    }
}

void searchData()
{
    if (listempty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to serach: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found " << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->nomhs << endl;
        cout << "\nNme " << curr->name << endl;
    }
}

int main()
{
    while (true)
    {
        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl; 
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all records in the ascending order of roll numbers" << endl;
            cout << "4. View all records in the descending order of roll nunners" << endl; 
            cout << "5. Search for a record in the list" << endl;
            cout << "6. Exit" << endl;
            cout << "\nEnter your colce (1-6): "; 
        char ch;
        cin >> ch;

        switch (ch)
            {
            case '1':
                addnode();
                break;
            case '2':
                deletenode();
                break;
            case '3':
                traverse();
                break;
            case '4':
                revtraverse();
                break;
            case '5':
                searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
}