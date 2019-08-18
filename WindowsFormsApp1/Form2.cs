using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Control;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        LoginControl lc = new LoginControl();

        public Form2()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                if(lc.cekLogin(int.Parse(textBox1.Text)) == true)
                {
                    Form3 f3 = new Form3();
                    f3.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Invalid Password");
                }
                
                textBox1.Text = "";
                textBox1.Focus();
            }
            
        }
    }
}
