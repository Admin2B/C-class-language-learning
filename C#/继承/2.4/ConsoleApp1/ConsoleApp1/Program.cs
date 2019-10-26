using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PetShop
{
    public class Pet
    {
        public Pet(string name)
        {
            _name = name;
        }
        protected string _name;
        public void PrintName()
        {
            Console.WriteLine("Pet's name is "+_name);
        }
        virtual public void Speak()
        {
            Console.WriteLine(_name+" is speaking");
        }
    }

    public class Dog:Pet
    {
        public Dog(string name):base(name)
        {

        }

        new public void PrintName()
        {
            Console.WriteLine("宠物的名字是" + _name);
        }
        public override void Speak()
        {
            Console.WriteLine(_name + " is speaking:"+"wow");
        }

    }

    public class Cat : Pet
    {
        public Cat (string name):base(name)
        {
           
        }

        public override void Speak()
        {
            Console.WriteLine(_name + " is speaking:" + "miaomiao");
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

