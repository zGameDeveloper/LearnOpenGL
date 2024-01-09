# LearnOpenGL

## 前言
记录学习OpenGL的过程，顺便把踩过的坑和大家分享一下。每个项目都可以单独运行。

## 开发环境和工具
- Windows 10
- Visual Studio Community 2022

## 项目文件结构
├── Project	解决方案<br>
│&ensp;&ensp;&ensp;&ensp;├── Dependencies 依赖文件夹<br>
│&ensp;&ensp;&ensp;&ensp;├── 01_CreateWindow<br>
│&ensp;&ensp;&ensp;&ensp;├── 02_HelloPrimitive<br>
│&ensp;&ensp;&ensp;&ensp;├── 03_GLEW<br>
│&ensp;&ensp;&ensp;&ensp;├── 04_DrawArrays<br>
│&ensp;&ensp;&ensp;&ensp;├── 05_DrawElements<br>
│&ensp;&ensp;&ensp;&ensp;├── 06_Shader<br>
├── Project.sln 工程文件<br>

## 目录
每一个项目工程都可以独立运行的。
1. 打开一个窗口：01_CreateWindow&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7294560261539725843/
    - 通过 GLFW 创建一个窗口
2. 你好，图元：02_HelloPrimitive&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7298165586935333417/
    - glBengin
    - glVertex3f
3. 接入GLEW：03_GLEW&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7299268967548486155/
4. 使用DrawArrays进行绘制：04_DrawArrays&emsp;&emsp;&emsp;https://www.toutiao.com/article/7314116504373510695/
    - glGenBuffers
    - glBindBuffer
    - glBufferData
    - glVertexAttribPointer
    - glEnableVertexAttribArray
    - glDrawArrays
5. 使用DrawElemtes进行绘制：05_DrawElements&emsp;https://www.toutiao.com/article/7317075299152527883/
    - glDrawElements
6. 着色器基础：06_Shader&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7317915584849723915/
    - glCreateShader
    - glShaderSource
    - glCompileShader
    - glCreateProgram
    - glAttachShader
    - glLinkProgram
    - glUseProgram
## 参考
- TheCherno OpenGL教程，来源：哔哩哔哩
- LearnOpen CN, https://learnopengl-cn.github.io/
- 《OpenGL 编程指南》（第9版）—— 红宝书
- 《OpenGL 超级宝典》（第5版）—— 蓝宝书