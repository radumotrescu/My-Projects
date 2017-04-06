using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Jeton
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Calculator> retea = new List<Calculator>();
            Jeton jeton = Jeton.Instance;



            foreach (string IP in File.ReadAllLines("calculatoare.txt"))
            {
                if (retea[0] == null)
                    retea.Add(new Calculator(IP));

            }

            //Calculator start = retea[0];
            //for (int i = 1; i < retea.Count; i++)
            //    start.urmator = retea[i];

            jeton.Start(retea, "OMG");
            while (true)
            {

                for (int i = 0; i < retea.Count; i++)
                {
                    
                }

            }


        }
    }
}
