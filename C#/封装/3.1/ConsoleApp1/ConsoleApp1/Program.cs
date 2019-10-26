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
            Child child = new Child();
            //child.PlayBall();
            child.EatSugar("榴莲糖");
            child.EatSugar(3);
            child.EatSugar("牛奶糖",3);
        }
    }
}
