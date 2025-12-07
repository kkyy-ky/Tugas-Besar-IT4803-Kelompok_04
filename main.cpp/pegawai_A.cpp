#include "pegawai.h"

addrPegawai allocatePegawai(int id, string nama, string jabatan, float gaji, string jenis) {
    addrPegawai P = new elmPegawai;

    P->idPegawai = id;
    P->namaPegawai = nama;
    P->jabatan = jabatan;
    P->gaji = gaji;
    P->jenisPegawai = jenis;

    P->next = nullptr;

    return P;
}

void insertLastPegawai(listPegawai &L, addrPegawai P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        addrPegawai Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstPegawai(listPegawai &L, addrPegawai &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteAfterPegawai(addrPegawai prec, addrPegawai &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

void showPegawai(listPegawai L) {
    addrPegawai P = L.first;

    while (P != nullptr) {
        cout << "ID: " << P->idPegawai
             << " | Nama: " << P->namaPegawai
             << " | Jabatan: " << P->jabatan
             << " | Gaji: " << P->gaji
             << " | Jenis: " << P->jenisPegawai
             << endl;

        P = P->next;
    }
}

void editPegawai(addrPegawai P, string namaBaru, string jabatanBaru, float gajiBaru, string jenisBaru) {
    if (P != nullptr) {
        P->namaPegawai = namaBaru;
        P->jabatan = jabatanBaru;
        P->gaji = gajiBaru;
        P->jenisPegawai = jenisBaru;
    }
}
