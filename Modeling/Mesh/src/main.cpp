#include "camera.h"
#include "extension.h"
#include "mesh.h"

int width = 1600,height = 1600, numColth;

// Camera & Keymap & Curser
Camera camera(width, height);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movements();
void do_floats();

std::vector<Vertex> vertices = 
{
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f,1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f,1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f))

};

std::vector<GLuint> indices;
std::vector<Texture> textures;

int main()
{
    // indices
    for (int i = 0 ; i < 36; i++)
    {
        indices.push_back(i);
    }

    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height ,"Lighting-Test", NULL, NULL);

    if (window == nullptr)
    {
        std::cout << "Failed to create a window object!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, key_callback);  
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // Pre-Process

    get_normal_raw(vertices);

    Texture texture_1("diffuse");
    texture_1.Load_Image("./resources/textures/container2.png",width,height,numColth);
    Texture texture_2("specular");
    texture_2.Load_Image("./resources/textures/container2_specular.png",width,height,numColth);
    Texture texture_floor_1("diffuse");
    texture_floor_1.Load_Image("./resources/textures/planks.png",width,height,numColth);
    Texture texture_floor_2("specular");
    texture_floor_2.Load_Image("./resources/textures/planks.png",width,height,numColth);

    textures.push_back(texture_1);
    textures.push_back(texture_2);
    textures.push_back(texture_floor_1);
    textures.push_back(texture_floor_2);

    Mesh objectmesh(vertices, indices, textures);
    Mesh lightmesh(vertices, indices, textures);
    Mesh floormesh(vertices, indices, textures);


    glm::vec3 objects[] = 
    {
        glm::vec3(-1.0f, 0.0f, 1.0f),
        glm::vec3(3.0f, -1.0f, 2.0f),
        glm::vec3(-4.0f, 4.0f, 4.0f),
        glm::vec3(0.0f, -4.0f, 0.0f),
    };

    glm::vec3 lightobjects[] = 
    {
        glm::vec3(2.0f, 2.0f, 2.0f),
    };

    std::vector<glm::vec3> floorobjects;

    for (int i = 0 ; i < 4; i ++)
    {
        for (int j= 0 ; j < 4; j ++)
        {
            floorobjects.push_back(glm::vec3(10.0f - 5 * float(i), -4.0f, 10.0f - 5 * float(j)));
        }
    }

    glm::vec3 cubeColor[] = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };

    glm::vec3 lightColor[] = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
    };

    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 projection = glm::make_mat4x4(I_4);
    glm::mat4 trans = glm::make_mat4x4(I_4);
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);

    // Shaders

    Shader objectShader("./resources/vertices/object.vert",
        "./resources/fragments/object.frag");

    Shader lightShader("./resources/vertices/object.vert",
        "./resources/fragments/light.frag");
    
    Shader floorShader("./resources/vertices/object.vert",
        "./resources/fragments/floor.frag");

    // Program
    GLfloat time_last = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        GLfloat time = glfwGetTime();
        GLfloat delta = time - time_last;
        time_last = glfwGetTime();

        glfwPollEvents();
        do_movements();
        do_floats();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.02f,0.01f,0.01f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // OBJECTS
        objectShader.Activate();

        // 3D Space

        GLint modelLoc = glGetUniformLocation(objectShader.Program, "model");
        GLint projectionLoc = glGetUniformLocation(objectShader.Program, "projection");
        GLint transLoc = glGetUniformLocation(objectShader.Program, "transform");
        GLint viewLoc = glGetUniformLocation(objectShader.Program, "view");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Draw

        GLint viewPosLoc = glGetUniformLocation(objectShader.Program, "viewPos");

        GLint shineLoc = glGetUniformLocation(objectShader.Program, "material_1.shininess");

        GLint lightStrengthLoc = glGetUniformLocation(objectShader.Program, "light.strength");
        GLint lightPosLoc = glGetUniformLocation(objectShader.Program, "light.position");
        GLint lightColorLoc = glGetUniformLocation(objectShader.Program, "light.color");
        GLint lightAmbientLoc = glGetUniformLocation(objectShader.Program, "light.ambient");
        GLint lightDiffuseLoc = glGetUniformLocation(objectShader.Program, "light.diffuse");
        GLint lightSpecularLoc = glGetUniformLocation(objectShader.Program, "light.specular");


        glUniform1f(lightStrengthLoc, 50.0f); 
        glUniform3fv(lightPosLoc, 1, &lightobjects[0][0]);
        glUniform3fv(lightColorLoc, 1, &lightColor[0][0]);
        glUniform3f(lightAmbientLoc, 0.1f, 0.1f, 0.1f);
        glUniform3f(lightDiffuseLoc, 0.4f, 0.4f, 0.4f);
        glUniform3f(lightSpecularLoc, 3.0f, 3.0f, 3.0f);

        glm::mat4 model = glm::make_mat4x4(I_4);
        for (int i = 0 ;i < 3; i++)
        {
            // Draw the object
            glUniform1f(shineLoc, 32.0f);
            model = glm::translate(model, objects[i]);
            model = glm::rotate(model, float(-55.0f / 180.0f * M_PI), glm::vec3(1.0f, 0.5f, 0.7f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            objectmesh.Draw(objectShader);
        } 

        // LIGHTING OBJECTS
        lightShader.Activate();

        // 3D Space

        modelLoc = glGetUniformLocation(lightShader.Program, "model");
        projectionLoc = glGetUniformLocation(lightShader.Program, "projection");
        transLoc = glGetUniformLocation(lightShader.Program, "transform");
        viewLoc = glGetUniformLocation(lightShader.Program, "view");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Draw 

        lightColorLoc = glGetUniformLocation(lightShader.Program, "lightColor");
        glUniform3fv(lightColorLoc,1 ,&lightColor[0][0]);

        model = glm::make_mat4x4(I_4); 
        model = glm::translate(model, lightobjects[0]);
        model = glm::scale(model,glm::vec3(0.2f, 0.2f, 0.2f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        floormesh.Draw(floorShader);


        // FLOOR OBJECTS
        floorShader.Activate();

        // 3D Space

        modelLoc = glGetUniformLocation(floorShader.Program, "model");
        projectionLoc = glGetUniformLocation(floorShader.Program, "projection");
        transLoc = glGetUniformLocation(floorShader.Program, "transform");
        viewLoc = glGetUniformLocation(floorShader.Program, "view");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Draw

        viewPosLoc = glGetUniformLocation(floorShader.Program, "viewPos");

        shineLoc = glGetUniformLocation(floorShader.Program, "material_1.shininess");

        lightStrengthLoc = glGetUniformLocation(floorShader.Program, "light.strength");
        lightPosLoc = glGetUniformLocation(floorShader.Program, "light.position");
        lightColorLoc = glGetUniformLocation(floorShader.Program, "light.color");
        lightAmbientLoc = glGetUniformLocation(floorShader.Program, "light.ambient");
        lightDiffuseLoc = glGetUniformLocation(floorShader.Program, "light.diffuse");
        lightSpecularLoc = glGetUniformLocation(floorShader.Program, "light.specular");

        glUniform1f(shineLoc, 16.0f);
        glUniform1f(lightStrengthLoc, 50.0f); 
        glUniform3fv(lightPosLoc, 1, &lightobjects[0][0]);
        glUniform3fv(lightColorLoc, 1, &lightColor[0][0]);
        glUniform3f(lightAmbientLoc, 0.1f, 0.1f, 0.1f);
        glUniform3f(lightDiffuseLoc, 0.4f, 0.4f, 0.4f);
        glUniform3f(lightSpecularLoc, 0.5f, 0.5f, 0.5f);

        for (int i = 0 ; i < 16; i++)
        {
            model = glm::make_mat4x4(I_4); 
            model = glm::translate(model, floorobjects[i]);
            model = glm::scale(model,glm::vec3(5.0f, 0.1f, 5.0f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            floormesh.Draw(floorShader);
        }

        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    objectShader.Delete();
    lightShader.Delete();
    floorShader.Delete();
    objectmesh.Delete();
    lightmesh.Delete();
    floormesh.Delete();
    glfwTerminate();
    return 0;

}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key <= 1023 && key >= 0)
    {
        if (action == GLFW_PRESS)
        {
            camera.keys[key] = true;
        }
        else if (action == GLFW_RELEASE) 
        {
            camera.keys[key] = false;
        }
    }

}

void do_movements()
{
    if(camera.keys[GLFW_KEY_W])
    {
        glm::vec3 clip = camera.front.y * camera.up;
        glm::vec3 direc = camera.front - clip; 
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos += camera.Speed * camera.weight;
        camera.Move();
    }
    if(camera.keys[GLFW_KEY_S])
    {
        glm::vec3 clip = camera.front.y * camera.up;
        glm::vec3 direc = camera.front - clip; 
        camera.Speed -=  0.00005f * glm::normalize(direc);
        camera.Pos += camera.Speed * camera.weight ;
        camera.Move();
    }
    if(camera.keys[GLFW_KEY_A])
    {
        glm::vec3 direc = 0.0f - glm::cross(camera.front, camera.up);
        glm::vec3 clip = direc.y * camera.up;
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos +=  camera.Speed * camera.weight * 0.2f ;
        camera.Move();
    }
    if(camera.keys[GLFW_KEY_D])
    {
        
        glm::vec3 direc = glm::cross(camera.front, camera.up);
        glm::vec3 clip = direc.y * camera.up;
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos +=  camera.Speed * camera.weight * 0.2f;
        camera.Move();
    }
    if(camera.keys[GLFW_KEY_SPACE])
    {
        camera.Speed += 0.00005f * camera.up;
        camera.Pos += camera.weight * 0.03f * camera.Speed;
        camera.Move();
    }   
    if (camera.keys[GLFW_KEY_LEFT_SHIFT])
    {
        camera.Speed -=  0.00005f * camera.up;
        camera.Pos += camera.weight * 0.03f * camera.Speed;
        camera.Move();
    } 

}

void do_floats()
{
    glm::vec3 clip = camera.front.y * camera.up;
    glm::vec3 direc = camera.front - clip; 
    camera.Speed *= 0.995f;

    if (glm::length(camera.Speed) < 0.000001f)
    {
        camera.Speed *= 0.0f;
    } 
    camera.Pos += camera.Speed  ;
    camera.Move();  
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (camera.firstMouse)
    {
        camera.lastX = xpos;
        camera.lastY = ypos;
        camera.firstMouse = false;
    }

    GLfloat xoffset = xpos - camera.lastX;
    GLfloat yoffset = camera.lastY - ypos; 
    camera.lastX = xpos;
    camera.lastY = ypos;

    GLfloat sensitivity = 0.02;	
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.yaw   += xoffset;
    camera.pitch += yoffset;


    if (camera.pitch > 89.0f )
    {
        camera.pitch = 89.0f;
    }
    if (camera.pitch < -89.0f)
    {
        camera.pitch = -89.0f;
    }

    glm::vec3 front;
    front.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    front.y = sin(glm::radians(camera.pitch));
    front.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.front = glm::normalize(front);
    camera.Move();
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.weight += yoffset* 0.01f ;
    if (camera.weight < 0.0f)
    {
        camera.weight = 0.0f;
    }
}
