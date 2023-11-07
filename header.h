#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define penyakit(C) C->penyakit
#define next(P) P->next
#define prev(P) P->prev
#define parent(R) R->parent
#define child(R) R->child
#define pasien(P) P->pasien

// SINGLE LINKED LIST
typedef string infotype;
typedef struct elm_child *adr_c;
struct elm_child{
    infotype penyakit;
    adr_c next, prev;
};
struct list_child{
    adr_c first, last;
};
void createList_c(list_child &L);
adr_c alokasi_c(infotype x);
void insertLast_c(list_child &L, adr_c C);
void deleteFirst_c(list_child &L, adr_c &C);
void deleteLast_c(list_child &L, adr_c &C);
void deleteAfter_c(list_child &L, adr_c Prec, adr_c &C);
adr_c searchElmn_c(list_child L, infotype x);
void printInfo_c(list_child L);
void hapusData_c(list_child &L, infotype x);

void insertFirst_c(list_child &L, adr_c P);
void insertAfter_c(list_child &L, adr_c Prec, adr_c P);

// CIRCULAR DOUBLE LINKED LIST
typedef struct elm_parent *adr_p;
struct elm_parent{
    infotype pasien;
    adr_p next, prev;
};
struct list_parent{
    adr_p first, last;
};
void createList_p(list_parent &L);
adr_p alokasi_p(infotype x);
void insertFirst_p(list_parent &L, adr_p P);
void insertLast_p(list_parent &L, adr_p P);
void insertAfter_p(list_parent &L, adr_p Prec, adr_p P);
void deleteFirst_p(list_parent &L, adr_p &P);
void deleteLast_p(list_parent &L, adr_p &P);
void deleteAfter_p(list_parent &L, adr_p Prec, adr_p &P);
adr_p searchElmn_p(list_parent L, infotype x);
void printInfo_p(list_parent L);
void insertAscending_p(list_parent &L, adr_p P);
void hapusData_p(list_parent &L, infotype x);


// DOUBLE LINKED LIST
typedef struct elm_relasi *adr_r;
struct elm_relasi{
    adr_r next, prev;
    adr_p parent;
    adr_c child;
};
struct list_relasi{
    adr_r first, last;
};
void createList_r(list_relasi &L);
adr_r alokasi_r(adr_p P, adr_c C);
void insertFirst_r(list_relasi &L, adr_r R);
void insertLast_r(list_relasi &L, adr_r R);
void printInfo_r(list_relasi L);
void cariRelasiPenyakit(list_relasi L, infotype x);
void cariRelasiPasien(list_relasi L, infotype x);
void hapusData_Rparent(list_relasi &L, infotype x);
void hapusData_Rchild(list_relasi &L, infotype x);
void deleteRelasi_r(list_relasi &L, adr_r &R);
int hitungRelasi(list_relasi L, infotype x);
void searchMax(list_relasi L, list_child LL);

void MENU();
void insert_parent();
void insert_child();
void relasikan_PC();
void relasikan_CP();
void delete_parent();
void delete_child();
void viewAll();
void searchView_child();
void searchView_parent();
void close();

#endif // HEADER_H_INCLUDED
