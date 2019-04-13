using System;
using System.Collections.Generic;
using System.Diagnostics;
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
            List<string> input = new List<string>();
            Regex regex = new Regex(@"^(?:[+]?[a-z A-Z]+|[-]+)$");
            for (var line = ReadLine(); regex.IsMatch(line); line = ReadLine())
                input.Add(line);
            if (input.Count < 3)
            {
                WriteLine("Too few parameters!");
                Pause();
                Process.GetCurrentProcess().Kill();
            }



            Pause();
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
