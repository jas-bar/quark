#ifndef BUFFEREDRENDERER_H
#define BUFFEREDRENDERER_H

#include <GL/gl.h>
#include <GLES2/gl2.h>

#define BUFFER_SIZE     0x2000000
#define VERTEX_SIZE     3
#define COLOR_SIZE      3
#define NORMAL_SIZE     3
#define TEXCOORD_SIZE   2

template <class T>
class Buffer {
private:
    GLuint bufferId;
    T* data;
    GLuint dataCount;
public:
    Buffer(unsigned int maxSize);
    void add(T newData);
    GLuint getBufferID();
    GLuint getDataCount();
    void sendData();
    void reset();
    ~Buffer();
};

class BufferedRenderer
{
private:
    Buffer<GLfloat> vertices, normals, texCoords;
    GLint mode;
public:
    BufferedRenderer(GLint mode);
    ~BufferedRenderer();
    void endEdit();
    void reset();
    void draw();
    void addVertex(float x, float y, float z);
    void addTextureCoord(float x, float y);
    void addNormal(float x, float y, float z);
};



#endif // BUFFEREDRENDERER_H
