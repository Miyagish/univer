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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        public void kursach4DataSetBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }

        public void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        public void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "_kursach__4_DataSet1.Группы". При необходимости она может быть перемещена или удалена.
            this.группыTableAdapter.Fill(this._kursach__4_DataSet.Группы);
        }

        public void dataGridView1_CellContentClick_2(object sender, DataGridViewCellEventArgs e)
        {

        }

        public void dataGridView1_CellContentClick_3(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
