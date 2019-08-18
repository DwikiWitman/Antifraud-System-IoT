using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp1.DataSet1TableAdapters;

namespace WindowsFormsApp1.Control
{
    class LoginControl
    {
        UserTableAdapter UTA = new UserTableAdapter();
        public bool cekLogin(int id)
        {
            bool cek = false;
            try
            {
                if (UTA.CekId(id).ToString() != "")
                    cek = true;
            }
            catch
            {
                cek = false;
            }
            return cek;
        }
    }
}
