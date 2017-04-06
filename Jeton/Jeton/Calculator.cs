using System;
using System.Text;
using System.Threading;

namespace Jeton
{
    class Calculator
    {
        private string ip;
        private static Random random = new Random(DateTime.Now.Millisecond);
        private Thread thread;
        public Jeton jeton;
        private string buffer;

        public Calculator(Jeton jeton)
        {
            generateIPAdress();
            this.jeton = jeton;
        }

        public string Buffer
        {
            get
            {
                return buffer;
            }
            set
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(buffer);
                sb.Append(value);
                buffer = sb.ToString();
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
                ip = value;
            }
        }

        private void generateIPAdress()
        {

            var i1 = random.Next(0, 255);
            var i2 = random.Next(0, 255);
            var i3 = random.Next(0, 255);
            var i4 = random.Next(0, 255);
            ip = null;
            ip = i1.ToString() + '.' + i2 + '.' + i3 + '.' + i4;
        }

        public void threading()
        {
            thread = new Thread(new ThreadStart(run));
            thread.Start();
        }

        public void Stop()
        {
            thread.Join();
        }

        private void run()
        {
            lock (jeton)
            {
                //for (int i = 0; i < 20; i++)
                while (true)
                {
                    Monitor.Pulse(jeton);
                    jeton.afisare(this);
                    jeton.verificaFinishJeton(this);
                    jeton.verificaLiberJeton(this);
                    jeton.verificaCreareMesaj(this);

                    Thread.Sleep(100);
                    try
                    {
                        Monitor.Wait(jeton);
                    }
                    catch (SynchronizationLockException e)
                    {
                        Console.WriteLine(e);
                    }

                }
                Monitor.Pulse(jeton);

            }

        }
    }
}
