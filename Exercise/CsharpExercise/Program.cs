#if true//练习
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Diagnostics;
using System.Text.RegularExpressions;
using System.Net;
using System.IO;
using static System.Console;

namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            WebTest();
            Pause();

        }
        public static void WebTest()
        {
            for (; ; )
            {
                try
                {
                    //获取或设置用于向Internet资源的请求进行身份验证的网络凭据
                    WebClient MyWebClient = new WebClient
                    {
                        Credentials = CredentialCache.DefaultCredentials
                    };
                    //从指定网站下载数据
                    Byte[] pageData = MyWebClient.DownloadData(@"http://cj.choclatl.com/");
                    string pageHtml = Encoding.UTF8.GetString(pageData);

                    Console.WriteLine(pageHtml);
                }
                catch (WebException webEx)
                {
                    Console.WriteLine(webEx.Message.ToString());
                    Pause();
                }
            }
        }
        public static void CompareFile(string file1path,string file2path)
        {
            var hash = System.Security.Cryptography.HashAlgorithm.Create();
            var stream_1 = new System.IO.FileStream(file1path, System.IO.FileMode.Open);
            byte[] hashByte_1 = hash.ComputeHash(stream_1); stream_1.Close(); //计算第二个文件的哈希值
            var stream_2 = new System.IO.FileStream(file2path, System.IO.FileMode.Open);
            byte[] hashByte_2 = hash.ComputeHash(stream_2); stream_2.Close(); //比较两个哈希值
            if (BitConverter.ToString(hashByte_1) == BitConverter.ToString(hashByte_2))
                Console.WriteLine("两个文件相等");
            else
                Console.WriteLine("两个文件不等");
        }
        public static void Pause()
        {
            Console.WriteLine("请按任意键继续. . .");
            Console.ReadKey(true);
        }
    }
}
#endif


#if false//2015-10-12   卡普雷卡尔重排求差黑洞数
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;//List类所在的命名空间
namespace CcharpExercise
{
    static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入一个至少三位且各个位数不能全部相同的正整数(正确示例:456,错误示例:444):");
            int number = 0;
            while (!int.TryParse(Console.ReadLine(), out number) || check(number) || number < 100)
            {
                Console.WriteLine("输入错误!请重新输入.");
                Pause();
                Console.Clear();
            }
            List<int> num = new List<int>() { number };
            for (int count = 1, max = 0, min = 0, current = 0; !num.Find(); ++count)
            {
                max = num.AscentSort();
                min = num.DeclineSort();
                current = max - min;
                num.Add(current);
                Console.WriteLine("第{0}步:\t{1} - {2} = {3}", count, max, min, current);
            }
            Console.WriteLine("出现重复数,陷入黑洞循环~~");
            Pause();
        }

        public static bool check(int item)//检查方法,当输入数字所有位都相同时返回true,否则返回false
        {
            StringBuilder str = new StringBuilder(item.ToString());
            for(int i = 1;i<str.Length;++i)
            {
                if (str[i] != str[i - 1])
                    return false;
            }
            return true;
        }
        public static bool Find(this List<int> obj)//查找方法,在数组中找到和最后一个数重复的则返回true,否则返回false
        {
            int index = 0;
            for (index = 0; index < obj.Count - 1; ++index)
            {
                if (obj[index] == obj.Last())
                    return true;
            }
            return false;
        }
        public static int AscentSort(this List<int> num)//升序
        {
            StringBuilder str = new StringBuilder(num.Last().ToString());
            while (str.Length != num[0].ToString().Length)
            {
                str.Append("0");
            }
            for (int i = 0; i < str.Length - 1; ++i)
            {
                char temp = '\0';
                int count = i;
                for (int j = i + 1; j < str.Length; ++j)
                {
                    if (str[count] < str[j])
                    {
                        count = j;
                    }
                }
                if (count != i)
                {
                    temp = str[i];
                    str[i] = str[count];
                    str[count] = temp;
                }
            }
            return Convert.ToInt32(str.ToString());
        }
        public static int DeclineSort(this List<int> num)//降序
        {
            StringBuilder str = new StringBuilder(num.Last().ToString());
            for (int i = 0; i < str.Length - 1; ++i)
            {
                char temp = '\0';
                int count = i;
                for (int j = i + 1; j < str.Length; ++j)
                {
                    if (str[count] > str[j])
                    {
                        count = j;
                    }
                }
                if (count != i)
                {
                    temp = str[i];
                    str[i] = str[count];
                    str[count] = temp;
                }
            }
            return Convert.ToInt32(str.ToString());
        }
        public static void Pause()
        {
            Console.WriteLine("请按任意键继续. . .");
            Console.ReadKey(true);
        }
    }
}
#endif


#if false//2015-10-03   分解质因数
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        public bool primer(int number)
        {
            int sqrtnum = (int)Math.Sqrt(number),i = 0;
            for (i = 2; i <= sqrtnum; ++i)
            {
                if (number % i == 0)
                    break;
            }
            if (i > sqrtnum)
                return true;
            else
                return false;
        }
        static void Main(string[] args)
        {
            int input = 0, number = 0, factor = 0;
            while (true)
            {
                Console.Clear();
                Console.WriteLine("请输入您要分解质因数的数字(正整数):");
                number = input = Convert.ToInt32(Console.ReadLine());
                if (input < 1)
                {
                    Console.WriteLine("输入错误!请输入正整数!");
                    Console.Write("请按任意键继续. . . ");
                    Console.ReadKey();
                }
                else
                    break;
            }
            if (number == 1)
            {
                Console.WriteLine("1既不是质数也不是合数!");
            }
            else
            {
                Program program = new Program();
                if (program.primer(number))
                    Console.WriteLine("该数不是合数,无法分解质因数!");
                else
                {
                    int i = 2;
                    Console.Write("{0}分解质因数为:\n{0} = ", number);
                    for (; i <= number; )
                    {
                        if (number % i == 0 && program.primer(i))
                        {
                            Console.Write("{0}*", i);
                            number /= i;
                            i = 2;
                        }
                        else
                        {
                            ++i;
                        }
                    }
                    Console.Write("\b ");
                    Console.WriteLine();
                }
            }
            Console.Write("请按任意键继续. . . ");
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-10-03   3位数的水仙花数
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int num = 100; num < 1000; ++num)
            {
                if (Math.Pow(num / 100, 3) + Math.Pow(num / 10 % 10, 3) + Math.Pow(num % 10, 3) == num)
                {
                    Console.Write("{0}\t",num);
                }
            }
            Console.Write("请按任意键继续. . .");
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-10-02   素数(质数)
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = new string[2];
            int start = 0, end = 0;
            while (true)
            {
                Console.Clear();
                Console.WriteLine("输入筛选范围,以逗号隔开:");
                str = Console.ReadLine().Split(',');
                start = Convert.ToInt32(str[0]);
                end = Convert.ToInt32(str[1]);
                if (start >= 1 && end >= 3 && end > start)
                    break;
                else
                {
                    Console.WriteLine("输入有误!请输入一小一大两个不相等的正整数!");
                    Console.Write("请按任意键继续...");
                    Console.ReadKey();
                }
            }
            for (int num; start <= end; ++start)
            {
                if (start < 2)
                    continue;
                double sqrtnum = Math.Sqrt((double)start);
                for (num = 2; (double)num <= sqrtnum; ++num)
                {
                    if (start % num == 0)
                        break;
                }
                if ((double)num > sqrtnum)
                {
                    Console.Write("{0}\t", start);
                }
            }
            Console.WriteLine("\n请按任意键继续. . .");
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-10-02   Fibonacci数列
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            int mouth = 0;
            for (Console.WriteLine("请输入月份:"); (mouth = Convert.ToInt32(Console.ReadLine())) < 1; Console.Clear())
            {
                Console.WriteLine("请输入一个正整数!");
                Console.Write("请按任意键继续...");
                Console.ReadKey();
            }
            int[] fibonacci = new int[mouth];
            for (int i = 0; i < fibonacci.Length; ++i)
            {
                if (i <= 1)
                {
                    fibonacci[i] = 1;
                }
                else
                {
                    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
                }
            }
            mouth = 0;
            foreach(int number in fibonacci)
            {
                Console.WriteLine("第{0}个月的兔子数量为:\t{1}", ++mouth, number);
            }
            Console.Write("请按任意键继续...");
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-10-02   十进制转二进制Low版
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            int temp = 0;
            char swap = '\0';
            string decimalnum;
            StringBuilder binary = new StringBuilder();
            Console.WriteLine("请输入十进制数:");
            decimalnum = Console.ReadLine();
            for (; decimalnum != "0"; )
            {
                temp = Convert.ToInt32(decimalnum);
                decimalnum = Convert.ToString(temp / 2);
                binary.Append(Convert.ToString(temp % 2));
            }
            for (int i = 0; i < binary.Length / 2; ++i)
            {
                swap = binary[i];
                binary[i] = binary[binary.Length - 1 - i];
                binary[binary.Length - 1 - i] = swap;
            }
            Console.WriteLine("该数的二进制数为:\n{0}", binary);
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-9-29    随机数
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();
            for (int i = 1; i <= 20; ++i)
            {
                Console.Write("{0}",random.Next(1,10));
            }
        }
    }
}
#endif


#if false//2015-9-24    圆的周长&面积
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            float radii = 0, area = 0, perimeter = 0;
            Console.WriteLine("请输入圆的半径:");
            radii = (float)Convert.ToDouble(Console.ReadLine());
            area = 2 * (float)Math.PI * radii;
            perimeter = (float)Math.PI * radii * radii;
            Console.WriteLine("半径为{0}的圆的周长area = {1},面积perimeter = {2}", radii, area, perimeter);
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-9-24    三角形海伦公式求面积
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpExercise
{
    class Program
    {
        static void Main(string[] args)
        {
            int side1 = 0, side2 = 0, side3 = 0;
            float area = 0f;
            double perimeter = 0;
            string[] value = new string[3];
            while (true)
            {
                Console.Clear();
                Console.WriteLine("请输入三角形的三条边,以空格隔开,回车结束");
                value = Console.ReadLine().Split(' ');
                side1 = Convert.ToInt32(value[0]);
                side2 = Convert.ToInt32(value[1]);
                side3 = Convert.ToInt32(value[2]);
                if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
                {
                    perimeter = (double)(side1 + side2 + side3) / 2;
                    area = (float)Math.Sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3));
                    Console.WriteLine("三角形的面积是{0}", area);
                    Console.WriteLine("感谢您的使用,再见!");
                    break;
                }
                else
                {
                    Console.WriteLine("不能组成三角形!\n请按任意键继续...");
                    Console.ReadKey();
                }
            }
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-9-24    结构体输入输出
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp
{
    class Program
    {
        struct Book
        {
            public string name;//书名
            public int number;//图书编号
            public string press;//出版社
            public float price;//单价
        }
        static void Main(string[] args)
        {
            Book test;
            Console.WriteLine("请输入书名");
            test.name=Console.ReadLine();
            Console.WriteLine("请输入图书编号");
            test.number = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("请输入图书出版社");
            test.press = Console.ReadLine();
            Console.WriteLine("请输入图书单价");
            test.price = Convert.ToSingle(Console.ReadLine());
            Console.WriteLine("\n\n图书信息:");
            Console.WriteLine("书名\t\t{0}",test.name);
            Console.WriteLine("编号\t\t{0}",test.number);
            Console.WriteLine("出版社\t\t{0}",test.press);
            Console.WriteLine("单价\t\t{0}",test.price);
            Console.ReadKey();
        }
    }
}
#endif


#if false//2015-9-24    字符串逆向输出
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CcharpExercise
{
    class Program
    {
        public void invert()
        {
            char ch = Convert.ToChar(Console.Read());
            if (ch != '\n')
            {
                invert();
                Console.Write("{0}", ch);
            }
        }
        static void Main(string[] args)
        {
            Program test = new Program();
            test.invert();
        }

    }
}
#endif