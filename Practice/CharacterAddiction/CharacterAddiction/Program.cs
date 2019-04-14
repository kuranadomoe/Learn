using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading;
using static System.Console;
using static System.Net.Mime.MediaTypeNames;

namespace kuranado.moe.Practice.CharacterAddiction
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            WriteLine("Please input expression:");
            List<string> expression = new List<string>();
            Regex regex = new Regex(@"^(?:[+]?(?<input>[a-z A-Z]{1,18})|[- ]+)$", RegexOptions.Compiled);
            for (var match = regex.Match(ReadLine()); match.Success; match = regex.Match(ReadLine()))
            {
                var line = match.Groups["input"].Value.Replace(" ", "");
                if (line != "")
                    expression.Add(line);
            }
            if (expression.Count < 3)
            {
                WriteLine("Too few parameters!");
                Pause();
                Process.GetCurrentProcess().Kill();
            }

            List<(char ch, int num)> tmp = new List<(char ch, int num)>();
            foreach (var line in expression)
            {
                foreach (var ch in line)
                {
                    if (!tmp.Contains((ch, 0)))
                        tmp.Add((ch, 0));
                }
            }
            var pairs = tmp.ToArray();

            List<string> result = new List<string>();
            var expStr = string.Join(Environment.NewLine, expression);
            WriteLine("calculating...");
            for (; pairs[0].num <= 9;)
            {
                var formula = expStr;
                foreach (var (ch, num) in pairs)
                    formula = formula.Replace(ch, (char)(num + '0'));

                var sum = 0ul;
                var nums = formula.Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0; i < nums.Length - 1; ++i)
                    sum += ulong.Parse(nums[i]);
                if (sum == ulong.Parse(nums[nums.Length - 1]))
                {
                    var res = $"================{Environment.NewLine}{formula}{Environment.NewLine}================";
                    result.Add(res);
                    WriteLine(res);
                }

                var index = pairs.Length - 1;
                pairs[index] = (pairs[index].ch, pairs[index].num + 1);
                for (int i = index; pairs[i].num > 9 && i > 0; --i)
                {
                    pairs[i - 1] = (pairs[i - 1].ch, pairs[i - 1].num + 1);
                    pairs[i] = (pairs[i].ch, 0);
                }
            }
            WriteLine("calculated");
            File.WriteAllLines($"{DateTime.Now.ToString("yyyy_MM_dd_hh_mm_ss")}_result.txt", result);

            Pause();
        }

        private static void EquationHolds(string[] express)
        {

        }

        /// <summary>
        /// Pause
        /// </summary>
        private static void Pause()
        {
            WriteLine("Press any key to continue...");
            ReadKey(true);
        }
    }
}
