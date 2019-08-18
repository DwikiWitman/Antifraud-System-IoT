using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp1.DataSet1TableAdapters;

namespace WindowsFormsApp1.Control
{
    class UpdateControl
    {
        dbo_KOneksiTableAdapter x = new dbo_KOneksiTableAdapter();
        public string updatex(string id)
        {
            return x.UpdateQuery(id).ToString();
        }
    }
}
