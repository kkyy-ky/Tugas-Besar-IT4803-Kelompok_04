#ifndef DIVISI_H
#define DIVISI_H
#include <iostream>
#include <string>
using namespace std;

struct elmDivisi;
typedef elmDivisi* addrDivisi;

struct elmDivisi {
    int idDivisi;
    string namaDivisi;
    int kapasitas;
    int jumlahPegawai;
    addrDivisi next;
    addrDivisi prev;
};

struct listDivisi {
    addrDivisi first;
    addrDivisi last;
};

void createListDivisi(listDivisi &LD);
addrDivisi allocateDivisi(int id, string nama, int kapasitas);
void insertFirstDivisi(listDivisi &LD, addrDivisi D);
void insertLastDivisi(listDivisi &LD, addrDivisi D);
void insertAfterDivisi(listDivisi &LD, addrDivisi prec, addrDivisi D);
void deleteFirstDivisi(listDivisi &LD, addrDivisi &D);
void deleteLastDivisi(listDivisi &LD, addrDivisi &D);
void deleteAfterDivisi(listDivisi &LD, addrDivisi prec, addrDivisi &D);
addrDivisi findDivisi(listDivisi LD, int idDivisi);
void showDivisi(listDivisi LD);
int countDivisi(listDivisi LD);
void editDivisi(addrDivisi D, string namaBaru, int kapasitasBaru);

#endif
