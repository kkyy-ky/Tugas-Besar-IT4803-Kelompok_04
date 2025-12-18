#include "pegawai.h"
#include <iostream>
using namespace std;

void createListPegawai(listPegawai &LP) {
    LP.first = nullptr;
}

void insertFirstPegawai(listPegawai &LP, addrPegawai P) {
        P->next = LP.first;
        LP.first = P;
}

void insertAfterPegawai(listPegawai &LP, addrPegawai prec, addrPegawai P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteLastPegawai(listPegawai &LP, addrPegawai &P) {
    if (LP.first != nullptr) {
        if (LP.first->next == nullptr) {
            P = LP.first;
            LP.first = nullptr;
        } else {
            addrPegawai Q = LP.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = nullptr;
        }
    } else {
        P = nullptr;
    }
}

addrPegawai findPegawai(listPegawai LP, int idPegawai) {
    addrPegawai P = LP.first;
    while (P != nullptr && P->idPegawai != idPegawai) {
        P = P->next;
    }
    return P;
}

int countPegawai(listPegawai LP) {
    int count = 0;
    addrPegawai P = LP.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}
