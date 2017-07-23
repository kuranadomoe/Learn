using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LightningSpecialEffects
{
    public partial class MainForm : Form
    {
        //  闪电特效类LightningSE
        private LightningSE se;

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            //初始化闪电特效类实例
            se = new LightningSE(this.CreateGraphics(), startPoint.Location, endPoint.Location);
            //将颜色名添加到下拉菜单项
            foreach (var item in typeof(Color).GetMembers())
            {
                if (item.MemberType == System.Reflection.MemberTypes.Property
                    && Color.FromName(item.Name).IsKnownColor == true)
                {
                    lineColorComboBox.Items.Add(Color.FromName(item.Name).Name);
                }
            }
            //启动定时器
            redraw.Start();
        }

        /// <summary>
        /// 定时器,负责刷新重绘闪电
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void redraw_Tick(object sender, EventArgs e)
        {
            se.Clear(this.BackColor);
            se.Draw();
        }

        /// <summary>
        /// 设置闪电粗细的跟踪条
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void lineWidthTrackbar_Scroll(object sender, EventArgs e)
        {
            se.LineWidth = lineWidthTrackbar.Value;
        }

        /// <summary>
        /// 设置闪电颜色的下拉菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void lineColorComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            se.LineColor = Color.FromName(lineColorComboBox.SelectedItem.ToString());
        }

        // 标签的位置和鼠标按下标签时的位置
        private Point labelLastPoint,mouseLastPoint;

        /// <summary>
        /// 标签被按下时,记录标签的位置以及此时鼠光标的位置
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void label_MouseDown(object sender, MouseEventArgs e)
        {
            labelLastPoint = (sender as Label).Location;
            mouseLastPoint = Control.MousePosition;
        }

        /// <summary>
        /// 计算并设置开始标签位置,同时更新闪电的开始位置
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void startPoint_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                startPoint.Location = new Point(labelLastPoint.X + Control.MousePosition.X - mouseLastPoint.X, labelLastPoint.Y + Control.MousePosition.Y - mouseLastPoint.Y);
                se.StartPoint = startPoint.Location;
            }
        }

        /// <summary>
        /// 计算并设置结束标签位置,同时更新闪电的结束位置
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void endPoint_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                endPoint.Location = new Point(labelLastPoint.X + Control.MousePosition.X - mouseLastPoint.X, labelLastPoint.Y + Control.MousePosition.Y - mouseLastPoint.Y);
                se.EndPoint = endPoint.Location;
            }
        }
    }
}