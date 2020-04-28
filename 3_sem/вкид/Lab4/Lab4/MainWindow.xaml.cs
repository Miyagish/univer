using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;
using System.Diagnostics;

namespace Lab4
{
    public partial class MainWindow : Window
    {
        List< String> list = new List<String>();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Read_File_Button_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog Dialog_one = new OpenFileDialog();            Dialog_one.Filter = "text_files|*.txt";            if (Dialog_one.ShowDialog()== true)
            {
                Stopwatch mytimer = new Stopwatch();
                mytimer.Start();
                
                string text = File.ReadAllText(Dialog_one.FileName);

                char[] separators = new char[] { ' ', '.', ',', '!', '?', '/', '\t', '\n', '\r' };
                string[] textArray = text.Split(separators);
                foreach (string strTemp in textArray)
                {
                    string str = strTemp.Trim();
                if (!list.Contains(str)) list.Add(str);
                }

                mytimer.Stop();
                this.textbox_for_timer.Text = mytimer.Elapsed.ToString();
                this.textbox_for_list.Text = list.Count.ToString();
            }
            else
            {
                MessageBox.Show("Please choose file");
            }


        }

        private void Search_button_Click(object sender, RoutedEventArgs e)
        {

            string word = this.Inputwords.Text.Trim();


            if (!string.IsNullOrWhiteSpace(word) && list.Count > 0 && word != "Input word you would like to find, please")
            {

                string wordUpper = word.ToUpper();

                List<string> tempList = new List<string>();
                Stopwatch t = new Stopwatch();
                t.Start();
                foreach (string str in list)
                {
                    if (str.ToUpper().Contains(wordUpper))
                    {
                        tempList.Add(str);
                    }
                }
                t.Stop();
                this.Anothertimer.Text = t.Elapsed.ToString();

                this.found_words.Items.Clear();

                foreach (string str in tempList)
                {
                    this.found_words.Items.Add(str);
                }

            }
            else
            {
                MessageBox.Show("Input the word you would like to find, please");
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
