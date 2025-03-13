#import <Foundation/Foundation.h>
#import "GLKit/GLKMathTypes.h"

GLKVector3 GLKMathProject(GLKVector3 object, GLKMatrix4 model, GLKMatrix4 projection, int* viewport)
{
  [NSException raise:NSRangeException
              format:@"Not implemented."];
}

GLKVector3 GLKMathUnproject(GLKVector3 window, GLKMatrix4 model, GLKMatrix4 projection, int* viewport, BOOL* success)
{
      [NSException raise:NSRangeException
              format:@"Not implemented."];
}
