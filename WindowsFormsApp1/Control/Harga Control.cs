using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp1.DataSet1TableAdapters;

namespace WindowsFormsApp1.Control
{
    class Harga_Control
    {
        HARGATableAdapter h = new HARGATableAdapter();

        public int gethargaberdasarkanid(int id)
        {
            return h.GetHarga(id).Value;
        }
    }
}
