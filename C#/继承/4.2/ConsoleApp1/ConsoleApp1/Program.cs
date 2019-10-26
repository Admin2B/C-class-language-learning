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

        public static implicit operator Cat(Dog dog)
        {
            return new Cat(dog._name);
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
        public static implicit operator Dog(Cat cat)
        {
            return new Dog(cat._name);
        }
    }



    class Program
    {
        static void Main(string[] args)
        {

            Dog dog = new Dog("Jack");
            dog.Speak();
            Cat cat = dog;
            cat.Speak();
            cat.PrintName();

            Dog dog2=(Dog)cat;
            dog2.Speak();

            //Pet[] pets = new Pet[] {new Dog("Jack"), new Cat("Tom") ,new Dog("Cherry")};
            //for(int i=0;i<pets.Length;i++)
            //{
            //    pets[i].Speak();
            //}

            //Cat c = new Cat("Tom2");
            //IClimbTree climb = (IClimbTree)c;
            //c.ClimbTree();
            //climb.ClimbTree();
            //ICatchMice catchM = (ICatchMice)c;
            //c.CatchMice();
            //catchM.CatchMice();

            //Dog.ShowNum();

            //Dog dog = new Dog("Tommy");
            //dog.HowToFeedDog();

            //{
            //    int i = 3;
            //    object oi = i;
            //    Console.WriteLine("i="+i+"oi="+oi.ToString());
            //    oi = 10;
            //    i = 7;
            //    Console.WriteLine("i=" + i + "oi=" + oi.ToString());
            //    int j = (int)oi;
            //    Console.WriteLine("j="+j);
            //}
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

