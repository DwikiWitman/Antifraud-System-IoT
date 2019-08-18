namespace WindowsFormsApp1
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnslsrpt = new System.Windows.Forms.Button();
            this.btnallmtr = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btncash = new System.Windows.Forms.Button();
            this.btncard = new System.Windows.Forms.Button();
            this.btnrestart = new System.Windows.Forms.Button();
            this.btnexit = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnslsrpt
            // 
            this.btnslsrpt.BackColor = System.Drawing.Color.Transparent;
            this.btnslsrpt.FlatAppearance.BorderSize = 3;
            this.btnslsrpt.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnslsrpt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnslsrpt.ForeColor = System.Drawing.Color.White;
            this.btnslsrpt.Location = new System.Drawing.Point(501, 260);
            this.btnslsrpt.Name = "btnslsrpt";
            this.btnslsrpt.Size = new System.Drawing.Size(128, 71);
            this.btnslsrpt.TabIndex = 0;
            this.btnslsrpt.Text = "SALES REPORT";
            this.btnslsrpt.UseVisualStyleBackColor = false;
            // 
            // btnallmtr
            // 
            this.btnallmtr.FlatAppearance.BorderSize = 3;
            this.btnallmtr.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnallmtr.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnallmtr.ForeColor = System.Drawing.Color.White;
            this.btnallmtr.Location = new System.Drawing.Point(723, 259);
            this.btnallmtr.Name = "btnallmtr";
            this.btnallmtr.Size = new System.Drawing.Size(128, 71);
            this.btnallmtr.TabIndex = 1;
            this.btnallmtr.Text = "ALL METER";
            this.btnallmtr.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btncash);
            this.groupBox1.Controls.Add(this.btncard);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(440, 337);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(470, 126);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "DAILY METER";
            // 
            // btncash
            // 
            this.btncash.FlatAppearance.BorderSize = 3;
            this.btncash.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btncash.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btncash.ForeColor = System.Drawing.Color.White;
            this.btncash.Location = new System.Drawing.Point(283, 23);
            this.btncash.Name = "btncash";
            this.btncash.Size = new System.Drawing.Size(128, 71);
            this.btncash.TabIndex = 1;
            this.btncash.Text = "CASH";
            this.btncash.UseVisualStyleBackColor = true;
            // 
            // btncard
            // 
            this.btncard.FlatAppearance.BorderSize = 3;
            this.btncard.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btncard.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btncard.ForeColor = System.Drawing.Color.White;
            this.btncard.Location = new System.Drawing.Point(61, 23);
            this.btncard.Name = "btncard";
            this.btncard.Size = new System.Drawing.Size(128, 71);
            this.btncard.TabIndex = 0;
            this.btncard.Text = "CARD";
            this.btncard.UseVisualStyleBackColor = true;
            // 
            // btnrestart
            // 
            this.btnrestart.FlatAppearance.BorderSize = 3;
            this.btnrestart.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnrestart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnrestart.ForeColor = System.Drawing.Color.White;
            this.btnrestart.Location = new System.Drawing.Point(501, 490);
            this.btnrestart.Name = "btnrestart";
            this.btnrestart.Size = new System.Drawing.Size(128, 71);
            this.btnrestart.TabIndex = 3;
            this.btnrestart.Text = "RESTART PROGRAM";
            this.btnrestart.UseVisualStyleBackColor = true;
            // 
            // btnexit
            // 
            this.btnexit.FlatAppearance.BorderSize = 3;
            this.btnexit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnexit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnexit.ForeColor = System.Drawing.Color.White;
            this.btnexit.Location = new System.Drawing.Point(723, 490);
            this.btnexit.Name = "btnexit";
            this.btnexit.Size = new System.Drawing.Size(128, 71);
            this.btnexit.TabIndex = 4;
            this.btnexit.Text = "EXIT ROGRAM";
            this.btnexit.UseVisualStyleBackColor = true;
            this.btnexit.Click += new System.EventHandler(this.btnexit_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(571, 139);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(233, 37);
            this.label1.TabIndex = 5;
            this.label1.Text = "ADMIN MENU";
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1366, 768);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnexit);
            this.Controls.Add(this.btnrestart);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnallmtr);
            this.Controls.Add(this.btnslsrpt);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form3";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form3";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnslsrpt;
        private System.Windows.Forms.Button btnallmtr;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btncash;
        private System.Windows.Forms.Button btncard;
        private System.Windows.Forms.Button btnrestart;
        private System.Windows.Forms.Button btnexit;
        private System.Windows.Forms.Label label1;
    }
}