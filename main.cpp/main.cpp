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

    int pilihUtama, pilihSub;

    do {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Divisi" << endl;
        cout << "2. Pegawai" << endl;
        cout << "3. Relasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihUtama;

        switch (pilihUtama) {

        case 1:
            do {
                cout << "\n===== MENU DIVISI =====" << endl;
                cout << "1. Insert Divisi" << endl;
                cout << "2. Delete Divisi" << endl;
                cout << "3. Find Divisi" << endl;
                cout << "4. Show Divisi" << endl;
                cout << "5. Count Divisi" << endl;
                cout << "6. Edit Divisi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> pilihSub;

                switch (pilihSub) {
                case 1:
                    d = allocateDivisi(1, "IT", 10);
                    insertLastDivisi(LD, d);
                    cout << "Insert divisi berhasil" << endl;
                    break;

                case 2:
                    deleteLastDivisi(LD, d);
                    cout << "Delete divisi berhasil" << endl;
                    break;

                case 3:
                    d = findDivisi(LD, 1);
                    if (d != nullptr)
                        cout << "Divisi ditemukan: " << d->namaDivisi << endl;
                    else
                        cout << "Divisi tidak ditemukan" << endl;
                    break;

                case 4:
                    showDivisi(LD);
                    break;

                case 5:
                    cout << "Jumlah divisi: " << countDivisi(LD) << endl;
                    break;

                case 6:
                    d = findDivisi(LD, 1);
                    if (d != nullptr)
                        editDivisi(d, "IT Updated", 15);
                    break;
                }
            } while (pilihSub != 0);
            break;

        case 2:
            do {
                cout << "\n===== MENU PEGAWAI =====" << endl;
                cout << "1. Insert Pegawai" << endl;
                cout << "2. Delete Pegawai" << endl;
                cout << "3. Find Pegawai" << endl;
                cout << "4. Show Pegawai" << endl;
                cout << "5. Count Pegawai" << endl;
                cout << "6. Edit Pegawai" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> pilihSub;

                switch (pilihSub) {
                case 1:
                    p = allocatePegawai(101, "Andi", "Programmer", 8000000);
                    insertLastPegawai(LP, p);
                    cout << "Insert pegawai berhasil" << endl;
                    break;

                case 2:
                    deleteLastPegawai(LP, p);
                    cout << "Delete pegawai berhasil" << endl;
                    break;

                case 3:
                    p = findPegawai(LP, 101);
                    if (p != nullptr)
                        cout << "Pegawai ditemukan: " << p->namaPegawai << endl;
                    else
                        cout << "Pegawai tidak ditemukan" << endl;
                    break;

                case 4:
                    showPegawai(LP);
                    break;

                case 5:
                    cout << "Jumlah pegawai: " << countPegawai(LP) << endl;
                    break;

                case 6:
                    p = findPegawai(LP, 101);
                    if (p != nullptr)
                        editPegawai(p, "Andi Update", "Senior Programmer", 9000000);
                    break;
                }
            } while (pilihSub != 0);
            break;

        case 3:
            do {
                cout << "\n===== MENU RELASI =====" << endl;
                cout << "1. Insert Relasi" << endl;
                cout << "2. Delete Relasi" << endl;
                cout << "3. Find Relasi" << endl;
                cout << "4. Show Semua Relasi" << endl;
                cout << "5. Count Child of Parent" << endl;
                cout << "6. Edit Relasi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> pilihSub;

                switch (pilihSub) {
                case 1:
                    insertRelation(LR, LD, LP, 1, 101);
                    cout << "Insert relasi berhasil" << endl;
                    break;

                case 2:
                    deleteRelation(LR, LD, LP, 1, 101);
                    cout << "Delete relasi berhasil" << endl;
                    break;

                case 3:
                    if (findRelation(LR, 1, 101) != nullptr)
                        cout << "Relasi ditemukan" << endl;
                    else
                        cout << "Relasi tidak ditemukan" << endl;
                    break;

                case 4:
                    showAllRelation(LR);
                    break;

                case 5:
                    cout << "Jumlah pegawai di divisi 1: "
                         << countChildOfParent(LR, 1) << endl;
                    break;

                case 6:
                    editRelation(LR, LD, LP, 1, 101, 2, 101);
                    cout << "Edit relasi berhasil" << endl;
                    break;
                }
            } while (pilihSub != 0);
            break;
        }

    } while (pilihUtama != 0);

    return 0;
}
