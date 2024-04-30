# LearnOpenGL

## 前言
记录学习OpenGL的过程，顺便把踩过的坑和大家分享一下。每个项目都可以单独运行。

## 开发环境和工具
- Windows 10
- Visual Studio Community 2022

## 项目文件结构
├── Project	解决方案<br>
│&ensp;&ensp;&ensp;&ensp;├─ Dependencies 依赖文件夹<br>
│&ensp;&ensp;&ensp;&ensp;├─ 01_CreateWindow<br>
│&ensp;&ensp;&ensp;&ensp;├─ 02_HelloPrimitive<br>
│&ensp;&ensp;&ensp;&ensp;├─ 03_GLEW<br>
│&ensp;&ensp;&ensp;&ensp;├─ 04_DrawArrays<br>
│&ensp;&ensp;&ensp;&ensp;├─ 05_DrawElements<br>
│&ensp;&ensp;&ensp;&ensp;├─ 06_Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 07_Texture<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ vendor<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ stb_image<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Texture2D<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 08_Transformation<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ vendor<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ stb_image<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ glm<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Texture2D<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 09_CoordinateSystem<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ vendor<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ stb_image<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ glm<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Texture2D<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 10_Assimp<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 11_Mesh<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ vendor<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ stb_image<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ glm<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Mesh<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Texture2D<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
│&ensp;&ensp;&ensp;&ensp;├─ 12_Model<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ src<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ vendor<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ stb_image<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ glm<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Mesh<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Model<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Shader<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ Texture2D<br>
│&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;├─ res<br>
├── Project.sln 工程文件<br>

## 目录
每一个项目工程都可以独立运行的。
1. 打开一个窗口：01_CreateWindow&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7294560261539725843/
![01.CreateWindow](https://github.com/zGameDeveloper/LearnOpenGL/blob/729808653e68e2f1256aada1cfdada11e3a36e43/doc/res/01.CreateWindow.png)    
    - 通过 GLFW 创建一个窗口
    
2. 你好，图元：02_HelloPrimitive&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7298165586935333417/
![02.HelloPrimitive](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/02.HelloPrimitive.png)
    - glBegin
    - glVertex3f
    - glEnd
    - glPointSize
    - glLineWidth
    
3. 接入GLEW：03_GLEW&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7299268967548486155/
![03.GLEW](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/03.GLEW.png)

4. 使用DrawArrays进行绘制：04_DrawArrays&emsp;&emsp;&emsp;https://www.toutiao.com/article/7314116504373510695/
![04.DrawArrays](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/04.DrawArrays.png)
    - glGenBuffers
    - glBindBuffer
    - glBufferData
    - glVertexAttribPointer
    - glEnableVertexAttribArray
    - glDrawArrays
5. 使用DrawElemtes进行绘制：05_DrawElements&emsp;https://www.toutiao.com/article/7317075299152527883/
![05.DrawElements](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/05.DrawElements.png)
    - glDrawElements
6. 着色器基础：06_Shader&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7317915584849723915/
![06.Shader](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/06.Shader.png)
    - glCreateShader
    - glShaderSource
    - glCompileShader
    - glCreateProgram
    - glAttachShader
    - glLinkProgram
    - glUseProgram
7. 纹理基础：07_Texture&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7323047177029190180/
![07.Texture](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/07.Texture.png)
    - glGenTextures
    - glBindTexture
    - glTexParameteri
    - glTexImage2D
    - glGenerateMipmap
    - glActiveTexture
8. 变换：08_Transformation&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7327209720761401868/
![08.Transformation](https://github.com/zGameDeveloper/LearnOpenGL/blob/b4badf995d646e690d80e67d73ff6fe626c5cf8b/doc/res/08.Transformation.gif)
    - glGetUniformLocation
    - glUniformMatrix4fv
9. 坐标系统：09_CoordinateSystem&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7327967563743347239/
![09.CoordinateSystem](https://github.com/zGameDeveloper/LearnOpenGL/blob/main/doc/res/09.CoordinateSystem.png)
10. Assimp构建和导入：10_Assimp&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7355314396362457663/
11. 网格基础：11_Mesh&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;https://www.toutiao.com/article/7363125067305304595/
![11.Mesh](https://github.com/zGameDeveloper/LearnOpenGL/blob/main/doc/res/11.Mesh.png)
12. 导入3D模型：12_Model
## 参考
- TheCherno OpenGL教程，来源：哔哩哔哩
- LearnOpen CN, https://learnopengl-cn.github.io/
- opengl-tutoial CN, http://www.opengl-tutorial.org/cn
- 《OpenGL 编程指南》（第9版）—— 红宝书
- 《OpenGL 超级宝典》（第5版）—— 蓝宝书