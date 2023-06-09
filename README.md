# Shader Playground
Shader Playground is a powerful and flexible tool for running GLSL shaders, designed with inspiration from the Shadertoy website. The application utilizes the OpenGL API as its graphics backend, with architecture that allows for potential support of other backends like Vulkan. Although currently supporting only Windows, Shader Playground is developed with portability in mind, facilitating future support for Linux and other platforms.

## Getting Started
These instructions will guide you on how to build Shader Playground from source code on your local machine.

### Prerequisites
Before you begin, ensure that you have met the following requirements:

- You have a Windows machine. Other OS support is planned for future releases.
- You have installed the latest drivers for your graphics card.
- You have installed MSVC build tools.

### Windows
To build Shader Playground from source, run the folowing script in the command-line
```batchscript
# Clone the repository
git clone https://github.com/BashirAbu/shader_playground.git --recursive

# Move to the repository directory
cd shader_playground

# Run the build script for debug mode
cl-build.bat

# Or for release mode
cl-build.bat release
```
## Quick Tour
The user interface of Shader Playground is designed for simplicity and ease of use, consisting of two main panels: the Viewport and the Editor.
- The Viewport panel visualizes the output of your GLSL code execution. This panel also features a Frames Per Second (FPS) counter for performance tracking. Additionally, it provides a Compile button for executing your GLSL code, and a Screenshot button for capturing the current Viewport state.
- The Editor panel serves as your workspace for writing and modifying GLSL code.

<div align="center">
<img src="https://github.com/BashirAbu/shader_playground/assets/80569644/c939b5c2-87a4-4445-9f80-29d8d11de0f6">
</div>

- When working within a project, any screenshots captured are automatically stored in the project's directory under ProjectName/screenshots/. If you're using Shader Playground without a specified project, the screenshots will be saved in the application's executable directory, specifically under data/screenshots/.
- In the File menu, you can find options to save your current project, save it under a new name with the 'Save As' function, or load an existing project. ***There's also the ability to run test projects located in the 'examples' folder***.

 <div align="center">
<img src="https://github.com/BashirAbu/shader_playground/assets/80569644/cfa29f32-8099-4f7c-b596-0ac9259ba5b3)" style="border-radius: 50%;">
</div>


<div align="center">
<img src="https://github.com/BashirAbu/shader_playground/assets/80569644/6253f670-ed0b-41b0-8be7-e3d73b9e59fb)" style="border-radius: 50%;">
</div>

- The File menu also houses the 'Settings' option, which opens a pop-up settings window. Here, you can tailor your Shader Playground experience by enabling or disabling VSync, adjusting the framebuffer size (Viewport size) in pixels, and changing the font color for the Editor panel.

<div align="center">
<img src="https://github.com/BashirAbu/shader_playground/assets/80569644/5b323d07-b697-4e34-9c67-3ca1bd794bcb)" style="border-radius: 50%;">
</div>


- The way you write GLSL shaders in Shader Playground is similar to Shadertoy. If you'd like to learn more about writing shaders, you can refer to the Shadertoy documentation and their guide available at https://www.shadertoy.com/howto.

## Project Dependencies

This project relies on several key dependencies:

1. **Dear ImGui**: This library is used for creating and managing the project's User Interface. More information can be found in the [Dear ImGui GitHub Repository](https://github.com/ocornut/imgui).

2. **stb_image**: This library is used for loading and writing PNG files within the project. More information can be found in the [stb GitHub Repository](https://github.com/nothings/stb).

3. **tinyxml2**: This library is used for saving the project file in an XML format. More information can be found in the [tinyxml2 GitHub Repository](https://github.com/leethomason/tinyxml2).
