#include "divisi.h"
#include <iostream>
using namespace std;

void createListDivisi(listDivisi &LD) {
    LD.first = NULL;
}

void insertFirstDivisi(listDivisi &LD, addrDivisi D) {
    D->next = LD.first;
    LD.first = D;
}

void insertAfterDivisi(addrDivisi prec, addrDivisi D) {
    if (prec != NULL) {
        D->next = prec->next;
        prec->next = D;
    }
}

void deleteLastDivisi(listDivisi &LD, addrDivisi &D) {
    if (LD.first == NULL) {
        D = NULL;
    } else if (LD.first->next == NULL) {
        D = LD.first;
        LD.first = NULL;
    } else {
        addrDivisi Q = LD.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        D = Q->next;
        Q->next = NULL;
    }
}

addrDivisi findDivisi(listDivisi LD, int id) {
    addrDivisi Q = LD.first;
    while (Q != NULL) {
        if (Q->idDivisi == id) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

int countDivisi(listDivisi LD) {
    int count = 0;
    addrDivisi Q = LD.first;
    while (Q != NULL) {
        count++;
        Q = Q->next;
    }
    return count;
}
