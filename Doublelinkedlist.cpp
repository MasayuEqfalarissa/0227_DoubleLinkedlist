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