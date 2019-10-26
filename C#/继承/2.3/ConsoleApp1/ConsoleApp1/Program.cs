using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PetShop
{
    public class Pet
    {
        public string Name;
        public void PrintName()
        {
            Console.WriteLine("Pet's name is "+Name);
        }
        virtual public void Speak()
        {
            Console.WriteLine(Name+" is speaking");
        }
    }

    public class Dog:Pet
    {
        public Dog(string name)
        {
            Name = name;
        }

        new public void PrintName()
        {
            Console.WriteLine("宠物的名字是" + Name);
        }
        public override void Speak()
        {
            Console.WriteLine(Name + " is speaking:"+"wow");
        }

    }

    public class Cat : Pet
    {
        public Cat (string name)
        {
            Name = name;
        }

        public override void Speak()
        {
            Console.WriteLine(Name + " is speaking:" + "miaomiao");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Pet[] pets = new Pet[] {new Dog("Jack"), new Cat("Tom") };
            for(int i=0;i<pets.Length;i++)
            {
                pets[i].Speak();
            } 


            //Pet dog = new Dog();
            //dog.Name ="Jack";
            //dog.PrintName();
            //dog.Speak();

            //Pet cat = new Cat();
            //cat.Name = "Tom";
            //cat.PrintName();
            //cat.Speak();
        }
    }

 }

