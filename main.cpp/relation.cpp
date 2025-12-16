#include "relation.h"
#include <iostream>
using namespace std;

void createListRelation(listRelation &LR) {
    LR.first = nullptr;
}

addrRelation allocateRelation(addrDivisi P, addrPegawai C) {
    addrRelation R = new elmRelation;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    return R;
}

void insertLastRelation(listRelation &LR, addrRelation R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        addrRelation Q = LR.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

void deleteLastRelation(listRelation &LR, addrRelation &R) {
    if (LR.first == nullptr) {
        R = nullptr;
    } else if (LR.first->next == nullptr) {
        R = LR.first;
        LR.first = nullptr;
        R->next = nullptr;
    } else {
        addrRelation Q = LR.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        R = Q->next;
        Q->next = nullptr;
        R->next = nullptr;
    }
}

void insertRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg) {
    addrDivisi P = findDivisi(LD, idDiv);
    addrPegawai C = findPegawai(LP, idPeg);

    if (P != nullptr && C != nullptr && findRelation(LR, idDiv, idPeg) == nullptr) {
        addrRelation R = allocateRelation(P, C);
        insertLastRelation(LR, R);
        P->jumlahPegawai++;
    }
}

void deleteRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg) {
    addrRelation R;

    if (LR.first == nullptr) return;

    addrRelation last = LR.first;
    while (last->next != nullptr) {
        last = last->next;
    }

    if (last->parent->idDivisi == idDiv && last->child->idPegawai == idPeg) {
        deleteLastRelation(LR, R);
        R->parent->jumlahPegawai--;
        delete R;
    }
}

addrRelation findRelation(listRelation LR, int idDiv, int idPeg) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->parent->idDivisi == idDiv && R->child->idPegawai == idPeg) {
            return R;
        }
        R = R->next;
    }
    return nullptr;
}

addrDivisi findParentFromRelation(listRelation LR, int idPeg) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->child->idPegawai == idPeg) {
            return R->parent;
        }
        R = R->next;
    }
    return nullptr;
}

addrPegawai findChildFromRelation(listRelation LR, int idDiv) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->parent->idDivisi == idDiv) {
            return R->child;
        }
        R = R->next;
    }
    return nullptr;
}

void showAllRelation(listRelation LR) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        cout << R->parent->namaDivisi << " - " << R->child->namaPegawai << endl;
        R = R->next;
    }
}

void showChildOfParent(listRelation LR, int idDiv) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->parent->idDivisi == idDiv) {
            cout << R->child->namaPegawai << endl;
        }
        R = R->next;
    }
}

void showParentOfChild(listRelation LR, int idPeg) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->child->idPegawai == idPeg) {
            cout << R->parent->namaDivisi << endl;
        }
        R = R->next;
    }
}

void showAllParentWithChild(listRelation LR) {
    addrRelation R = LR.first;
    while (R != nullptr) {
        cout << R->parent->namaDivisi << " memiliki " << R->child->namaPegawai << endl;
        R = R->next;
    }
}

void showParentWithoutChild(listDivisi LD, listRelation LR) {
    addrDivisi P = LD.first;
    while (P != nullptr) {
        if (countChildOfParent(LR, P->idDivisi) == 0) {
            cout << P->namaDivisi << endl;
        }
        P = P->next;
    }
}

void showChildWithoutParent(listPegawai LP, listRelation LR) {
    addrPegawai C = LP.first;
    while (C != nullptr) {
        if (countParentOfChild(LR, C->idPegawai) == 0) {
            cout << C->namaPegawai << endl;
        }
        C = C->next;
    }
}

int countChildOfParent(listRelation LR, int idDiv) {
    int count = 0;
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->parent->idDivisi == idDiv) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int countParentOfChild(listRelation LR, int idPeg) {
    int count = 0;
    addrRelation R = LR.first;
    while (R != nullptr) {
        if (R->child->idPegawai == idPeg) {
            count++;
        }
        R = R->next;
    }
    return count;
}

int countParentWithoutChild(listDivisi LD, listRelation LR) {
    int count = 0;
    addrDivisi P = LD.first;
    while (P != nullptr) {
        if (countChildOfParent(LR, P->idDivisi) == 0) {
            count++;
        }
        P = P->next;
    }
    return count;
}

int countChildWithoutParent(listPegawai LP, listRelation LR) {
    int count = 0;
    addrPegawai C = LP.first;
    while (C != nullptr) {
        if (countParentOfChild(LR, C->idPegawai) == 0) {
            count++;
        }
        C = C->next;
    }
    return count;
}

void editRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int oldDiv, int oldPeg, int newDiv, int newPeg) {
    addrRelation R = findRelation(LR, oldDiv, oldPeg);
    if (R != nullptr) {
        addrDivisi newP = findDivisi(LD, newDiv);
        addrPegawai newC = findPegawai(LP, newPeg);
        if (newP != nullptr && newC != nullptr) {
            R->parent->jumlahPegawai--;
            R->parent = newP;
            R->child = newC;
            newP->jumlahPegawai++;
        }
    }
}

 
