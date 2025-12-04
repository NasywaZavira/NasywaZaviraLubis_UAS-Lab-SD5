//Laundry Kilat

#include <iostream>
#include <string>

using namespace std;

struct Cust {
    string nama;
    int berat;
    string jenis;
    Cust* next;
};

Cust* head = NULL;
Cust* tail = NULL;

void tambahRegular(string nama, int berat) {
    Cust* baru = new Cust;
    baru->nama = nama;
    baru->berat = berat;
    baru->jenis = "regular";
    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void tambahExpress(string nama, int berat) {
    Cust* baru = new Cust;
    baru->nama = nama;
    baru->berat = berat;
    baru->jenis = "express";
    baru->next = head;

    head = baru;
    if (tail == NULL) {
        tail = baru;
    }
}

int hitungDFS(Cust* node) {
    if (node == NULL) return 0;

    int durasi;
    if (node->jenis == "regular")
        durasi = node->berat * 10;
    else
        durasi = node->berat * 5;

    return durasi + hitungDFS(node->next);
}

void printUrutan(Cust* node) {
    if (node == NULL) return;
    cout << node->nama << " ";
    printUrutan(node->next);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama, jenis;
        int berat;
        cin >> nama >> berat >> jenis;

        if (jenis == "express") {
            tambahExpress(nama, berat);
        } else {
            tambahRegular(nama, berat);
        }
    }

    cout << "Urutan: ";
    printUrutan(head);
    cout << endl;

    int total = hitungDFS(head);
    cout << "Total waktu: " << total << " menit" << endl;

    return 0;
}

