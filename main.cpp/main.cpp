#include <iostream>
#include "divisi.h"
#include "pegawai.h"
#include "relation.h"

using namespace std;

int main() {
    listDivisi LD;
    listPegawai LP;
    listRelation LR;

    addrDivisi d;
    addrPegawai p;

    createListDivisi(LD);
    createListPegawai(LP);
    createListRelation(LR);

    int menuUtama = -1;
    int menuSub = -1;

    while (menuUtama != 0) {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Divisi" << endl;
        cout << "2. Pegawai" << endl;
        cout << "3. Relasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menuUtama;
        if (menuUtama == 1) {
            menuSub = -1;
            while (menuSub != 0) {
                cout << "\n--- MENU DIVISI ---" << endl;
                cout << "1. Insert Divisi" << endl;
                cout << "2. Delete Divisi" << endl;
                cout << "3. Find Divisi" << endl;
                cout << "4. Show Divisi" << endl;
                cout << "5. Count Divisi" << endl;
                cout << "6. Edit Divisi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuSub;

                if (menuSub == 1) {
                    d = allocateDivisi(1, "IT", 10);
                    insertLastDivisi(LD, d);
                    cout << "Divisi berhasil ditambahkan" << endl;
                }
                else if (menuSub == 2) {
                    deleteLastDivisi(LD, d);
                    cout << "Divisi berhasil dihapus" << endl;
                }
                else if (menuSub == 3) {
                    d = findDivisi(LD, 1);
                    if (d != nullptr)
                        cout << "Divisi ditemukan: " << d->namaDivisi << endl;
                    else
                        cout << "Divisi tidak ditemukan" << endl;
                }
                else if (menuSub == 4) {
                    showDivisi(LD);
                }
                else if (menuSub == 5) {
                    cout << "Jumlah divisi: " << countDivisi(LD) << endl;
                }
                else if (menuSub == 6) {
                    d = findDivisi(LD, 1);
                    if (d != nullptr) {
                        editDivisi(d, "IT Updated", 15);
                        cout << "Divisi berhasil diubah" << endl;
                    }
                }
            }
        }
        else if (menuUtama == 2) {
            menuSub = -1;
            while (menuSub != 0) {
                cout << "\n--- MENU PEGAWAI ---" << endl;
                cout << "1. Insert Pegawai" << endl;
                cout << "2. Delete Pegawai" << endl;
                cout << "3. Find Pegawai" << endl;
                cout << "4. Show Pegawai" << endl;
                cout << "5. Count Pegawai" << endl;
                cout << "6. Edit Pegawai" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuSub;

                if (menuSub == 1) {
                    p = allocatePegawai(101, "Andi", "Programmer", 8000000);
                    insertLastPegawai(LP, p);
                    cout << "Pegawai berhasil ditambahkan" << endl;
                }
                else if (menuSub == 2) {
                    deleteLastPegawai(LP, p);
                    cout << "Pegawai berhasil dihapus" << endl;
                }
                else if (menuSub == 3) {
                    p = findPegawai(LP, 101);
                    if (p != nullptr)
                        cout << "Pegawai ditemukan: " << p->namaPegawai << endl;
                    else
                        cout << "Pegawai tidak ditemukan" << endl;
                }
                else if (menuSub == 4) {
                    showPegawai(LP);
                }
                else if (menuSub == 5) {
                    cout << "Jumlah pegawai: " << countPegawai(LP) << endl;
                }
                else if (menuSub == 6) {
                    p = findPegawai(LP, 101);
                    if (p != nullptr) {
                        editPegawai(p, "Andi Update", "Senior Programmer", 9000000);
                        cout << "Pegawai berhasil diubah" << endl;
                    }
                }
            }
        }
        else if (menuUtama == 3) {
            menuSub = -1;
            while (menuSub != 0) {
                cout << "\n--- MENU RELASI ---" << endl;
                cout << "1. Insert Relasi" << endl;
                cout << "2. Delete Relasi" << endl;
                cout << "3. Find Relasi" << endl;
                cout << "4. Show Relasi" << endl;
                cout << "5. Count Child of Parent" << endl;
                cout << "6. Edit Relasi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuSub;

                if (menuSub == 1) {
                    insertRelation(LR, LD, LP, 1, 101);
                    cout << "Relasi berhasil ditambahkan" << endl;
                }
                else if (menuSub == 2) {
                    deleteRelation(LR, LD, LP, 1, 101);
                    cout << "Relasi berhasil dihapus" << endl;
                }
                else if (menuSub == 3) {
                    if (findRelation(LR, 1, 101) != nullptr)
                        cout << "Relasi ditemukan" << endl;
                    else
                        cout << "Relasi tidak ditemukan" << endl;
                }
                else if (menuSub == 4) {
                    showAllRelation(LR);
                }
                else if (menuSub == 5) {
                    cout << "Jumlah pegawai di divisi 1: "
                         << countChildOfParent(LR, 1) << endl;
                }
                else if (menuSub == 6) {
                    editRelation(LR, LD, LP, 1, 101, 2, 101);
                    cout << "Relasi berhasil diubah" << endl;
                }
            }
        }
    }
    cout << "Program selesai." << endl;
    return 0;
}
