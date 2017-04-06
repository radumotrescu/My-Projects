using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jeton
{
    class Calculator
    {
        private string ip;

        public Calculator urmator
        {
            get;
            set;
        }

        public Calculator(string nouIP)
        {
            IP = nouIP;
        }

        public string Buffer
        {
            get
            {
                return Buffer;
            }
            set
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(Buffer);
                sb.Append(value);
                Buffer = sb.ToString();
            }
        }
        public string IP
        {
            get
            {
                return ip;
            }
            set
            {
                if (verificaIP(value))
                    ip = value;
                else
                    Console.WriteLine("Adresa IP nu are formatul bun");
            }
        }

        private bool verificaIP(string IP)
        {
            foreach (char c in IP)
            {
                if (!"0123456789.".Contains(c))
                    return false;

            }
            return true;
        }

        
        public bool verificaFinishJeton(Jeton jeton)
        {
            if (ip.Equals(jeton.DestinatieIP))
            {
                jeton.Finish = true;
                return true;
            }
                
            return false;
        }

        public bool verificaLiberJeton(Jeton jeton)
        {
            if(ip.Equals(jeton.SursaIP))
            {
                jeton.Liber = true;
                return true;
            }
            return false;
        }



    }
}
