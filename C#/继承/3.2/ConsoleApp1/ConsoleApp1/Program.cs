using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PetShop
{ 
    struct fish
    {
        int weight;
        int size;
        int type;
    }
    interface ICatchMice
    {
        void CatchMice();
    }

    interface IClimbTree
    {
        void ClimbTree();
    }

    abstract public class Pet
    {
        public Pet(string name)
        {
            _name = name;
        }
        protected string _name;
        public void PrintName()
        {
            Console.WriteLine("Pet's name is " + _name);
        }
        abstract public void Speak();

    }

    public class Dog : Pet
    {
        static int Num;
        static Dog()
        {
            Num = 0;
        }
        public Dog(string name) : base(name)
        {
            ++Num;
        }

        new public void PrintName()
        {
            Console.WriteLine("宠物的名字是" + _name);
        }
        sealed public override void Speak()
        {
            Console.WriteLine(_name + " is speaking:" + "wow");
        }
        //override public void Move()
        //{

        //}

        static public void ShowNum()
        {
            Console.WriteLine("Dog'number="+Num);
        }



    }

    public class Labrador:Dog
    {
        public Labrador (string name)
            :base(name)
        {

        }


    }

    static class PetGuide
    {
        static public void HowToFeedDog(this Dog dog)
        {
            Console.WriteLine("Play a video about how to feed a dog");
        }
    }

    public class Cat : Pet, ICatchMice, IClimbTree
    {
        public Cat(string name) : base(name)
        {

        }

        public override void Speak()
        {
            Console.WriteLine(_name + " is speaking:" + "miaomiao");
        }
        public void CatchMice()
        {
            Console.WriteLine("Catch mice");
        }
        public void ClimbTree()
        {
            Console.WriteLine("Climb tree");
        }
    }



    class Program
    {
        static void Main(string[] args)
        {

            Pet[] pets = new Pet[] {new Dog("Jack"), new Cat("Tom") ,new Dog("Cherry")};
            for(int i=0;i<pets.Length;i++)
            {
                pets[i].Speak();
            }

            Cat c = new Cat("Tom2");
            IClimbTree climb = (IClimbTree)c;
            c.ClimbTree();
            climb.ClimbTree();
            ICatchMice catchM = (ICatchMice)c;
            c.CatchMice();
            catchM.CatchMice();



            Dog.ShowNum();

            Dog dog = new Dog("Tommy");
            dog.HowToFeedDog();

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

