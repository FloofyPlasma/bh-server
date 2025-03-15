#import <Foundation/Foundation.h>

@interface Shader : NSObject
{
  unsigned int program;
  NSArray* uniformLocations;
}

@property (readonly) NSArray* uniformLocations; // @synthesize uniformLocations;
@property (readonly) unsigned int program; // @synthesize program;
- (BOOL)validateProgram:(unsigned int)arg1;
- (BOOL)linkProgram:(unsigned int)arg1;
- (BOOL)compileShader:(unsigned int*)arg1
                 type:(unsigned int)arg2
                 file:(id)arg3;
- (void)dealloc;
- (id)initWithShaderVertexFile:(id)arg1
                  fragmentFile:(id)arg2
                    attributes:(id)arg3
                      uniforms:(id)arg4;

@end
