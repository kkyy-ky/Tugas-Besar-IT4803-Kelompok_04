#include "divisi.h"
#include <iostream>
using namespace std;

addrDivisi allocateDivisi(int id, string nama, string pic, int kapasitas) {
    addrDivisi D = new elmDivisi;
    D->idDivisi = id;
    D->namaDivisi = nama;
    D->pic = pic;
    D->kapasitas = kapasitas;
    D->jumlahPegawai = 0;
    D->next = NULL;
    return D;
}

void insertLastDivisi(listDivisi &LD, addrDivisi D) {
    if (LD.first == NULL) {
        LD.first = D;
    } else {
        addrDivisi Q = LD.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = D;
    }
}

void deleteFirstDivisi(listDivisi &LD, addrDivisi &D) {
    if (LD.first != NULL) {
        D = LD.first;
        LD.first = D->next;
        D->next = NULL;
    }
}

void deleteAfterDivisi(addrDivisi prec, addrDivisi &D) {
    if (prec != NULL && prec->next != NULL) {
        D = prec->next;
        prec->next = D->next;
        D->next = NULL;
    }
}

void showDivisi(listDivisi LD) {
    addrDivisi Q = LD.first;
    cout << "===== DATA DIVISI =====\n";
    while (Q != NULL) {
        cout << "ID Divisi     : " << Q->idDivisi << endl;
        cout << "Nama Divisi   : " << Q->namaDivisi << endl;
        cout << "PIC           : " << Q->pic << endl;
        cout << "Kapasitas     : " << Q->kapasitas << endl;
        cout << "Jumlah Pegawai: " << Q->jumlahPegawai << endl;
        cout << "------------------------------\n";
        Q = Q->next;
    }
}

void editDivisi(addrDivisi D, string namaBaru, string picBaru, int kapasitasBaru) {
    if (D != NULL) {
        D->namaDivisi = namaBaru;
        D->pic = picBaru;
        D->kapasitas = kapasitasBaru;
    }
}
