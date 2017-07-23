using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LightningSpecialEffects
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Shown(object sender, EventArgs e)
        {
            System.Drawing.Pen myPen;
            // 画笔颜色 
            myPen = new System.Drawing.Pen(System.Drawing.Color.Black);
            System.Drawing.Graphics formGraphics = this.CreateGraphics();
            // 画线 
            formGraphics.DrawLine(myPen, 100,100,200,200);
            //释放画笔和画布资源 
            myPen.Dispose();
            formGraphics.Dispose();
        }
    }
}
