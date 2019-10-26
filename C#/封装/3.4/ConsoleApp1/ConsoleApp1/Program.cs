using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Child child = new Child("Tiancuihua","Female",3);
            Child child1 = new Child("Tiancuihua","Male" ,3);
            Child child2 = new Child();
            child2.Name = "Huxiaomei";
            child2.Age = 4;
            Child child3 = new Child() { Name = "Zhourunhua", Age = 1 };
            //Console.WriteLine("My name is {0}",child.Name);
            //Console.WriteLine("My sex is {0}", child.Sex);
            //Console.WriteLine("I am {0} years old", child.Age);
        }
    }
}
