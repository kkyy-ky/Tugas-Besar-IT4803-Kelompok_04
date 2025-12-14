#include "divisi.h"
#include <iostream>
using namespace std;

void createListDivisi(listDivisi &LD) {
    LD.first = nullptr;
    LD.last = nullptr;
}


void insertFirstDivisi(listDivisi &LD, addrDivisi D) {
    if (LD.first == nullptr) {
        LD.first = D;
        LD.last = D;
    } else {
        D->next = LD.first;
        LD.first->prev = D;
        LD.first = D;
    }
}


void insertAfterDivisi(listDivisi &LD, addrDivisi prec, addrDivisi D) {
    if (prec != nullptr) {
        if (prec == LD.last) {
            insertLastDivisi(LD, D);
        } else {
            D->next = prec->next;
            D->prev = prec;
            prec->next->prev = D;
            prec->next = D;
        }
    }
}

void deleteLastDivisi(listDivisi &LD, addrDivisi &D) {
    if (LD.last != nullptr) {
        D = LD.last;

        if (LD.first == LD.last) {
            LD.first = nullptr;
            LD.last = nullptr;
        } else {
            LD.last = D->prev;
            LD.last->next = nullptr;
        }
        D->prev = nullptr;
        D->next = nullptr;
    }
}


addrDivisi findDivisi(listDivisi LD, int idDivisi) {
    addrDivisi P = LD.first;
    while (P != nullptr && P->idDivisi != idDivisi) {
        P = P->next;
    }
    return P;
}


int countDivisi(listDivisi LD) {
    int count = 0;
    addrDivisi P = LD.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}


