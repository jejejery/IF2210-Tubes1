# IF2210 - Tugas Besar 1 : Kompetisi Kartu ala Kerajaan Permen

Projek ini dibuat untuk memenuhi Tugas Besar Besar 1 IF2210 Pemrograman Berorientasi Objek. Permainan ini adalah program berbasis CLI menggunakan bahasa C++ dan menerapkan konsep OOP (Object Oriented Programming) dalam pembuatannya. Beberapa konsep penting yang diterapkan adalah Inheritance, Polymorphismm, Abstract Base Class, Method and Operator Overloading, Template and Generic Classes, serta Exception Handling dan juga Standard Template Library (STL) C++.


## Authors 

| Nama                        |  Nim      |
|-----------------------------|-----------|
| Yobel Dean Christopher      | 13521067  |
| Hobert Anthony Jonatan      | 13521079  |
| Jeremya Dharmawan Raharjo   | 13521131  |
| Ferindya Aulia Berlianty    | 13521161  |
| Akhmad Setiawan             | 13521164  |


## General Information & Features 
Dalam permainan kartu kerajaan permen, permainan dimainkan oleh tepat 7 orang, dan akan berjalan sampai salah satu pemain mendapatkan total poin sebesar 2^32 atau lebih. Suatu permainan terdiri dari 6 ronde, dimana pada setiap ronde pemain akan dapat melakukan command berupa Next untuk melanjutkan permainan (semacam pass), Double untuk mengalikan 2 poin hadiah, Half untuk mengalikan setengah poin hadiah, serta Ability yang dimiliki oleh masing-masing pemain (ada sebanyak 7 ability berbeda). Pada awal permainan, pemain akan dibagikan 2 buah kartu Permainan Kerajaan Permen dan seiring berjalannya ronde akan ada kartu yang dibuka pada Table Card yang dapat dipakai oleh setiap pemain untuk membentuk combo di akhir permainan. Pemain dengan combo tertinggi pada akhir permainan (setelah ronde ke-6) akan mendapatkan poin hadiah yang telah ditetapkan. 

## Program Requirements
1. Compiler  g++ versi 11, 14 atau 17.
2. IDE (VScode/Sublimetext)

## How To Build 
1. Clone repositori ini dengan ```https://github.com/jejejery/IF2210-Tubes1.git```
2. Pindah ke direktori yang telah di clone menggunakan command ```cd``` pada terminal
3. Setelah sampai pada direktori ini, program dapat langsung dijalankan menggunakan file yang telah di compile ```./main```
4. Dapat juga melakukan compile ulang dengan cara menginclude header dan library-library yang bersangkutan pada folder modules