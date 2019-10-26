using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    struct Dog
    {
        string _name;

        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                _name = value;
            }
        }

        public void Sing()
        {
            Console.WriteLine("WANGWANG");
        }

        //public Dog()
        //{

        //}

        public Dog(string name)
        {
            Name = name;
        }
    }
}
