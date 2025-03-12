union _GLKMatrix4
{
  struct
  {
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
  };
  float m[16];
};

union _GLKVector3
{
  struct
  {
    float x;
    float y;
    float z;
  };
  struct
  {
    float r;
    float g;
    float b;
  };
  struct
  {
    float s;
    float t;
    float p;
  };
  float v[3];
};

union _GLKVector4
{
  struct
  {
    float x;
    float y;
    float z;
    float w;
  };
  struct
  {
    float r;
    float g;
    float b;
    float a;
  };
  struct
  {
    float s;
    float t;
    float p;
    float q;
  };
  float v[4];
};


typedef _GLKMatrix4 GLKMatrix4;
typedef _GLKVector3 GLKVector3;
typedef _GLKVector4 GLKVEctor4;
