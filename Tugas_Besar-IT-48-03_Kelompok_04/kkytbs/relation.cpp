#include <iostream>
#include "relation.h"

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
        addrRelation P = LR.first;
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = R;
    }
}

void deleteLastRelation(listRelation &LR, addrRelation &R) {
    if (LR.first == nullptr) {
        R = nullptr;
        return;
    }

    if (LR.first->next == nullptr) {
        R = LR.first;
        LR.first = nullptr;
        return;
    }

    addrRelation P = LR.first;
    while (P->next->next != nullptr) {
        P = P->next;
    }

    R = P->next;
    P->next = nullptr;
}

void insertRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg) {
    addrDivisi D = findDivisi(LD, idDiv);
    addrPegawai P = findPegawai(LP, idPeg);

    if (D == nullptr || P == nullptr) {
        cout << "Divisi atau Pegawai tidak ditemukan" << endl;
        return;
    }

    if (findRelation(LR, idDiv, idPeg) != nullptr) {
        cout << "Relasi sudah ada" << endl;
        return;
    }

    addrRelation R = allocateRelation(D, P);
    insertLastRelation(LR, R);
}

void deleteRelation(listRelation &LR, listDivisi &LD, listPegawai &LP, int idDiv, int idPeg) {
    addrRelation P = LR.first;
    addrRelation prec = nullptr;

    while (P != nullptr) {
        if (P->parent->idDivisi == idDiv &&
            P->child->idPegawai == idPeg) {

            if (prec == nullptr) {
                LR.first = P->next;
            } else {
                prec->next = P->next;
            }

            P->next = nullptr;
            delete P;
            cout << "Relasi berhasil dihapus" << endl;
            return;
        }
        prec = P;
        P = P->next;
    }

    cout << "Relasi tidak ditemukan" << endl;
}

addrRelation findRelation(listRelation LR, int idDiv, int idPeg) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->parent->idDivisi == idDiv &&
            P->child->idPegawai == idPeg) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

addrDivisi findParentFromRelation(listRelation LR, int idPeg) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->child->idPegawai == idPeg) {
            return P->parent;
        }
        P = P->next;
    }
    return nullptr;
}

addrPegawai findChildFromRelation(listRelation LR, int idDiv) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->parent->idDivisi == idDiv) {
            return P->child;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllRelation(listRelation LR) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        cout << P->parent->namaDivisi << " - "
             << P->child->namaPegawai << endl;
        P = P->next;
    }
}

void showChildOfParent(listRelation LR, int idDiv) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->parent->idDivisi == idDiv) {
            cout << P->child->namaPegawai << endl;
        }
        P = P->next;
    }
}

void showParentOfChild(listRelation LR, int idPeg) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->child->idPegawai == idPeg) {
            cout << P->parent->namaDivisi << endl;
        }
        P = P->next;
    }
}

void showAllParentWithChild(listRelation LR) {
    addrRelation P = LR.first;
    while (P != nullptr) {
        cout << P->parent->namaDivisi << endl;
        P = P->next;
    }
}

void showParentWithoutChild(listDivisi LD, listRelation LR) {
    addrDivisi D = LD.first;
    while (D != nullptr) {
        if (countChildOfParent(LR, D->idDivisi) == 0) {
            cout << D->namaDivisi << endl;
        }
        D = D->next;
    }
}

void showChildWithoutParent(listPegawai LP, listRelation LR) {
    addrPegawai P = LP.first;
    while (P != nullptr) {
        if (countParentOfChild(LR, P->idPegawai) == 0) {
            cout << P->namaPegawai << endl;
        }
        P = P->next;
    }
}

int countChildOfParent(listRelation LR, int idDiv) {
    int count = 0;
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->parent->idDivisi == idDiv) {
            count++;
        }
        P = P->next;
    }
    return count;
}

int countParentOfChild(listRelation LR, int idPeg) {
    int count = 0;
    addrRelation P = LR.first;
    while (P != nullptr) {
        if (P->child->idPegawai == idPeg) {
            count++;
        }
        P = P->next;
    }
    return count;
}

int countParentWithoutChild(listDivisi LD, listRelation LR) {
    int count = 0;
    addrDivisi D = LD.first;
    while (D != nullptr) {
        if (countChildOfParent(LR, D->idDivisi) == 0) {
            count++;
        }
        D = D->next;
    }
    return count;
}

int countChildWithoutParent(listPegawai LP, listRelation LR) {
    int count = 0;
    addrPegawai P = LP.first;
    while (P != nullptr) {
        if (countParentOfChild(LR, P->idPegawai) == 0) {
            count++;
        }
        P = P->next;
    }
    return count;
}

void editRelation(listRelation &LR, listDivisi &LD, listPegawai &LP,int oldDiv, int oldPeg, int newDiv, int newPeg) {
    deleteRelation(LR, LD, LP, oldDiv, oldPeg);
    insertRelation(LR, LD, LP, newDiv, newPeg);
}
