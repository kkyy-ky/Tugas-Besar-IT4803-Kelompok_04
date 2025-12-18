#include "divisi.h"
#include <iostream>
using namespace std;

addrDivisi allocateDivisi(int id, string nama, int kapasitas) {
    addrDivisi D = new elmDivisi;
    D->idDivisi = id;
    D->namaDivisi = nama;
    D->kapasitas = kapasitas;
    D->jumlahPegawai = 0;
    D->next = nullptr;
    D->prev = nullptr;
    return D;
}

void insertLastDivisi(listDivisi &LD, addrDivisi D) {
    if (LD.first == nullptr) {
        LD.first = D;
        LD.last = D;
    } else {
        D->prev = LD.last;
        LD.last->next = D;
        LD.last = D;
    }
}


void deleteFirstDivisi(listDivisi &LD, addrDivisi &D) {
    if (LD.first != nullptr) {
        D = LD.first;
        if (LD.first == LD.last) {
            LD.first = nullptr;
            LD.last = nullptr;
        } else {
            LD.first = D->next;
            LD.first->prev = nullptr;
        }
        D->next = nullptr;
        D->prev = nullptr;
    }
}


void deleteAfterDivisi(listDivisi &LD, addrDivisi prec, addrDivisi &D) {
    if (prec != nullptr && prec->next != nullptr) {
        D = prec->next;
        if (D == LD.last) {
            LD.last = prec;
        }
        prec->next = D->next;
        if (D->next != nullptr) {
            D->next->prev = prec;
        }
        D->next = nullptr;
        D->prev = nullptr;
    }
}



void showDivisi(listDivisi LD) {
    addrDivisi P = LD.first;
    if (P == nullptr) {
        cout << "List divisi kosong" << endl;
    } else {
        while (P != nullptr) {
            cout << "ID Divisi      : " << P->idDivisi << endl;
            cout << "Nama Divisi    : " << P->namaDivisi << endl;
            cout << "Kapasitas      : " << P->kapasitas << endl;
            cout << "Jumlah Pegawai : " << P->jumlahPegawai << endl;
            cout << "-----------------------------" << endl;
            P = P->next;
        }
    }
}


void editDivisi(addrDivisi D, string namaBaru, int kapasitasBaru) {
    if (D != nullptr) {
        D->namaDivisi = namaBaru;
        D->kapasitas = kapasitasBaru;
    }
}
