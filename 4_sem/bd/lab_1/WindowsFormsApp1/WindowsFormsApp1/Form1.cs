using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "_kursach__4_DataSet.Студенты". При необходимости она может быть перемещена или удалена.
            this.студентыTableAdapter.Fill(this._kursach__4_DataSet.Студенты);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "_kursach__4_DataSet.Группы". При необходимости она может быть перемещена или удалена.
            this.группыTableAdapter.Fill(this._kursach__4_DataSet.Группы);

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            студентыTableAdapter.Update(_kursach__4_DataSet);
            this.Validate();
            this.группыСтудентыBindingSource.EndEdit();
            this.студентыTableAdapter.Update(_kursach__4_DataSet);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.Show();

            string mybdpath = "C:/Users/STAS-I7/Desktop/даунка/bd/lab_1/kursach (4).mdb";
            string conStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + mybdpath;
            OleDbConnection connection = new OleDbConnection(conStr);
            OleDbDataAdapter adapter = new OleDbDataAdapter();
            connection.Open();
            OleDbCommand command = new OleDbCommand("SELECT Студенты.ФИО, Группы.[номер группы]" +
                " FROM (Группы INNER JOIN Студенты ON Группы.[Код группы] = Студенты.[Номер_группы])" +
                " ORDER BY Группы.[номер группы]",
                connection); // добавляем текст SQL запроса
            connection.Close();
            adapter.SelectCommand = command;
            DataSet dataSet = new DataSet();
            adapter.Fill(dataSet);
            frm2.dataGridView1.DataSource = dataSet.Tables[0];
            adapter.Update(dataSet);
        }

        private void bindingNavigator1_RefreshItems(object sender, EventArgs e)
        {

        }
    }
}
