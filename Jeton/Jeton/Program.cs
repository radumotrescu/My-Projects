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
            
            for (var i = 0; i < 10; i++)
            {
                retea.Add(new Calculator());
                //Console.WriteLine(retea[i].IP);
                retea[i].jeton = jeton;
                if (i > 0)
                {
                    retea[i].urmator = retea[i - 1];
                }

            }
            jeton.setRetea(retea);
            jeton.calcCurent = retea[0];
            jeton.Start();
            retea[0].urmator = retea[retea.Count-1];
            Calculator cur = retea[0];
            foreach(var calc in retea)
            {
                calc.threading();
            }

           
            foreach(var calc in retea)
            {
                
                calc.Stop();
                
                
            }
            Console.WriteLine();
            
            foreach(var calc in retea)
            {
                Console.WriteLine(calc.IP + " " + calc.Buffer);
            }



            //jeton.Start(retea, "OMG");
            //while (true)
            //{

            //    for (int i = 0; i < retea.Count; i++)
            //    {

            //    }

            //}


        }
    }
}
