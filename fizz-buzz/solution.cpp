//
//  main.cpp
//  fizz_buzz
//
//  Created by Yaroslav on 12.02.2020.
//  Copyright © 2020 Yaroslav. All rights reserved.
//

#include <iostream>
#include <string>

int cycle();
int div_by_3(std::string buf);
int div_by_5(std::string buf);
int test();

int main(int argc, const char * argv[]) {
    
    test();
    
    return cycle();
}

// Function read numbers; e - means exit
int cycle()
{
    std::string buf;
    
    while(1) {
        std::cin >> buf;

        for (int i = 0; i < buf.size(); i++) {
            if(buf[i] != '-' && buf[i] < '0' && buf[i] > '9')  {
                std::cout << "error" << std::endl;
                return 1;
            }
        }
        
        if(buf.size() > 64) {
            std::cout << "error" << std::endl;
            return 1;
        }
        
        if(buf[0] == 'e') break;
        
            else if(div_by_3(buf))  std::cout << "fizz" << std::endl;
        
                else if(div_by_5(buf))    std::cout << "buzz" << std::endl;
                    
                    else std::cout << buf << std::endl;
    }
    
    return 0;
}

// Function verify if a number from the buf devided by 3 ore not
int div_by_5(std::string buf)
{
    if(buf[buf.size() - 1] == '0' || buf[buf.size() - 1] == '5')    return 1;
       
        else return 0;
    
}

// Function verify if a number from the buf devided by 3 ore not
int div_by_3(std::string buf) {
    int sum = 0;
    int k = 0;
    while(buf.size() != 1)
    {
        sum = 0;
        
        if(buf[0] == '-')   k++;
            
        for(int k = 0; k < buf.length(); k++)
        {
            sum += buf[k] - '0';
        }
        
        buf = std::to_string(sum);
    }
    
    if(buf[0] == '3' || buf[0] == '6' || buf[0] == '9') {
        return 1;
    }
    
        else    return 0;
}

// Function tests different available cases and return 0 if all correct or 1 if there are any problemes
int test()
{
    std::string buf = "535555555555";
    if(div_by_5(buf) == 0) return 1;
    
    buf = "5500000000000000000000000";
    if(div_by_5(buf) == 0) return 1;
    
    buf = "10";
    if(div_by_5(buf) == 0) return 1;
    
    buf = "15";
    if(div_by_5(buf) == 0 || div_by_3(buf) == 0) return 1;
    
    buf = "-15";
    if(div_by_5(buf) == 0 || div_by_3(buf) == 0) return 1;
    
    buf = "-33";
    if(div_by_5(buf) == 0 || div_by_3(buf) == 0) return 1;
    
    buf = "999";
    if(div_by_5(buf) == 0 || div_by_3(buf) == 0) return 1;
    
        else return 0;
    
}
