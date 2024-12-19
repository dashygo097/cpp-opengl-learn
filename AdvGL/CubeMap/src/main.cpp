#include "camera.h"
#include "mesh.h"

int width = 2400,height = 1600, numColth;

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

std::vector<Vertex> skyboxVertices = 
{
    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec2(0.0f, 0.0f))
};

GLfloat quadVertices[] = { 
        //   Pos    //   Coord   //
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
};

std::vector<GLuint> indices;
std::vector<Texture> textures;

std::vector<std::string> faces=
{
    "./resources/skybox/right.jpg",
    "./resources/skybox/left.jpg",
    "./resources/skybox/top.jpg",
    "./resources/skybox/bottom.jpg",
    "./resources/skybox/front.jpg",
    "./resources/skybox/back.jpg"
};


int main()
{

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
    glfwSetWindowSize(window, 800, 600);
    glfwSetWindowPos(window, 500, 300);
    gladLoadGL();

    // Texture2D
    glEnable(GL_TEXTURE_2D);

    // Depth Testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Stencil Testing
    // glEnable(GL_STENCIL_TEST);

    // Gamma Testing
    glEnable(GL_FRAMEBUFFER_SRGB);

    // Face Culting
    // glEnable(GL_CULL_FACE);

    glfwSetKeyCallback(window, key_callback);  
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // Pre-Process

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

    Mesh boxmesh(vertices, indices, textures);
    Mesh lightmesh(vertices, indices, textures);
    Mesh floormesh(vertices, indices, textures);

    // Params

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


    glm::vec3 objectColor[] = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };

    glm::vec3 floorColor = glm::vec3(1.0f);

    glm::vec3 lightColor[] = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
    };

    glm::vec3 light_pos = glm::vec3(2.0f, 2.0f, 2.0f);

    std::vector<LightProperty> pointlight = 
    {
        LightProperty("strength", glm::vec3(20.0f)),
        LightProperty("direction", glm::vec3(0.5f, -3.0f, 2.0f)),
        LightProperty("color", glm::vec3(1.0f)),
        LightProperty("ambient", glm::vec3(0.6f)),
        LightProperty("diffuse", glm::vec3(0.8f)),
        LightProperty("specular", glm::vec3(2.0f)),
    };

    LightLoader light_loader("DirecLight", pointlight);


    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 projection = glm::make_mat4x4(I_4);
    glm::mat4 trans = glm::make_mat4x4(I_4);
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);

    // Shaders
    Shader skyboxShader("./resources/vertices/skybox.vert",
        "./resources/fragments/skybox.frag");

    Shader lightShader("./resources/vertices/object.vert",
        "./resources/fragments/light.frag");
    
    Shader objectShader("./resources/vertices/object.vert",
        "./resources/fragments/object.frag");
    
    Shader surfaceShader("./resources/vertices/object.vert",
        "./resources/fragments/surface.frag");
    
    Shader screenShader("./resources/vertices/screen.vert",
        "./resources/fragments/screen.frag");
    

    
    // FBO
    // screenShader.Activate();
    // screenShader.set1d("screenTexture", 3);

    // unsigned int quadVAO, quadVBO;
    // glGenVertexArrays(1, &quadVAO);
    // glGenBuffers(1, &quadVBO);
    // glBindVertexArray(quadVAO);
    // glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(1);
    // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    // QuadVAO quadVAO;
    // VBO quadVBO(quadVertices, sizeof(quadVertices));
    // quadVAO.Bind();
    // quadVBO.Bind();
    // quadVAO.LinkVBO(quadVBO, 0);
    // quadVAO.LinkVBO(quadVBO, 1);

    // FBO fbo;
    // TexColorBuffer tcb(width, height);
    // RBO rbo(width, height);
    // fbo.Link(tcb, rbo);

    // Skybox
    SkyboxMesh skyboxmesh(skyboxVertices, indices, faces);


    // Program
    GLfloat time_last = glfwGetTime();
    int count = 0;
    float fps[200];
    float fps_ave = 0;
    
    while (!glfwWindowShouldClose(window))
    {
        GLfloat time = glfwGetTime();
        GLfloat delta = time - time_last;
        time_last = glfwGetTime();

        fps[count] = 1 / delta;
        count ++;
        if (count == 199)
        {
            for (int i = 0 ; i < 200 ; i ++)
            {
                fps_ave += fps[i] / 200;
            }
            printf("%d FPS\n", (int)fps_ave);
            fps_ave = 0;
            count = 0;
        }


        glfwPollEvents();
        do_movements();
        do_floats();
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_STENCIL_BUFFER_BIT(x)
        glEnable(GL_DEPTH_TEST);




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

        // Load LIGHTS and OBJECTS

        GLint viewPosLoc = glGetUniformLocation(objectShader.Program, "viewPos");

        GLint diffuseLoc = glGetUniformLocation(objectShader.Program, "material_1.diffuse");
        GLint specularLoc = glGetUniformLocation(objectShader.Program, "material_1.specular");
        GLint shineLoc = glGetUniformLocation(objectShader.Program, "material_1.shininess");
        GLint objectColorLoc = glGetUniformLocation(objectShader.Program, "objectColor");

        glUniform3fv(viewPosLoc, 1, &camera.Pos[0]);

        glUniform3f(diffuseLoc, 0.5f, 0.5f, 0.5f);
        glUniform3f(specularLoc, 0.7f, 0.7f, 0.7f);
        glUniform1f(shineLoc, 1024.0f);

        light_loader.handler(objectShader);


        // Draw the OBJECTS

        glm::mat4 model = glm::make_mat4x4(I_4);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        for (int i = 0 ;i < 3; i++)
        {
            // Draw the object
            glUniform1f(shineLoc, 32.0f);
            model = glm::translate(model, objects[i]);
            model = glm::rotate(model, float(-55.0f / 180.0f * M_PI), glm::vec3(1.0f, 0.5f, 0.7f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            boxmesh.Draw(objectShader);
        } 
     
        // SKYBOX
        glDepthMask(GL_FALSE);
        skyboxShader.Activate();

        projectionLoc = glGetUniformLocation(skyboxShader.Program, "projection");
        viewLoc = glGetUniformLocation(skyboxShader.Program, "view");
        glm::mat4 view = glm::mat4(glm::mat3(camera.view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        skyboxmesh.Draw(skyboxShader);
        glDepthMask(GL_TRUE);
        // Post-Process of the screen

        // glBindFramebuffer(GL_FRAMEBUFFER, 0);
        // glDisable(GL_DEPTH_TEST); 
        // glClear(GL_COLOR_BUFFER_BIT);

        // screenShader.Activate();
        // glBindVertexArray(quadVAO);
        // glBindTexture(GL_TEXTURE_2D, tcb.ID);
        // glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    lightShader.Delete();
    objectShader.Delete();
    surfaceShader.Delete();
    screenShader.Delete();
    skyboxShader.Delete();
    boxmesh.Delete();
    lightmesh.Delete();
    floormesh.Delete();
    skyboxmesh.Delete();

    // tcb.Delete();
    // rbo.Delete();
    // fbo.Delete();
    // quadVBO.Delete();
    // quadVAO.Delete();
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
