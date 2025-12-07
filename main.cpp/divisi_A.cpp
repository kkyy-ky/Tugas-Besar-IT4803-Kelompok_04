#include "divisi.h"
#include <iostream>
using namespace std;

void createListDivisi(listDivisi &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void insertFirstDivisi(listDivisi &L, addrDivisi D) {
    if (L.first == nullptr) {
        L.first = D;
        L.last = D;
    } else {
        D->next = L.first;
        L.first->prev = D;
        L.first = D;
    }
}

void insertAfterDivisi(addrDivisi prec, addrDivisi D) {
    if (prec != nullptr) {
        D->next = prec->next;
        D->prev = prec;

        if (prec->next != nullptr) {
            prec->next->prev = D;
        }

        prec->next = D;
    }
}

void deleteLastDivisi(listDivisi &L, addrDivisi &D) {
    if (L.first == nullptr) {
        D = nullptr;
    } else if (L.first == L.last) {
        D = L.first;
        L.first = L.last = nullptr;
    } else {
        D = L.last;
        L.last = D->prev;
        L.last->next = nullptr;

        D->prev = nullptr;
    }
}

addrDivisi findDivisi(listDivisi L, int id) {
    addrDivisi D = L.first;

    while (D != nullptr) {
        if (D->idDivisi == id) {
            return D;
        }
        D = D->next;
    }

    return nullptr;
}

int countDivisi(listDivisi L) {
    int count = 0;
    addrDivisi D = L.first;

    while (D != nullptr) {
        count++;
        D = D->next;
    }

    return count;
}



