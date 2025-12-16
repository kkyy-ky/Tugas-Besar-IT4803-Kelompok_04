#include "main.h"
#include <iostream>

using namespace std;

void initDummyData(listDivisi &LD, listPegawai &LP, listRelation &LR) {
    createListDivisi(LD);
    insertLastDivisi(LD, allocateDivisi(1, "IT", 10));
    insertLastDivisi(LD, allocateDivisi(2, "HRD", 5));
    insertLastDivisi(LD, allocateDivisi(3, "Finance", 7));

    createListPegawai(LP);
    insertLastPegawai(LP, allocatePegawai(101, "Andi", "Programmer", 8000000));
    insertLastPegawai(LP, allocatePegawai(102, "Budi", "HR Staff", 6000000));
    insertLastPegawai(LP, allocatePegawai(103, "Citra", "Accountant", 7000000));

    createListRelation(LR);
    insertRelation(LR, LD, LP, 1, 101);
    insertRelation(LR, LD, LP, 2, 102);
    insertRelation(LR, LD, LP, 3, 103);
}

void menuUtama() {
    cout << "\n===== MENU UTAMA =====\n";
    cout << "1. Divisi\n";
    cout << "2. Pegawai\n";
    cout << "3. Relasi\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void menuDivisi() {
    cout << "\n===== MENU DIVISI =====\n";
    cout << "1. Insert Divisi\n";
    cout << "2. Delete Divisi\n";
    cout << "3. Find Divisi\n";
    cout << "4. Show Divisi\n";
    cout << "5. Count Divisi\n";
    cout << "6. Edit Divisi\n";
    cout << "0. Kembali\n";
    cout << "Pilih menu: ";
}

void menuPegawai() {
    cout << "\n===== MENU PEGAWAI =====\n";
    cout << "1. Insert Pegawai\n";
    cout << "2. Delete Pegawai\n";
    cout << "3. Find Pegawai\n";
    cout << "4. Show Pegawai\n";
    cout << "5. Count Pegawai\n";
    cout << "6. Edit Pegawai\n";
    cout << "0. Kembali\n";
    cout << "Pilih menu: ";
}

void menuRelasi() {
    cout << "\n===== MENU RELASI =====\n";
    cout << "1. Insert Relasi\n";
    cout << "2. Delete Relasi\n";
    cout << "3. Find Relasi\n";
    cout << "4. Show Relasi\n";
    cout << "5. Count Relasi\n";
    cout << "6. Edit Relasi\n";
    cout << "0. Kembali\n";
    cout << "Pilih menu: ";
}

void prosesMenuDivisi(listDivisi &LD) {
    int pilih;
    menuDivisi();
    cin >> pilih;

    switch (pilih) {
    case 1: {
        int id, kapasitas;
        string nama;
        cout << "ID Divisi: ";
        cin >> id;
        cout << "Nama Divisi: ";
        cin >> nama;
        cout << "Kapasitas: ";
        cin >> kapasitas;
        insertLastDivisi(LD, allocateDivisi(id, nama, kapasitas));
        break;
    }
    case 2: {
        addrDivisi D;
        deleteLastDivisi(LD, D);
        break;
    }
    case 3: {
        int id;
        cout << "ID Divisi: ";
        cin >> id;
        addrDivisi D = findDivisi(LD, id);
        if (D != nullptr) cout << "Divisi ditemukan: " << D->namaDivisi << endl;
        else cout << "Divisi tidak ditemukan\n";
        break;
    }
    case 4:
        showDivisi(LD);
        break;
    case 5:
        cout << "Jumlah Divisi: " << countDivisi(LD) << endl;
        break;
    case 6: {
        int id, kapasitas;
        string nama;
        cout << "ID Divisi: ";
        cin >> id;
        addrDivisi D = findDivisi(LD, id);
        if (D != nullptr) {
            cout << "Nama Baru: ";
            cin >> nama;
            cout << "Kapasitas Baru: ";
            cin >> kapasitas;
            editDivisi(D, nama, kapasitas);
        }
        break;
    }
    }
    while (pilih != 0);
}

void prosesMenuPegawai(listPegawai &LP) {
    int pilih;
    menuPegawai();
    cin >> pilih;

    switch (pilih) {
    case 1: {
        int id;
        string nama, jabatan;
        float gaji;
        cout << "ID Pegawai: ";
        cin >> id;
        cout << "Nama: ";
        cin >> nama;
        cout << "Jabatan: ";
        cin >> jabatan;
        cout << "Gaji: ";
        cin >> gaji;
        insertLastPegawai(LP, allocatePegawai(id, nama, jabatan, gaji));
        break;
    }
    case 2: {
        addrPegawai P;
        deleteLastPegawai(LP, P);
        break;
    }
    case 3: {
        int id;
        cout << "ID Pegawai: ";
        cin >> id;
        addrPegawai P = findPegawai(LP, id);
        if (P != nullptr) cout << "Pegawai ditemukan: " << P->namaPegawai << endl;
        else cout << "Pegawai tidak ditemukan\n";
        break;
    }
    case 4:
        showPegawai(LP);
        break;
    case 5:
        cout << "Jumlah Pegawai: " << countPegawai(LP) << endl;
        break;
    case 6: {
        int id;
        string nama, jabatan;
        float gaji;
        cout << "ID Pegawai: ";
        cin >> id;
        addrPegawai P = findPegawai(LP, id);
        if (P != nullptr) {
            cout << "Nama Baru: ";
            cin >> nama;
            cout << "Jabatan Baru: ";
            cin >> jabatan;
            cout << "Gaji Baru: ";
            cin >> gaji;
            editPegawai(P, nama, jabatan, gaji);
        }
        break;
    }
    }
    while (pilih != 0);
}

void prosesMenuRelasi(listDivisi &LD, listPegawai &LP, listRelation &LR) {
    int pilih;
    menuRelasi();
    cin >> pilih;

    switch (pilih) {
    case 1: {
        int idDiv, idPeg;
        cout << "ID Divisi: ";
        cin >> idDiv;
        cout << "ID Pegawai: ";
        cin >> idPeg;
        insertRelation(LR, LD, LP, idDiv, idPeg);
        break;
    }
    case 2: {
        int idDiv, idPeg;
        cout << "ID Divisi: ";
        cin >> idDiv;
        cout << "ID Pegawai: ";
        cin >> idPeg;
        deleteRelation(LR, LD, LP, idDiv, idPeg);
        break;
    }
    case 3: {
        int idDiv, idPeg;
        cout << "ID Divisi: ";
        cin >> idDiv;
        cout << "ID Pegawai: ";
        cin >> idPeg;
        addrRelation R = findRelation(LR, idDiv, idPeg);
        if (R != nullptr) cout << "Relasi ditemukan\n";
        else cout << "Relasi tidak ditemukan\n";
        break;
    }
    case 4:
        showAllRelation(LR);
        break;
    case 5:
        cout << "Jumlah Relasi: " << countChildOfParent(LR, 1)
            + countChildOfParent(LR, 2)
            + countChildOfParent(LR, 3) << endl;
        break;
    case 6: {
        int oD, oP, nD, nP;
        cout << "Old ID Divisi: ";
        cin >> oD;
        cout << "Old ID Pegawai: ";
        cin >> oP;
        cout << "New ID Divisi: ";
        cin >> nD;
        cout << "New ID Pegawai: ";
        cin >> nP;
        editRelation(LR, LD, LP, oD, oP, nD, nP);
        break;
    }
    }
    while (pilih != 0);
}

int main() {
    listDivisi LD;
    listPegawai LP;
    listRelation LR;
    initDummyData(LD, LP, LR);

    int pilih;
    menuUtama();
    cin >> pilih;

    switch (pilih) {
    case 1:
        prosesMenuDivisi(LD);
        break;
    case 2:
        prosesMenuPegawai(LP);
        break;
    case 3:
        prosesMenuRelasi(LD, LP, LR);
        break;
        }
    while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}

