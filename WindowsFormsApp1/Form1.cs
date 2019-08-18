using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        int x = 0;
        int y = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            y++;
            label3.Text = y.ToString();
        }

        private void btnadmin_Click(object sender, EventArgs e)
        {
            if(label2.Text == "2" && label3.Text == "1")
            {
                Form2 f2 = new Form2();
                f2.Show();
                //this.Hide();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Application.Exit();
            x++;
            label2.Text = x.ToString();

        }
        public void reset()
        {
            x = 0;
            y = 0;
            label2.Text = "0";
            label3.Text = "0";
        }

        private void btncard_Click(object sender, EventArgs e)
        {
            reset();
        }

        private void btncash_Click(object sender, EventArgs e)
        {
            reset();
            Form4 f4 = new Form4();
            f4.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
