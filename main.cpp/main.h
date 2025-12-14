#ifndef MAIN_H
#define MAIN_H
#include "divisi.h"
#include "pegawai.h"
#include "relation.h"

void initDummyData(listDivisi &LD, listPegawai &LP, listRelation &LR);
void menuUtama();
void menuDivisi();
void menuPegawai();
void menuRelasi();
void prosesMenuDivisi(listDivisi &LD);
void prosesMenuPegawai(listPegawai &LP);
void prosesMenuRelasi(listDivisi &LD, listPegawai &LP, listRelation &LR);

#endif


