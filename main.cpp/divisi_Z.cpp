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

    D->next = nullptr;
    D->prev = nullptr;

    return D;
}

void insertLastDivisi(listDivisi &L, addrDivisi D) {
    if (L.first == nullptr) {
        L.first = D;
        L.last = D;
    } else {
        LD.last->next = D;
        D->prev = L.last;
        L.last = D;
    }
}

void deleteFirstDivisi(listDivisi &L, addrDivisi &D) {
    if (L.first == nullptr) {
        D = NULL;
    } else if (L.first == L.last) {
        D = L.first;
        L.first = L.last = nullptr;
    } else {
        D = L.first;
        L.first = D->next;
        L.first->prev = nullptr;

        D->next = nullptr;
    }
}

void deleteAfterDivisi(addrDivisi prec, addrDivisi &D) {
    if (prec != nullptr && prec->next != nullptr) {
        D = prec->next;

        prec->next = D->next;
        if (D->next != nullptr) {
            D->next->prev = prec;
        }

        D->next = nullptr;
        D->prev = nullptr;
    }
}

void showDivisi(listDivisi L) {
    addrDivisi D = L.first;

    while (D != nullptr) {
        cout << "ID: " << D->idDivisi
             << " | Nama: " << D->namaDivisi
             << " | PIC: " << D->pic
             << " | Kapasitas: " << D->kapasitas
             << " | Jumlah Pegawai: " << D->jumlahPegawai
             << endl;

        D = D->next;
    }
}

void editDivisi(addrDivisi D, string namaBaru, string picBaru, int kapasitasBaru) {
    if (D != nullptr) {
        D->namaDivisi = namaBaru;
        D->pic = picBaru;
        D->kapasitas = kapasitasBaru;
    }
}



