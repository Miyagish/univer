using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab2
{
    class Program
    {
        static void Main_menu()
        {
            Console.WriteLine("MENU");
            Console.WriteLine();
            Console.WriteLine("1.Find the square of Rectangle");
            Console.WriteLine("2.Find the square of Square");
            Console.WriteLine("3.Find the square of Circle");
            Console.WriteLine("4.Exit");

        }

        static int Main(string[] args)
        {
            int n = 0;

            while (n != 4)
            {

                Main_menu();
                n = int.Parse(Console.ReadLine());
                switch (n)
                {
                    case 1:
                        {
                            double len;
                            Rectangle rect = new Rectangle(0,0);
                            Console.WriteLine("Please put in your value");
                            Console.Write("Length 1 ");
                            len = Double.Parse(Console.ReadLine());

                            rect.length1 = len;

                            Console.Write("Length 2 ");
                            len = Double.Parse(Console.ReadLine());

                            rect.length2 = len;
                            rect.finding_area();

                            rect.Print();

                            break;
                        }
                    case 2:
                        {
                            double len;
                            Square scv = new Square(0);
                            Console.WriteLine("Please put in your value");
                            Console.Write("Length ");
                            len = Double.Parse(Console.ReadLine());
                            scv.length1 = len;
                            scv.length2 = len;
                            
                            scv.finding_area();

                            scv.Print();

                            break;
                        }
                    case 3:
                        {
                            double len;
                            Circle cir = new Circle(0);
                            Console.WriteLine("Please put in your value");
                            Console.Write("Radius ");
                            len = Double.Parse(Console.ReadLine());
                            cir.radius = len;

                            cir.finding_area();

                            cir.Print();

                            break;
                        }
                    case 4:
                        {
                            Console.WriteLine("Exiting.\n");
                            Console.ReadKey();
                            break;
                        }
                    default:
                        {
                            Console.WriteLine("ERROR");
                        }
                        break;
                }

            }
            return 0;
        }

    }

}

