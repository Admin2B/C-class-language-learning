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
            _age = 0;
        }
        protected string _name;
        protected int _age;
        public void PrintName()
        {
            Console.WriteLine("Pet's name is " + _name);
        }
        public void ShowAge()
        {
            Console.WriteLine(_name+"'s Age="+_age);
        }
        abstract public void Speak();
        public static void TestS()
        {
            Console.WriteLine("abc");
        }
        public static Pet operator ++ (Pet pet)
        {
            ++pet._age;
            return pet; 
        }

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

    public class Cage<T>
    {
        T[] array;
        readonly int Size;
        int num;
        public  Cage (int n)
        {
            Size = n;
            num = 0;
            array = new T[Size];
        }
        public void Putin(T pet)
        {
            if (num < Size)
            {
                array[num++] = pet;
            }
            else
            {
                Console.WriteLine("Cafe is full");
            }
        }
        public T TakeOut()
        {
            if (num > 0)
            {
                return array[--num];
            }
            else
            {
                Console.WriteLine("Cafe is empty");
                return default (T);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            var dogCage = new Cage<Dog>(1);
            dogCage.Putin(new Dog("A"));
            dogCage.Putin(new Dog("B"));

            var dog = dogCage.TakeOut();
            dog.PrintName();

            //Dog dog = new Dog("Jack");
            //dog.Speak();
            //Cat cat = dog;
            //cat.Speak();
            //cat.PrintName();

            //Dog dog2=(Dog)cat;
            //dog2.Speak();

            //Pet[] pets = new Pet[] { new Dog("Jack"), new Cat("Tom"), new Dog("Cherry") };
            //for (int i=0;i<pets.Length;++i)
            //{
            //    pets[i]++;
            //    pets[i].ShowAge();
            //}


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

