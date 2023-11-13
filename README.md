# LearnOpenGL

## 前言
记录学习OpenGL的过程，顺便把踩过的坑和大家分享一下。

## 开发环境和工具
- Windows 10
- Visual Studio Community 2022

## 项目文件结构
├── Project	解决方案<br>
│&ensp;&ensp;&ensp;&ensp;├── Dependencies 依赖文件夹<br>
│&ensp;&ensp;&ensp;&ensp;├── 01_CreateWindow<br>
│&ensp;&ensp;&ensp;&ensp;├── 02_HelloPrimitive<br>
│&ensp;&ensp;&ensp;&ensp;├── 03_GLEW<br>
├── Project.sln 工程文件<br>

## 目录
每一个项目工程都可以独立运行的。
1. 打开一个窗口	01_CreateWindow
- 通过 GLFW 创建一个窗口
2. 你好，图元	02_HelloPrimitive
- 通过 glBengin、glVertex3f 绘制基本图元
3. 接入GLEW

## 参考
- TheCherno OpenGL教程，来源：哔哩哔哩
- LearnOpen CN, https://learnopengl-cn.github.io/
- 《OpenGL 编程指南》（第9版）—— 红宝书
- 《OpenGL 超级宝典》（第5版）—— 蓝宝书