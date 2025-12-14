#ifndef RELATION_H
#define RELATION_H
#include "divisi.h"
#include "pegawai.h"

struct elmRelation;
typedef elmRelation* addrRelation;

struct elmRelation {
    addrDivisi parent;
    addrPegawai child;
    addrRelation next;
};

struct listRelation {
    addrRelation first;
};

void createListRelation(listRelation &LR);
addrRelation allocateRelation(addrDivisi P, addrPegawai C);
void insertLastRelation(listRelation &LR, addrRelation R);
void deleteLastRelation(listRelation &LR, addrRelation &R);
void insertRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg);
void deleteRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg);
addrRelation findRelation(listRelation LR, int idDiv, int idPeg);
addrDivisi findParentFromRelation(listRelation LR, int idPeg);
addrPegawai findChildFromRelation(listRelation LR, int idDiv);
void showAllRelation(listRelation LR);
void showChildOfParent(listRelation LR, int idDiv);
void showParentOfChild(listRelation LR, int idPeg);
void showAllParentWithChild(listRelation LR);
void showParentWithoutChild(listDivisi LD, listRelation LR);
void showChildWithoutParent(listPegawai LP, listRelation LR);
int countChildOfParent(listRelation LR, int idDiv);
int countParentOfChild(listRelation LR, int idPeg);
int countParentWithoutChild(listDivisi LD, listRelation LR);
int countChildWithoutParent(listPegawai LP, listRelation LR);
void editRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int oldDiv, int oldPeg, int newDiv, int newPeg);

#endif

