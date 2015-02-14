#include "bufferedrenderer.h"

#define QUARK_GL_NULL 0

BufferedRenderer::BufferedRenderer(GLint mode) :
    vertices(Buffer<GLfloat>(BUFFER_SIZE*VERTEX_SIZE)),
    normals(Buffer<GLfloat>(BUFFER_SIZE*NORMAL_SIZE)),
    texCoords(Buffer<GLfloat>(BUFFER_SIZE*TEXCOORD_SIZE))
{
    this->mode = mode;
}

BufferedRenderer::~BufferedRenderer()
{
}

void BufferedRenderer::endEdit()
{
    vertices.sendData();
    normals.sendData();
    texCoords.sendData();

    glBindBuffer(GL_ARRAY_BUFFER, QUARK_GL_NULL);
}

void BufferedRenderer::reset()
{
    vertices.reset();
    texCoords.reset();
    normals.reset();
}

void BufferedRenderer::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, vertices.getBufferID());
    glVertexPointer(VERTEX_SIZE, GL_FLOAT, QUARK_GL_NULL, QUARK_GL_NULL);

    glBindBuffer(GL_ARRAY_BUFFER, normals.getBufferID());
    glNormalPointer(GL_FLOAT, QUARK_GL_NULL, QUARK_GL_NULL);

    glBindBuffer(GL_ARRAY_BUFFER, texCoords.getBufferID());
    glTexCoordPointer(TEXCOORD_SIZE, GL_FLOAT, QUARK_GL_NULL, QUARK_GL_NULL);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glDrawArrays(mode, 0, vertices.getDataCount());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, QUARK_GL_NULL);
}

void BufferedRenderer::addVertex(float x, float y, float z)
{
    vertices.add(x);
    vertices.add(y);
    vertices.add(z);
}

void BufferedRenderer::addTextureCoord(float x, float y)
{
    texCoords.add(x);
    texCoords.add(y);
}

void BufferedRenderer::addNormal(float x, float y, float z)
{
    normals.add(x);
    normals.add(y);
    normals.add(z);
}


template <class T>
Buffer<T>::Buffer(unsigned int maxSize)
{
    data = new T[maxSize];
    glGenBuffers(1, &bufferId);
    dataCount = 0;
}

template <class T>
void Buffer<T>::add(T newData)
{
    data[dataCount] = newData;
    ++dataCount;
}

template <class T>
GLuint Buffer<T>::getBufferID()
{
    return bufferId;
}

template <class T>
GLuint Buffer<T>::getDataCount()
{
    return dataCount;
}

template <class T>
void Buffer<T>::sendData()
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ARRAY_BUFFER, dataCount*sizeof(T), data, GL_STATIC_DRAW);
}

template <class T>
void Buffer<T>::reset()
{
    dataCount = 0;
}

template <class T>
Buffer<T>::~Buffer()
{
    glDeleteBuffers(1, &bufferId);
    delete[] data;
}
