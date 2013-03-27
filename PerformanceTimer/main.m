//
//  main.m
//  PerformanceTimer
//
//  Created by oropon 3/27/13.
//  Copyright (c) 2013 oropon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PTDefine.h"

int takz(int x, int y, int z)
{
    if (x <= y) return z;
    
    return takz(takz(x-1, y, z), takz(y-1, z, x), takz(z-1, x, y));    
}

int main(int argc, const char * argv[])
{
    @autoreleasepool {
        PTStart
        
        takz(1, 0, 0);
        
        PTGetDuration("1,0,0")

        takz(10, 0, 0);

        PTGetDuration("10,0,0")
        
        takz(12, 6, 0);
        
        PTGetDuration("12,6,0")
        
        takz(18, 9, 0);
        
        PTGetDuration("18,9,0")
        
        PTPrintResult
    }
    return 0;
}

