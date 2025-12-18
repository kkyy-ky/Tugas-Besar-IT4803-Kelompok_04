#include <iostream>
#include "divisi.h"
#include "pegawai.h"
#include "relation.h"

using namespace std;

void initDummyData(listDivisi &LD, listPegawai &LP, listRelation &LR) {
    insertLastDivisi(LD, allocateDivisi(1, "IT", 10));
    insertLastDivisi(LD, allocateDivisi(2, "HRD", 5));
    insertLastDivisi(LD, allocateDivisi(3, "Finance", 7));

    insertLastPegawai(LP, allocatePegawai(101, "Andi", "Programmer", 8));
    insertLastPegawai(LP, allocatePegawai(102, "Budi", "HR Staff", 6));
    insertLastPegawai(LP, allocatePegawai(103, "Citra", "Finance Staff", 6.5));

    insertRelation(LR, LD, LP, 1, 101);
    insertRelation(LR, LD, LP, 2, 102);
    insertRelation(LR, LD, LP, 3, 103);
}

int main() {
    listDivisi LD;
    listPegawai LP;
    listRelation LR;
    createListDivisi(LD);
    createListPegawai(LP);
    createListRelation(LR);
    initDummyData(LD, LP, LR);

    int menuUtama = -1;
    while (menuUtama != 0) {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Menu Divisi" << endl;
        cout << "2. Menu Pegawai" << endl;
        cout << "3. Menu Relasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> menuUtama;

        if (menuUtama == 1) {
            int menuDivisi = -1;
            while (menuDivisi != 0) {
                cout << "\n--- MENU DIVISI ---" << endl;
                cout << "1. Insert Divisi" << endl;
                cout << "2. Delete Divisi" << endl;
                cout << "3. Find Divisi" << endl;
                cout << "4. Show Divisi" << endl;
                cout << "5. Count Divisi" << endl;
                cout << "6. Edit Divisi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuDivisi;

                if (menuDivisi == 1) {
                    int pilih, id, kapasitas, idAfter;
                    string nama;

                    cout << "\n--- INSERT DIVISI ---" << endl;
                    cout << "1. Awal" << endl;
                    cout << "2. Akhir" << endl;
                    cout << "3. After ID" << endl;
                    cout << "Pilih: ";
                    cin >> pilih;

                    cout << "ID Divisi     : ";
                    cin >> id;
                    cout << "Nama Divisi   : ";
                    cin >> nama;
                    cout << "Kapasitas     : ";
                    cin >> kapasitas;

                    addrDivisi d = allocateDivisi(id, nama, kapasitas);

                    if (pilih == 1) {
                        insertFirstDivisi(LD, d);
                    }
                    else if (pilih == 2) {
                        insertLastDivisi(LD, d);
                    }
                    else if (pilih == 3) {
                        cout << "After ID Divisi: ";
                        cin >> idAfter;
                        addrDivisi prec = findDivisi(LD, idAfter);
                        if (prec != nullptr)
                            insertAfterDivisi(LD, prec, d);
                        else
                            cout << "ID tidak ditemukan" << endl;
                    }
                }

                else if (menuDivisi == 2) {
                    int pilih, idAfter;
                    addrDivisi d;

                    cout << "\n--- DELETE DIVISI ---" << endl;
                    cout << "1. Awal" << endl;
                    cout << "2. Akhir" << endl;
                    cout << "3. After ID" << endl;
                    cout << "Pilih: ";
                    cin >> pilih;

                    if (pilih == 1) {
                        deleteFirstDivisi(LD, d);
                    }
                    else if (pilih == 2) {
                        deleteLastDivisi(LD, d);
                    }
                    else if (pilih == 3) {
                        cout << "After ID Divisi: ";
                        cin >> idAfter;
                        addrDivisi prec = findDivisi(LD, idAfter);
                        if (prec != nullptr)
                            deleteAfterDivisi(LD, prec, d);
                        else
                            cout << "ID tidak ditemukan" << endl;
                    }
                }

                else if (menuDivisi == 3) {
                    int id;
                    cout << "\nID Divisi: ";
                    cin >> id;
                    addrDivisi d = findDivisi(LD, id);

                    if (d != nullptr)
                        cout << "Divisi ditemukan: " << d->namaDivisi << endl;
                    else
                        cout << "Divisi tidak ditemukan" << endl;
                }

                else if (menuDivisi == 4) {
                    showDivisi(LD);
                }

                else if (menuDivisi == 5) {
                    cout << "Jumlah Divisi: " << countDivisi(LD) << endl;
                }

                else if (menuDivisi == 6) {
                    int id, kapasitas;
                    string nama;

                    cout << "\nID Divisi: ";
                    cin >> id;
                    addrDivisi d = findDivisi(LD, id);

                    if (d != nullptr) {
                        cout << "Nama Baru      : ";
                        cin >> nama;
                        cout << "Kapasitas Baru : ";
                        cin >> kapasitas;
                        editDivisi(d, nama, kapasitas);
                    }
                    else {
                        cout << "Divisi tidak ditemukan" << endl;
                    }
                }
            }
        }
        if (menuUtama == 2) {
            int menuPegawai = -1;
            while (menuPegawai != 0) {
                cout << "\n--- MENU PEGAWAI ---" << endl;
                cout << "1. Insert Pegawai" << endl;
                cout << "2. Delete Pegawai" << endl;
                cout << "3. Find Pegawai" << endl;
                cout << "4. Show Pegawai" << endl;
                cout << "5. Count Pegawai" << endl;
                cout << "6. Edit Pegawai" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuPegawai;

                if (menuPegawai == 1) {
                    int pilih, id, idAfter;
                    string nama, jabatan;
                    float gaji;

                    cout << "\n--- INSERT PEGAWAI ---" << endl;
                    cout << "1. Awal" << endl;
                    cout << "2. Akhir" << endl;
                    cout << "3. After ID" << endl;
                    cout << "Pilih: ";
                    cin >> pilih;

                    cout << "ID Pegawai   : ";
                    cin >> id;
                    cout << "Nama         : ";
                    cin >> nama;
                    cout << "Jabatan      : ";
                    cin >> jabatan;
                    cout << "Gaji (juta)  : ";
                    cin >> gaji;

                    addrPegawai p = allocatePegawai(id, nama, jabatan, gaji);

                    if (pilih == 1) {
                        insertFirstPegawai(LP, p);
                    }
                    else if (pilih == 2) {
                        insertLastPegawai(LP, p);
                    }
                    else if (pilih == 3) {
                        cout << "After ID Pegawai: ";
                        cin >> idAfter;
                        addrPegawai prec = findPegawai(LP, idAfter);
                        if (prec != nullptr)
                            insertAfterPegawai(LP, prec, p);
                        else
                            cout << "ID tidak ditemukan" << endl;
                    }
                }

                else if (menuPegawai == 2) {
                    int pilih, idAfter;
                    addrPegawai p;

                    cout << "\n--- DELETE PEGAWAI ---" << endl;
                    cout << "1. Awal" << endl;
                    cout << "2. Akhir" << endl;
                    cout << "3. After ID" << endl;
                    cout << "Pilih: ";
                    cin >> pilih;

                    if (pilih == 1) {
                        deleteFirstPegawai(LP, p);
                    }
                    else if (pilih == 2) {
                        deleteLastPegawai(LP, p);
                    }
                    else if (pilih == 3) {
                        cout << "After ID Pegawai: ";
                        cin >> idAfter;
                        addrPegawai prec = findPegawai(LP, idAfter);
                        if (prec != nullptr)
                            deleteAfterPegawai(LP, prec, p);
                        else
                            cout << "ID tidak ditemukan" << endl;
                    }
                }

                else if (menuPegawai == 3) {
                    int id;
                    cout << "\nID Pegawai: ";
                    cin >> id;
                    addrPegawai p = findPegawai(LP, id);

                    if (p != nullptr)
                        cout << "Pegawai ditemukan: " << p->namaPegawai << endl;
                    else
                        cout << "Pegawai tidak ditemukan" << endl;
                }

                else if (menuPegawai == 4) {
                    showPegawai(LP);
                }

                else if (menuPegawai == 5) {
                    cout << "Jumlah Pegawai: " << countPegawai(LP) << endl;
                }

                else if (menuPegawai == 6) {
                    int id;
                    string nama, jabatan;
                    float gaji;

                    cout << "\nID Pegawai: ";
                    cin >> id;
                    addrPegawai p = findPegawai(LP, id);

                    if (p != nullptr) {
                        cout << "Nama Baru        : ";
                        cin >> nama;
                        cout << "Jabatan Baru     : ";
                        cin >> jabatan;
                        cout << "Gaji Baru (juta) : ";
                        cin >> gaji;
                        editPegawai(p, nama, jabatan, gaji);
                    }
                    else {
                        cout << "Pegawai tidak ditemukan" << endl;
                    }
                }
            }
        }

        if (menuUtama == 3) {
            int menuRelasi = -1;

            while (menuRelasi != 0) {
                cout << "\n--- MENU RELASI ---" << endl;
                cout << "1. Insert Relasi" << endl;
                cout << "2. Delete Relasi" << endl;
                cout << "3. Find Relasi" << endl;
                cout << "4. Show Relasi" << endl;
                cout << "5. Count Relasi" << endl;
                cout << "6. Edit Relasi" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilih: ";
                cin >> menuRelasi;

                if (menuRelasi == 1) {
                    int idD, idP;
                    cout << "\n--- INSERT RELASI ---" << endl;
                    cout << "ID Divisi  : ";
                    cin >> idD;
                    cout << "ID Pegawai : ";
                    cin >> idP;

                    insertRelation(LR, LD, LP, idD, idP);
                    cout << "Relasi berhasil ditambahkan" << endl;
                }

                else if (menuRelasi == 2) {
                    int idD, idP;
                    cout << "\n--- DELETE RELASI ---" << endl;
                    cout << "ID Divisi  : ";
                    cin >> idD;
                    cout << "ID Pegawai : ";
                    cin >> idP;

                    deleteRelation(LR, LD, LP, idD, idP);
                    cout << "Relasi berhasil dihapus" << endl;
                }

                else if (menuRelasi == 3) {
                    int pilihFind;
                    cout << "\n--- FIND RELASI ---" << endl;
                    cout << "1. Cari Relasi (Divisi & Pegawai)" << endl;
                    cout << "2. Cari Divisi dari Pegawai" << endl;
                    cout << "3. Cari Pegawai dari Divisi" << endl;
                    cout << "Pilih: ";
                    cin >> pilihFind;

                    if (pilihFind == 1) {
                        int idD, idP;
                        cout << "ID Divisi  : ";
                        cin >> idD;
                        cout << "ID Pegawai : ";
                        cin >> idP;

                        if (findRelation(LR, idD, idP) != nullptr)
                            cout << "Relasi ditemukan" << endl;
                        else
                            cout << "Relasi tidak ditemukan" << endl;
                    }
                    else if (pilihFind == 2) {
                        int idP;
                        cout << "ID Pegawai : ";
                        cin >> idP;

                        addrDivisi d = findParentFromRelation(LR, idP);
                        if (d != nullptr)
                            cout << "Divisi: " << d->namaDivisi << endl;
                        else
                            cout << "Divisi tidak ditemukan" << endl;
                    }
                    else if (pilihFind == 3) {
                        int idD;
                        cout << "ID Divisi : ";
                        cin >> idD;

                        addrPegawai p = findChildFromRelation(LR, idD);
                        if (p != nullptr)
                            cout << "Pegawai: " << p->namaPegawai << endl;
                        else
                            cout << "Pegawai tidak ditemukan" << endl;
                    }
                }

                else if (menuRelasi == 4) {
                    int pilihShow;
                    cout << "\n--- SHOW RELASI ---" << endl;
                    cout << "1. Show Semua Relasi" << endl;
                    cout << "2. Show Pegawai per Divisi" << endl;
                    cout << "3. Show Divisi per Pegawai" << endl;
                    cout << "4. Show Divisi yang Punya Pegawai" << endl;
                    cout << "5. Show Divisi Tanpa Pegawai" << endl;
                    cout << "6. Show Pegawai Tanpa Divisi" << endl;
                    cout << "Pilih: ";
                    cin >> pilihShow;

                    if (pilihShow == 1)
                        showAllRelation(LR);
                    else if (pilihShow == 2) {
                        int idD;
                        cout << "ID Divisi : ";
                        cin >> idD;
                        showChildOfParent(LR, idD);
                    }
                    else if (pilihShow == 3) {
                        int idP;
                        cout << "ID Pegawai : ";
                        cin >> idP;
                        showParentOfChild(LR, idP);
                    }
                    else if (pilihShow == 4)
                        showAllParentWithChild(LR);
                    else if (pilihShow == 5)
                        showParentWithoutChild(LD, LR);
                    else if (pilihShow == 6)
                        showChildWithoutParent(LP, LR);
                }

                else if (menuRelasi == 5) {
                    int pilihCount;
                    cout << "\n--- COUNT RELASI ---" << endl;
                    cout << "1. Hitung Pegawai per Divisi" << endl;
                    cout << "2. Hitung Divisi per Pegawai" << endl;
                    cout << "3. Hitung Divisi tanpa Pegawai" << endl;
                    cout << "4. Hitung Pegawai tanpa Divisi" << endl;
                    cout << "Pilih: ";
                    cin >> pilihCount;

                    if (pilihCount == 1) {
                        int idD;
                        cout << "ID Divisi : ";
                        cin >> idD;
                        cout << "Jumlah Pegawai: "
                             << countChildOfParent(LR, idD) << endl;
                    }
                    else if (pilihCount == 2) {
                        int idP;
                        cout << "ID Pegawai : ";
                        cin >> idP;
                        cout << "Jumlah Divisi: "
                             << countParentOfChild(LR, idP) << endl;
                    }
                    else if (pilihCount == 3)
                        cout << "Divisi tanpa Pegawai: "
                             << countParentWithoutChild(LD, LR) << endl;
                    else if (pilihCount == 4)
                        cout << "Pegawai tanpa Divisi: "
                             << countChildWithoutParent(LP, LR) << endl;
                }

                else if (menuRelasi == 6) {
                    int oldD, oldP, newD, newP;
                    cout << "\n--- EDIT RELASI ---" << endl;
                    cout << "ID Divisi Lama  : ";
                    cin >> oldD;
                    cout << "ID Pegawai Lama : ";
                    cin >> oldP;
                    cout << "ID Divisi Baru  : ";
                    cin >> newD;
                    cout << "ID Pegawai Baru : ";
                    cin >> newP;

                    editRelation(LR, LD, LP, oldD, oldP, newD, newP);
                    cout << "Relasi berhasil diubah" << endl;
                }
            }
        }
    }
}
