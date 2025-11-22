#ifndef PEGAWAI_H_INCLUDED
#define PEGAWAI_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct elmPeg *addrPeg;

struct elmPeg {
    string namaPegawai;
    int idPegawai;
    string jabatan;
    int gaji;

    addrPeg nextPeg;
};

struct listPeg {
    addrPeg firstPeg;
};

addrPeg allocatePeg(string namaPeg, int idPeg, string jabatan, int gaji);

#endif // PEGAWAI_H_INCLUDED
