#include<iostream>
using namespace std;

//===========fungsi
void layar();
void input();
void exit();
string check(string x);

//membuat varibel bertipe data int (Integer )
int sisabangku = 84;
int tiket = 0;

//membuat output list tempat duduk yang masih tersedia dan tidak menggunakan array cout << "|==================================================================================================================|" << endl;
string bangku[11][11]{
    {"\b", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
    {"0", "*", "*", "*", "#", "#", "#", "#", "*", "*", "*"},
    {"1", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"2", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"3", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"4", "#", "#", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"5", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"6", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"7", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"8", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"9", "*", "#", "#", "#", "#", "#", "#", "#", "#", "*"},
};

// Memberikan logic pada function layar()
void layar()
{
    cout << "\n\n";
    for (int i = 0; i < 11; i++)
    {
    	
    //jika i sudah masuk ke bilangan 0 / 1 ( dalanm array ) program akan menampilkan " (======================== Layar Disini ========================) "
        if (i == 1)
        {
            cout << endl;
            cout << "\t    (======================== Layar Disini ========================) " << endl;
            cout << endl;
        }
        
		//jika i sudah masuk ke bilangan 10 / 9 ( dalanm array ) program akan menampilkan " Sweetbox "
        if (i == 10)
        {
            cout << endl;
            cout << "\t\t\t\t\tSweetbox\n";
            cout << endl;
        }
        for (int j = 0; j < 11; j++)
        {
            cout << bangku[i][j] << "\t";
        }
        cout << endl;
    }
}

// Memberikan logic pada function input()
void input()
{
//	int harga;
//	long int biasa,vip,sweetbox;
//	biasa = 50000;
//	vip = 110000;
//	sweetbox = 100000;
	 
	
    //membuat variabel bertipe data string 
    string bangku_check = "";
    string temp_bangku = "";
    string kode_film = "";
    string tipe = "";
    string mc = "Miracle in cell no. 17";
    string ps = "Pengabdi setan 2";
    string jl = "Jailangkung";
    string dp = "KKN Di desa penari";
    string rs = "Mencuri Raden Saleh";
    string op = "One Piece";
    string in = "Inang";
    string ns = "Ngeri-ngeri sedap";
    string b = "Biasa";
    string v = "VIP";
    string s = "Sweetbox";
    cout << endl;
    cout << " (b = biasa)  (v = VIP) (s = Sweetbox)" << endl;
    cout << " Pilih tipe bangku : ";
    cin >> tipe;
    
    //Memberikan logic pada input tipe bangku yaitu jika menginput v maka program akan menampilkan VIP, jika menginput b maka program akan menampilkan Biasa, jika menginput s maka program akan menampilkan SweetBox
    if (tipe == "v" || tipe == "V")
    {
        tipe = v;
    }else if (tipe == "b" || tipe == "B"){
        tipe = b;
    }else if (tipe == "s" || tipe == "S"){
        tipe = s;
    }else{
        tipe = b;
    }
    cout << endl;
    cout << " Masukkan Kode Film : ";
    cin >> kode_film;
    
    //memberikan logic pada input kode film yaitu jika meningput kode film maka program akan menampilkan judul filmnya
    if (kode_film == "mc")
    {
        kode_film = mc;
    }else if (kode_film == "ps")
	{
        kode_film = ps;
    }
    else if (kode_film == "jl")
    {
        kode_film = jl;
    }
    else if (kode_film == "dp")
    {
        kode_film = dp;
    }
    else if (kode_film == "rs")
    {
        kode_film = rs;
    }
    else if (kode_film == "op")
    {
        kode_film = op;
    }
    else if (kode_film == "in")
    {
        kode_film = in;
    }
    else if (kode_film == "ns")
    {
        kode_film = ns;
    }
    else
    {
    }
    cout << endl;
    string tkt_pos[tiket];
    for (int i = 0; i < tiket; i++)
    {
        do
        {
        	
            //membuat form input nomer tempat duduk yang akan dipilih
            cout << "\nMasukkan nomor tempat duduk  (" << (i +  1) <<  "): ";
            cin >> temp_bangku;
            bangku_check = check(temp_bangku);
            
            //melakukan pengecekan ketersedian bangku, jika tersedia maka bisa diproses 
            if (bangku_check != "OK")
                cout << endl
                     << bangku_check;

        } while (bangku_check != "OK");
        // pesan
        
        tkt_pos[i] = temp_bangku;
        sisabangku--;
        
        //memberikan informasi jika bangku yang dipesan telah diproses dan berhasil dipesan
        bangku[(int)(temp_bangku[1]) - 48 + 1][(int)(toupper(temp_bangku[0])) - 64] = "#";
        cout << "Berhasil";
        cout << endl;
    }
    cout << "\n\n";
    
    //memberikan informasi pemesanan berupa jumlah tiket dan judul film yang dipesan
    cout << "|============================================================ SELAMAT! ==============================================================|" << endl;
    cout << "\n\n Kamu berhasil memesan " << tiket << " tiket film " << kode_film << endl;
    cout << endl;
    cout << endl;
    
    //memberikan informasi pemesanan berupa tipe bangku yang dipesan
    cout << "Tipe bangku : " << tipe << endl;
    
    //memberikan informasi pemesanan berupa Nomer tempat duduk yang dipesan
    cout << "Nomer tempat duduk yang dipesan: " << endl;
    for (size_t i = 0; i < tiket; i++){ 
        cout << tkt_pos[i] << "  "<< endl;
    }
}
string check(string x)
{
	
    //Logic untuk memberikan panjang input 2 karakter
    if (x.length() == 2){
    	
        // Logic untuk melakukan pengecekan format yang dimasukan benar atau salah
        int sementara = toupper(x[0]);
        int simpan = x[1];
        if ((sementara >= 65 && sementara <= 90) && (simpan >= 48 && simpan <= 57)){
            if (toupper(x[0]) >= 'A' && toupper(x[0]) <= 'J'){
                //Logic untuk melakukan pengecekan inputan masih dalam tempat duduk yang tersedia
                if (bangku[(int)(x[1]) - 48 + 1][(int)(toupper(x[0])) - 64] == "*"){
                    return "OK";
                }else{
                    return "!!!!! Tempat duduk sudah dibooking! silahkan pilih yang lain !!!!!";
                }
            }else{
                return "!!!!! Pastikan memilih tempat duduk dibarisan A sampai J !!!!!";
            }
        }else{
            return "!!!!! Masukan format yang benar !!!!!";
        }
   }else{
        return "!!!!! Kamu harus memasukkan 2 karakter, contoh : B2 !!!!!";
    }
}
//menambahkan pesan "Terima Kasih" Jika function exit dieksekusi dan menyelesaikan program
void exit()
{
    cout << "\n\n Terima kasih!.";
    cout << endl
         << endl;
    exit(1);
}



int main (){
	int menu;
	while (true) {
	cout << endl;
	cout << " " << endl;
	cout << "|============================================================ MAIN MENU =============================================================|" << endl;
	cout << " " << endl;
	cout << endl;
	cout << "\t 1. Pesan Tiket "  << endl;
	cout << endl;
	cout << "\t 2. List Film yang sedang tayang hari ini  " << endl;
	cout << endl;
	cout << "\t 3. List Harga tiket " <<  endl;
	cout << endl;
	cout << "\t 4. List Jam tayang "<< endl;
	cout << endl;
	cout << "\t 5. Keluar "<< endl;
	cout << endl;
	cout << " " << endl;
	cout << "|====================================================================================================================================|" << endl;
	cout << " " << endl;
	cout << " Masukkan menu yang ingin kamu pilih : ";
	cin >> menu; 
	
	//=====Membuat percabangan menggunakan switch case sebagai fitur pemilihan menu
	switch(menu){
    //Jika case 1 / pilihan 1 dipilih program cinekom akan mengeksekusi menu Pemesanan tiket
    case 1: 
    //membuat variable rep bertipe data char
    char rep;
	cout <<endl;
	cout << "\n\n Tekan Y untuk Lanjutkan atau N untuk kembali = ";
    //Melakukan penginputan data dan memasukanya ke variabel rep
    cin >> rep;
    //Memberikan logic jika pemesan menginput N / n maka program akan memanggil function exit yang artinya program akan selesai
    if (rep == 'N' || rep == 'n')
    {
        exit();
    }
	cout << endl;
    //Memberikan logic jika pemesan menginput Y / y maka program akan memberi tahu pemesan sisa tempat duduk yang tersedia dan melakukan penginputan data selanjutnya
    do
    {
        cout << "Total " << sisabangku << " Tempat duduk yang tersisa.\n";
        cout << endl;
        cout << "Berapa tiket yang ingin kamu pesan ? ";
        
    //Melakukan penginputan data dan memasukanya ke variabel tiket
        cin >> tiket;
    //Memberikan logic jika tiket yang dipesan lebih dari 10 maka program cinekom akan menampilkan pesan "Maximal pembelian 10 Tiket" dan pemesan diminta untuk menginput ulang data yang sesuai 
        if (tiket > 10){
            cout << "Maximal pembelian 10 Tiket\n\n";
        }
		}while (tiket > 10 || tiket > sisabangku);
    cout << "";
    
    //program memanggil function layar untuk menampilkan data tempat duduk yang tersedia dan sudah terbooking 
    layar();
    //program memanggil function input untuk menampilkan form input data pemesanan tiket yang akan ditampilkan diresult akhir
    input();
    void input();
   
    break;

    case 2: 
    
    //Jika case 2 / pilihan 2 dipilih program akan mengeksekusi menu List Film yang sedang tayang hari ini
	cout << endl;
	cout << endl;
	cout << "|======================================================== DAFTAR FILM ===============================================================|" << endl;
	//Menampilkan data film berupa judul film dan kode film dalam bentuk tabel
	cout << "\t No \t\tJudul Film  \t\t\t\t\t\t Kode Film " << endl;
	cout << endl;
	cout << endl;
	cout << "\t 1 \t\tMiracle in cell no. 17 \t\t\t\t\t    mc " << endl;
	cout << endl;
	cout << "\t 2 \t\tPengabdi setan 2 \t\t\t\t\t    ps " << endl ;
	cout << endl;
	cout << "\t 3 \t\tJailangkung \t\t\t\t\t\t    jl " << endl ; 
	cout << endl;
	cout << "\t 4 \t\tKKN di desa penari \t\t\t\t\t    dp " << endl ; 
	cout << endl;
	cout << "\t 5 \t\tMencuri Raden Saleh \t\t\t\t\t    rs " << endl ; 
	cout << endl;
	cout << "\t 6 \t\tOne Piece \t\t\t\t\t\t    op " << endl ; 
	cout << endl;
	cout << "\t 7 \t\tInang \t\t\t\t\t\t\t    in " << endl ; 
	cout << endl;
	cout << "\t 8 \t\tNgeri-ngeri sedap \t\t\t\t\t    ns " << endl ; 
	cout << endl; 
	cout << endl;
	cout << "|====================================================================================================================================|" << endl;
    break;

    case 3: 
	//Jika case 3 / pilihan 3 dipilih program akan mengeksekusi menu List Harga Tiket
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	//Menampilkan data Harga Tiket berupa Hari, tipe tempat duduk, dan harga dalam bentuk tabel
	cout << "|========================================================== HARGA TIKET =============================================================|" << endl;
	cout << endl;
	cout << endl;
	cout <<endl;
	cout << "Biasa (B)  \t\t  50k  " <<endl;
	cout <<endl;
	cout << "VIP (V) \t\t  110k  " <<endl;
	cout <<endl;
	cout << "Sweetbox (S)\t\t  100k  " <<endl;
	cout << endl;
	cout << endl;
	cout << "|====================================================================================================================================|" << endl;
	cout << endl;
    break;
    
    case 4: 
    //Jika case 4 / pilihan 4 dipilih program cinekom akan mengeksekusi menu List Jam Tayang
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    //Menampilkan data List Jam Tayang Film berupa Judul Film dan Jam Tayang Film dalam bentuk tabel
	cout << "|====================================================================================================================================|" << endl;
	cout << "\t No \t\tJudul Film  \t\t\t\t    Jam Tayang Film " << endl;
	cout << endl;
	cout << endl;
	cout << "\t 1 \t\tMiracle in cel no. 17 \t\t\t     09.50, 11.30, 13.50, 15.00, 19.00 " << endl; 
	cout << endl;
	cout << "\t 2 \t\tPengabdi setan 2 \t\t\t     10.00, 11.50, 14.20, 16.20, 19.20  " << endl ; 
	cout << endl;
	cout << "\t 3 \t\tJailangkung \t\t\t\t     09.50, 11.40, 14.00, 15.30, 19.20  " << endl ; 
	cout << endl;
	cout << "\t 4 \t\tKKN Di desa penari \t\t\t     09.50, 11.10, 13.50, 15.20, 19.40  " << endl ; 
	cout << endl;
	cout << "\t 5 \t\tMencuri Raden Saleh \t\t\t     10.50, 12.30, 14.50, 16.00, 20.00  " << endl ; 
	cout << endl;
	cout << "\t 6 \t\tOne Piece \t\t\t\t     09.00, 11.10, 13.20, 15.30, 19.40  " << endl ; 
	cout << endl;
	cout << "\t 7 \t\tInang \t\t\t\t\t     10.30, 12.20, 14.30, 16.20, 20.10  " << endl ; 
	cout << endl;
	cout << "\t 8 \t\tNgeri-ngeri sedap \t\t\t     10.00, 12.50, 14.50, 16.50, 20.50  " << endl ; 
	cout << endl;
	cout << endl;
    break;
    
    case 5:  
   //Jika case 5 / pilihan 5 dipilih program akan memanggil function exit yang artinya program akan keluar / selesai
   exit();
   break;
   //Memberikan logic pada switch jika menu yang dipilih tidak ada maka program akan menampilkan pesan " Menu tidak ditemukan "
   default: cout << "Menu tidak ditemukan";
   break;
}
}

return 0;
}


