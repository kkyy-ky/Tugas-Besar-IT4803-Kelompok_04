#ifndef PEGAWAI_H
#define PEGAWAI_H
#include <iostream>
#include <string>
using namespace std;

struct elmPeg;
typedef elmPeg* addrPeg;

struct elmPeg {
    int idPegawai;
    string namaPegawai;
    addrPeg next;
    addrPeg prev;
};

struct listPeg {
    addrPeg first;
    addrPeg last;
};

void createListPeg(listPeg &L);
addrPeg allocatePeg(int id, string nama);
void insertFirstPeg(listPeg &L, addrPeg p);
void insertLastPeg(listPeg &L, addrPeg p);
void insertAfterPeg(addrPeg prec, addrPeg p);
void deleteFirstPeg(listPeg &L, addrPeg &p);
void deleteLastPeg(listPeg &L, addrPeg &p);
void deleteAfterPeg(addrPeg prec, addrPeg &p);
addrPeg findPeg(listPeg L, int idPegawai);
void showPegawai(listPeg L);
void printPeg(addrPeg p);

#endif // PEGAWAI_H
