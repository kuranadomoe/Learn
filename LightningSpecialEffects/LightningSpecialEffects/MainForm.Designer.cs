namespace LightningSpecialEffects
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
            this.components = new System.ComponentModel.Container();
            this.endPoint = new System.Windows.Forms.Label();
            this.startPoint = new System.Windows.Forms.Label();
            this.redraw = new System.Windows.Forms.Timer(this.components);
            this.lineWidthTrackbar = new System.Windows.Forms.TrackBar();
            this.lineColorComboBox = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.lineWidthTrackbar)).BeginInit();
            this.SuspendLayout();
            // 
            // endPoint
            // 
            this.endPoint.AutoSize = true;
            this.endPoint.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.endPoint.Cursor = System.Windows.Forms.Cursors.Hand;
            this.endPoint.Location = new System.Drawing.Point(226, 145);
            this.endPoint.MaximumSize = new System.Drawing.Size(8, 8);
            this.endPoint.MinimumSize = new System.Drawing.Size(8, 8);
            this.endPoint.Name = "endPoint";
            this.endPoint.Size = new System.Drawing.Size(8, 8);
            this.endPoint.TabIndex = 1;
            this.endPoint.MouseDown += new System.Windows.Forms.MouseEventHandler(this.label_MouseDown);
            this.endPoint.MouseMove += new System.Windows.Forms.MouseEventHandler(this.endPoint_MouseMove);
            // 
            // startPoint
            // 
            this.startPoint.AutoSize = true;
            this.startPoint.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.startPoint.Cursor = System.Windows.Forms.Cursors.Hand;
            this.startPoint.Location = new System.Drawing.Point(50, 81);
            this.startPoint.MaximumSize = new System.Drawing.Size(8, 8);
            this.startPoint.MinimumSize = new System.Drawing.Size(8, 8);
            this.startPoint.Name = "startPoint";
            this.startPoint.Size = new System.Drawing.Size(8, 8);
            this.startPoint.TabIndex = 0;
            this.startPoint.MouseDown += new System.Windows.Forms.MouseEventHandler(this.label_MouseDown);
            this.startPoint.MouseMove += new System.Windows.Forms.MouseEventHandler(this.startPoint_MouseMove);
            // 
            // redraw
            // 
            this.redraw.Tick += new System.EventHandler(this.redraw_Tick);
            // 
            // lineWidthTrackbar
            // 
            this.lineWidthTrackbar.Location = new System.Drawing.Point(168, 204);
            this.lineWidthTrackbar.Minimum = 1;
            this.lineWidthTrackbar.Name = "lineWidthTrackbar";
            this.lineWidthTrackbar.Size = new System.Drawing.Size(104, 45);
            this.lineWidthTrackbar.TabIndex = 2;
            this.lineWidthTrackbar.Value = 1;
            this.lineWidthTrackbar.Scroll += new System.EventHandler(this.lineWidthTrackbar_Scroll);
            // 
            // lineColorComboBox
            // 
            this.lineColorComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.lineColorComboBox.FormattingEnabled = true;
            this.lineColorComboBox.Location = new System.Drawing.Point(12, 204);
            this.lineColorComboBox.Name = "lineColorComboBox";
            this.lineColorComboBox.Size = new System.Drawing.Size(121, 20);
            this.lineColorComboBox.TabIndex = 3;
            this.lineColorComboBox.SelectedIndexChanged += new System.EventHandler(this.lineColorComboBox_SelectedIndexChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.lineColorComboBox);
            this.Controls.Add(this.lineWidthTrackbar);
            this.Controls.Add(this.endPoint);
            this.Controls.Add(this.startPoint);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "LightningSpecialEffects";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.lineWidthTrackbar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label endPoint;
        private System.Windows.Forms.Label startPoint;
        private System.Windows.Forms.Timer redraw;
        private System.Windows.Forms.TrackBar lineWidthTrackbar;
        private System.Windows.Forms.ComboBox lineColorComboBox;
    }
}

