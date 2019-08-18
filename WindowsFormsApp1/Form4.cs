using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Entity;
using WindowsFormsApp1.Control;

namespace WindowsFormsApp1
{
    public partial class Form4 : Form
    {
        double totaluang = 0;
        double tagihan = 0;

        public Form4()
        {
            InitializeComponent();
            Harga_Control lc = new Harga_Control();
            tagihan = (Double) lc.gethargaberdasarkanid(1);

            label5.Text = pisahtitik(tagihan.ToString());
            label5.Text = String.Format("{0:n0}", label5.Text);            //untuk menambah tanda titik
        }

        private void btncash_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        public String pisahtitik(string s)
        {
            string uang_tanpa_titik = "";
            // Split string on spaces.
            // ... This will separate all the words.
            string[] words = s.Split('.');
            
            foreach (string word in words)
            {
                uang_tanpa_titik = word;
            }
            return uang_tanpa_titik;
        }

        private void cek(double nom)
        {
            totaluang += nom;
            if (totaluang > tagihan)
            {
                MessageBox.Show("Kelebihan uang.");
                totaluang -= nom;
            }
            else if (totaluang == tagihan)
            {
                MessageBox.Show("Print");
                totaluang = 0;
            }

            label6.Text = pisahtitik(totaluang.ToString());
            label6.Text = String.Format("{0:n0}", label6.Text);            //untuk menambah tanda titik
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            double nominal = 2000;
            cek(nominal);
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            double nominal = 5000;
            cek(nominal);
        }

        private void btn10_Click(object sender, EventArgs e)
        {
            double nominal = 10000;
            cek(nominal);
        }

        private void btn20_Click(object sender, EventArgs e)
        {
            double nominal = 20000;
            cek(nominal);
        }

        private void btn50_Click(object sender, EventArgs e)
        {
            double nominal = 50000;
            cek(nominal);
        }
    }
}
