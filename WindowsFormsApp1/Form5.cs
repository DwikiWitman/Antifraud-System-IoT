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
using System.IO.Ports;
using System.Threading;

namespace WindowsFormsApp1
{
    public partial class Form5 : MetroFramework.Forms.MetroForm
    {
        test_ixoboxControl t = new test_ixoboxControl();
        UpdateControl u = new UpdateControl();
        string str;
        string temp_cekkursi;
        int[] sisaWaktuKursi = new int[] { -1, -1, -1, -1, -1};
        string qrkode;
        Dictionary<string, string> caseArduino = new Dictionary<string, string>()
        {
            { "DisplayTicketNotValid", "A" },
            { "DisplayInputStylist", "B" },
            { "DisplayStylistNotValid", "C" },
            { "ProsesQRCode", "D" },
            { "AktifkanKursi", "E" },
            { "CekStatusKursi", "F" },
            { "MatikanKursi", "G" }
        };


        public Form5()
        {
            InitializeComponent();
        }
        private void Form5_Load(object sender, EventArgs e)
        {
            CenterToScreen();
            autoDetectPortArduino();
            fillComboboxByIdStylist();
        }
        private void autoDetectPortArduino()
        {
            foreach (string s in SerialPort.GetPortNames())
            {
                try
                {
                    serialPort1.PortName = s;
                    serialPort1.Open();
                    if (serialPort1.IsOpen)
                    {
                        break;
                    }
                }
                catch { }
            }
        }
        private void fillComboboxByQRCode()
        {
            DataTable dt = t.GetAllIDScan();
            foreach (DataRow dr in dt.Rows)
            {
                comboBox1.Items.Add(dr[1]);
            }
        }

        private void fillComboboxByIdStylist()
        {
            DataTable dt = t.GetAllIDStylist();
            foreach (DataRow dr in dt.Rows)
            {
                comboBox1.Items.Add(dr[1]);
            }
        }

        delegate void SetTextCallback(string text);
        private void SetText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.richTextBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.richTextBox1.Text = text;
            }
        }
        private void SetStatusKursi(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox8.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetStatusKursi);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox8.Text = text;
            }
        }
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string temp = serialPort1.ReadExisting().ToString();

            try
            {
                if (temp[0].Equals('K'))
                {
                    temp_cekkursi = temp;
                    SetStatusKursi(temp.ToString());
                }
                else
                {
                    str += temp;
                    SetText(str.ToString());
                }
            }
            catch { }
        }
        private void Form5_FormClosed(object sender, FormClosedEventArgs e)
        {
            serialPort1.Close();
        }
        private void enableControls()
        {
            richTextBox1.Enabled = true;
            metroButton1.Enabled = true;
            
        }
        private void disableControls()
        {
            richTextBox1.Enabled = true;
            metroButton1.Enabled = true;
        }
        private void timer1_Tick_1(object sender, EventArgs e)
        {
            Case_B_C();
            Case_D();
        }
        void ClearSerialConsole()
        {
            str = "";
            richTextBox1.Text = "";
            textBox8.Text = "";
        }
        void Case_B_C()
        {
            try
            {
                string data = richTextBox1.Text;
                data = data.Substring(richTextBox1.Text.LastIndexOf('T'));

                if (!string.IsNullOrEmpty(data))
                {
                    int idx_stylist = data.IndexOf('T');
                    int idx_end = data.IndexOf('.');
                    string stylist = data.Substring(idx_stylist + 1, idx_end - idx_stylist - 1);

                    if (!string.IsNullOrEmpty(stylist))
                    {
                        if (t.validIdStylist(stylist))
                        {
                            serialPort1.Write(caseArduino["ProsesQRCode"]);
                        }
                        else
                        {
                            serialPort1.Write(caseArduino["DisplayStylistNotValid"]);
                        }
                        ClearSerialConsole();
                    }
                }
            }
            catch { }
        }

        void Case_D()
        {
            try
            {
                string data = richTextBox1.Text;
                data = data.Substring(richTextBox1.Text.LastIndexOf('P'));

                if (!string.IsNullOrEmpty(data))
                {
                    int idx_kursi = data.IndexOf('P');
                    int idx_qrcode = data.IndexOf('Q');
                    int idx_stylist = data.IndexOf('I');
                    int idx_end = data.IndexOf('.');

                    string kursi = data.Substring(idx_kursi + 1, idx_qrcode - idx_kursi - 1);
                    string stylist = data.Substring(idx_stylist + 1, idx_end - idx_stylist - 1);

                    if (t.validQRCode(qrkode) && !string.IsNullOrEmpty(stylist))
                    {
                        t.updateAllIxobox(1, "Expired", int.Parse(stylist), int.Parse(kursi), qrkode);
                        sisaWaktuKursi[int.Parse(kursi) - 1] = 1500;  
                        string s = caseArduino["AktifkanKursi"] + kursi.ToString();
                        serialPort1.Write(s);
                    }
                    ClearSerialConsole();
                }
            }
            catch { }
        }
        void cekKursiArduino()
        {
            string data = "";
            try
            {
                data = temp_cekkursi.Substring(textBox8.Text.LastIndexOf('K'));
            }
            catch { };

            try
            {
                if (data[1].ToString().Equals("1"))
                {
                    textBox2.BackColor = Color.OrangeRed;
                }
                else
                    textBox2.BackColor = Color.GreenYellow;
            }
            catch { };
            try
            {
                if (data[2].ToString().Equals("1"))
                {
                    textBox3.BackColor = Color.Red;
                }
                else
                    textBox3.BackColor = Color.GreenYellow;
            }
            catch { }
            try
            {
                if (data[3].ToString().Equals("1"))
                {
                    textBox4.BackColor = Color.Red;
                }
                else
                    textBox4.BackColor = Color.GreenYellow;
            }
            catch { }
        }
        private void textBox8_TextChanged(object sender, EventArgs e)
        {
            cekKursiArduino();
        }
        private void metroButton1_Click(object sender, EventArgs e)
        {
            if (!t.validQRCode(comboBox1.Text))
            {
                serialPort1.Write(caseArduino["DisplayTicketNotValid"]);
            }
            else
            {
                qrkode = comboBox1.Text;
                serialPort1.WriteLine(caseArduino["DisplayInputStylist"]);
            }
            //DataTable dt = t.getAllIxobox(textBox1.Text.ToString());
            //string id_scan = dt.Rows[0]["id_scan"].ToString();
            //cekQRkode();
        }
        private void metroButton2_Click(object sender, EventArgs e)
        {
            serialPort1.Write(comboBox1.Text);
        }
        private void metroButton3_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine(caseArduino["CekStatusKursi"]);
            cekKursiArduino();
        }
    }
}
