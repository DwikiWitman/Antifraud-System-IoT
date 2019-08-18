using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp1.DataSet1TableAdapters;

namespace WindowsFormsApp1.Control
{
    class UserControl
    {
        tbl_pegawaiTableAdapter h = new tbl_pegawaiTableAdapter();
        public string getnamapeg(string id)
        {
            return h.GetnamaPeg(id).ToString();
        }

    }
}
