using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp1.DataSet1TableAdapters;

namespace WindowsFormsApp1.Control
{
    class test_ixoboxControl
    {
        test_ixoboxTableAdapter t = new test_ixoboxTableAdapter();
        UserTableAdapter u = new UserTableAdapter();
        SisaWaktuTableAdapter s = new SisaWaktuTableAdapter();

        public DataTable getAllIxobox(string id_scan)
        {
            DataTable dt = new DataTable();
            dt = t.GetAll(id_scan);
            return dt;
        }

        public void updateAllIxobox(int flag, string status, int id_stylist, int kursi, string id_scan)
        {
            t.UpdateAll1(flag, status, id_stylist, kursi, id_scan);           
        }

        public void updateSisaWaktuKursi(int sisa_waktu, int kursi)
        {
            s.UpdateWaktuKursi(sisa_waktu, kursi);
        }

        public bool validQRCode(string id_scan)
        {
            return t.CheckQRCode(id_scan).Value > 0 ?  true : false;
        }

        public bool validIdStylist(string id_scan)
        {
            return u.CekIdStylist(int.Parse(id_scan)).Value > 0 ? true : false;
        }

        public DataTable GetAllIDScan()
        {
            DataTable dt = new DataTable();
            dt = t.GetAllIdScan();
            return dt;
        }

        public DataTable GetAllIDStylist()
        {
            DataTable dt = new DataTable();
            dt = u.GetAllIdStylist();
            return dt;
        }

        public void updateIDStylist(int stylist, string id)
        {
           // t.UpdateIDStylist(stylist,id);
        }
    }
}
