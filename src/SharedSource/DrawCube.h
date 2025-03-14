

#import <objc/NSObject.h>

@interface DrawCube : NSObject {
  float* vertices;
  float* texCoords;
  float* normals;
  BOOL multitexture;
  BOOL luminous;
}

+ (void)fillCylinderBuffer:(float*)arg1
                 fromIndex:(int)arg2
                    matrix:(union _GLKMatrix4)arg3
                    radius:(float)arg4
                    height:(float)arg5
                   centerX:(float)arg6
                   centerY:(float)arg7
                   centerZ:(float)arg8
                   topMinS:(float)arg9
                   topMaxS:(float)arg10
                   topMinT:(float)arg11
                   topMaxT:(float)arg12
                  sideMinS:(float)arg13
                  sideMaxS:(float)arg14
                  sideMinT:(float)arg15
                  sideMaxT:(float)arg16
               macroWorldX:(int)arg17
               macroWorldY:(int)arg18
                paintColor:(Vector)arg19;
+ (void)fillBuffer:(float*)arg1
         fromIndex:(int)arg2
            matrix:(union _GLKMatrix4)arg3
             width:(float)arg4
            height:(float)arg5
             depth:(float)arg6
           centerX:(float)arg7
           centerY:(float)arg8
           centerZ:(float)arg9
           topMinS:(float)arg10
           topMaxS:(float)arg11
           topMinT:(float)arg12
           topMaxT:(float)arg13
          sideMinS:(float)arg14
          sideMaxS:(float)arg15
          sideMinT:(float)arg16
          sideMaxT:(float)arg17
       macroWorldX:(int)arg18
       macroWorldY:(int)arg19
        paintColor:(Vector)arg20;
+ (void)fillBuffer:(float*)arg1
         fromIndex:(int)arg2
            matrix:(union _GLKMatrix4)arg3
             width:(float)arg4
            height:(float)arg5
             depth:(float)arg6
           centerX:(float)arg7
           centerY:(float)arg8
           centerZ:(float)arg9
           topMinS:(float)arg10
           topMaxS:(float)arg11
           topMinT:(float)arg12
           topMaxT:(float)arg13
          sideMinS:(float)arg14
          sideMaxS:(float)arg15
          sideMinT:(float)arg16
          sideMaxT:(float)arg17
       macroWorldX:(int)arg18
       macroWorldY:(int)arg19;
+ (void)fillBufferForBlockOfType:(int)arg1
                          buffer:(float*)arg2
                       fromIndex:(int)arg3
                     macroWorldX:(int)arg4
                     macroWorldY:(int)arg5
                          matrix:(union _GLKMatrix4)arg6
                           level:(int)arg7
                      paintColor:(int)arg8
                            size:(float)arg9
                           world:(id)arg10;
@property BOOL luminous; // @synthesize luminous;
- (id)cubeDebugDescription;
- (void)draw;
- (id)initMultiTextureWithWidth:(float)arg1
                         height:(float)arg2
                          depth:(float)arg3
                        centerX:(float)arg4
                        centerY:(float)arg5
                        centerZ:(float)arg6
                   topTexCoords:(struct CGRect)arg7
                  sideTexCoords:(struct CGRect)arg8
                  topTexCoordsB:(struct CGRect)arg9
                 sideTexCoordsB:(struct CGRect)arg10
               calculateNormals:(BOOL)arg11
            useBoxTexCoordsForB:(BOOL)arg12;
- (id)initPyramidWithWidth:(float)arg1
                    height:(float)arg2
                     depth:(float)arg3
                   centerX:(float)arg4
                   centerY:(float)arg5
                   centerZ:(float)arg6
                   topMinS:(float)arg7
                   topMaxS:(float)arg8
                   topMinT:(float)arg9
                   topMaxT:(float)arg10
                  sideMinS:(float)arg11
                  sideMaxS:(float)arg12
                  sideMinT:(float)arg13
                  sideMaxT:(float)arg14
          calculateNormals:(BOOL)arg15
                  topScale:(float)arg16
                rightScale:(float)arg17;
- (id)initWithWidth:(float)arg1
              height:(float)arg2
               depth:(float)arg3
             centerX:(float)arg4
             centerY:(float)arg5
             centerZ:(float)arg6
    calculateNormals:(BOOL)arg7;
- (id)initWithWidth:(float)arg1
              height:(float)arg2
               depth:(float)arg3
    calculateNormals:(BOOL)arg4;
- (id)initWithWidth:(float)arg1
              height:(float)arg2
               depth:(float)arg3
          imageIndex:(int)arg4
    calculateNormals:(BOOL)arg5;
- (void)dealloc;
- (id)initWithWidth:(float)arg1
              height:(float)arg2
               depth:(float)arg3
             centerX:(float)arg4
             centerY:(float)arg5
             centerZ:(float)arg6
             topMinS:(float)arg7
             topMaxS:(float)arg8
             topMinT:(float)arg9
             topMaxT:(float)arg10
            sideMinS:(float)arg11
            sideMaxS:(float)arg12
            sideMinT:(float)arg13
            sideMaxT:(float)arg14
    calculateNormals:(BOOL)arg15;
- (id)initWithWidth:(float)arg1
              height:(float)arg2
               depth:(float)arg3
             topMinS:(float)arg4
             topMaxS:(float)arg5
             topMinT:(float)arg6
             topMaxT:(float)arg7
            sideMinS:(float)arg8
            sideMaxS:(float)arg9
            sideMinT:(float)arg10
            sideMaxT:(float)arg11
    calculateNormals:(BOOL)arg12;
- (id)initItemBlockOfType:(int)arg1
                    level:(int)arg2
                    paint:(BOOL)arg3
                     size:(float)arg4
                    world:(id)arg5;

@end
