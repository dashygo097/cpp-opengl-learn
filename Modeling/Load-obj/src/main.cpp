#include "camera.h"
#include "mesh.h"
#include "extension.h"

int width = 1600,height = 1600, numColth;

// Camera & Keymap & Curser
Camera camera(width, height);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movements();
void do_floats();


int main()
{

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

    // Depth Testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetKeyCallback(window, key_callback);  
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // Pre-Process

    Mesh floormesh("./resources/models/cornellbox/floor.obj");
    Mesh leftmesh("./resources/models/cornellbox/left.obj");
    Mesh rightmesh("./resources/models/cornellbox/right.obj");
    Mesh lightmesh("./resources/models/cornellbox/light.obj");
    Mesh shortboxmesh("./resources/models/cornellbox/shortbox.obj");
    Mesh tallboxmesh("./resources/models/cornellbox/tallbox.obj");

    std::vector<Mesh> objectMeshes;
    std::vector<Mesh> surfaceMeshes;
    std::vector<Mesh> lightMeshes;
    surfaceMeshes.push_back(floormesh);
    surfaceMeshes.push_back(leftmesh);
    surfaceMeshes.push_back(rightmesh);
    objectMeshes.push_back(shortboxmesh);
    objectMeshes.push_back(tallboxmesh);
    lightMeshes.push_back(lightmesh);

    // Params

    std::vector<glm::vec3> objectColors = 
    {
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.5f ,0.5f, 0.5f),
    }; 

    std::vector<glm::vec3> surfaceColors = 
    {
        glm::vec3(0.97f, 0.97f, 0.92f),
        glm::vec3(0.7f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.7f, 0.0f),
    };

    std::vector<glm::vec3> lightColors = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
    };


    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 projection = glm::make_mat4x4(I_4);
    glm::mat4 trans = glm::make_mat4x4(I_4);
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);

    // Shaders

    Shader lightShader("./resources/vertices/object.vert",
        "./resources/fragments/light.frag");
    
    Shader objectShader("./resources/vertices/object.vert",
        "./resources/fragments/object.frag");
    
    Shader surfaceShader("./resources/vertices/object.vert",
        "./resources/fragments/surface.frag");

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

        glClearColor(0.1f,0.2f,0.2f,1.0f);
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

        // Load the LIGHTS

        GLint viewPosLoc = glGetUniformLocation(objectShader.Program, "viewPos");

        GLint lightStrengthLoc = glGetUniformLocation(objectShader.Program, "light.strength");
        GLint lightPosLoc = glGetUniformLocation(objectShader.Program, "light.position");
        GLint lightCutoffLoc = glGetUniformLocation(objectShader.Program, "light.cutoff");
        GLint lightOuterCutoffLoc = glGetUniformLocation(objectShader.Program, "light.outercutoff");
        GLint lightDirLoc = glGetUniformLocation(objectShader.Program, "light.direction");
        GLint lightColorLoc = glGetUniformLocation(objectShader.Program, "light.color");
        GLint lightAmbientLoc = glGetUniformLocation(objectShader.Program, "light.ambient");
        GLint lightDiffuseLoc = glGetUniformLocation(objectShader.Program, "light.diffuse");
        GLint lightSpecularLoc = glGetUniformLocation(objectShader.Program, "light.specular");

        GLint ambientLoc = glGetUniformLocation(objectShader.Program, "Texture.ambient");
        GLint diffuseLoc = glGetUniformLocation(objectShader.Program, "Texture.diffuse");
        GLint specularLoc = glGetUniformLocation(objectShader.Program, "Texture.specular");
        GLint shineLoc = glGetUniformLocation(objectShader.Program, "Texture.shininess");
        GLint objectColorLoc = glGetUniformLocation(objectShader.Program, "objectColor");

        glUniform3fv(viewPosLoc, 1, &camera.Pos[0]);

        glUniform3f(ambientLoc, 1.3f, 1.3f, 1.3f); 
        glUniform3f(diffuseLoc, 0.5f, 0.5f, 0.5f);
        glUniform3f(specularLoc, 1.0f, 1.0f, 1.0f);
        glUniform1f(shineLoc, 256.0f);

        glm::vec3 lightG = get_G(lightmesh.vertices);

        glUniform1f(lightStrengthLoc, 100.0f); 
        glUniform3fv(lightPosLoc, 1, &lightG[0]);
        glUniform1f(lightCutoffLoc, glm::cos(glm::radians(60.0f)));
        glUniform1f(lightOuterCutoffLoc, glm::cos(glm::radians(75.0f))); 
        glUniform3f(lightDirLoc, 0.0f, -1.0f, 0.0f);
        glUniform3fv(lightColorLoc, 1, &lightColors[0][0]);
        glUniform3f(lightAmbientLoc, 0.1f, 0.1f, 0.1f);
        glUniform3f(lightDiffuseLoc, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);


        // Draw the OBJECTS

        glm::mat4 model = glm::make_mat4x4(I_4);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        for (int i = 0; i < 2; i++)
        {

            glUniform3fv(objectColorLoc, 1, &objectColors[i][0]);
            objectMeshes[i].Draw(objectShader);
        }

        // SURFACE OBJECTS
        surfaceShader.Activate();

        // 3D Space

        modelLoc = glGetUniformLocation(surfaceShader.Program, "model");
        projectionLoc = glGetUniformLocation(surfaceShader.Program, "projection");
        transLoc = glGetUniformLocation(surfaceShader.Program, "transform");
        viewLoc = glGetUniformLocation(surfaceShader.Program, "view");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Load the LIGHTS

        viewPosLoc = glGetUniformLocation(surfaceShader.Program, "viewPos");

        lightStrengthLoc = glGetUniformLocation(surfaceShader.Program, "light.strength");
        lightPosLoc = glGetUniformLocation(surfaceShader.Program, "light.position");
        lightCutoffLoc = glGetUniformLocation(surfaceShader.Program, "light.cutoff");
        lightOuterCutoffLoc = glGetUniformLocation(surfaceShader.Program, "light.outercutoff");
        lightDirLoc = glGetUniformLocation(surfaceShader.Program, "light.direction");
        lightColorLoc = glGetUniformLocation(surfaceShader.Program, "light.color");
        lightAmbientLoc = glGetUniformLocation(surfaceShader.Program, "light.ambient");
        lightDiffuseLoc = glGetUniformLocation(surfaceShader.Program, "light.diffuse");
        lightSpecularLoc = glGetUniformLocation(surfaceShader.Program, "light.specular");

        ambientLoc = glGetUniformLocation(surfaceShader.Program, "Texture.ambient");
        diffuseLoc = glGetUniformLocation(surfaceShader.Program, "Texture.diffuse");
        specularLoc = glGetUniformLocation(surfaceShader.Program, "Texture.specular");
        shineLoc = glGetUniformLocation(surfaceShader.Program, "Texture.shininess");
        objectColorLoc = glGetUniformLocation(surfaceShader.Program, "objectColor");

        glUniform3fv(viewPosLoc, 1, &camera.Pos[0]);

        glUniform3f(ambientLoc, 1.3f, 1.3f, 1.3f); 
        glUniform3f(diffuseLoc, 0.3f, 0.3f, 0.3f);
        glUniform3f(specularLoc, 0.2f, 0.2f, 0.2f);
        glUniform1f(shineLoc, 64.0f);

        lightG = get_G(lightmesh.vertices);

        glUniform1f(lightStrengthLoc, 100.0f); 
        glUniform3fv(lightPosLoc, 1, &lightG[0]);
        glUniform1f(lightCutoffLoc, glm::cos(glm::radians(60.0f)));
        glUniform1f(lightOuterCutoffLoc, glm::cos(glm::radians(75.0f))); 
        glUniform3f(lightDirLoc, 0.0f, -1.0f, 0.0f);
        glUniform3fv(lightColorLoc, 1, &lightColors[0][0]);
        glUniform3f(lightAmbientLoc, 0.1f, 0.1f, 0.1f);
        glUniform3f(lightDiffuseLoc, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightSpecularLoc, 0.7f, 0.7f, 0.7f);


        // Draw the OBJECTS

        model = glm::make_mat4x4(I_4);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        for (int i = 0; i < 3; i++)
        {

            glUniform3fv(objectColorLoc, 1, &surfaceColors[i][0]);
            surfaceMeshes[i].Draw(surfaceShader);
        }
  


        // LIGHTS
        lightShader.Activate();

        // 3D Space

        modelLoc = glGetUniformLocation(lightShader.Program, "model");
        projectionLoc = glGetUniformLocation(lightShader.Program, "projection");
        transLoc = glGetUniformLocation(lightShader.Program, "transform");
        viewLoc = glGetUniformLocation(lightShader.Program, "view");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Draw the LIGHTS

        lightColorLoc = glGetUniformLocation(lightShader.Program, "lightColor");

        model = glm::make_mat4x4(I_4);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        glUniform3fv(lightColorLoc, 1, &lightColors[0][0]);
        lightMeshes[0].Draw(lightShader);


        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    lightShader.Delete();
    objectShader.Delete();
    surfaceShader.Delete();
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
