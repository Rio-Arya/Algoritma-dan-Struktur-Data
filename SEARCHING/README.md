# SEARCHING(Sequential Searching & Binary Searching)
[SEARCHING](https://github.com/MeiLing19/ALGORITMA-DAN-STRUKTUR-DATA-ASSIGNMENT/tree/main/SEARCHING)
- Searching adalah pencarian data dengan cara menelusuri data-data tersebut. Tempat pencarian data dapat berupa array dalam memori maupun pada file external
- Ada dua macam teknik searching yaitu :
 1. [Sequential Searching](https://github.com/Rio-Arya/Algoritma-dan-Struktur-Data/tree/main/SEARCHING/Binary%20Searching)\
      -> Sequential Searching maerupakan sebuah teknik pencarian data dengan cara mencari dan membandingkan data secara satu persatu sampai datanya ditemukan.
      Sequential Searching ini memiliki kekurangan apabila data yang diinput terlalu banyak.
 2. [Binary Searching](https://github.com/Rio-Arya/Algoritma-dan-Struktur-Data/tree/main/SEARCHING/Sequential%20Searching)\
      ->Binary Searching merupakan sebuah teknik pencarian data dengan cara membagi 1/2 data yang ada secara berulang kali dengan tujuan memperkecil lokasi pencarian sampai menjadi satu data.
Binary Searching ini sangat berguna apabila data yang diinputkan berjumlah banyak. Prinsipnya kurang lebih:
      1. Mula-mula diambil posisi awal 0 dan posisi akhir = N-1, kemudian dicari posisi data tengah dengan rumus (posisi awal + posisi akhir)/2. Kemudian data yang dicari dibandingkan dengan data tengah.
      2. Jika lebih kecil, proses dilakukan kembali tetapi posisi akhir dianggap sama dengan posisi tengah –1.
      3. Jika lebih besar, proses dilakukan kembali tetapi posisi awal dianggap sama dengan posisi tengah +1. Jika data sama, berarti data ditemu.
