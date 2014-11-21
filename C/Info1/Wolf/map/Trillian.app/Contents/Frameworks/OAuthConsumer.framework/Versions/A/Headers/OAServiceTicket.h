//
//  OAServiceTicket.h
//  OAuthConsumer
//
//  Created by Jon Crosby on 11/5/07.
//  Copyright 2007 Kaboomerang LLC. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Back-ported to obj-c 1.x by George Fletcher


#import <Cocoa/Cocoa.h>
#import "OAMutableURLRequest.h"


@interface OAServiceTicket : NSObject {
@private
    OAMutableURLRequest *request;
    NSURLResponse *response;
    BOOL didSucceed;
}
// Obj-c 1.x does not support the @property feature -- GFF
//@property(readonly) OAMutableURLRequest *request;
//@property(readonly) NSURLResponse *response;
//@property(readonly) BOOL didSucceed;

- (id)initWithRequest:(OAMutableURLRequest *)aRequest response:(NSURLResponse *)aResponse didSucceed:(BOOL)success;

// Obj-c 1.x requires explicit property methods
- (OAMutableURLRequest *)request;
- (NSURLResponse *)response;
- (BOOL)didSucceed;

@end
