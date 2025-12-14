#ifndef PEGAWAI_H
#define PEGAWAI_H
#include <iostream>
#include <string>
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
addrPegawai allocatePegawai(
    int idPegawai,
    string namaPegawai,
    string jabatan,
    float gaji
);

void insertFirstPegawai(listPegawai &LP, addrPegawai P);
void insertLastPegawai(listPegawai &LP, addrPegawai P);
void insertAfterPegawai(addrPegawai prec, addrPegawai P);
void deleteFirstPegawai(listPegawai &LP, addrPegawai &P);
void deleteLastPegawai(listPegawai &LP, addrPegawai &P);
void deleteAfterPegawai(addrPegawai prec, addrPegawai &P);
addrPegawai findPegawai(listPegawai LP, int idPegawai);
void showPegawai(listPegawai LP);
int countPegawai(listPegawai LP);
void editPegawai(addrPegawai P, string namaBaru, string jabatanBaru, float gajiBaru);

#endif

ini pegawai.h nya
