//
//  PTDefine.h
//  PerformanceTimer
//
//  Created by oropon 3/27/13.
//  Copyright (c) 2013 oropon. All rights reserved.
//

#define PTStart \
int PTIndex = 0;\
double PTElapledTimes[100] = {0.0f};\
int PTLines[100] = {0};\
char PTComments[100][30] = {'\n'};\
int PTStartLine = __LINE__;\
CFAbsoluteTime PTStartTime = CFAbsoluteTimeGetCurrent();\
CFAbsoluteTime PTCurrent = CFAbsoluteTimeGetCurrent();

#define PTGetDuration(comment) \
PTLines[PTIndex] = __LINE__;\
strcpy(PTComments[PTIndex], comment);\
PTElapledTimes[PTIndex++] = CFAbsoluteTimeGetCurrent() - PTCurrent;\
PTCurrent = CFAbsoluteTimeGetCurrent();

#define PTPrintResult  \
NSLog(@"%s", __PRETTY_FUNCTION__);\
NSLog(@"total duration: %f", CFAbsoluteTimeGetCurrent() - PTStartTime);\
for (int i = 0; i < PTIndex; i++) {\
int sl = i == 0 ? PTStartLine : PTLines[i-1];\
NSLog(@"%04d-%04d\telapsed:%.10f\t%s", sl, PTLines[i], PTElapledTimes[i], PTComments[i]);\
}
