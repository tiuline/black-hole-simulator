#include "Engine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

std::string loadShaderSource(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir shader: " << filePath << std::endl;
        exit(EXIT_FAILURE);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

Engine::Engine()
    : width(800), height(600)
{
    offsetX = 0.0f;
    offsetY =  0.0f;
    zoom = 1.0f;
    middleMousePressed = false;
    lastMouseX = 0.0;
    lastMouseY = 0.0;

    if (!glfwInit())
    {
        std::cerr << "Falha ao iniciar o GLFW" <<std::endl;
        exit(EXIT_FAILURE);
    }
    
    window = glfwCreateWindow(width, height, "BHS - Black Hole Simulator", NULL, NULL );
    
    if(!window)
    {
        std::cerr << "Falha ao iniciar a janela GLFW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "Falha ao iniciar o GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    std::string vertexCode = loadShaderSource("shaders/vertex.glsl");
    std::string fragmentCode = loadShaderSource("shaders/fragment.glsl");
    shaderProgram = compileShader(vertexCode.c_str(), fragmentCode.c_str());

    initBlackHoleCircle(0.1f);
    glViewport(0,0, width, height);;
}

Engine::~Engine()
{
    glDeleteVertexArrays(1, &blackHoleVAO);
    glDeleteBuffers(1, &blackHoleVBO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLuint Engine::compileShader(const char* vertexSrc, const char* fragmentSrc)
{
    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &vertexSrc, nullptr);
    glCompileShader(vert);
    // checar erros (omitido pra brevidade)

    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &fragmentSrc, nullptr);
    glCompileShader(frag);

    GLuint prog = glCreateProgram();
    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glLinkProgram(prog);

    // checar erros, deletar shaders
    glDeleteShader(vert);
    glDeleteShader(frag);
    return prog;
}


void Engine::initBlackHoleCircle(float radius)
{
    BlackHole bh(glm::vec2(0.0f, 0.0f), 8.54e36);
    auto circleVertices = bh.generateBlackHoleVertices(radius, 100);
    blackHoleVertexCount = circleVertices.size();

    glGenVertexArrays(1, &blackHoleVAO);
    glGenBuffers(1, &blackHoleVBO);

    glBindVertexArray(blackHoleVAO);
    glBindBuffer(GL_ARRAY_BUFFER, blackHoleVBO);
    glBufferData(GL_ARRAY_BUFFER, circleVertices.size() * sizeof(glm::vec2), circleVertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Engine::run()
{
    float aspect = static_cast<float>(width) / height;
    glm::mat4 projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        GLint projLoc = glGetUniformLocation(shaderProgram, "uProjection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(blackHoleVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, blackHoleVertexCount);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}