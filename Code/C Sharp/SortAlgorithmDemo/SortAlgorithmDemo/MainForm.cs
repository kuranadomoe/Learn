using System;
using System.Windows.Forms;

namespace SortAlgorithmDemo
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }


        private int[] arr = new int[45];


        private void Init(System.Windows.Forms.Label label)
        {
            Random num = new Random();
            for (int i = 0; i < arr.Length; ++i)
            {
                arr[i] = num.Next(127);
                label.Text += string.Format("{0,-5:d0}",arr[i]);
            }
        }


        private void BubbleSort_Click(object sender, EventArgs e)
        {
            Title.Text = "冒泡排序";
            BuildingPrint.Text = "待排序数据:";
            Init(BuildingPrint);

            //冒泡排序
            for (int i = 0; i < arr.Length - 1; ++i)
            {
                for (int j = 0,temp = 0; j < arr.Length - 1 - i; ++j)
                {
                    if(arr[j]>arr[j+1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            ResultPrint.Text = "排序结果为:";
            for (int i = 0; i < arr.Length; ++i)
                ResultPrint.Text += string.Format("{0,-5:d0}", arr[i]);
        }

        private void SelectSort_Click(object sender, EventArgs e)
        {
            Title.Text = "选择排序";
            BuildingPrint.Text = "待排序数据:";
            Init(BuildingPrint);

            //选择排序
            for (int i = 0, mark = 0, temp = 0; i < arr.Length; ++i)
            {
                mark = i;
                for (int j = i + 1; j < arr.Length; ++j)
                {
                    if (arr[j] < arr[mark])
                        mark = j;
                }
                if (mark != i)
                {
                    temp = arr[mark];
                    arr[mark] = arr[i];
                    arr[i] = temp;
                }
            }

            ResultPrint.Text = "排序结果为:";
            for (int i = 0; i < arr.Length; ++i)
                ResultPrint.Text += string.Format("{0,-5:d0}", arr[i]);
        }

        private void MergeSort_Click(object sender, EventArgs e)
        {
            Title.Text = "归并排序";
            BuildingPrint.Text = "待排序数据:";
            Init(BuildingPrint);
            
            //归并排序
            MSort(arr, new int[arr.Length], 0, arr.Length - 1);

            ResultPrint.Text = "排序结果为:";
            for (int i = 0; i < arr.Length; ++i)
                ResultPrint.Text += string.Format("{0,-5:d0}", arr[i]);
        }


        private void MSort(int[] sortArr, int[] tempArr, int start, int end)
        {
            int mid = (start + end) / 2;
            if (start < end)
            {
                MSort(sortArr, tempArr, start, mid);
                MSort(sortArr, tempArr, mid + 1, end);
                Merge(sortArr, tempArr, start, mid + 1, end);
            }
        }


        private void Merge(int[] sortArr, int[] tempArr, int leftStart, int rightStart, int rightEnd)
        {
            int leftEnd = rightStart - 1, tempIndex = leftStart, tempStart = leftStart;
            //合并两组数据
            for (; leftStart <= leftEnd && rightStart <= rightEnd;)
            {
                if (sortArr[leftStart] <= sortArr[rightStart])
                    tempArr[tempIndex++] = sortArr[leftStart++];
                else
                    tempArr[tempIndex++] = sortArr[rightStart++];
            }
            //处理剩下的数据
            for (; leftStart <= leftEnd;)
                tempArr[tempIndex++] = sortArr[leftStart++];
            for (; rightStart <= rightEnd;)
                tempArr[tempIndex++] = sortArr[rightStart++];
            //将temp的内容复制到要排序的数组
            for (; tempStart <= rightEnd; ++tempStart)
                sortArr[tempStart] = tempArr[tempStart];
        }
    }
}
