namespace SortAlgorithmDemo
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.BubbleSort = new System.Windows.Forms.Button();
            this.SelectSort = new System.Windows.Forms.Button();
            this.MergeSort = new System.Windows.Forms.Button();
            this.BuildingPrint = new System.Windows.Forms.Label();
            this.ResultPrint = new System.Windows.Forms.Label();
            this.Title = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BubbleSort
            // 
            this.BubbleSort.Location = new System.Drawing.Point(74, 276);
            this.BubbleSort.Name = "BubbleSort";
            this.BubbleSort.Size = new System.Drawing.Size(72, 24);
            this.BubbleSort.TabIndex = 0;
            this.BubbleSort.Text = "冒泡排序";
            this.BubbleSort.UseVisualStyleBackColor = true;
            this.BubbleSort.Click += new System.EventHandler(this.BubbleSort_Click);
            // 
            // SelectSort
            // 
            this.SelectSort.Location = new System.Drawing.Point(220, 276);
            this.SelectSort.Name = "SelectSort";
            this.SelectSort.Size = new System.Drawing.Size(72, 24);
            this.SelectSort.TabIndex = 1;
            this.SelectSort.Text = "选择排序";
            this.SelectSort.UseVisualStyleBackColor = true;
            this.SelectSort.Click += new System.EventHandler(this.SelectSort_Click);
            // 
            // MergeSort
            // 
            this.MergeSort.Location = new System.Drawing.Point(366, 276);
            this.MergeSort.Name = "MergeSort";
            this.MergeSort.Size = new System.Drawing.Size(72, 24);
            this.MergeSort.TabIndex = 2;
            this.MergeSort.Text = "归并排序";
            this.MergeSort.UseVisualStyleBackColor = true;
            this.MergeSort.Click += new System.EventHandler(this.MergeSort_Click);
            // 
            // BuildingPrint
            // 
            this.BuildingPrint.Location = new System.Drawing.Point(74, 96);
            this.BuildingPrint.Name = "BuildingPrint";
            this.BuildingPrint.Size = new System.Drawing.Size(364, 50);
            this.BuildingPrint.TabIndex = 3;
            // 
            // ResultPrint
            // 
            this.ResultPrint.Location = new System.Drawing.Point(74, 180);
            this.ResultPrint.Name = "ResultPrint";
            this.ResultPrint.Size = new System.Drawing.Size(364, 50);
            this.ResultPrint.TabIndex = 4;
            // 
            // Title
            // 
            this.Title.Location = new System.Drawing.Point(218, 48);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(74, 24);
            this.Title.TabIndex = 5;
            this.Title.Text = "请选择算法";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(496, 345);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.ResultPrint);
            this.Controls.Add(this.BuildingPrint);
            this.Controls.Add(this.MergeSort);
            this.Controls.Add(this.SelectSort);
            this.Controls.Add(this.BubbleSort);
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Sort Algorithm Demo";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BubbleSort;
        private System.Windows.Forms.Button SelectSort;
        private System.Windows.Forms.Button MergeSort;
        private System.Windows.Forms.Label BuildingPrint;
        private System.Windows.Forms.Label ResultPrint;
        private System.Windows.Forms.Label Title;
    }
}

