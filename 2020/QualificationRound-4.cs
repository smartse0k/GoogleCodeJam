using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Submit(int[] result)
        {
            string answer = "";
            for(int i=1; i<result.Length; i++)
            {
                answer += result[i].ToString();
            }
            Console.WriteLine(answer);
        }

        static int Query(int num, ref int[] result, ref bool[] isExact)
        {
            Console.WriteLine(num);

            int answer = GetInt();
            result[num] = answer;
            isExact[num] = true;

            return answer;
        }
        
        static string GetStr()
        {
            return Console.ReadLine();
        }

        static int GetInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static void Solve(int B)
        {
            int[] result = new int[B + 1];
            bool[] isExact = new bool[B + 1];
            for (int i = 0; i < B; i++)
            {
                result[i] = 0;
                isExact[i] = false;
            }

            // set 1
            for(int i=1; i<=10; i++)
            {
                Query(i, ref result, ref isExact);
            }

            Submit(result);
        }

        static int Main(string[] args)
        {
            string input;
            input = Console.ReadLine();

            int T, B;
            T = int.Parse(input.Split(' ')[0]);
            B = int.Parse(input.Split(' ')[1]);
            
            for (int i=0; i<T; i++)
            {
                Solve(B);

                string response = GetStr();
                if(response != "Y")
                {
                    break;
                }
            }

            return 0;
        }
    }
}
