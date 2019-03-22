#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
//TYPE FOR SPEED v 0.1
//BY KEVIN AGUSTO
void spab(int x=3, std::string y = "\n"){for (;x>=0;x--){std::cout << y;}}

        std::string str[4] = {
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "0123456789",
        "!@#$%^&*()_+-={}|[]:;'<>?,./'",
        }, result;
        //amount, waktu
        int rules[4][2] = {{10, 10}, {15, 10}, {20, 10}, {25, 10}};
        int amount, diff, waktu, level=1, temp=0, fin, tau;
        void wait(int sec)
        {
         int to_mul = 1000000;
         for (;sec>=0;sec--)
         {
            usleep(to_mul);
         }
        }
        std::string ran_char(int amount, int diff)
        {
         std::string res = "", temp="";
         srand(time(NULL));
         for (int i = 0; i < diff+1; i++)
         {
          temp+=(::str[i]);
         }
         for (int i = 0; i < amount; i++)
         {
          res+=temp[rand()%temp.length()];
         }
         return res;
        }
        void get_input()
        {
            std::cout << "INPUT:\n";
            std::cin >> (::result);
            //::result = std::cin.get();
        }
        int wait1(int detik)
        {
         //karena usleep pake nano detik, kali dulu
         detik*=1000000;
         int sec = 0;
         for (int i = 1000000; i < detik; i+=1000000)
         {
            sec++;
          if (::result!="")
          {break;}
          usleep(1000000);
         }
         return sec;
        }
        void main0()
        {
         while (1)
         {
            spab(10);
            std::cout << "-----------------------------\n";
            std::cout << "Level " << ::level << "\n";
            std::cout << "-----------------------------\n\n";
            ::spab();
            std::cout << "To type:\n";
            std::string temp = ::ran_char(::rules[::diff][0], ::diff);
            std::cout << temp;
            spab(3);
            std::cout << "TYPE NOW!\n";
            std::thread th0(::get_input);
            th0.join();
            int sudah = ::wait1(::rules[::diff][1]);
            std::cout << "to type: " << temp << "    your type: " << ::result << "\n";
            //::wait1(::rules[::diff][1], temp);
            if (!(temp==::result))
            {
                std::cout << "MISMATCH!. YOU LOSE!\n";
                break;
            }
            ::fin = 0;
            ::level++;
            ::result = "";
            ::rules[::diff][0] += 5;
            ::rules[::diff][1] += 3;
         }
        }
        void menu()
        {
            std::string weltxt = "Type For Speed\nWritten by Kevin Agusto\n";
            std::string diftxt = "Please type the difficulty number and press enter\n\n0.Easy\n1.Normal\n2.Hard\n3.Expert\n\nNumber: ";
            std::cout << weltxt << "\n";
            std::cout << diftxt;
            std::cin >> ::diff;
        }
        
int main()
{
    menu();
    //std::thread obj(::main0);
    //obj.join();
    main0();
    return 0;
}