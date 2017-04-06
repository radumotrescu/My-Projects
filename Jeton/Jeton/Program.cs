using System;
using System.Collections.Generic;


namespace Jeton
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Calculator> retea = new List<Calculator>();
            Jeton jeton = Jeton.Instance;

            for (var i = 0; i < 10; i++)
            {
                retea.Add(new Calculator(jeton));
            }

            jeton.setRetea(retea);
            jeton.Liber = true;
            jeton.Finish = false;

            jeton.GeneratePath();

            foreach (var calc in retea)
            {
                calc.threading();
            }
            foreach (var calc in retea)
            {
                calc.Stop();
            }
            Console.WriteLine();

            foreach (var calc in retea)
            {
                Console.WriteLine(calc.IP + " " + calc.Buffer);
            }
        }
    }
}
