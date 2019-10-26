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
            int age = 3;
            //Child c1 = new Child("LIUYOUCAI", Gender.Male, 3);
            //Growth(ref age);
            Console.WriteLine("I am {0} years old now!",age);
            int ly, ny;
            Growth(age, out ly, out ny);
            Console.WriteLine("I am {0} years old next year,{1}years old last year!", ny,ly);


            //Child c1 = new Child("A", Gender.Female,5);
            //Child c2 = new Child("B", Gender.Male,5);
            //Console.WriteLine("My name is {0},I am {1} ", c1.Name,c1.Sex);
            //Console.WriteLine("My name is {0},I am {1} ", c2.Name, c2.Sex);


            //Dog dog = new Dog();
            //dog.Name = "xiaobai";
            //Console.WriteLine("I am {0}", dog.Name);
            //dog.Sing();
            //Child child = new Child("Tiancuihua","Female",3);
            //Child child1 = new Child("Tiancuihua","Male" ,3);
            //Child child2 = new Child();
            //child2.Name = "Huxiaomei";
            //child2.Age = 4;
            //Child child3 = new Child() { Name = "Zhourunhua", Age = 1 };
            //Console.WriteLine("My name is {0}",child.Name);
            //Console.WriteLine("My sex is {0}", child.Sex);
            //Console.WriteLine("I am {0} years old", child.Age);
        }
        static void Growth(Child child)
        {
            child.Age++;
            Console.WriteLine("1 Yeah! 我又长大一岁！");
        }

        static void Growth(ref int age)
        {
            age++;
            Console.WriteLine("22Yeah! 我又长大一岁！"+age);

        }

        static void Growth(int age,out int lastYear,out int nextYear)
        {
            lastYear = age - 1;
            nextYear = age + 1;

        }

    }
}
