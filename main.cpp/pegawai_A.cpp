#include "pegawai.h"
#include <iostream>
using namespace std;

addrPegawai allocatePegawai(int idPegawai, string namaPegawai, string jabatan, float gaji) {
    addrPegawai P = new elmPegawai;
    P->idPegawai = idPegawai;
    P->namaPegawai = namaPegawai;
    P->jabatan = jabatan;
    P->gaji = gaji;
    P->next = nullptr;
    return P;
}

void insertLastPegawai(listPegawai &LP, addrPegawai P) {
    if (LP.first == nullptr) {
        LP.first = P;
    } else {
        addrPegawai Q = LP.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstPegawai(listPegawai &LP, addrPegawai &P) {
    if (LP.first != nullptr) {
        P = LP.first;
        LP.first = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}


void deleteAfterPegawai(listPegawai &LP, addrPegawai prec, addrPegawai &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

void showPegawai(listPegawai LP) {
    addrPegawai P = LP.first;
    while (P != nullptr) {
        cout << "ID Pegawai : " << P->idPegawai << endl;
        cout << "Nama Pegawai : " << P->namaPegawai << endl;
        cout << "Jabatan : " << P->jabatan << endl;
        cout << "Gaji : " << P->gaji << " (juta)" << endl;
        cout << "-----------------------------" << endl;
        P = P->next;
    }
}

void editPegawai(addrPegawai P, string namaBaru, string jabatanBaru, float gajiBaru) {
    if (P != nullptr) {
        P->namaPegawai = namaBaru;
        P->jabatan = jabatanBaru;
        P->gaji = gajiBaru;
    }
}
