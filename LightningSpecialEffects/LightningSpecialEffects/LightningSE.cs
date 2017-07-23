using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LightningSpecialEffects
{
    /// <summary>
    /// 闪电特效类,可设置闪电起止位置,颜色,粗细
    /// </summary>
    class LightningSE
    {
        private Pen myPen = new System.Drawing.Pen(System.Drawing.Color.Black);//画笔
        private Graphics formGraphics;//画布
        private Random rand = new Random();//随机数生成器
        private Point startPoint, endPoint;//闪电起止位置
        private float diff;//闪电曲折程度,越大越曲折
        private float minDiff = 4;//曲折最小值

        /// <summary>
        /// 默认构造函数,必需指定画布,起止位置
        /// </summary>
        /// <param name="formGraphics">设置画布</param>
        /// <param name="startPoint">开始位置</param>
        /// <param name="endPoint">结束位置</param>
        /// <param name="diff">曲折程度,默认64</param>
        /// <param name="minDiff">曲折最小值,默认4</param>
        public LightningSE(Graphics formGraphics,Point startPoint,Point endPoint,float diff = 64,float minDiff = 4)
        {
            this.formGraphics = formGraphics;
            this.startPoint = startPoint;
            this.endPoint = endPoint;
            this.diff = diff;
            this.minDiff = minDiff;
        }

        /// <summary>
        /// 闪电粗细
        /// </summary>
        public float LineWidth
        {
            get
            {
                return myPen.Width;
            }
            set
            {
                myPen.Width = value;
            }
        }

        /// <summary>
        /// 闪电颜色
        /// </summary>
        public Color LineColor
        {
            get
            {
                return myPen.Color;
            }
            set
            {
                myPen.Color = value;
            }
        }

        /// <summary>
        /// 开始位置
        /// </summary>
        public Point StartPoint
        {
            get
            {
                return startPoint;
            }
            set
            {
                startPoint = value;
            }
        }

        /// <summary>
        /// 结束位置
        /// </summary>
        public Point EndPoint
        {
            get
            {
                return endPoint;
            }
            set
            {
                endPoint = value;
            }
        }

        /// <summary>
        /// 绘制闪电
        /// </summary>
        public void Draw()
        {
            Draw(startPoint, endPoint, diff);
        }

        public void Clear(Color color)
        {
            formGraphics.Clear(color);
        }

        private void Draw(Point start, Point end, float diff)
        {
            if (diff < minDiff)
            {
                // 绘制直线 
                formGraphics.DrawLine(myPen, start, end);
            }
            else
            {
                Point mid = new Point((start.X + end.X) / 2, (start.Y + end.Y) / 2);
                mid.X += (int)((rand.NextDouble() - 0.5f) * diff);
                mid.Y += (int)((rand.NextDouble() - 0.5f) * diff);
                Draw(start, mid, diff / 2);
                Draw(end, mid, diff / 2);
            }
        }// end of function

        ~LightningSE()
        {
            //释放画笔和画布资源
            myPen.Dispose();
            formGraphics.Dispose();
        }
    }// end of class
}
