namespace WindowsFormsApp1
{
    partial class Form2
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
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this._kursach__4_DataSet = new WindowsFormsApp1._kursach__4_DataSet();
            this.kursach4DataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.группыTableAdapter = new WindowsFormsApp1._kursach__4_DataSetTableAdapters.ГруппыTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._kursach__4_DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.kursach4DataSetBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(96, -1);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(589, 439);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick_3);
            // 
            // _kursach__4_DataSet
            // 
            this._kursach__4_DataSet.DataSetName = "_kursach__4_DataSet";
            this._kursach__4_DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // kursach4DataSetBindingSource
            // 
            this.kursach4DataSetBindingSource.DataSource = this._kursach__4_DataSet;
            this.kursach4DataSetBindingSource.Position = 0;
            // 
            // группыTableAdapter
            // 
            this.группыTableAdapter.ClearBeforeFill = true;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._kursach__4_DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.kursach4DataSetBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private _kursach__4_DataSet _kursach__4_DataSet;
        private System.Windows.Forms.BindingSource kursach4DataSetBindingSource;
        private _kursach__4_DataSetTableAdapters.ГруппыTableAdapter группыTableAdapter;
        public System.Windows.Forms.DataGridView dataGridView1;
    }
}