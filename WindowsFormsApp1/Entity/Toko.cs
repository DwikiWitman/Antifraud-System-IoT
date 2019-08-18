using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1.Entity
{
    class Toko
    {
        int id,harga;
        string nama;

        public Toko(int id, string nama, int harga)
        {
            this.id = id;
            this.nama = nama;
            this.harga = harga;
        }

        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Nama
        {
            get { return nama; }
            set { nama = value; }
        }
        public int Harga
        {
            get { return harga; }
            set { harga = value; }
        }
        
    }
}
