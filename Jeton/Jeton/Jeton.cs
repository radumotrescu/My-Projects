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

        

        public void Start(List<Calculator> listaCalculatoare,string mesaj)
        {
            Random rand = new Random();
            int finish = listaCalculatoare.Count;
            int intSursaIP = rand.Next(0, finish);
            SursaIP = listaCalculatoare[intSursaIP].IP;
            int intDestinatieIP=-1;
            while(true)
            {
                intDestinatieIP = rand.Next(0, finish);
                if (intDestinatieIP != intSursaIP)
                    break;
            }
             
            DestinatieIP = listaCalculatoare[intDestinatieIP].IP;
            this.mesaj = mesaj;
            Liber = false;

        }


    }
}
