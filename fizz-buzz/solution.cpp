//
//  main.cpp
//  fizz_buzz
//
//  Created by Yaroslav on 12.02.2020.
//  Copyright © 2020 Yaroslav. All rights reserved.
//

#include <iostream>
#include <string>

void cycle();
int div_by_3(std::string buf);
int div_by_5(std::string buf);
int test();

int main(int argc, const char * argv[]) {
    
    test();
    cycle();
    
    return 0;
}

void cycle()
{
    std::string buf;
    
    while(1) {
        std::cin >> buf;

        
        if(buf[0] == 'e') break;
        
            else if(div_by_3(buf))  std::cout << "fizz" << std::endl;
        
                else if(div_by_5(buf))    std::cout << "buzz" << std::endl;
                    
                    else std::cout << buf << std::endl;
    }
}

int div_by_5(std::string buf)
{
    if(buf[buf.size() - 1] == '0' || buf[buf.size() - 1] == '5')    return 1;
       
        else return 0;
    
}

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
