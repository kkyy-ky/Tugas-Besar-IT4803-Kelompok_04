#include "pegawai.h"

void createListPegawai(listPegawai &L) {
    L.first = nullptr;
}

void insertFirstPegawai(listPegawai &L, addrPegawai P) {
    P->next = L.first;
    L.first = P;
}

void insertAfterPegawai(addrPegawai prec, addrPegawai P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteLastPegawai(listPegawai &L, addrPegawai &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        addrPegawai Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

addrPegawai findPegawai(listPegawai L, int id) {
    addrPegawai P = L.first;

    while (P != NULL) {
        if (P->idPegawai == id) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

int countPegawai(listPegawai L) {
    int count = 0;
    addrPegawai P = L.first;

    while (P != nullptr) {
        count++;
        P = P->next;
    }

    return count;
}

