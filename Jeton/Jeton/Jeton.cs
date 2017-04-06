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

        public void GeneratePath()
        {
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
            Finish = false;
            Liber = true;

        }
        public void afisare(Calculator calc)
        {
            Console.WriteLine(calc.IP);
        }

        public void verificaFinishJeton(Calculator calculator)
        {
            if (calculator.IP.Equals(DestinatieIP) && Liber == false)
            {
                Finish = true;
                calculator.Buffer = mesaj;
                Console.WriteLine("Jetonul a ajuns la destinatie {0} Bufferul calculatorului este : {1}", calculator.IP, calculator.Buffer);
            }
        }


        public void verificaLiberJeton(Calculator calculator)
        {
            if (calculator.IP.Equals(SursaIP) && Finish == true)
            {
                Liber = true;
                GeneratePath();
            }
        }

        public void verificaCreareMesaj(Calculator calculator)
        {
            if (calculator.IP.Equals(SursaIP) && Finish == false)
            {
                Liber = false;
                var newMesaj = RandomName(10);
                mesaj = newMesaj;
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

    }
}
