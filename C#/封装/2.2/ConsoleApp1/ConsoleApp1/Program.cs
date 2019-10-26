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
            Child xiaoMing = new Child();
            xiaoMing.Name = "马小明";
            xiaoMing.Sex = "男";
            xiaoMing.Age = 5;
            xiaoMing.Age = 7;
            xiaoMing.Height = 120;
            Console.WriteLine("我叫"+xiaoMing.Name+",今年"+xiaoMing.Age+"岁。");
            xiaoMing.PlayBall();
        }
    }
}
