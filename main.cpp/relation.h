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
void insertFirstRelation(listRelation &LR, addrRelation R);
void insertLastRelation(listRelation &LR, addrRelation R);
void deleteFirstRelation(listRelation &LR, addrRelation &R);
void deleteLastRelation(listRelation &LR, addrRelation &R);
void deleteAfterRelation(listRelation &LR, addrRelation prec, addrRelation &R);
void insertRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg);
void deleteRelationByPC(listRelation &LR, int idDiv, int idPeg);
addrRelation findRelation(listRelation LR, int idDiv, int idPeg);
bool isRelated(listRelation LR, int idDiv, int idPeg);
void showChildOfParent(listRelation LR, int idDiv);
void showParentOfChild(listRelation LR, int idPeg);
void showAllParentWithChild(listRelation LR);
void showAllChildWithParent(listRelation LR);
int countChildOfParent(listRelation LR, int idDiv);
int countParentOfChild(listRelation LR, int idPeg);
int countChildWithoutParent(listPegawai LP, listRelation LR);
int countParentWithoutChild(listDivisi LD, listRelation LR);
void editRelationParent(listRelation &LR, int oldParent, int newParent, int idPeg);
void editRelationChild(listRelation &LR, int oldChild, int newChild, int idDiv);

#endif
