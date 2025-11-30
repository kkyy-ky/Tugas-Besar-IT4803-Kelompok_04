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
    string pic;
    int kapasitas;
    int jumlahPegawai;

    addrDivisi next;
};

struct listDivisi {
    addrDivisi first;
};

void createListDivisi(listDivisi &LD);
addrDivisi allocateDivisi(int id, string nama, string pic, int kapasitas);
void insertFirstDivisi(listDivisi &LD, addrDivisi D);
void insertLastDivisi(listDivisi &LD, addrDivisi D);
void insertAfterDivisi(addrDivisi prec, addrDivisi D);
void deleteFirstDivisi(listDivisi &LD, addrDivisi &D);
void deleteLastDivisi(listDivisi &LD, addrDivisi &D);
void deleteAfterDivisi(addrDivisi prec, addrDivisi &D);
addrDivisi findDivisi(listDivisi LD, int id);
void showDivisi(listDivisi LD);
int countDivisi(listDivisi LD);
void editDivisi(addrDivisi D, string namaBaru, string picBaru, int kapasitasBaru);

#endif
