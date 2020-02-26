//
//  nums.cpp
//  Find_num
//
//  Created by Yaroslav on 06.02.2020.
//  Copyright © 2020 Yaroslav. All rights reserved.
//

#include <iostream>


int comp(const void *x, const void *y);
int * read_nums(int n);
void print_nums(int n, int m, int * nums);

int main(int argc, const char * argv[]) {
    int m, n;
    std::cout << "Enter m\n";
    std::cin >> m;
    while(m == 0)
    {
        std::cout << "Enter m again\n";
        std::cin >> m;
    }
    std::cout << "Enter n\n";
    std::cin >> n;
    while(n == 0)
    {
        std::cout << "Enter n again\n";
        std::cin >> n;
    }
    
    int test[] = {2, 1, 3, 4};
    std::qsort(test, sizeof(test) / sizeof(*test), sizeof(int), comp);
    if(test[0] != 1 && test[1] != 2 && test[2] != 3 && test[3] != 4)
        std::cout << "Error!!! Function \"comp\" does not work properly";
    
    int * nums = read_nums(n);
    
    while(nums == NULL)
    {
        std::cout << "Enter nums again\n";
        nums = read_nums(n);
    }
    
    std::qsort(nums, sizeof(nums) / sizeof(*nums), sizeof(int), comp);
    
    print_nums(n, m, nums);

    return 0;
}

// Function compare x and y and return the difference
int comp(const void *x, const void *y)
{
    int X = *(int*) x;
    int Y = *(int*) y;
    return X - Y;
}

// Function read n numbers ans return they in array
int * read_nums(int n)
{
    int * nums = (int *) std::calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)  {
        std::cout << "Enter number\n";
        std::cin >> nums[i];
    }
    
    return nums;
}

// Function print m numbers int the right order excludes n numbers fron array nums
void print_nums(int n, int m, int * nums)
{
    int i = 0;
    int j = 1;
    while(j <= m) {
        
        if(j != nums[i]) {
            std::cout << j << std::endl;
            j++;
        }
            else {
                j++;
                i++;
            }
    }
}
