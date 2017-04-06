using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jeton
{
    class Jeton
    {


        private string mesaj;
        private bool visitedDestination = false;
        private static Random rand = new Random(DateTime.Now.Millisecond);
        private List<Calculator> retea;
        private static Random random = new Random(DateTime.Now.Millisecond);

        public void setRetea(List<Calculator> retea)
        {
            this.retea = retea;
        }


        public bool Liber
        {
            get;
            set;
        }

        public bool Finish
        {
            get;
            set;
        }

        public string SursaIP
        {
            get;
            set;
        }

        public string DestinatieIP
        {
            get;
            set;
        }

        public Calculator calcCurent
        {
            get;
            set;
        }


        private Jeton()
        {
        }

        public static readonly Jeton instance = new Jeton();

        public static Jeton Instance
        {
            get
            {
                return instance;
            }
        }

        public void FirstStart()
        {
            
        }

        public void Start()
        {
            var newText = RandomName(15);
            int finish = retea.Count;
            int intSursaIP = rand.Next(0, finish);
            SursaIP = retea[intSursaIP].IP;
            int intDestinatieIP = -1;
            while (true)
            {
                intDestinatieIP = rand.Next(0, finish);
                if (intDestinatieIP != intSursaIP)
                    break;
            }

            DestinatieIP = retea[intDestinatieIP].IP;
            mesaj=newText;
            Liber = false;

        }
        public void afisare(Calculator calc)
        {
            Console.WriteLine(calc.IP);
        }

        public void verificaFinishJeton(Calculator calculator)
        {
            if (calculator.IP.Equals(DestinatieIP))
            {
                Finish = true;
                Console.WriteLine("Jetonul a ajuns la destinatie {0}", calculator.IP);
                calculator.Buffer = mesaj;
                visitedDestination = true;

            }


        }
        public string RandomName(int num)
        {
            string possibleCharsArray = "qwertyuioasdfghjklzxcvbnm1234567890";
            var stringSize = possibleCharsArray.Length;
            var result = new char[num];
            while (num-- > 0)
            {
                result[num] = possibleCharsArray[random.Next(stringSize)];
            }
            return new string(result);
        }

        public void verificaLiberJeton(Calculator calculator)
        {
            if (calculator.IP.Equals(SursaIP) && visitedDestination == true)
            {
                Liber = true;
                Console.WriteLine("Jetonul a fost eliberat {0}", calculator.IP);
                visitedDestination = false;

                Console.WriteLine(mesaj);
                Start();

            }

        }

    }
}
