#ifdef SPG_WINDOWS
#include "win32_renderer_backend.h"
#include "renderer/opengl/opengl_headers.h"
#include "renderer/renderer_api.h"
#pragma comment (lib, "opengl32.lib")

namespace SPG
{
#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_CONTEXT_LAYER_PLANE_ARB               0x2093
#define WGL_CONTEXT_FLAGS_ARB                     0x2094
#define WGL_CONTEXT_DEBUG_BIT_ARB                 0x0001
#define WGL_DRAW_TO_WINDOW_ARB                    0x2001
#define WGL_ACCELERATION_ARB                      0x2003
#define WGL_SUPPORT_OPENGL_ARB                    0x2010
#define WGL_DOUBLE_BUFFER_ARB                     0x2011
#define WGL_PIXEL_TYPE_ARB                        0x2013
#define WGL_COLOR_BITS_ARB                        0x2014
#define WGL_DEPTH_BITS_ARB                        0x2022
#define WGL_STENCIL_BITS_ARB                      0x2023
#define WGL_FULL_ACCELERATION_ARB                 0x2027
#define WGL_TYPE_RGBA_ARB                         0x202B
#define WGL_ALPHA_BITS_ARB                        0x201B



    #if SPG_DEBUG
    void GLDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char *message, const void *userParam)
    {
    
        SPG_LOG_TEXT("[OPENGL]");
        switch (source) {
            case GL_DEBUG_SOURCE_API: {
                SPG_LOG_TEXT("[Source: API]");
            }
                break;
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM: {
                SPG_LOG_TEXT("[Source: Window System]");

            }
                break;
            case GL_DEBUG_SOURCE_SHADER_COMPILER: {
                SPG_LOG_TEXT("[Source: Shader Compiler]");

            }
                break;
            case GL_DEBUG_SOURCE_THIRD_PARTY: {
                SPG_LOG_TEXT("[Source: Third Party]");

            }
                break;
            case GL_DEBUG_SOURCE_APPLICATION: {
                SPG_LOG_TEXT("[Source: Application]");

            }
                break;
            case GL_DEBUG_SOURCE_OTHER: {
                SPG_LOG_TEXT("[Source: Other]");

            }
                break;
        }

        switch (type) {
            case GL_DEBUG_TYPE_ERROR: {
                SPG_LOG_TEXT("[Type: Error]");

            }
                break;
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: {
                SPG_LOG_TEXT("[Type: Deprecated Behaviour]");
            }
                break;
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: {
                SPG_LOG_TEXT("[Type: Undefined Behaviour]");

            }
                break;
            case GL_DEBUG_TYPE_PORTABILITY: {
                SPG_LOG_TEXT("[Type: Portability]");

            }
                break;
            case GL_DEBUG_TYPE_PERFORMANCE: {
                SPG_LOG_TEXT("[Type: Performance]");

            }
                break;
            case GL_DEBUG_TYPE_MARKER: {
                SPG_LOG_TEXT("[Type: Marker]");

            }
                break;
            case GL_DEBUG_TYPE_PUSH_GROUP: {
                SPG_LOG_TEXT("[Type: Push Group]");

            }
                break;
            case GL_DEBUG_TYPE_POP_GROUP: {
                SPG_LOG_TEXT("[Type: Pop Group]");

            }
                break;
            case GL_DEBUG_TYPE_OTHER: {
                SPG_LOG_TEXT("[Type: Other]");
            }
                break;
        }

        switch (severity) {
            case GL_DEBUG_SEVERITY_HIGH: {
                SPG_LOG_TEXT("[Severity: high]");
            }
                break;
            case GL_DEBUG_SEVERITY_MEDIUM: {
                SPG_LOG_TEXT("[Severity: medium]");
            }
                break;
            case GL_DEBUG_SEVERITY_LOW: {
                SPG_LOG_TEXT("[Severity: low]");
            }
                break;
            case GL_DEBUG_SEVERITY_NOTIFICATION: {
                SPG_LOG_TEXT("[Severity: notification]");
            }
                break;
        }
        SPG_LOG_TEXT(": %s\n", message);
    }

#endif

typedef BOOL(WINAPI* PFN_wglChoosePixelFormatARB)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
typedef HGLRC(WINAPI* PFN_wglCreateContextAttribsARB) (HDC hdc, HGLRC hShareContext, const int* attribList);
typedef BOOL(*PFN_wglSwapIntervalEXT)(int interval);
typedef int (*PFN_wglGetSwapIntervalEXT)(void);
typedef const char* (*PFN_wglGetExtensionsStringARB)(HDC hdc);

FUNCTION_PTR(wglChoosePixelFormatARB);
FUNCTION_PTR(wglCreateContextAttribsARB);
FUNCTION_PTR(wglGetExtensionsStringARB);
FUNCTION_PTR(wglSwapIntervalEXT);
FUNCTION_PTR(wglGetSwapIntervalEXT);

#define OPENGL_LOAD_FUNCTION_PTR(function)\
function = (PFN_##function) wglGetProcAddress(#function);


    void LoadExtensionFunctionPointers()
    {
        OPENGL_LOAD_FUNCTION_PTR(wglChoosePixelFormatARB);
        OPENGL_LOAD_FUNCTION_PTR(wglCreateContextAttribsARB);
        OPENGL_LOAD_FUNCTION_PTR(wglGetExtensionsStringARB);
        OPENGL_LOAD_FUNCTION_PTR(wglSwapIntervalEXT);
        OPENGL_LOAD_FUNCTION_PTR(wglGetSwapIntervalEXT);


        OPENGL_LOAD_FUNCTION_PTR(glGetStringi);
        OPENGL_LOAD_FUNCTION_PTR(glDebugMessageCallback);
        OPENGL_LOAD_FUNCTION_PTR(glDebugMessageControl);
        OPENGL_LOAD_FUNCTION_PTR(glGenBuffers);
        OPENGL_LOAD_FUNCTION_PTR(glBindBuffer);
        OPENGL_LOAD_FUNCTION_PTR(glBufferData);
        OPENGL_LOAD_FUNCTION_PTR(glCreateShader);
        OPENGL_LOAD_FUNCTION_PTR(glShaderSource);
        OPENGL_LOAD_FUNCTION_PTR(glLinkProgram);
        OPENGL_LOAD_FUNCTION_PTR(glUseProgram);
        OPENGL_LOAD_FUNCTION_PTR(glCompileShader);
        OPENGL_LOAD_FUNCTION_PTR(glGetShaderiv);
        OPENGL_LOAD_FUNCTION_PTR(glGetShaderInfoLog);
        OPENGL_LOAD_FUNCTION_PTR(glCreateProgram);
        OPENGL_LOAD_FUNCTION_PTR(glAttachShader);
        OPENGL_LOAD_FUNCTION_PTR(glDeleteShader);
        OPENGL_LOAD_FUNCTION_PTR(glGetProgramiv);
        OPENGL_LOAD_FUNCTION_PTR(glGetProgramInfoLog);
        OPENGL_LOAD_FUNCTION_PTR(glDeleteProgram);
        OPENGL_LOAD_FUNCTION_PTR(glVertexAttribPointer);
        OPENGL_LOAD_FUNCTION_PTR(glDisableVertexAttribArray);
        OPENGL_LOAD_FUNCTION_PTR(glEnableVertexAttribArray);
        OPENGL_LOAD_FUNCTION_PTR(glGenVertexArrays);
        OPENGL_LOAD_FUNCTION_PTR(glBindVertexArray);
        OPENGL_LOAD_FUNCTION_PTR(glDeleteVertexArrays);
        OPENGL_LOAD_FUNCTION_PTR(glDrawArraysInstanced);
        OPENGL_LOAD_FUNCTION_PTR(glCreateBuffers);
        OPENGL_LOAD_FUNCTION_PTR(glDeleteBuffers);
        OPENGL_LOAD_FUNCTION_PTR(glCreateVertexArrays);
        OPENGL_LOAD_FUNCTION_PTR(glUniformMatrix4fv);
        OPENGL_LOAD_FUNCTION_PTR(glGetUniformLocation);
        OPENGL_LOAD_FUNCTION_PTR(glUniform1i);
        OPENGL_LOAD_FUNCTION_PTR(glUniform1f);
        OPENGL_LOAD_FUNCTION_PTR(glUniform2fv);
        OPENGL_LOAD_FUNCTION_PTR(glUniform3fv);
        OPENGL_LOAD_FUNCTION_PTR(glUniform4fv);
        OPENGL_LOAD_FUNCTION_PTR(glActiveTexture);
        OPENGL_LOAD_FUNCTION_PTR(glGenerateMipmap);
        OPENGL_LOAD_FUNCTION_PTR(glGenFramebuffers);
        OPENGL_LOAD_FUNCTION_PTR(glCheckFramebufferStatus);
        OPENGL_LOAD_FUNCTION_PTR(glFramebufferTexture2D);
        OPENGL_LOAD_FUNCTION_PTR(glBindFramebuffer);
        OPENGL_LOAD_FUNCTION_PTR(glDeleteFramebuffers);
        OPENGL_LOAD_FUNCTION_PTR(glCopyImageSubData);
    }

    void Win32OpenGLRendererBackend::LoadOpenGLExtensions()
    {
        WNDCLASSW windowClass = {0};
        windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        windowClass.lpfnWndProc = DefWindowProcA;
        windowClass.hInstance = GetModuleHandle(0);
        windowClass.lpszClassName = L"Dummy_Window";
        
        ATOM reg = RegisterClassW(&windowClass);
        assert(reg);

        HWND dummyWindow = CreateWindowExW(
            0,
            windowClass.lpszClassName,
            L"Dummy Window",
            0,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            windowClass.hInstance,
            0);

        assert(dummyWindow);

        HDC dummyDC = GetDC(dummyWindow);

        PIXELFORMATDESCRIPTOR pfd = { 0 };
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;

        int32_t pixelFormat = ChoosePixelFormat(dummyDC, &pfd);
        assert(pixelFormat);
        BOOL SPF = SetPixelFormat(dummyDC, pixelFormat, &pfd);
        assert(SPF);
        HGLRC dummyContext = wglCreateContext(dummyDC);
        assert(dummyContext);
        BOOL WMC = wglMakeCurrent(dummyDC, dummyContext);
        assert(WMC);
        LoadExtensionFunctionPointers();
        //call glew init here

        wglMakeCurrent(dummyDC, 0);
        wglDeleteContext(dummyContext);
        ReleaseDC(dummyWindow, dummyDC);
        DestroyWindow(dummyWindow);
    }
    
    RendererBackendAPI Win32OpenGLRendererBackend::GetAPI()
    {
        return _specs.api;
    }
    
    void Win32OpenGLRendererBackend::SetVsync(bool on)
    {
        wglSwapIntervalEXT(on? 1 : 0);
    }
    
    Win32OpenGLRendererBackend::Win32OpenGLRendererBackend(const RendererBackendSpecs& specs)
    {
        _specs = specs;
        LoadOpenGLExtensions();
        _hdc = GetDC((HWND)specs.internalWindowHandle);

        const int attribList[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB, 32,
            WGL_DEPTH_BITS_ARB, 24,
            WGL_STENCIL_BITS_ARB, 8,
            WGL_ALPHA_BITS_ARB, 8,
            0, // End
        };

        int32_t pixelFormat;
        UINT numFormats;
        wglChoosePixelFormatARB(_hdc, attribList, NULL, 1, &pixelFormat, &numFormats);
        assert(numFormats != 0);

        PIXELFORMATDESCRIPTOR pfd;
        DescribePixelFormat(_hdc, pixelFormat, sizeof(pfd), &pfd);
        BOOL SPF = SetPixelFormat(_hdc, pixelFormat, &pfd);
        assert(SPF);

#ifdef SPG_DEBUG
        int32_t openglContextAttribs[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 6,
            WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
            0,
        };
#else
        int32_t openglContextAttribs[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 6,
            WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0,
        };
#endif
        HGLRC _openglContext = wglCreateContextAttribsARB(_hdc, 0, openglContextAttribs);
        assert(_openglContext);
        BOOL WMC = wglMakeCurrent(_hdc, _openglContext);
        assert(WMC);
#if 0
        GLint flags;
        glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
        {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(GLDebugOutput, NULL);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
        }
#endif
        SPG_LOG_MESSAGE("OPENGL VERSION: %s", glGetString(GL_VERSION));
        SPG_LOG_MESSAGE("OPENGL VERSION: %s", glGetString(GL_VENDOR));
        wglSwapIntervalEXT(1);
        
        RECT clientRect;
        GetClientRect((HWND)specs.internalWindowHandle, &clientRect);
        int width = clientRect.right - clientRect.left;
        int height = clientRect.bottom - clientRect.top;
        glViewport(0, 0, width, height);
    }
    
    Win32OpenGLRendererBackend::~Win32OpenGLRendererBackend()
    {
        wglMakeCurrent(_hdc, 0);
        wglDeleteContext(_openglContext);
    }

    
}
#endif