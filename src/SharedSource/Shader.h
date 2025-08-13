#import <Foundation/Foundation.h>

/**
 * @class Shader
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Shader : NSObject {
  unsigned int program;
  NSArray* uniformLocations;
}

/**
 * @property uniformLocations
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* uniformLocations; // @synthesize uniformLocations;
/**
 * @property program
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) unsigned int program; // @synthesize program;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)validateProgram:(unsigned int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)linkProgram:(unsigned int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)compileShader:(unsigned int*)arg1
                 type:(unsigned int)arg2
                 file:(id)arg3;
/**
 * @brief Deallocates this Shader, along with any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithShaderVertexFile:(id)arg1
                  fragmentFile:(id)arg2
                    attributes:(id)arg3
                      uniforms:(id)arg4;

@end
