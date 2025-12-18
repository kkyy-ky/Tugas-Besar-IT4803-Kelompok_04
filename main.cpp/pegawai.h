#ifndef PEGAWAI_H
#define PEGAWAI_H
#include <iostream>
using namespace std;

struct elmPegawai;
typedef elmPegawai* addrPegawai;

struct elmPegawai {
    int idPegawai;
    string namaPegawai;
    string jabatan;
    float gaji;
    addrPegawai next;
};

struct listPegawai {
    addrPegawai first;
};

void createListPegawai(listPegawai &LP);
addrPegawai allocatePegawai(int id, string nama, string jabatan, float gaji);
void insertFirstPegawai(listPegawai &LP, addrPegawai P);
void insertLastPegawai(listPegawai &LP, addrPegawai P);
void insertAfterPegawai(listPegawai &LP, addrPegawai prec, addrPegawai P);
void deleteFirstPegawai(listPegawai &LP, addrPegawai &P);
void deleteLastPegawai(listPegawai &LP, addrPegawai &P);
void deleteAfterPegawai(listPegawai &LP, addrPegawai prec, addrPegawai &P);
addrPegawai findPegawai(listPegawai LP, int id);
void showPegawai(listPegawai LP);
int countPegawai(listPegawai LP);
void editPegawai(addrPegawai P, string nama, string jabatan, float gaji);

#endif
