// LimeChat is copyrighted free software by Satoshi Nakagawa <psychs AT limechat DOT net>.
// You can redistribute it and/or modify it under the terms of the GPL version 2 (see the file GPL.txt).

#import <Foundation/Foundation.h>


#define MODES_SIZE          52
#define INVALID_MODE_CHAR   ' '
#define INVALID_MARK_CHAR   ' '


@interface IRCISupportInfo : NSObject
{
    unsigned char modes[MODES_SIZE];
    int nickLen;
    int modesCount;
    NSMutableDictionary* markMap;
    NSMutableDictionary* modeMap;
}

@property (nonatomic, readonly) int nickLen;
@property (nonatomic, readonly) int modesCount;
@property (nonatomic, readonly) NSMutableDictionary* markMap;
@property (nonatomic, readonly) NSMutableDictionary* modeMap;

- (void)reset;
- (void)update:(NSString*)s;
- (NSArray*)parseMode:(NSString*)s;
- (char)modeForMark:(char)mark;
- (char)markForMode:(char)mode;

@end


@interface IRCModeInfo : NSObject
{
    unsigned char mode;
    BOOL plus;
    BOOL op;
    BOOL simpleMode;
    NSString* param;
}

@property (nonatomic) unsigned char mode;
@property (nonatomic) BOOL plus;
@property (nonatomic) BOOL op;
@property (nonatomic) BOOL simpleMode;
@property (nonatomic, strong) NSString* param;

+ (IRCModeInfo*)modeInfo;

@end
