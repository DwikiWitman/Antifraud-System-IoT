
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1.Entity
{
    class User
    {
        int id;
        string nama;

        public User(int id, string nama)
        {
            this.id = id;
            this.nama = nama;
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

    }
}
