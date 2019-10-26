using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    //小朋友
    class Child
    {
        private string _name;
        private string sex="Male";
        private int age;
        private int height;

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

        public string Sex
        {
            get
            {
                return sex;
            }

            //set
            //{
            //    sex = value;
            //}
        }

        public int Age
        {
            get
            {
                return age;
            }

            set
            {
                if(value >= 3 && value <= 7)
                age = value;
            }
        }

        public int Height
        {
            get
            {
                return height;
            }

            set
            {
                height = value;
            }
        }

        public void PlayBall()
        {
            Console.WriteLine("耶！我是小小C罗！");
        }

        public void EatSugar(string sugar)
        {
            if(sugar=="榴莲糖")
                Console.WriteLine("哎呀，我最讨厌榴莲的味道了！");
            else
                Console.WriteLine("哈哈，是我喜欢吃的糖！");
        }

        public void EatSugar(int count)
        {
            if (count > 3)
                Console.WriteLine("吃糖太多对牙齿不好！");
            else
                Console.WriteLine("吃吧！");
        }

        public void EatSugar(string sugar, int count)
        {
            if (sugar=="牛奶糖"&& count > 2)
                Console.WriteLine("牛奶糖不能吃太多！");
            else if (count>3)
                Console.WriteLine("糖不能吃太多！");
            else
                Console.WriteLine("吃吧！");
        }

        public int Add(int n1, int n2)
        {
            int sum = n1 + n2;
            return sum;
        }

        public void EatSugar()
        {
            if (Age < 3)
                Console.WriteLine("too small to eat sugar！");
            else
            {
                Console.WriteLine("吃a！");
                Console.WriteLine("吃b！");
                Console.WriteLine("吃c！");
                Console.WriteLine("吃d！");
                Console.WriteLine("吃e！");
                Console.WriteLine("吃f！");
            }



        
        }

        public void SayHello()
        {
            Console.WriteLine("My name is{0}",Name);
            Console.WriteLine("I like:");
            Console.WriteLine("PlayBall");
            Console.WriteLine("Listen");
        }

        public Child()
        {

        }

        public Child (string name,string sex,int age)
        {
            Name=name;
            Age=age;
            this.sex=sex;
            this.EatSugar();
        }

        public Child(string name,int age)
        {
            Name = name;
            Age = age;
        }
    }
}
