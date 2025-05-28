#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import "InventoryItem.h"
#import "MJMath.h"
#import "World.h"

/**
 * @class DrawCube
 * @brief Placeholder! Please remember to fill this in.
 */
@interface DrawCube : NSObject {
  float* vertices;
  float* texCoords;
  float* normals;
  BOOL multitexture;
  BOOL luminous;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)fillCylinderBuffer:(float*)buffer
                 fromIndex:(int)start
                    matrix:(GLKMatrix4)matrix
                    radius:(float)radius
                    height:(float)height
                   centerX:(float)centerX
                   centerY:(float)centerY
                   centerZ:(float)centerZ
                   topMinS:(float)topMinS
                   topMaxS:(float)topMaxS
                   topMinT:(float)topMinT
                   topMaxT:(float)topMaxT
                  sideMinS:(float)sideMinS
                  sideMaxS:(float)sideMaxS
                  sideMinT:(float)sideMinT
                  sideMaxT:(float)sideMaxT
               macroWorldX:(int)macroWorldX
               macroWorldY:(int)macroWorldY
                paintColor:(Vector)paintColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)fillBuffer:(float*)buffer
         fromIndex:(int)start
            matrix:(GLKMatrix4)matrix
             width:(float)width
            height:(float)height
             depth:(float)depth
           centerX:(float)centerX
           centerY:(float)centerY
           centerZ:(float)centerZ
           topMinS:(float)topMinS
           topMaxS:(float)topMaxS
           topMinT:(float)topMinT
           topMaxT:(float)topMaxT
          sideMinS:(float)sideMinS
          sideMaxS:(float)sideMaxS
          sideMinT:(float)sideMinT
          sideMaxT:(float)sideMaxT
       macroWorldX:(int)macroWorldX
       macroWorldY:(int)macroWorldY
        paintColor:(Vector)paintColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)fillBuffer:(float*)buffer
         fromIndex:(int)start
            matrix:(GLKMatrix4)matrix
             width:(float)width
            height:(float)height
             depth:(float)depth
           centerX:(float)centerX
           centerY:(float)centerY
           centerZ:(float)centerZ
           topMinS:(float)topMinS
           topMaxS:(float)topMaxS
           topMinT:(float)topMinT
           topMaxT:(float)topMaxT
          sideMinS:(float)sideMinS
          sideMaxS:(float)sideMaxS
          sideMinT:(float)sideMinT
          sideMaxT:(float)sideMaxT
       macroWorldX:(int)macroWorldX
       macroWorldY:(int)macroWorldY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)fillBufferForBlockOfType:(ItemType)arg1
                          buffer:(float*)buffer
                       fromIndex:(int)start
                     macroWorldX:(int)macroWorldX
                     macroWorldY:(int)macroWorldY
                          matrix:(GLKMatrix4)matrix
                           level:(int)level
                      paintColor:(int)paintColor
                            size:(float)size
                           world:(World*)world;
@property BOOL luminous; // @synthesize luminous;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cubeDebugDescription;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initMultiTextureWithWidth:(float)width
                                height:(float)height
                                 depth:(float)depth
                               centerX:(float)centerX
                               centerY:(float)centerY
                               centerZ:(float)centerZ
                          topTexCoords:(CGRect)topTexCoords
                         sideTexCoords:(CGRect)sideTexCoords
                         topTexCoordsB:(CGRect)topTexCoordsB
                        sideTexCoordsB:(CGRect)sideTexCoordsB
                      calculateNormals:(BOOL)calculateNormals
                   useBoxTexCoordsForB:(BOOL)useBoxTexCoordsForB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initPyramidWithWidth:(float)width
                           height:(float)height
                            depth:(float)depth
                          centerX:(float)centerX
                          centerY:(float)centerY
                          centerZ:(float)centerZ
                          topMinS:(float)topMinS
                          topMaxS:(float)topMaxS
                          topMinT:(float)topMinT
                          topMaxT:(float)topMaxT
                         sideMinS:(float)sideMinS
                         sideMaxS:(float)sideMaxS
                         sideMinT:(float)sideMinT
                         sideMaxT:(float)sideMaxT
                 calculateNormals:(BOOL)calculateNormals
                         topScale:(float)topScale
                       rightScale:(float)rightScale;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initWithWidth:(float)width
                    height:(float)height
                     depth:(float)depth
                   centerX:(float)centerX
                   centerY:(float)centerY
                   centerZ:(float)centerZ
          calculateNormals:(BOOL)calculateNormals;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initWithWidth:(float)width
                    height:(float)height
                     depth:(float)depth
          calculateNormals:(BOOL)calculateNormals;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initWithWidth:(float)width
                    height:(float)height
                     depth:(float)depth
                imageIndex:(ImageType)imageIndex
          calculateNormals:(BOOL)calculateNormals;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initWithWidth:(float)width
                    height:(float)height
                     depth:(float)depth
                   centerX:(float)centerX
                   centerY:(float)centerY
                   centerZ:(float)centerZ
                   topMinS:(float)topMinS
                   topMaxS:(float)topMaxS
                   topMinT:(float)topMinT
                   topMaxT:(float)topMaxT
                  sideMinS:(float)sideMinS
                  sideMaxS:(float)sideMaxS
                  sideMinT:(float)sideMinT
                  sideMaxT:(float)sideMaxT
          calculateNormals:(BOOL)calculateNormals;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initWithWidth:(float)width
                    height:(float)height
                     depth:(float)depth
                   topMinS:(float)topMinS
                   topMaxS:(float)topMaxS
                   topMinT:(float)topMinT
                   topMaxT:(float)topMaxT
                  sideMinS:(float)sideMinS
                  sideMaxS:(float)sideMaxS
                  sideMinT:(float)sideMinT
                  sideMaxT:(float)sideMaxT
          calculateNormals:(BOOL)calculateNormals;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DrawCube*)initItemBlockOfType:(ItemType)ItemType
                           level:(int)level
                           paint:(BOOL)paint
                            size:(float)size
                           world:(World*)world;

@end
