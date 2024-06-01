#ifndef TREEGAANTRE_H
#define TREEGAANTRE_H

void sortAntrian(address *root);
/*
Digunakan untuk mengurutkan data pendaftar di dalam file berdasarkan prioritas dan jam daftar.
File akan diambil ke array sesuai panjang dari modul urutanTerakhir. Lalu dilakukan operasi,
setelah selesai akan di tulis kembali kedalam file tersebut.
IS : file belum terurut berdasarkan jam daftar dan prioritas
FS : file sudah terurut berdasarkan jam daftar dan prioritas

// referensi bubble sort
*/

void buildBST(address *root);
/* 
Digunakan untuk membangun Tree berdasarkan file Data_Pasien yang sudah terurut di modul sortAntrian
IS : tree untuk antrian belum ada
FS : tree untuk antrian sudah ada
*/

address createNode (Pasien info);
/*
Digunakan untuk membuat sebuah node baru dalam BST.
IS: Tidak ada spesifikasi khusus.
FS: Sebuah node baru dengan informasi pasien tertentu sudah dibuat.
*/

bool cekKosong (address *root);
/*
Digunakan untuk pengecekan tree kosong.
*/

address push (address root, Pasien info);
/*
digunakan untuk insertion sebuah node pasien ke dalam BST.
IS: BST belum memiliki node yang akan ditambahkan.
FS: Sebuah node baru dengan informasi pasien sudah ditambahkan ke dalam BST.
*/

address pop (address root, Pasien *info);
/*
digunakan untuk menghapus sebuah node pasien dari BST.
IS: BST memiliki node dengan informasi pasien yang akan dihapus.
FS: Node dengan informasi pasien sudah dihapus dari BST.
*/

void displayPreorder(address root); 
/*
digunakan untuk menampilkan data dalam BST secara Preorder traversal.
IS: BST memiliki node-node yang berisi data yang akan ditampilkan.
FS: Data dalam BST ditampilkan secara Preorder traversal.
*/

void displayTree(address root);
/*
digunakan untuk menampilkan struktur BST secara berhierarki.
IS: BST sudah dibangun berisi data yang akan ditampilkan..
FS: Struktur BST ditampilkan secara berhierarki.
*/

#endif
