using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Resources;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace FormExercise
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            textBox1.Text = new ResourceManager("FormExercise.DemoResource", typeof(MainForm).Assembly).GetString("Foobar");
            textBox1.Text += Properties.Settings.Default.Test;

            Properties.Settings.Default.Reset();

            toolTip1.SetToolTip(this.button1, "My button1");
            dataGridView1.CellEnter += (x, y) => (x as DataGridView).Rows.RemoveAt(y.RowIndex);
            
        }
        public void PrintScreen()
        {
            //获得当前屏幕的大小 
            Rectangle rect = new Rectangle();
            rect = System.Windows.Forms.Screen.GetWorkingArea(this);
            Bitmap bitmap = new Bitmap(this.Width, this.Height);
            Graphics g = Graphics.FromImage(bitmap);
            g.CopyFromScreen(this.Bounds.X, this.Bounds.Y, 0, 0, this.Size);
            string ImageName = DateTime.Now.ToString("yyyyMMdd_hhmmss") + ".jpg";
            bitmap.Save(ImageName);
            //释放资源
            bitmap.Dispose();
            g.Dispose();
            GC.Collect();
        }
        private void TabControl1_DrawItem(object sender, DrawItemEventArgs e)
        {
            Rectangle tabArea = tabControl1.GetTabRect(e.Index);//主要是做个转换来获得TAB项的RECTANGELF 
            RectangleF tabTextArea = (RectangleF)(tabControl1.GetTabRect(e.Index));
            Graphics g = e.Graphics;
            StringFormat sf = new StringFormat();//封装文本布局信息 
            sf.LineAlignment = StringAlignment.Center;
            sf.Alignment = StringAlignment.Center;
            Font font = this.tabControl1.Font;
            SolidBrush brush = new SolidBrush(Color.Black);//绘制边框的画笔 
            g.DrawString(((TabControl)(sender)).TabPages[e.Index].Text, font, brush, tabTextArea, sf);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            tabControl1.DrawMode = TabDrawMode.OwnerDrawFixed;
            tabControl1.Alignment = TabAlignment.Left;
            //tabControl1.SizeMode = TabSizeMode.Fixed;
            //tabControl1.Multiline = true;
            tabControl1.ItemSize = new Size(50, 100);
            tabControl1.DrawItem += TabControl1_DrawItem;

            //tableLayoutPanel1.Controls.Clear();
            tableLayoutPanel1.Controls.Add(button1, 0, 0);
            for(int i = 0;i<5;++i)
            {
                tableLayoutPanel1.Controls.Add(new Button());
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            tableLayoutPanel1.Controls.Add(button1, 0, 0);
            for (int i = 0; i < 5; ++i)
            {
                tableLayoutPanel1.Controls.Add(new Button());
            }

            Properties.Settings.Default.Test = "SecondValue";
            Properties.Settings.Default.Save();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            PrintScreen();
            string[] text = { @"<ICDATA></ICDATA>", @"<ICDATA>TEST123</ICDATA>" ,@"<YHKH>123</YHKH>"};
            string patten = @"\<ICDATA\>(.+)\<\/ICDATA\>";
            foreach(var str in text)
            {
                foreach (Match item in Regex.Matches(str, patten,RegexOptions.IgnoreCase))
                    MessageBox.Show(item.Groups[1].Value+"\n"+item.Success);
            }
            //MessageBox.Show(tableLayoutPanel1.Controls.Count.ToString()+button3.Tag);
            tableLayoutPanel1.Controls.Clear();
        }

        private void textBox1_Validating(object sender, CancelEventArgs e)
        {
            //MessageBox.Show("validating");
        }

        private void textBox1_Validated(object sender, EventArgs e)
        {
            errorProvider1.SetError(textBox1, "Nya");
        }

        private void dataGridView1_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show("CellEndEdit");
        }

        private void dataGridView1_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show("RowLeave");
        }

        private void dataGridView1_CellLeave(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show("CellLeave");
        }

        private void dataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show("CellValueChanged");
        }

        private void dataGridView1_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
        {
            //MessageBox.Show("RowsAdded:" + e.RowIndex);
        }

        private void dataGridView1_UserAddedRow(object sender, DataGridViewRowEventArgs e)
        {
            //MessageBox.Show("UserRowsAdded:" + e.Row.Index);
        }
    }
}