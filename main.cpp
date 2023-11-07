#include "header.h"

list_child Lc;
list_parent Lp;
list_relasi Lr;

void MENU(){
    int pilihan;

    do{
        cout<<"  ========================================================"<<endl;
        cout<<"                 D A T A   B E R O B A T 2                "<<endl;
        cout<<"  =======================  M E N U  ======================"<<endl;
        cout<<"    [1]  Tambahkan Data Pasien                            "<<endl;
        cout<<"    [2]  Tambahkan Data Penyakit                          "<<endl;
        cout<<"    [3]  Relasikan Pasien - Penyakit                      "<<endl;
        cout<<"    [4]  Relasikan Penyakit - Pasien                      "<<endl;
        cout<<"    [5]  Hapus Data Pasien                                "<<endl;
        cout<<"    [6]  Hapus Data Penyakit                              "<<endl;
        cout<<"    [7]  Tampilkan Semua Data Berobat 2                   "<<endl;
        cout<<"    [8]  Tampilkan Data Pasien Berdasarkan Penyakit       "<<endl;
        cout<<"    [9]  Tampilkan Data Penyakit Berdasarkan Pasien       "<<endl;
        cout<<"    [10] Tampilkan Penyakit Yang Paling Banyak            "<<endl<<
              "         Terjangkit Di Lingkungan Masyarakat              "<<endl<<endl;
        cout<<"    [0]  EXIT PROGRAM                                     "<<endl;
        cout<<"  ========================================================"<<endl;
        cout<<"  Masukan Pilihan : ";
        cin>>pilihan;

        switch(pilihan){
            case 1: insert_parent();break;
            case 2: insert_child();break;
            case 3: relasikan_PC();break;
            case 4: relasikan_CP();break;
            case 5: delete_parent();break;
            case 6: delete_child();break;
            case 7: viewAll();break;
            case 8: searchView_child();break;
            case 9: searchView_parent();break;;
            case 10: searchMax(Lr, Lc);break;
            case 0: close();break;
            default :
                cout<<"  WRONG INPUT!  "<<endl;break;
        }
        cout<<"  Tekan Enter...  ";
        getch();
        cout<<endl;
        system("cls");
    }while(pilihan != 0);
};
void insert_child(){
    system("cls");
    string penyakit;
    adr_c C;
    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Penyakit: ";
    cin>>penyakit;

    C = alokasi_c(penyakit);
    insertLast_c(Lc, C);

    cout<<endl<<"  ========================================================"<<endl;
    cout<<"  Sukses! Data Berhasil Ditambahkan  "<<endl;
    cout<<"  ========================================================"<<endl;

};
void insert_parent(){
    system("cls");
    string pasien;
    adr_p P;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Pasien : ";
    cin>>pasien;

    P = alokasi_p(pasien);
    insertAscending_p(Lp, P);

    cout<<endl<<"  ========================================================"<<endl;
    cout<<"  Sukses! Data Berhasil Ditambahkan  "<<endl;
    cout<<"  ========================================================"<<endl;
};
void relasikan_PC(){
    system("cls");
    adr_c C;
    adr_p P;
    adr_r R;
    string pasien, penyakit;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Pasien   : ";
    cin>>pasien;
    cout<<"  Masukan Nama penyakit : ";
    cin>>penyakit;

    C = searchElmn_c(Lc, penyakit);
    P = searchElmn_p(Lp, pasien);

    cout<<endl<<"  ========================================================"<<endl;
    if(C == NULL || P == NULL){
        if(C == NULL){
            cout<<"  Nama Penyakit Tidak Ditemukan!  "<<endl;
        }
        if(P == NULL){
            cout<<"  Nama Pasien Tidak Ditemukan!  "<<endl;
        }
    } else {
        R = alokasi_r(P, C);
        insertFirst_r(Lr, R);

        cout<<"  Sukses! Data Berhasil Di Relasikan  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void relasikan_CP(){
    system("cls");
    adr_c C;
    adr_p P;
    adr_r R;
    string pasien, penyakit;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Penyakit : ";
    cin>>penyakit;
    cout<<"  Masukan Nama Pasien   : ";
    cin>>pasien;

    C = searchElmn_c(Lc, penyakit);
    P = searchElmn_p(Lp, pasien);

    cout<<endl<<"  ========================================================"<<endl;
    if(C == NULL || P == NULL){
        if(C == NULL){
            cout<<"  Nama Penyakit Tidak Ditemukan!  "<<endl;
        }
        if(P == NULL){
            cout<<"  Nama Pasien Tidak Ditemukan!  "<<endl;
        }
    } else {
        R = alokasi_r(P, C);
        insertLast_r(Lr, R);

        cout<<"  Sukses! Data Berhasil Di Relasikan  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void delete_parent(){
    system("cls");
    string p; adr_p P;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Pasien Yang Akan Dihapus: ";
    cin>>p;

    cout<<endl<<"  ========================================================"<<endl;
    P = searchElmn_p(Lp, p);
    if(P != NULL){
        hapusData_p(Lp, p);
        hapusData_Rparent(Lr, p);
    } else {
        cout<<"  DATA TIDAK DITEMUKAN  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void delete_child(){
    system("cls");
    string p; adr_c C;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Penyakit Yang Akan Dihapus: ";
    cin>>p;

    cout<<endl<<"  ========================================================"<<endl;
    C = searchElmn_c(Lc, p);
    if(C != NULL){
        hapusData_c(Lc, p);
        hapusData_Rchild(Lr, p);
    } else {
        cout<<"  DATA TIDAK DITEMUKAN  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void viewAll(){
    system("cls");
    cout<<endl<<"  ========================================================"<<endl;
    printInfo_p(Lp);
    cout<<"  ========================================================"<<endl;
    printInfo_c(Lc);
    cout<<"  ========================================================"<<endl;
    printInfo_r(Lr);
    cout<<"  ========================================================"<<endl;
};
void searchView_child(){
    system("cls");
    string p; adr_c C;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Penyakit: ";
    cin>>p;

    cout<<endl<<"  ========================================================"<<endl;
    C = searchElmn_c(Lc, p);
    if(C != NULL){
        cariRelasiPenyakit(Lr, p);
    } else {
        cout<<"  DATA TIDAK DITEMUKAN  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void searchView_parent(){
    system("cls");
    string p; adr_p P;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Pasien : ";
    cin>>p;

    cout<<endl<<"  ========================================================"<<endl;
    P = searchElmn_p(Lp, p);
    if(P != NULL){
        cariRelasiPasien(Lr, p);
    } else {
        cout<<"  DATA TIDAK DITEMUKAN  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};
void close(){
    system("cls");
    cout<<endl<<"  +======================================================+"<<endl;
    cout<<endl<<"  ||               A N D A   K E L U A R                ||"<<endl;
    cout<<endl<<"  |======================================================|"<<endl;
    cout<<endl<<"  ||             S T R U K T U R   D A T A              ||"<<endl;
    cout<<endl<<"  +======================================================+"<<endl;
    exit(0);
};

int main(){
    createList_c(Lc);
    createList_p(Lp);
    createList_r(Lr);

    string pasien, penyakit;
    adr_c C; adr_p P; adr_r R;

    P = alokasi_p("nama1");
    insertAscending_p(Lp, P);
    P = alokasi_p("nama2");
    insertAscending_p(Lp, P);
    P = alokasi_p("nama3");
    insertAscending_p(Lp, P);
    P = alokasi_p("nama4");
    insertAscending_p(Lp, P);

    C = alokasi_c("penyakit1");
    insertLast_c(Lc, C);
    C = alokasi_c("penyakit2");
    insertLast_c(Lc, C);
    C = alokasi_c("penyakit3");
    insertLast_c(Lc, C);
    C = alokasi_c("penyakit4");
    insertLast_c(Lc, C);
    C = alokasi_c("penyakit5");
    insertLast_c(Lc, C);
    C = alokasi_c("penyakit6");
    insertLast_c(Lc, C);

    P = searchElmn_p(Lp, "nama1");
    C = searchElmn_c(Lc, "penyakit1");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit2");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit5");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);

    P = searchElmn_p(Lp, "nama2");
    C = searchElmn_c(Lc, "penyakit3");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit4");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);

    P = searchElmn_p(Lp, "nama3");
    C = searchElmn_c(Lc, "penyakit5");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit6");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);

    P = searchElmn_p(Lp, "nama4");
    C = searchElmn_c(Lc, "penyakit6");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit5");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);
    C = searchElmn_c(Lc, "penyakit4");
    R = alokasi_r(P, C);
    insertLast_r(Lr, R);


    MENU();

    return 0;
}
