#include "header.h"

// SINGLE LINKED LIST
void createList_c(list_child &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_c alokasi_c(infotype x){
    adr_c C = new elm_child;
    penyakit(C) = x;
    next(C) = NULL;
    prev(C) = NULL;

    return C;
};
void insertLast_c(list_child &L, adr_c C){
    if(first(L) == NULL){
        first(L) = C;
        last(L) = C;
    } else {
        prev(C) = last(L);
        next(last(L)) = C;
        last(L) = C;
    }
};
void deleteFirst_c(list_child &L, adr_c &C){
    if(first(L) == NULL){
        cout<<"  TIDAK ADA DATA!"<<endl;
    } else if(next(first(L)) == NULL){
        C = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        C = first(L);
        first(L) = next(C);
        next(C) = NULL;
    }
};
void deleteLast_c(list_child &L, adr_c &C){
    adr_c Q;
    if(first(L) == NULL){
        cout<<"  TIDAK ADA DATA!"<<endl;
    } else if(next(first(L)) == NULL){
        C = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        C = first(L);
        while(next(C) != NULL){
            Q = C;
            C = next(C);
        }
        next(Q) = NULL;
        last(L) = Q;
    }
};
void deleteAfter_c(list_child &L, adr_c Prec, adr_c &C){
    C = next(Prec);
    next(Prec) = next(C);
    next(C) = NULL;
};
adr_c searchElmn_c(list_child L, infotype x){
    if(first(L) != NULL){
        adr_c C = first(L);
        while(C != NULL && penyakit(C) != x){
            C = next(C);
        }
        return C;
    } else {
        return NULL;
    }
};
void printInfo_c(list_child L){
    int i = 1;
    adr_c C = first(L);

    cout<<endl<<"  Data Penyakit : "<<endl;
    while(C != NULL){
        cout<<"    "<< i <<". "<< penyakit(C) <<endl;
        i++;
        C = next(C);
    }

    if(first(L) == NULL){
        cout<<"    DATA KOSONG!  "<<endl;
    }
    cout<<endl;
};
void hapusData_c(list_child &L, infotype x){
    adr_c C, Q;

    if(first(L) == NULL){
        cout<<"  TIDAK ADA DATA!"<<endl;
    } else if(penyakit(first(L)) == x){
        deleteFirst_c(L, C);
    } else if(penyakit(last(L)) == x){
        deleteLast_c(L, C);
    } else {
        C = first(L);
        while(C != NULL && penyakit(C) != x){
            Q = C;
            C = next(C);
        }
        if(penyakit(C) == x) {
            deleteAfter_c(L, Q, C);
        } else  if(C == NULL){
            cout<<"  DATA TIDAK DITEMUKAN!"<<endl;
        }
    }
};

// CIRCULAR DOUBLE LINKED LIST
void createList_p(list_parent &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_p alokasi_p(infotype x){
    adr_p P = new elm_parent;
    pasien(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
};
void insertFirst_p(list_parent &L, adr_p P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
        prev(first(L)) = P;
        next(last(L)) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
    }
};
void insertLast_p(list_parent &L, adr_p P){
    if(first(L) == NULL){
        insertFirst_p(L, P);
    } else {
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
};
void insertAfter_p(list_parent &L, adr_p Prec, adr_p P){
    if(Prec == NULL){
        cout<<"Prec Tidak Ditemukan!  "<<endl;
    } else {
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
};
void deleteFirst_p(list_parent &L, adr_p &P){
    if(first(L) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLast_p(list_parent &L, adr_p &P){
    if(first(L) == NULL){
        cout<<"  TIDAK ADA DATA "<<endl;
        P = NULL;
    } else if(next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        prev(first(L)) = NULL;
        next(last(L)) = NULL;
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteAfter_p(list_parent &L, adr_p Prec, adr_p &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
};
adr_p searchElmn_p(list_parent L, infotype x){
    if(first(L) != NULL){
        adr_p P = first(L);
        while(pasien(P) != x && next(P) != first(L)){
            P = next(P);
        }

        if(pasien(P) == x){
            return P;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
};
void printInfo_p(list_parent L){
    int i = 2;

    cout<<endl<<"  Data Pasien : "<<endl;
    if(first(L) == NULL){
        cout<<"    DATA KOSONG!  "<<endl;
    } else {
        adr_p P = next(first(L));
        cout<<"    1. "<< pasien(first(L)) <<endl;
        while(P != first(L)){
            cout<<"    "<< i <<". "<< pasien(P) <<endl;
            i++;
            P = next(P);
        }

    }
    cout<<endl;
};
void insertAscending_p(list_parent &L, adr_p P){
    if(first(L) == NULL || pasien(P) <= pasien(first(L))){
        insertFirst_p(L, P);
    } else if(pasien(P) >= pasien(last(L))){
        insertLast_p(L, P);
    } else {
        adr_p Q = first(L);
        while(Q != NULL && pasien(P) >= pasien(Q)){
            Q = next(Q);
        }
        insertAfter_p(L, Q, P);
    }
};
void hapusData_p(list_parent &L, infotype x){
    adr_p P, Q;

    if(first(L) == NULL){
        cout<<"  TIDAK ADA DATA!"<<endl;
    } else if(pasien(first(L)) == x){
        deleteFirst_p(L, P);
        cout<<"  DATA BERHASIL DIHAPUS!"<<endl;
    } else if(pasien(last(L)) == x){
        deleteLast_p(L, P);
        cout<<"  DATA BERHASIL DIHAPUS!"<<endl;
    } else {
        P = first(L);
        while(next(P) != first(L) && pasien(P) != x){
            Q = P;
            P = next(P);
        }
        if(pasien(P) == x) {
            deleteAfter_p(L, Q, P);
            cout<<"  DATA BERHASIL DIHAPUS!"<<endl;
        } else  if(P == NULL){
            cout<<"  DATA TIDAK DITEMUKAN!"<<endl;
        }
    }
};

// DOUBLE LINKED LIST
int hitungRelasi(list_relasi L, infotype x){
    adr_r R = first(L);
    int i = 0;

    while(R != NULL){
        if(penyakit(child(R)) == x){
            i++;
        }
        R = next(R);
    }
    return i;
};
void createList_r(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_r alokasi_r(adr_p P, adr_c C){
    adr_r R = new elm_relasi;
    parent(R) = P;
    child(R) = C;
    next(R) = NULL;
    prev(R) = NULL;

    return R;
};
void insertFirst_r(list_relasi &L, adr_r R){
    if(first(L) == NULL){
        first(L) = R;
        last(L) = R;
    } else {
        next(R) = first(L);
        prev(first(L)) = R;
        first(L) = R;
    }
};
void insertLast_r(list_relasi &L, adr_r R){
    if(first(L) == NULL){
        first(L) = R;
        last(L) = R;
    } else {
        next(last(L)) = R;
        prev(R) = last(L);
        last(L) = R;
    }
};
void printInfo_r(list_relasi L){
    int i = 1;
    adr_r R = first(L);

    cout<<endl<<"  Data Berobat 2 : "<<endl;
    while(R != NULL){
        cout<<"    "<< i <<". Pasien     : "<< pasien(parent(R)) <<endl<<
                       "       Penyakit   : "<< penyakit(child(R)) <<endl;
        i++;
        R = next(R);
    }

    if(first(L) == NULL){
        cout<<"    DATA KOSONG!  "<<endl;
    }
    cout<<endl;
};
void cariRelasiPenyakit(list_relasi L, infotype x){
    int i = 1;
    adr_r R = first(L);

    if(first(L) != NULL){
        cout<<endl<<"  Data Pasien Dengan Penyakit "<<x<<endl;
        while(R != NULL){
            if(penyakit(child(R)) == x){
                cout<<"    "<< i <<". "<< pasien(parent(R)) <<endl;
                i++;
            }
            R = next(R);
        }
    } else {
        cout<<endl<<"  DATA TIDAK DITEMUKAN!  "<<endl;
    }
    cout<<endl;
};
void cariRelasiPasien(list_relasi L, infotype x){
    adr_r R = first(L);

    if(first(L) != NULL){
        cout<<endl<<"  Penyakit Yang Diderita Pasien "<<x <<":"<<endl;
            while(R != NULL){
                if(pasien(parent(R)) == x) {
                    cout<<"  - "<<penyakit(child(R))<<endl;
                }
                R = next(R);
            }
            cout<<endl;
    } else {
        cout<<"  DATA TIDAK DITEMUKAN!  "<<endl;
    }
    cout<<endl;
};
void searchMax(list_relasi L, list_child LL){
    int j, i, max = -999;
    adr_c R, Q, S;

    system("cls");
    cout<<"  ========================================================"<<endl;
    cout<<"  Penyakit Yang Sering Diderita Pasien : "<<endl;

    R = first(LL);
    while(R != NULL){
        j = hitungRelasi(L, penyakit(R));
        if(j > max){
            max = j;
            Q = R;
        }
        R = next(R);
    }

    cout<<endl<<"    => Penyakit "<<penyakit(Q)<<" - diderita oleh "<<max<<" orang"<<endl;
    cout<<endl<<"  ========================================================"<<endl;
};
void deleteRelasi_r(list_relasi &L, adr_r &R){
    if(next(R) == NULL){      //R adalah elemen terahir
        if(prev(R) == NULL){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            next(prev(R)) = NULL;
            prev(R) = NULL;
        }
        R = NULL;             //R menjadi null
    } else if(next(next(R)) == NULL){
        if(prev(R) == NULL){
            first(L) = next(R);
            prev(next(R)) = NULL;
            next(R) = NULL;
        } else {
            next(prev(R)) = next(R);
            prev(next(R)) = prev(R);
            next(R) = NULL;
            prev(R) = NULL;
        }
        R = last(L);             //R menjadi elemen terakhir
    } else {
        if(prev(R) != NULL){
            adr_r Prec = prev(R);
            next(Prec) = next(R);
            prev(next(R)) = Prec;
            next(R) = NULL;
            prev(R) = NULL;
            R = next(Prec);          //R menjadi next R
        } else {
            first(L) = next(R);
            prev(first(L)) = NULL;
            next(R) = NULL;
            R = first(L);
        }
    }
};
void hapusData_Rparent(list_relasi &L, infotype x){
    adr_r R = first(L);
    while(R != NULL){
        if(pasien(parent(R)) == x){
            deleteRelasi_r(L, R);
        } else {
            R = next(R);
        }
    }
};
void hapusData_Rchild(list_relasi &L, infotype x){
    adr_r R = first(L);
    while(R != NULL){
        if(penyakit(child(R)) == x){
            deleteRelasi_r(L, R);
        } else {
            R = next(R);
        }
    }
};
